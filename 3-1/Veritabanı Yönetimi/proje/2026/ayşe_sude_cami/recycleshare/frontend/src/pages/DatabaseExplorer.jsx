import { useState, useEffect, useCallback } from 'react'
import { useNavigate } from 'react-router-dom'
import { useAuth } from '../context/AuthContext'
import { adminAPI } from '../services/api'
import toast from 'react-hot-toast'
import { FiArrowLeft, FiDatabase, FiTable, FiKey, FiLink, FiColumns, FiChevronRight, FiChevronLeft } from 'react-icons/fi'
import ERDiagram from '../components/ERDiagram'

const DatabaseExplorer = () => {
    const { user, logout } = useAuth()
    const navigate = useNavigate()

    const [tables, setTables] = useState([])
    const [schema, setSchema] = useState(null)
    const [selectedTable, setSelectedTable] = useState(null)
    const [tableSchema, setTableSchema] = useState(null)
    const [tableData, setTableData] = useState(null)
    const [loading, setLoading] = useState(true)
    const [viewMode, setViewMode] = useState('er') // 'er' or 'data'
    const [currentPage, setCurrentPage] = useState(1)

    useEffect(() => {
        loadInitialData()
    }, [])

    const loadInitialData = async () => {
        setLoading(true)
        try {
            const [tablesRes, schemaRes] = await Promise.all([
                adminAPI.getTableList(),
                adminAPI.getDatabaseSchema()
            ])
            if (tablesRes.success) setTables(tablesRes.data)
            if (schemaRes.success) setSchema(schemaRes.data)
        } catch (error) {
            toast.error('Veritabanı bilgileri yüklenemedi')
        } finally {
            setLoading(false)
        }
    }

    const loadTableDetails = async (tableName) => {
        setSelectedTable(tableName)
        setLoading(true)
        try {
            const [schemaRes, dataRes] = await Promise.all([
                adminAPI.getTableSchema(tableName),
                adminAPI.getTableData(tableName, 1, 20)
            ])
            if (schemaRes.success) setTableSchema(schemaRes.data)
            if (dataRes.success) setTableData(dataRes)
            setCurrentPage(1)
        } catch (error) {
            toast.error('Tablo detayları yüklenemedi')
        } finally {
            setLoading(false)
        }
    }

    const loadPage = async (page) => {
        if (!selectedTable) return
        try {
            const dataRes = await adminAPI.getTableData(selectedTable, page, 20)
            if (dataRes.success) {
                setTableData(dataRes)
                setCurrentPage(page)
            }
        } catch (error) {
            toast.error('Sayfa yüklenemedi')
        }
    }

    // Generate Mermaid ER diagram code
    const generateMermaidER = useCallback(() => {
        if (!schema) return ''

        let mermaid = 'erDiagram\n'

        // Add tables with columns
        schema.tables.forEach(table => {
            table.columns.forEach(col => {
                const pk = col.is_primary_key ? 'PK' : ''
                const type = col.data_type.toUpperCase().replace('CHARACTER VARYING', 'VARCHAR')
                mermaid += `    ${table.name} {\n        ${type} ${col.column_name} ${pk}\n    }\n`
            })
        })

        // Add relationships
        schema.relationships.forEach(rel => {
            const deleteRule = rel.delete_rule === 'CASCADE' ? 'CASCADE' : 'RESTRICT'
            mermaid += `    ${rel.target_table} ||--o{ ${rel.source_table} : "${rel.source_column}"\n`
        })

        return mermaid
    }, [schema])

    return (
        <div className="min-h-screen bg-gradient-to-br from-slate-900 via-slate-800 to-slate-900">
            {/* Header */}
            <header className="bg-black/30 backdrop-blur-xl border-b border-white/10 sticky top-0 z-50">
                <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
                    <div className="flex items-center justify-between h-16">
                        <div className="flex items-center gap-4">
                            <button
                                onClick={() => navigate('/admin/dashboard')}
                                className="p-2 text-white/70 hover:text-white hover:bg-white/10 rounded-lg transition"
                            >
                                <FiArrowLeft className="w-5 h-5" />
                            </button>
                            <div className="flex items-center gap-2">
                                <FiDatabase className="w-6 h-6 text-emerald-400" />
                                <h1 className="text-xl font-bold text-white">Veritabanı Gezgini</h1>
                            </div>
                        </div>
                        <div className="flex gap-2">
                            <button
                                onClick={() => setViewMode('er')}
                                className={`px-4 py-2 rounded-lg text-sm font-medium transition ${viewMode === 'er'
                                    ? 'bg-emerald-500 text-white'
                                    : 'bg-white/10 text-white/70 hover:bg-white/20'
                                    }`}
                            >
                                🗺️ ER Diyagramı
                            </button>
                            <button
                                onClick={() => setViewMode('data')}
                                className={`px-4 py-2 rounded-lg text-sm font-medium transition ${viewMode === 'data'
                                    ? 'bg-emerald-500 text-white'
                                    : 'bg-white/10 text-white/70 hover:bg-white/20'
                                    }`}
                            >
                                📋 Tablo Verileri
                            </button>
                        </div>
                    </div>
                </div>
            </header>

            <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-8">
                {loading && !selectedTable ? (
                    <div className="flex items-center justify-center py-20">
                        <div className="animate-spin rounded-full h-12 w-12 border-4 border-emerald-500 border-t-transparent"></div>
                    </div>
                ) : (
                    <div className="grid grid-cols-1 lg:grid-cols-4 gap-6">
                        {/* Left Sidebar - Table List */}
                        <div className="lg:col-span-1">
                            <div className="bg-white/10 backdrop-blur-xl rounded-2xl border border-white/10 overflow-hidden">
                                <div className="p-4 border-b border-white/10">
                                    <h2 className="text-lg font-semibold text-white flex items-center gap-2">
                                        <FiTable className="w-5 h-5" />
                                        Tablolar ({tables.length})
                                    </h2>
                                </div>
                                <div className="divide-y divide-white/5">
                                    {tables.map((table) => (
                                        <button
                                            key={table.table_name}
                                            onClick={() => loadTableDetails(table.table_name)}
                                            className={`w-full px-4 py-3 text-left hover:bg-white/10 transition flex items-center justify-between ${selectedTable === table.table_name ? 'bg-emerald-500/20 border-l-4 border-emerald-500' : ''
                                                }`}
                                        >
                                            <div>
                                                <p className={`font-medium ${selectedTable === table.table_name ? 'text-emerald-300' : 'text-white'}`}>
                                                    {table.table_name}
                                                </p>
                                                <p className="text-xs text-white/50">
                                                    {table.column_count} sütun • {table.row_count} kayıt
                                                </p>
                                            </div>
                                            <FiChevronRight className="w-4 h-4 text-white/30" />
                                        </button>
                                    ))}
                                </div>
                            </div>
                        </div>

                        {/* Main Content */}
                        <div className="lg:col-span-3">
                            {viewMode === 'er' ? (
                                /* ER Diagram View - React Flow */
                                <div className="bg-white/10 backdrop-blur-xl rounded-2xl border border-white/10 p-4">
                                    <h2 className="text-lg font-semibold text-white mb-4">🗺️ ER Diyagramı (İnteraktif)</h2>
                                    <p className="text-white/50 text-sm mb-4">Tabloları sürükleyerek hareket ettirebilir, zoom yapabilir ve bir tabloya tıklayarak detaylarını görebilirsiniz.</p>
                                    <ERDiagram schema={schema} onTableSelect={loadTableDetails} />
                                </div>
                            ) : (
                                /* Table Data View */
                                <div className="space-y-4">
                                    {/* Table Schema */}
                                    {tableSchema && (
                                        <div className="bg-white/10 backdrop-blur-xl rounded-2xl border border-white/10 p-4">
                                            <h3 className="text-lg font-semibold text-white mb-4 flex items-center gap-2">
                                                <FiColumns className="w-5 h-5" />
                                                {selectedTable} - Şema
                                            </h3>
                                            <div className="overflow-x-auto">
                                                <table className="w-full text-sm">
                                                    <thead>
                                                        <tr className="bg-white/5">
                                                            <th className="px-3 py-2 text-left text-xs font-medium text-white/70">Sütun</th>
                                                            <th className="px-3 py-2 text-left text-xs font-medium text-white/70">Tip</th>
                                                            <th className="px-3 py-2 text-left text-xs font-medium text-white/70">Nullable</th>
                                                            <th className="px-3 py-2 text-left text-xs font-medium text-white/70">Keys</th>
                                                            <th className="px-3 py-2 text-left text-xs font-medium text-white/70">Default</th>
                                                        </tr>
                                                    </thead>
                                                    <tbody className="divide-y divide-white/5">
                                                        {tableSchema.columns.map((col) => (
                                                            <tr key={col.column_name} className="hover:bg-white/5">
                                                                <td className="px-3 py-2 text-white font-mono">{col.column_name}</td>
                                                                <td className="px-3 py-2 text-emerald-300 font-mono text-xs">
                                                                    {col.data_type}{col.character_maximum_length ? `(${col.character_maximum_length})` : ''}
                                                                </td>
                                                                <td className="px-3 py-2">
                                                                    <span className={`px-2 py-0.5 rounded text-xs ${col.is_nullable === 'YES' ? 'bg-yellow-500/20 text-yellow-300' : 'bg-red-500/20 text-red-300'
                                                                        }`}>
                                                                        {col.is_nullable === 'YES' ? 'NULL' : 'NOT NULL'}
                                                                    </span>
                                                                </td>
                                                                <td className="px-3 py-2">
                                                                    {col.is_primary_key && (
                                                                        <span className="px-2 py-0.5 bg-yellow-500/20 text-yellow-300 rounded text-xs mr-1">PK</span>
                                                                    )}
                                                                    {col.is_foreign_key && (
                                                                        <span className="px-2 py-0.5 bg-blue-500/20 text-blue-300 rounded text-xs" title={`→ ${col.foreign_table_name}.${col.foreign_column_name}`}>
                                                                            FK
                                                                        </span>
                                                                    )}
                                                                </td>
                                                                <td className="px-3 py-2 text-white/50 text-xs font-mono truncate max-w-[150px]">
                                                                    {col.column_default || '-'}
                                                                </td>
                                                            </tr>
                                                        ))}
                                                    </tbody>
                                                </table>
                                            </div>

                                            {/* Check Constraints */}
                                            {tableSchema.checkConstraints?.length > 0 && (
                                                <div className="mt-4 p-3 bg-orange-500/10 rounded-lg border border-orange-500/20">
                                                    <h4 className="text-sm font-medium text-orange-300 mb-2">CHECK Constraints</h4>
                                                    {tableSchema.checkConstraints.map((c, idx) => (
                                                        <p key={idx} className="text-xs text-white/70 font-mono">{c.check_clause}</p>
                                                    ))}
                                                </div>
                                            )}
                                        </div>
                                    )}

                                    {/* Table Data */}
                                    {tableData && (
                                        <div className="bg-white/10 backdrop-blur-xl rounded-2xl border border-white/10 overflow-hidden">
                                            <div className="p-4 border-b border-white/10 flex justify-between items-center">
                                                <h3 className="text-lg font-semibold text-white">
                                                    📊 Veriler ({tableData.pagination.totalRows} kayıt)
                                                </h3>
                                                <div className="flex items-center gap-2">
                                                    <button
                                                        onClick={() => loadPage(currentPage - 1)}
                                                        disabled={currentPage === 1}
                                                        className="p-2 text-white/70 hover:text-white hover:bg-white/10 rounded-lg disabled:opacity-30"
                                                    >
                                                        <FiChevronLeft className="w-4 h-4" />
                                                    </button>
                                                    <span className="text-white/70 text-sm">
                                                        {currentPage} / {tableData.pagination.totalPages}
                                                    </span>
                                                    <button
                                                        onClick={() => loadPage(currentPage + 1)}
                                                        disabled={currentPage >= tableData.pagination.totalPages}
                                                        className="p-2 text-white/70 hover:text-white hover:bg-white/10 rounded-lg disabled:opacity-30"
                                                    >
                                                        <FiChevronRight className="w-4 h-4" />
                                                    </button>
                                                </div>
                                            </div>
                                            <div className="overflow-x-auto max-h-[400px] overflow-y-auto">
                                                <table className="w-full text-sm">
                                                    <thead className="sticky top-0 bg-slate-800">
                                                        <tr>
                                                            {tableData.data[0] && Object.keys(tableData.data[0]).map(key => (
                                                                <th key={key} className="px-3 py-2 text-left text-xs font-medium text-white/70 whitespace-nowrap">
                                                                    {key}
                                                                </th>
                                                            ))}
                                                        </tr>
                                                    </thead>
                                                    <tbody className="divide-y divide-white/5">
                                                        {tableData.data.map((row, idx) => (
                                                            <tr key={idx} className="hover:bg-white/5">
                                                                {Object.values(row).map((val, i) => (
                                                                    <td key={i} className="px-3 py-2 text-white/80 whitespace-nowrap max-w-[200px] truncate">
                                                                        {val === null ? <span className="text-white/30 italic">NULL</span> : String(val)}
                                                                    </td>
                                                                ))}
                                                            </tr>
                                                        ))}
                                                    </tbody>
                                                </table>
                                            </div>
                                        </div>
                                    )}

                                    {!selectedTable && (
                                        <div className="bg-white/10 backdrop-blur-xl rounded-2xl border border-white/10 p-12 text-center">
                                            <FiTable className="w-12 h-12 text-white/30 mx-auto mb-4" />
                                            <p className="text-white/50">Soldaki listeden bir tablo seçin</p>
                                        </div>
                                    )}
                                </div>
                            )}
                        </div>
                    </div>
                )}
            </div>
        </div>
    )
}

export default DatabaseExplorer

import { useCallback, useMemo } from 'react'
import ReactFlow, {
    Background,
    Controls,
    MiniMap,
    useNodesState,
    useEdgesState,
    MarkerType,
    Handle,
    Position
} from 'reactflow'
import 'reactflow/dist/style.css'
import { FiKey, FiLink } from 'react-icons/fi'

// Custom Table Node Component
const TableNode = ({ data }) => {
    return (
        <div className="bg-slate-800 rounded-lg border-2 border-emerald-500/50 shadow-xl min-w-[200px] overflow-hidden">
            {/* Table Header */}
            <div className="bg-gradient-to-r from-emerald-600 to-teal-600 px-4 py-2">
                <h3 className="font-bold text-white text-sm flex items-center gap-2">
                    🗃️ {data.label}
                </h3>
                <p className="text-emerald-100 text-xs">{data.rowCount} kayıt</p>
            </div>

            {/* Columns */}
            <div className="p-2 max-h-48 overflow-y-auto">
                {data.columns?.map((col, idx) => (
                    <div
                        key={idx}
                        className={`flex items-center gap-2 px-2 py-1.5 text-xs rounded ${col.is_primary_key ? 'bg-yellow-500/10' : 'hover:bg-white/5'
                            }`}
                    >
                        {col.is_primary_key && <FiKey className="w-3 h-3 text-yellow-400 flex-shrink-0" />}
                        {col.is_foreign_key && <FiLink className="w-3 h-3 text-blue-400 flex-shrink-0" />}
                        <span className={`${col.is_primary_key ? 'text-yellow-300 font-medium' : 'text-white/80'}`}>
                            {col.column_name}
                        </span>
                        <span className="text-white/40 text-[10px] ml-auto">
                            {col.data_type.replace('character varying', 'varchar').replace('timestamp without time zone', 'timestamp')}
                        </span>
                    </div>
                ))}
            </div>

            {/* Handles for connections */}
            <Handle type="target" position={Position.Left} className="!bg-emerald-500 !w-3 !h-3" />
            <Handle type="source" position={Position.Right} className="!bg-teal-500 !w-3 !h-3" />
        </div>
    )
}

const nodeTypes = { tableNode: TableNode }

// Grid layout for tables
const calculateLayout = (tables) => {
    const COLS = 3
    const NODE_WIDTH = 250
    const NODE_HEIGHT = 280
    const GAP_X = 80
    const GAP_Y = 50

    return tables.map((table, index) => {
        const col = index % COLS
        const row = Math.floor(index / COLS)

        return {
            id: table.name,
            type: 'tableNode',
            position: {
                x: col * (NODE_WIDTH + GAP_X),
                y: row * (NODE_HEIGHT + GAP_Y)
            },
            data: {
                label: table.name,
                columns: table.columns,
                rowCount: table.row_count || 0
            }
        }
    })
}

// Create edges from relationships
const createEdges = (relationships) => {
    return relationships.map((rel, idx) => ({
        id: `edge-${idx}`,
        source: rel.source_table,
        target: rel.target_table,
        type: 'smoothstep',
        animated: true,
        style: { stroke: rel.delete_rule === 'CASCADE' ? '#f97316' : '#3b82f6', strokeWidth: 2 },
        markerEnd: {
            type: MarkerType.ArrowClosed,
            color: rel.delete_rule === 'CASCADE' ? '#f97316' : '#3b82f6',
        },
        label: `${rel.source_column} → ${rel.target_column}`,
        labelStyle: {
            fill: '#fff',
            fontWeight: 500,
            fontSize: 10,
            textShadow: '0 0 4px rgba(0,0,0,0.8)'
        },
        labelBgStyle: {
            fill: rel.delete_rule === 'CASCADE' ? '#f9731650' : '#3b82f650',
            fillOpacity: 0.9
        },
        labelBgPadding: [4, 2],
        labelBgBorderRadius: 4
    }))
}

const ERDiagram = ({ schema, onTableSelect }) => {
    const initialNodes = useMemo(() => {
        if (!schema?.tables) return []
        return calculateLayout(schema.tables)
    }, [schema])

    const initialEdges = useMemo(() => {
        if (!schema?.relationships) return []
        return createEdges(schema.relationships)
    }, [schema])

    const [nodes, setNodes, onNodesChange] = useNodesState(initialNodes)
    const [edges, setEdges, onEdgesChange] = useEdgesState(initialEdges)

    const onNodeClick = useCallback((event, node) => {
        if (onTableSelect) {
            onTableSelect(node.id)
        }
    }, [onTableSelect])

    if (!schema) {
        return (
            <div className="h-[500px] flex items-center justify-center text-white/50">
                Şema yükleniyor...
            </div>
        )
    }

    return (
        <div className="h-[600px] w-full bg-slate-900 rounded-xl overflow-hidden border border-white/10">
            <ReactFlow
                nodes={nodes}
                edges={edges}
                onNodesChange={onNodesChange}
                onEdgesChange={onEdgesChange}
                onNodeClick={onNodeClick}
                nodeTypes={nodeTypes}
                fitView
                minZoom={0.3}
                maxZoom={1.5}
                attributionPosition="bottom-left"
                proOptions={{ hideAttribution: true }}
            >
                <Background color="#334155" gap={20} size={1} />
                <Controls
                    className="!bg-slate-700 !border-slate-600 !rounded-lg"
                    showInteractive={false}
                />
                <MiniMap
                    nodeColor={() => '#10b981'}
                    maskColor="rgba(0, 0, 0, 0.8)"
                    className="!bg-slate-800 !border-slate-600 !rounded-lg"
                />
            </ReactFlow>

            {/* Legend */}
            <div className="absolute bottom-4 right-4 bg-slate-800/90 backdrop-blur rounded-lg p-3 border border-white/10">
                <p className="text-white/70 text-xs font-medium mb-2">İlişkiler:</p>
                <div className="flex items-center gap-2 text-xs mb-1">
                    <div className="w-4 h-0.5 bg-orange-500"></div>
                    <span className="text-orange-300">CASCADE</span>
                </div>
                <div className="flex items-center gap-2 text-xs">
                    <div className="w-4 h-0.5 bg-blue-500"></div>
                    <span className="text-blue-300">RESTRICT</span>
                </div>
            </div>
        </div>
    )
}

export default ERDiagram

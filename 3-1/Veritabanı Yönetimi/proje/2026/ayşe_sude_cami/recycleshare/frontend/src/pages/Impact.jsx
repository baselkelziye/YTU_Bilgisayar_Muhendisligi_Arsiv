import React, { useState, useEffect } from "react";
import { useNavigate } from "react-router-dom";
import { FiArrowLeft, FiBox, FiCloud, FiUsers, FiCalendar, FiTrendingUp, FiDatabase } from "react-icons/fi";
import { wasteAPI, reportAPI } from '../services/api';
import { useAuth } from '../context/AuthContext';

const ViewImpact = () => {
  const navigate = useNavigate();
  const { user } = useAuth();

  const [stats, setStats] = useState({
    itemsShared: 0,
    co2Saved: "0.0",
    communityConnections: 0,
    totalScore: 0,
    monthlyProgress: []
  });

  // fn_get_user_monthly_report - CURSOR & RECORD fonksiyonu
  const [monthlyReport, setMonthlyReport] = useState([]);
  const [reportLoading, setReportLoading] = useState(false);

  // v_monthly_recycling_report VIEW
  const [communityOverview, setCommunityOverview] = useState({ summary: null, data: [] });
  const [overviewLoading, setOverviewLoading] = useState(false);

  useEffect(() => {
    const fetchImpactData = async () => {
      try {
        const response = await wasteAPI.getImpactStats();

        if (response.success && response.data) {
          const apiData = response.data;
          setStats({
            itemsShared: apiData.itemsShared || 0,
            co2Saved: apiData.co2Saved || "0.0",
            communityConnections: apiData.connections || 0,
            totalScore: apiData.totalScore || 0,
            monthlyProgress: apiData.monthlyImpact || []
          });
        }
      } catch (error) {
        console.error("Veri çekme hatası:", error);
      }
    };
    fetchImpactData();
  }, []);

  // fn_get_user_monthly_report fonksiyonunu çağır (CURSOR & RECORD)
  useEffect(() => {
    const fetchMonthlyReport = async () => {
      if (!user?.userId) return;

      setReportLoading(true);
      try {
        const currentDate = new Date();
        const response = await reportAPI.getUserMonthlyReport(
          user.userId,
          currentDate.getFullYear(),
          currentDate.getMonth() + 1
        );

        if (response.success && response.data) {
          setMonthlyReport(response.data);
        }
      } catch (error) {
        console.error("Aylık rapor hatası:", error);
      } finally {
        setReportLoading(false);
      }
    };
    fetchMonthlyReport();
  }, [user]);

  // v_monthly_recycling_report VIEW'ını çağır
  useEffect(() => {
    const fetchCommunityOverview = async () => {
      setOverviewLoading(true);
      try {
        const currentYear = new Date().getFullYear();
        const response = await reportAPI.getMonthlyOverview(currentYear);

        if (response.success) {
          setCommunityOverview({
            summary: response.summary,
            data: response.data || []
          });
        }
      } catch (error) {
        console.error("Topluluk özeti hatası:", error);
      } finally {
        setOverviewLoading(false);
      }
    };
    fetchCommunityOverview();
  }, []);

  const maxValue = stats.monthlyProgress.length > 0
    ? Math.max(...stats.monthlyProgress.map((d) => d.value), 10)
    : 10;

  return (
    <div className="min-h-screen bg-emerald-50 text-emerald-900 p-6">
      <div className="max-w-6xl mx-auto">
        <div className="flex items-center justify-between mb-6">
          <div>
            <h1 className="text-3xl font-semibold text-emerald-700">Çevre Etkiniz </h1>
            <p className="text-sm text-emerald-600 mt-1">
              Topluluğunuzda atıkları ve emisyonları nasıl azalttığınızı görün. Aylık ilerlemenizi takip edin ve çevresel etkinizi artırmak için motive olun!
            </p>
          </div>
          <button
            onClick={() => navigate("/dashboard")}
            className="inline-flex items-center gap-2 px-4 py-2 rounded-md bg-emerald-600 hover:bg-emerald-700 text-white shadow"
          >
            <FiArrowLeft className="w-5 h-5" />
            Ana Sayfa
          </button>
        </div>

        {/* İstatistik Kartları */}
        <div className="grid grid-cols-1 sm:grid-cols-3 gap-4 mb-8">
          <div className="flex items-center gap-4 p-4 bg-white rounded-lg shadow border-l-4 border-emerald-400">
            <div className="p-3 bg-emerald-100 text-emerald-600 rounded-md">
              <FiBox className="w-6 h-6" />
            </div>
            <div>
              <div className="text-sm text-emerald-600">Paylaşılan Atık Sayısı</div>
              <div className="text-2xl font-semibold text-emerald-800">{stats.itemsShared}</div>
            </div>
          </div>

          <div className="flex items-center gap-4 p-4 bg-white rounded-lg shadow border-l-4 border-emerald-400">
            <div className="p-3 bg-emerald-100 text-emerald-600 rounded-md">
              <FiCloud className="w-6 h-6" />
            </div>
            <div>
              <div className="text-sm text-emerald-600">CO2 Tasarrufu (kg)</div>
              <div className="text-2xl font-semibold text-emerald-800">{stats.co2Saved}</div>
            </div>
          </div>

          <div className="flex items-center gap-4 p-4 bg-white rounded-lg shadow border-l-4 border-emerald-400">
            <div className="p-3 bg-emerald-100 text-emerald-600 rounded-md">
              <FiUsers className="w-6 h-6" />
            </div>
            <div>
              <div className="text-sm text-emerald-600">Topluluk Bağlantıları</div>
              <div className="text-2xl font-semibold text-emerald-800">{stats.communityConnections}</div>
            </div>
          </div>
        </div>

        {/* 2 Sütunlu Layout: Aylık İlerleme + Kişisel Rapor */}
        <div className="grid grid-cols-1 lg:grid-cols-2 gap-6 mb-8">

          {/* Grafik Kartı - Animasyonlu Barlar */}
          <div className="bg-white rounded-lg shadow p-6">
            <h2 className="text-lg font-medium text-emerald-800 mb-6 flex items-center gap-2">
              <FiTrendingUp className="text-emerald-500" />
              Aylık Etki İlerleme Durumu
            </h2>

            {stats.monthlyProgress.length > 0 ? (
              <div className="space-y-4">
                {stats.monthlyProgress.map((d, i) => {
                  const percentage = maxValue > 0 ? (d.value / maxValue) * 100 : 0;
                  return (
                    <div key={i} className="group">
                      <div className="flex justify-between items-center mb-1">
                        <span className="text-sm font-semibold text-slate-700">
                          {new Date(new Date().getFullYear(), new Date(`${new Date().getFullYear()}-${d.month}-01`).getMonth()).toLocaleDateString('tr-TR', { month: 'long' })}</span>
                        <span className="text-sm font-bold text-emerald-600 opacity-0 group-hover:opacity-100 transition-opacity">
                          {d.value} kg
                        </span>
                      </div>
                      <div className="h-8 bg-emerald-100 rounded-full overflow-hidden relative">
                        <div
                          className="h-full bg-gradient-to-r from-emerald-400 to-teal-500 rounded-full transition-all duration-1000 ease-out flex items-center justify-end pr-3"
                          style={{
                            width: `${percentage}%`,
                            animation: `growBar 1s ease-out ${i * 0.15}s both`
                          }}
                        >
                          <span className="text-white text-xs font-bold drop-shadow-sm">
                            {d.value} kg
                          </span>
                        </div>
                      </div>
                    </div>
                  );
                })}
              </div>
            ) : (
              <div className="text-center py-12">
                <div className="text-6xl mb-4">📊</div>
                <p className="text-slate-400">Henüz veri yok</p>
                <p className="text-sm text-slate-300 mt-1">Atıklar toplandığında burada görünecek</p>
              </div>
            )}

            <style>{`
              @keyframes growBar {
                from { width: 0%; opacity: 0; }
                to { opacity: 1; }
              }
            `}</style>
          </div>

          {/* fn_get_user_monthly_report - CURSOR & RECORD Fonksiyonu */}
          <div className="bg-white rounded-lg shadow p-6">
            <h2 className="text-lg font-medium text-emerald-800 mb-4 flex items-center gap-2">
              <FiCalendar className="text-blue-500" />
              Aylık Detaylı Raporum
              <span className="text-xs bg-blue-100 text-blue-600 px-2 py-1 rounded-full ml-2">
                CURSOR & RECORD
              </span>
            </h2>
            <p className="text-xs text-slate-400 mb-4">
              📌 SQL: <code className="bg-slate-100 px-1 rounded">fn_get_user_monthly_report()</code>
            </p>

            {reportLoading ? (
              <div className="flex justify-center py-8">
                <span className="loading loading-spinner text-emerald-500"></span>
              </div>
            ) : monthlyReport.length > 0 ? (
              <div className="space-y-3">
                {monthlyReport.map((item, idx) => (
                  <div
                    key={idx}
                    className={`p-4 rounded-xl border ${item.report_type === 'SUMMARY'
                      ? 'bg-gradient-to-r from-emerald-50 to-teal-50 border-emerald-200'
                      : 'bg-slate-50 border-slate-100'
                      }`}
                  >
                    <div className="flex justify-between items-start">
                      <div>
                        <h4 className={`font-bold ${item.report_type === 'SUMMARY' ? 'text-emerald-700' : 'text-slate-700'}`}>
                          {item.type_name}
                        </h4>
                        <p className="text-xs text-slate-500 mt-1">{item.details}</p>
                      </div>
                      <div className="text-right">
                        <div className="text-lg font-bold text-emerald-600">{item.total_score || 0} puan</div>
                        <div className="text-xs text-slate-400">
                          {item.item_count} adet • {parseFloat(item.total_amount || 0).toFixed(1)} kg
                        </div>
                      </div>
                    </div>
                  </div>
                ))}
              </div>
            ) : (
              <div className="text-center py-8">
                <div className="text-4xl mb-2">📋</div>
                <p className="text-slate-400 text-sm">Bu ay topladığınız atık yok</p>
              </div>
            )}
          </div>
        </div>

        {/* v_monthly_recycling_report VIEW - Topluluk Özeti */}
        <div className="bg-white rounded-lg shadow p-6">
          <h2 className="text-lg font-medium text-emerald-800 mb-4 flex items-center gap-2">
            <FiDatabase className="text-purple-500" />
            Topluluk Geri Dönüşüm Özeti
            <span className="text-xs bg-purple-100 text-purple-600 px-2 py-1 rounded-full ml-2">
              VIEW
            </span>
          </h2>
          <p className="text-xs text-slate-400 mb-4">
            📌 SQL: <code className="bg-slate-100 px-1 rounded">v_monthly_recycling_report</code>
          </p>

          {overviewLoading ? (
            <div className="flex justify-center py-8">
              <span className="loading loading-spinner text-purple-500"></span>
            </div>
          ) : (
            <>
              {/* Özet Kartları */}
              {communityOverview.summary && (
                <div className="grid grid-cols-2 sm:grid-cols-4 gap-4 mb-6">
                  <div className="bg-gradient-to-br from-purple-50 to-indigo-50 p-4 rounded-xl border border-purple-100">
                    <div className="text-2xl font-bold text-purple-600">{communityOverview.summary.total_types || 0}</div>
                    <div className="text-xs text-purple-500">Atık Türü</div>
                  </div>
                  <div className="bg-gradient-to-br from-blue-50 to-cyan-50 p-4 rounded-xl border border-blue-100">
                    <div className="text-2xl font-bold text-blue-600">{communityOverview.summary.total_items || 0}</div>
                    <div className="text-xs text-blue-500">Toplam Adet</div>
                  </div>
                  <div className="bg-gradient-to-br from-emerald-50 to-teal-50 p-4 rounded-xl border border-emerald-100">
                    <div className="text-2xl font-bold text-emerald-600">{parseFloat(communityOverview.summary.total_amount || 0).toFixed(1)}</div>
                    <div className="text-xs text-emerald-500">Toplam kg</div>
                  </div>
                  <div className="bg-gradient-to-br from-amber-50 to-yellow-50 p-4 rounded-xl border border-amber-100">
                    <div className="text-2xl font-bold text-amber-600">{communityOverview.summary.total_score || 0}</div>
                    <div className="text-xs text-amber-500">Toplam Puan</div>
                  </div>
                </div>
              )}

              {/* Detay Tablosu */}
              {communityOverview.data.length > 0 ? (
                <div className="overflow-x-auto">
                  <table className="w-full text-sm">
                    <thead>
                      <tr className="bg-slate-50 text-slate-600">
                        <th className="text-left p-3 rounded-l-lg">Ay</th>
                        <th className="text-left p-3">Atık Türü</th>
                        <th className="text-right p-3">Adet</th>
                        <th className="text-right p-3">Miktar</th>
                        <th className="text-right p-3 rounded-r-lg">Puan</th>
                      </tr>
                    </thead>
                    <tbody>
                      {communityOverview.data.slice(0, 10).map((row, idx) => (
                        <tr key={idx} className="border-b border-slate-50 hover:bg-slate-50 transition-colors">
                          <td className="p-3 text-slate-600">{row.month}/{row.year}</td>
                          <td className="p-3 font-medium text-slate-800">{row.type_name}</td>
                          <td className="p-3 text-right text-slate-600">{row.total_items}</td>
                          <td className="p-3 text-right text-slate-600">{parseFloat(row.total_amount).toFixed(1)} {row.official_unit}</td>
                          <td className="p-3 text-right font-bold text-emerald-600">{row.total_score_contribution}</td>
                        </tr>
                      ))}
                    </tbody>
                  </table>
                </div>
              ) : (
                <div className="text-center py-8">
                  <div className="text-4xl mb-2">🌍</div>
                  <p className="text-slate-400 text-sm">Henüz topluluk verisi yok</p>
                </div>
              )}
            </>
          )}
        </div>
      </div>
    </div>
  );
};

export default ViewImpact;


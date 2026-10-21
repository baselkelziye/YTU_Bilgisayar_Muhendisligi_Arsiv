const fetch = require('node-fetch');
const TOKEN = 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOjEzLCJlbWFpbCI6ImFobWV0QHRlc3QuY29tIiwicm9sZSI6InVzZXIiLCJpc1ZlcmlmaWVkIjp0cnVlLCJpYXQiOjE3Njc1MzQxNDksImV4cCI6MTc2ODEzODk0OX0.CcziFFDsoTIZN5OtV9XCWXd2z5NILluF0QAVTnXE7DU';
const BASE_URL = 'http://localhost:5001/api';

async function test() {
  console.log('\n========== API TEST RAPORU ==========\n');
  
  const results = [];
  
  // 1. GET testleri
  const getTests = [
    { name: 'GET /waste/types (Public)', url: '/waste/types', auth: false },
    { name: 'GET /waste (VIEW)', url: '/waste', auth: true },
    { name: 'GET /waste/search?city=Istanbul (FUNCTION)', url: '/waste/search?city=Istanbul', auth: true },
    { name: 'GET /reservations', url: '/reservations', auth: true },
    { name: 'GET /reports/active-users (UNION)', url: '/reports/active-users', auth: true },
    { name: 'GET /reports/inactive-collectors (EXCEPT)', url: '/reports/inactive-collectors', auth: true },
    { name: 'GET /reports/top-contributors (HAVING)', url: '/reports/top-contributors?minWasteCount=1', auth: true },
    { name: 'GET /reports/user/13/score (FUNCTION)', url: '/reports/user/13/score', auth: true },
    { name: 'GET /reports/user/13/monthly (CURSOR)', url: '/reports/user/13/monthly?year=2026&month=1', auth: true },
  ];
  
  for (const t of getTests) {
    try {
      const headers = t.auth ? { 'Authorization': 'Bearer ' + TOKEN } : {};
      const res = await fetch(BASE_URL + t.url, { headers });
      const data = await res.json();
      results.push({ name: t.name, success: data.success, message: data.message });
      console.log((data.success ? '✅' : '❌') + ' ' + t.name);
    } catch (e) {
      results.push({ name: t.name, success: false, message: e.message });
      console.log('❌ ' + t.name + ' - ' + e.message);
    }
  }
  
  // 2. POST /waste testi (INSERT + CHECK)
  console.log('\n--- POST Testleri ---');
  try {
    const wasteRes = await fetch(BASE_URL + '/waste', {
      method: 'POST',
      headers: { 'Authorization': 'Bearer ' + TOKEN, 'Content-Type': 'application/json' },
      body: JSON.stringify({ type_id: 1, amount: 3.5, description: 'Test karton kutu' })
    });
    const wasteData = await wasteRes.json();
    console.log((wasteData.success ? '✅' : '❌') + ' POST /waste (INSERT)');
    
    // 3. CHECK constraint testi
    const checkRes = await fetch(BASE_URL + '/waste', {
      method: 'POST',
      headers: { 'Authorization': 'Bearer ' + TOKEN, 'Content-Type': 'application/json' },
      body: JSON.stringify({ type_id: 1, amount: 0, description: 'Hatali test' })
    });
    const checkData = await checkRes.json();
    console.log((checkData.success === false ? '✅' : '❌') + ' CHECK Constraint (amount=0 reddedilmeli): ' + (checkData.success ? 'HATA' : 'Dogru'));
    
  } catch (e) {
    console.log('❌ POST testi hatasi: ' + e.message);
  }
  
  // Özet
  console.log('\n========== ÖZET ==========');
  const passed = results.filter(r => r.success).length;
  console.log('Toplam: ' + results.length + ' test');
  console.log('Basarili: ' + passed);
  console.log('Basarisiz: ' + (results.length - passed));
  console.log('==========================\n');
}

test().catch(console.error);

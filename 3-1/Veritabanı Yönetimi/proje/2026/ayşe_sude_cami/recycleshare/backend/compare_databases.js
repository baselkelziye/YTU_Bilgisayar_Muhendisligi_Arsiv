const { Client } = require('pg');

const localUrl = 'postgresql://' + process.env.USER + '@localhost:5432/recycleshare';
const neonUrl = 'postgresql://neondb_owner:npg_2YGbxCH5MWwR@ep-polished-flower-ag9xm9mb.c-2.eu-central-1.aws.neon.tech/neondb?sslmode=require';

const tables = ['users', 'waste', 'reservations', 'environmental_scores', 'waste_types', 'trigger_logs'];

async function getCounts(url, label) {
    const client = new Client({ connectionString: url });
    const counts = {};

    try {
        await client.connect();
        console.log(`Connected to ${label}`);

        for (const table of tables) {
            try {
                const res = await client.query(`SELECT COUNT(*) FROM ${table}`);
                counts[table] = parseInt(res.rows[0].count);
            } catch (e) {
                console.error(`Error querying ${table} in ${label}:`, e.message);
                counts[table] = 'Error';
            }
        }
    } catch (err) {
        console.error(`Failed to connect to ${label}:`, err.message);
        return null;
    } finally {
        await client.end();
    }
    return counts;
}

async function compare() {
    console.log('Comparing Local vs Neon Databases...\n');

    const localCounts = await getCounts(localUrl, 'LOCAL');
    const neonCounts = await getCounts(neonUrl, 'NEON');

    console.log('\n--- COMPARISON RESULTS ---');
    console.log('Table'.padEnd(25) + 'Local'.padEnd(10) + 'Neon'.padEnd(10) + 'Diff');
    console.log('-'.repeat(55));

    if (localCounts && neonCounts) {
        for (const table of tables) {
            const local = localCounts[table];
            const neon = neonCounts[table];
            const diff = (typeof local === 'number' && typeof neon === 'number') ? (local - neon) : '?';

            console.log(
                table.padEnd(25) +
                String(local).padEnd(10) +
                String(neon).padEnd(10) +
                (diff === 0 ? 'MATCH' : (diff > 0 ? `+${diff} (Local)` : `${diff} (Neon)`))
            );
        }
    } else {
        console.log('Could not fetch data from one or both databases.');
    }
}

compare();

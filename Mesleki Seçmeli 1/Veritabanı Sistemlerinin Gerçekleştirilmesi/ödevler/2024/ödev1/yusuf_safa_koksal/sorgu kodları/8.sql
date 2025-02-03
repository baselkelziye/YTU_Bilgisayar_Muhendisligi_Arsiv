EXPLAIN SELECT b, count(a) 
FROM T 
WHERE a > 'c' 
GROUP BY b;


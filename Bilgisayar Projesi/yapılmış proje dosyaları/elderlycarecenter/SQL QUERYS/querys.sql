-- Get Rooms
SELECT * FROM room ORDER BY id

-- Get Elders // View kullanıldı
SELECT * FROM elder_view ORDER BY id

-- Get Visitors
SELECT * FROM visitor ORDER BY id

-- Get Visits //VİEW KULLANILDI
SELECT * FROM visit_view ORDER BY visit_id

-- Search Visits
SELECT * FROM visit_view WHERE elder_first_name LIKE '%?%' OR elder_last_name LIKE '%?%' OR visitor1_first_name LIKE '%?%' OR visitor1_last_name LIKE '%?%' OR visitor2_first_name LIKE '%?%' OR visitor2_last_name LIKE '%?%' ORDER BY visit_id

-- Insert Visit
INSERT INTO visit(first_visitor_id, second_visitor_id, elder_id) VALUES (?, ?, ?)

-- Insert Room //SEQUENCE KULLANILDI - room_number
INSERT INTO room(room_number) VALUES(nextval('room_number'))

-- Delete Room 
DELETE FROM room WHERE id=?

-- Insert Visitor
INSERT INTO visitor(first_name, last_name) VALUES (?, ?)

-- Update Visitor
UPDATE visitor SET first_name=?, last_name=? WHERE id=?

-- Delete Visitor
DELETE FROM visitor WHERE id=?

-- Insert Elder
INSERT INTO elder(first_name, last_name, date_of_birth, gender) VALUES (?, ?, ?, ?)

-- Update Elder
UPDATE elder SET first_name=?, last_name=?, date_of_birth=?, gender=? WHERE id=?

-- Delete Elder
DELETE FROM elder WHERE id=?

-- Filter Visits by COUNT // AGGREGATE HAVING // UNION
SELECT elder_first_name AS NAME,elder_last_name AS SURNAME,COUNT(elder_id) 
FROM visit_view GROUP BY elder_first_name,elder_last_name HAVING COUNT(elder_id)>=? 
UNION 
SELECT visitor1_first_name AS NAME,visitor1_last_name AS SURNAME,COUNT(visitor1_id) 
FROM visit_view GROUP BY visitor1_first_name,visitor1_last_name HAVING COUNT(visitor1_id)>=?
UNION 
SELECT visitor2_first_name as NAME,visitor2_last_name as SURNAME,COUNT(visitor2_id) 
FROM visit_view GROUP BY visitor2_first_name,visitor2_last_name HAVING COUNT(visitor2_id)>=?
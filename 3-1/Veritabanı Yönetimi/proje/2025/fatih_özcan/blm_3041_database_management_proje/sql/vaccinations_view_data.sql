INSERT INTO vaccinations (pet_id, vaccine_name, date_given, next_due_date) 
VALUES 
    (13, 'Kuduz Aşısı', CURRENT_DATE, CURRENT_DATE + INTERVAL '1 year'),
    (15, 'Karma Aşı', CURRENT_DATE, CURRENT_DATE + INTERVAL '6 months'),
	(14, 'Parvo', CURRENT_DATE, CURRENT_DATE + INTERVAL '3 months');
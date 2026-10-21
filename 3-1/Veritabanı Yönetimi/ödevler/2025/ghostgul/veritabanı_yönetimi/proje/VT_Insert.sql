INSERT INTO jobfinder.users (username, password, full_name, email, experience_years, education, phone, address)
VALUES
    ('ozturk', '123', 'Kerem Öztürk', 'ciaoemirkerem@gmail.com', 1, 'Computer Engineering', '5342360126', '123 Barajyolu Cd.'),
    ('doe', '456', 'John Doe', 'johnd@gmail.com', 3, 'Software Engineering', '9876543210', '456 Oak St'),
    ('pitt', '789', 'Brad Pitt', 'bradp3@gmail.com', 2, 'Business Administration', '5551112233', '789 Pine St'),
    ('jolie', '000', 'Angelina Jolie', 'angel@gmail.com', 7, 'Electrical Engineering', '9998887766', '101 Maple St'),
    ('portman', '159', 'Natalie Portman', 'portman@gmail.com', 4, 'Information Technology', '1110009999', '202 Cedar St'),
    ('sakai', '1244', 'Jin Sakai', 'sakai99@gmail.com', 6, 'Mechanical Engineering', '4443332222', '303 Birch St'),
    ('jordan', '852', 'Michael Jordan', 'mj@gmail.com', 10, 'Software Engineering', '7776665555', '404 Oak St'),
    ('james', '963', 'Lebron James', 'lebron66@gmail.com', 8, 'Computer Science', '2223334444', '505 Pine St'),
    ('turan', 'asd', 'Arda Turan', 'ardat@gmail.com', 12, 'Water Seller', '6667778888', '606 Maple St'),
    ('tunali', 'qwe', 'Esra Tunali', 'esrat@gmail.com', 3, 'Mechanical Engineering', '3334445555', '707 Birch St');

INSERT INTO jobfinder.jobs (company_name, position, description, opening_date)
VALUES
    ('Google', 'Software Engineer', 'Developing software solutions', '2023-01-16'),
    ('Migros', 'Data Scientist', 'Analyzing complex data sets', '2023-02-08'),
    ('UTS', 'Web Developer', 'Creating dynamic web applications', '2023-03-01'),
    ('Getir', 'Senior Data Analyst', 'Analyzing and visualizing data for businesses', '2023-04-30'),
    ('Sony', 'UX/UI Designer', 'Designing user-friendly interfaces', '2023-05-12'),
    ('Creative Minds', 'AI Learning Engineer', 'Implementing algorithms for AI to improve its predictive analysis', '2023-06-01'),
    ('Unity', 'Network Engineer', 'Designing and implementing network solutions for clients', '2023-07-22'),
    ('Data Insights', 'Business IT Analyst', 'Extracting and analyzing data to provide actions', '2023-08-01'),
    ('Erikli Code', 'Full Stack Developer', 'Developing web applications with more recent technologies', '2023-09-01'),
    ('Innovative Systems', 'Team Leader', 'Leading the team of engineers to create innovative UI', '2023-10-01');

INSERT INTO jobfinder.applications (user_id, job_id, application_date)
VALUES
    (1, 1, '2023-01-05'),
    (2, 1, '2023-01-06'),
    (3, 2, '2023-02-08'),
    (4, 2, '2023-02-10'),
    (5, 3, '2023-03-15'),
    (6, 3, '2023-03-18'),
    (7, 4, '2023-04-22'),
    (8, 4, '2023-04-25'),
    (9, 5, '2023-05-30'),
    (10, 5, '2023-06-01');

INSERT INTO jobfinder.experiences (user_id, company_name, position, start_date, end_date, description)
VALUES
    (1, 'YTU', 'Assistant', '2021-01-01', '2022-01-01', 'Assisted the students well'),
    (2, 'Maxima', 'Data Analyst', '2021-02-01', '2023-02-28', 'Created complex data sets'),
    (3, 'Looksmaxx', 'UX/UI Intern', '2019-06-01', '2020-01-01', 'Assisted the team in designing user interfaces'),
    (4, 'Code Wizards', 'Full Stack Developer', '2022-03-01', NULL, 'Developed smooth web applications'),
    (5, 'Data Insights', 'Business Analyst', '2021-08-01', '2022-08-01', 'Extracted and analyzed data for businesses'),
    (6, 'Entertain Games', 'Network Engineer', '2020-12-01', '2021-12-01', 'Designed and implemented network solutions for multiplayer games'),
    (7, 'Creative Minds', 'UX/UI Designer', '2018-10-01', '2019-05-01', 'Designed visually appealing interfaces'),
    (8, 'Innovative Systems', 'DevOps Engineer', '2022-04-01', NULL, 'Automated and optimized the software development lifecycle'),
    (9, 'Trash Collection', 'Leader Collector', '2019-03-01', '2021-03-01', 'Kept the streets very clean'),
    (10, 'Seniukai', 'Data Scientist', '2022-06-01', NULL, 'Analyzed and interpreted data sets');
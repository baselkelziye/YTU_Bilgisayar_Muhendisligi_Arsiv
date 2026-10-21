CREATE TABLE jobfinder.users (
    user_id SERIAL PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    password VARCHAR(50) NOT NULL,
    full_name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL,
    experience_years INTEGER,
    education VARCHAR(100),
	phone VARCHAR(15) NOT NULL,
	address VARCHAR(100) NOT NULL,
	status BOOLEAN DEFAULT TRUE 
);

CREATE TABLE jobfinder.jobs (
    job_id SERIAL PRIMARY KEY,
    company_name VARCHAR(100) NOT NULL,
    position VARCHAR(100) NOT NULL,
    description TEXT NOT NULL,
    opening_date DATE NOT NULL,
    application_count INTEGER CHECK (application_count >= 0) DEFAULT 0 NOT NULL
);

CREATE TABLE jobfinder.applications (
    application_id SERIAL PRIMARY KEY,
    user_id INTEGER REFERENCES jobfinder.users(user_id) ON DELETE RESTRICT,
    job_id INTEGER REFERENCES jobfinder.jobs(job_id) ON DELETE CASCADE,
    application_date DATE DEFAULT CURRENT_DATE
);

CREATE TABLE jobfinder.experiences (
    experience_id SERIAL PRIMARY KEY,
    user_id INTEGER REFERENCES jobfinder.users(user_id) ON DELETE CASCADE,
    company_name VARCHAR(100) NOT NULL,
    position VARCHAR(100) NOT NULL,
    start_date DATE NOT NULL,
    end_date DATE,
    description TEXT
);

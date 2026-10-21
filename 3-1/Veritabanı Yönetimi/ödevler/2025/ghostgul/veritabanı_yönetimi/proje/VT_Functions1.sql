CREATE OR REPLACE FUNCTION jobfinder.search_jobs(searchTerm VARCHAR)
RETURNS TABLE (
    Job_Id integer,
    Company_Name VARCHAR,
    "Position" VARCHAR,
    Description TEXT,
    Opening_Date DATE,
    Application_Count INT
) AS $$
BEGIN
    RETURN QUERY
    SELECT jobs.Job_Id, jobs.Company_Name, jobs.Position, jobs.Description, jobs.Opening_Date, jobs.Application_Count
    FROM jobfinder.jobs
    WHERE jobs.Company_Name LIKE ('%' || searchTerm || '%')
       OR jobs.Position LIKE ('%' || searchTerm || '%')
       OR jobs.Description LIKE ('%' || searchTerm || '%');
END;
$$ LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION jobfinder.get_user_applications(user_id_param INTEGER, OUT application_id INTEGER, OUT job_id INTEGER, OUT application_date DATE, OUT user_id INTEGER)
RETURNS SETOF RECORD AS $$
DECLARE
    user_applications CURSOR FOR
        SELECT ap.application_id, ap.job_id, ap.application_date, ap.user_id
        FROM jobfinder.applications ap
        WHERE ap.user_id = user_id_param;
BEGIN
    OPEN user_applications;
    LOOP
        FETCH user_applications INTO application_id, job_id, application_date,user_id;
        EXIT WHEN NOT FOUND;
        RETURN NEXT;
    END LOOP;
    CLOSE user_applications;
    RETURN;
END;
$$ LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION jobfinder.contact_companies(userid int)
RETURNS TABLE (
    Company_Name VARCHAR
) AS $$
BEGIN
    RETURN QUERY
SELECT
    j.company_name
FROM
    jobfinder.applications app inner join jobfinder.jobs j on j.job_id = app.job_id
	WHERE app.user_id = userid
UNION
SELECT
    e.company_name
FROM
    jobfinder.experiences e
	WHERE e.user_id = userid;
END;
$$ LANGUAGE plpgsql;
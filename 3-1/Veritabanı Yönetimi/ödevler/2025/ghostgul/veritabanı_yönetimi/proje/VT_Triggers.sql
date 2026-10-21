CREATE OR REPLACE FUNCTION jobfinder.update_application_count()
RETURNS TRIGGER AS $$
BEGIN
    UPDATE jobfinder.jobs
    SET application_count = application_count + 1
    WHERE job_id = NEW.job_id;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER update_application_count_trigger
AFTER INSERT ON jobfinder.applications
FOR EACH ROW
EXECUTE FUNCTION jobfinder.update_application_count();

CREATE OR REPLACE FUNCTION jobfinder.check_application_count()
RETURNS TRIGGER AS $$
BEGIN
    IF (SELECT COUNT(*) FROM jobfinder.applications WHERE job_id = NEW.job_id AND user_id = NEW.user_id) >= 1 THEN
        RAISE EXCEPTION 'Bir kullanıcı aynı ilana birden fazla başvuruda bulunamaz.';
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER application_count_trigger
BEFORE INSERT ON jobfinder.applications
FOR EACH ROW
EXECUTE FUNCTION jobfinder.check_application_count();


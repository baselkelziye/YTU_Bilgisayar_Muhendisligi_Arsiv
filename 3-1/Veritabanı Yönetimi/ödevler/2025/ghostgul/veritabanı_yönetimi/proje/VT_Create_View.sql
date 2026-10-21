CREATE OR REPLACE VIEW jobfinder.active_users
 AS
 SELECT user_id,
    username,
    password,
    full_name,
    email,
    experience_years,
    education,
    phone,
    address,
    status
   FROM jobfinder.users
  WHERE status = true;

CREATE OR REPLACE FUNCTION updateUnitBalance()
  RETURNS TRIGGER AS $donation_accept_unit$
BEGIN
  UPDATE donation_accept_unit d
  SET balance = (select sum(amount) from accounting a group by a.unit_name
  having d.unit_name = a.unit_name);

  UPDATE donation_accept_unit
  SET balance = 0 WHERE balance is null;

  RETURN new;
END;
$donation_accept_unit$ LANGUAGE plpgsql;

CREATE TRIGGER updateBalance
AFTER INSERT ON accounting
FOR EACH ROW EXECUTE PROCEDURE updateUnitBalance();

--CREATE OR REPLACE FUNCTION insertAccounting()
--  RETURNS TRIGGER AS $spending_request$
--BEGIN
--  if new.state = 2 then
--    INSERT INTO accounting (unit_name, user_name, date_time, amount)
--    VALUES(new.dau, new.updater, new.updated_date_time, -new.amount);
--  end if;
--  RETURN new;
--END;
--$spending_request$ LANGUAGE plpgsql;

--CREATE TRIGGER insertAccounting
--AFTER UPDATE ON spending_request
--FOR EACH ROW EXECUTE PROCEDURE insertAccounting();

CREATE OR REPLACE FUNCTION countReferenceForCategory()
  RETURNS TRIGGER AS $announcement$
BEGIN
  update announcement_category ac
  set references_count = (
    select count(a.announcement_category) from announcement a group by a.announcement_category
    having ac.id = a.announcement_category);

  update announcement_category set references_count = 0 WHERE references_count is null;

  return new;

END;
$announcement$ LANGUAGE plpgsql;

CREATE TRIGGER isDeleteable
AFTER INSERT OR UPDATE OR DELETE ON announcement
FOR EACH ROW EXECUTE PROCEDURE countReferenceForCategory();

-- Function 1: Calculate pet age in human years
CREATE OR REPLACE FUNCTION calculate_human_age(
    pet_age INTEGER,
    species VARCHAR
) RETURNS INTEGER AS $$
BEGIN
    IF species = 'Dog' THEN
        RETURN CASE
            WHEN pet_age <= 2 THEN pet_age * 11
            ELSE 22 + ((pet_age-2) * 5)
        END;
    ELSIF species = 'Cat' THEN
        RETURN CASE
            WHEN pet_age <= 2 THEN pet_age * 12
            ELSE 24 + ((pet_age-2) * 4)
        END;
    ELSE
        RETURN pet_age * 7;
    END IF;
END;
$$ LANGUAGE plpgsql;

-- Function 2: Get vaccination history using cursor
CREATE OR REPLACE FUNCTION get_pet_vaccination_history(
    p_pet_id INTEGER
) RETURNS TABLE (
    vaccine_name VARCHAR,
    date_given DATE,
    next_due_date DATE,
    clinic_name VARCHAR
) AS $$
DECLARE
    vac_cursor CURSOR FOR 
        SELECT v.vaccine_name, v.date_given, v.next_due_date, vc.name
        FROM vaccinations v
        JOIN vet_clinics vc ON v.vet_clinic_id = vc.clinic_id
        WHERE v.pet_id = p_pet_id
        ORDER BY v.date_given DESC;
    vac_record RECORD;
BEGIN
    FOR vac_record IN vac_cursor LOOP
        vaccine_name := vac_record.vaccine_name;
        date_given := vac_record.date_given;
        next_due_date := vac_record.next_due_date;
        clinic_name := vac_record.name;
        RETURN NEXT;
    END LOOP;
END;
$$ LANGUAGE plpgsql;

-- Function 3: Calculate total spending for a user
CREATE OR REPLACE FUNCTION calculate_user_spending(
    p_user_id INTEGER,
    p_start_date DATE,
    p_end_date DATE
) RETURNS DECIMAL AS $$
DECLARE
    total_spent DECIMAL;
BEGIN
    SELECT COALESCE(SUM(total_amount), 0)
    INTO total_spent
    FROM orders
    WHERE user_id = p_user_id
    AND order_date BETWEEN p_start_date AND p_end_date;
    
    RETURN total_spent;
END;
$$ LANGUAGE plpgsql;

-- Trigger 1: Update product stock after order
CREATE OR REPLACE FUNCTION update_product_stock()
RETURNS TRIGGER AS $$
BEGIN
    UPDATE products
    SET stock_quantity = stock_quantity - NEW.quantity
    WHERE product_id = NEW.product_id;
    
    -- Check if stock is low
    IF (SELECT stock_quantity FROM products WHERE product_id = NEW.product_id) < 10 THEN
        RAISE NOTICE 'Low stock alert for product %', NEW.product_id;
    END IF;
    
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER after_order_detail_insert
AFTER INSERT ON order_details
FOR EACH ROW
EXECUTE FUNCTION update_product_stock();

-- Trigger 2: Log vaccination updates
CREATE OR REPLACE FUNCTION log_vaccination_changes()
RETURNS TRIGGER AS $$
BEGIN
    IF TG_OP = 'INSERT' THEN
        RAISE NOTICE 'New vaccination record added for pet %', NEW.pet_id;
    ELSIF TG_OP = 'UPDATE' THEN
        RAISE NOTICE 'Vaccination record updated for pet %', NEW.pet_id;
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER vaccination_audit
AFTER INSERT OR UPDATE ON vaccinations
FOR EACH ROW
EXECUTE FUNCTION log_vaccination_changes();



--EK
CREATE OR REPLACE FUNCTION get_new_products()
RETURNS REFCURSOR AS $$
DECLARE
    cur_products REFCURSOR;
BEGIN
    OPEN cur_products FOR
    SELECT * FROM products
    WHERE created_at > NOW() - INTERVAL '30 days';
    RETURN cur_products;
END;
$$ LANGUAGE plpgsql;
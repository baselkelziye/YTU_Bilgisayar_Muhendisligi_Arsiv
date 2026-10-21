CREATE OR REPLACE FUNCTION get_product_descriptions_with_cursor()
RETURNS TABLE(product_id INT, name TEXT, description TEXT) AS $$
DECLARE
    prod_cursor CURSOR FOR SELECT p.product_id, p.name::TEXT, p.description FROM products p;
BEGIN
    OPEN prod_cursor;
    LOOP
        FETCH prod_cursor INTO product_id, name, description;
        EXIT WHEN NOT FOUND;
        RETURN NEXT; -- Otomatik olarak RETURN TABLE sütunlarını döner
    END LOOP;
    CLOSE prod_cursor;
END;
$$ LANGUAGE plpgsql;

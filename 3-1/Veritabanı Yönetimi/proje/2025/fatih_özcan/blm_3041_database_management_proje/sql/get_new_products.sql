CREATE OR REPLACE FUNCTION get_new_products(days_interval INTEGER)
RETURNS TABLE (
    product_id INT,
    name VARCHAR,
    category VARCHAR,
    price DECIMAL,
    stock_quantity INT,
    description TEXT,
    created_at TIMESTAMP
) AS $$
BEGIN
    RETURN QUERY
    SELECT 
        products.product_id, 
        products.name, 
        products.category, 
        products.price, 
        products.stock_quantity, 
        products.description, 
        products.created_at
    FROM products
    WHERE products.created_at >= NOW() - (days_interval || ' days')::INTERVAL
    ORDER BY products.created_at DESC;
END;
$$ LANGUAGE plpgsql;
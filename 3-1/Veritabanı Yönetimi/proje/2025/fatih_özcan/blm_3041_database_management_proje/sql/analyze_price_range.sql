CREATE OR REPLACE FUNCTION analyze_price_range(
    min_price NUMERIC,
    max_price NUMERIC
) 
RETURNS TABLE (
    category_name VARCHAR,
    product_count INTEGER,
    avg_price NUMERIC(10,2),
    total_stock INTEGER,
    sample_products TEXT
) AS $$
DECLARE
    -- Record tanımı - her bir kategori için
    category_rec RECORD;
    -- Cursor tanımı - her kategorideki ürünler için
    product_cur CURSOR(cat VARCHAR) FOR 
        SELECT name, price, stock_quantity 
        FROM products 
        WHERE category = cat 
        AND price BETWEEN min_price AND max_price
        ORDER BY price DESC;
    
    -- Geçici değişkenler
    product_names TEXT := '';
    product_count INTEGER := 0;
    total_price NUMERIC := 0;
    stock_sum INTEGER := 0;
BEGIN
    -- Her kategori için döngü
    FOR category_rec IN (
        SELECT DISTINCT category 
        FROM products 
        WHERE price BETWEEN min_price AND max_price
    ) LOOP
        -- Değişkenleri sıfırla
        product_names := '';
        product_count := 0;
        total_price := 0;
        stock_sum := 0;
        
        -- Cursor ile ürünleri işle
        FOR product IN product_cur(category_rec.category) LOOP
            -- İlk 3 ürünün ismini birleştir
            IF product_count < 3 THEN
                IF product_count > 0 THEN
                    product_names := product_names || ', ';
                END IF;
                product_names := product_names || product.name;
            END IF;
            
            -- İstatistikleri güncelle
            product_count := product_count + 1;
            total_price := total_price + product.price;
            stock_sum := stock_sum + product.stock_quantity;
        END LOOP;
        
        -- Sonuçları döndür
        IF product_count > 0 THEN
            category_name := category_rec.category;
            avg_price := ROUND(total_price / product_count, 2);
            total_stock := stock_sum;
            sample_products := product_names;
            RETURN NEXT;
        END IF;
    END LOOP;
END;
$$ LANGUAGE plpgsql;

-- Test edelim
-- SELECT * FROM analyze_price_range(10, 50);
CREATE TABLE customer (
    customer_id SERIAL PRIMARY KEY,
    email VARCHAR(100) UNIQUE NOT NULL,
    password_customer TEXT NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    phone_number VARCHAR(20),
    
    gender VARCHAR(10) CHECK (gender IN ('female', 'male', 'other')),
    age INT CHECK (age > 0),

    profession VARCHAR(100),
    
    income_level VARCHAR(20) CHECK (income_level IN ('low', 'medium', 'high')),
    
    city VARCHAR(100),
    
    
    first_visit_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE dealer (
    id SERIAL PRIMARY KEY,
    email VARCHAR(100) UNIQUE NOT NULL,
    password TEXT NOT NULL
);

CREATE TABLE warehouse (
    id SERIAL PRIMARY KEY,
    email VARCHAR(100) UNIQUE NOT NULL,
    password TEXT NOT NULL
);


CREATE TABLE vehicle (
    vehicle_id SERIAL PRIMARY KEY,
    brand VARCHAR(50) NOT NULL,
    model VARCHAR(50) NOT NULL,
    year INT CHECK (year >= 1900 AND year <= EXTRACT(YEAR FROM CURRENT_DATE) + 1),
    package VARCHAR(50),
    price NUMERIC(12, 2) CHECK (price >= 0)
);

CREATE TABLE stock (
    stock_id SERIAL PRIMARY KEY,
    vehicle_id INT NOT NULL REFERENCES vehicle(vehicle_id),
    location_type VARCHAR(20) NOT NULL CHECK (location_type IN ('warehouse', 'dealer')),
    quantity INT NOT NULL CHECK (quantity >= 0),
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE sales (
    sale_id SERIAL PRIMARY KEY,
    vehicle_id INT NOT NULL REFERENCES vehicle(vehicle_id),
    user_id INT NOT NULL REFERENCES customer(customer_id),
    sale_date DATE NOT NULL,
    sale_price NUMERIC(12, 2) NOT NULL CHECK (sale_price >= 0),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE requests (
    request_id SERIAL PRIMARY KEY,
    user_id INT NOT NULL REFERENCES customer(customer_id),
    request_type VARCHAR(20) NOT NULL CHECK (request_type IN ('test_drive', 'price_offer', 'order')),
    vehicle_id INT REFERENCES vehicle(vehicle_id),
    request_date DATE NOT NULL,
    status VARCHAR(20) DEFAULT 'pending' CHECK (status IN ('pending', 'accepted', 'rejected'))
);

CREATE OR REPLACE FUNCTION register_customer(
    p_email VARCHAR(100),
    p_password VARCHAR(255),
    p_first_name VARCHAR(50),
    p_last_name VARCHAR(50),
    p_phone VARCHAR(20),
    p_gender VARCHAR(10),
    p_age INT,
    p_profession VARCHAR(100),
    p_income_level VARCHAR(20),
    p_city VARCHAR(100)
)
RETURNS INTEGER AS $$
DECLARE
    new_customer_id INTEGER;
BEGIN
    INSERT INTO customer(
        email, password_customer, first_name, last_name,
        phone_number, gender, age, profession,
        income_level, city
    )
    VALUES (
        p_email, p_password, p_first_name, p_last_name,
        p_phone, p_gender, p_age, p_profession,
        p_income_level, p_city
    )
    RETURNING customer_id INTO new_customer_id;

    RETURN new_customer_id;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION login_customer(
    p_email VARCHAR(100),
    p_password VARCHAR(255)
)
RETURNS BOOLEAN AS $$
DECLARE
    found_password TEXT;
BEGIN
    SELECT password_customer INTO found_password
    FROM customer
    WHERE email = p_email;

    IF found_password IS NOT NULL AND found_password = p_password THEN
        RETURN TRUE;
    ELSE
        RETURN FALSE;
    END IF;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION login_dealer(
    p_email VARCHAR(100),
    p_password VARCHAR(255)
)
RETURNS BOOLEAN AS $$
DECLARE
    found_password TEXT;
BEGIN
    SELECT password INTO found_password
    FROM dealer
    WHERE email = p_email;

    IF found_password IS NOT NULL AND found_password = p_password THEN
        RETURN TRUE;
    ELSE
        RETURN FALSE;
    END IF;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION login_warehouse(
    p_email VARCHAR(100),
    p_password VARCHAR(255)
)
RETURNS BOOLEAN AS $$
DECLARE
    found_password TEXT;
BEGIN
    SELECT password INTO found_password
    FROM warehouse
    WHERE email = p_email;

    IF found_password IS NOT NULL AND found_password = p_password THEN
        RETURN TRUE;
    ELSE
        RETURN FALSE;
    END IF;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION add_vehicle(
    p_brand VARCHAR(50),
    p_model VARCHAR(50),
    p_year INT,
    p_package VARCHAR(50),
    p_price NUMERIC(12, 2),
	p_quantity INT
)
RETURNS BOOLEAN AS $$
DECLARE
    new_vehicle_id INTEGER;
	existing_vehicle_id INTEGER;
BEGIN
	SELECT vehicle_id INTO existing_vehicle_id
    FROM vehicle
    WHERE brand = p_brand
      AND model = p_model
      AND year = p_year
      AND package = p_package;

    IF existing_vehicle_id IS NOT NULL THEN
        RETURN FALSE;
    END IF;

    INSERT INTO vehicle(
        brand, model, year, package, price
    )
    VALUES (
        p_brand, p_model, p_year, p_package, p_price
    )
    RETURNING vehicle_id INTO new_vehicle_id;
	
	IF new_vehicle_id != 0 THEN
		INSERT INTO stock(
			vehicle_id, location_type, quantity
		)
		VALUES (
			new_vehicle_id, 'warehouse', p_quantity
		);
        RETURN TRUE;
    ELSE
        RETURN FALSE;
    END IF;
END;
$$ LANGUAGE plpgsql;




CREATE TABLE price_offers (
    offer_id SERIAL PRIMARY KEY,
    request_id INT NOT NULL REFERENCES requests(request_id),
    user_id INT NOT NULL REFERENCES customer(customer_id),
    vehicle_id INT NOT NULL REFERENCES vehicle(vehicle_id),
    offer_date DATE NOT NULL DEFAULT CURRENT_DATE,
    offered_price NUMERIC(12, 2) NOT NULL
);

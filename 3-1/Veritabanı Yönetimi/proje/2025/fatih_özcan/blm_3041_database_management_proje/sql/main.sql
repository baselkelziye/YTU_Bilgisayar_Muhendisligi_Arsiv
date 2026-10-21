-- Sequences
CREATE SEQUENCE pet_id_seq START 1;
CREATE SEQUENCE appointment_id_seq START 1;
CREATE SEQUENCE order_id_seq START 1;

-- Users table
CREATE TABLE users (
    user_id SERIAL PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    password_hash VARCHAR(100) NOT NULL,
    phone VARCHAR(15),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Pets table
CREATE TABLE pets (
    pet_id INTEGER PRIMARY KEY DEFAULT nextval('pet_id_seq'),
    user_id INTEGER REFERENCES users(user_id) ON DELETE CASCADE,
    name VARCHAR(50) NOT NULL,
    species VARCHAR(30) NOT NULL,
    breed VARCHAR(50),
    age INTEGER CHECK (age >= 0 AND age <= 30),
    birth_date DATE,
    weight DECIMAL(5,2) CHECK (weight > 0),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Veterinary clinics table
CREATE TABLE vet_clinics (
    clinic_id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    address TEXT NOT NULL,
    phone VARCHAR(15) NOT NULL,
    email VARCHAR(100),
    rating DECIMAL(2,1) CHECK (rating >= 0 AND rating <= 5)
);

-- Appointments table
CREATE TABLE appointments (
    appointment_id INTEGER PRIMARY KEY DEFAULT nextval('appointment_id_seq'),
    pet_id INTEGER REFERENCES pets(pet_id) ON DELETE CASCADE,
    clinic_id INTEGER REFERENCES vet_clinics(clinic_id),
    appointment_date TIMESTAMP NOT NULL,
    reason TEXT,
    status VARCHAR(20) DEFAULT 'Scheduled',
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Products table
CREATE TABLE products (
    product_id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    category VARCHAR(50) NOT NULL,
    price DECIMAL(10,2) CHECK (price > 0),
    stock_quantity INTEGER CHECK (stock_quantity >= 0),
    description TEXT
);

-- Orders table
CREATE TABLE orders (
    order_id INTEGER PRIMARY KEY DEFAULT nextval('order_id_seq'),
    user_id INTEGER REFERENCES users(user_id),
    total_amount DECIMAL(10,2),
    order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    status VARCHAR(20) DEFAULT 'Pending'
);

-- Order details table
CREATE TABLE order_details (
    order_id INTEGER REFERENCES orders(order_id),
    product_id INTEGER REFERENCES products(product_id),
    quantity INTEGER CHECK (quantity > 0),
    unit_price DECIMAL(10,2),
    PRIMARY KEY (order_id, product_id)
);

-- Vaccination records table
CREATE TABLE vaccinations (
    vaccination_id SERIAL PRIMARY KEY,
    pet_id INTEGER REFERENCES pets(pet_id) ON DELETE CASCADE,
    vaccine_name VARCHAR(100) NOT NULL,
    date_given DATE NOT NULL,
    next_due_date DATE,
    vet_clinic_id INTEGER REFERENCES vet_clinics(clinic_id)
);

-- Create a view for upcoming vaccinations
CREATE VIEW upcoming_vaccinations AS
SELECT 
    p.name AS pet_name,
    p.species,
    v.vaccine_name,
    v.next_due_date,
    u.username AS owner_name,
    u.email AS owner_email
FROM vaccinations v
JOIN pets p ON v.pet_id = p.pet_id
JOIN users u ON p.user_id = u.user_id
WHERE v.next_due_date > CURRENT_DATE
ORDER BY v.next_due_date;
--User Tablosu

CREATE TABLE users (
	user_id integer primary key not null default nextval('increase_id'),
	user_name varchar(50) not null,
	user_surname varchar(50) not null,
	user_mail text not null,
	user_password text not null,
	is_active smallint default 1,
	is_admin smallint default 0,
	user_name_surname varchar(100)
);

ALTER TABLE users ADD COLUMN user_name_surname varchar(100);

CREATE TRIGGER concatName
AFTER INSERT
ON users
FOR EACH ROW EXECUTE PROCEDURE concatanateNames();

CREATE OR REPLACE FUNCTION concatanateNames()
RETURNS TRIGGER AS $$
BEGIN
	
	UPDATE users SET user_name_surname = new.user_name || ' ' || new.user_surname WHERE user_id = new.user_id;
	RETURN new;
END;
$$LANGUAGE 'plpgsql';

SELECT * FROM users;
SELECT * FROM addresses;

--Adres Tablosu

CREATE TABLE addresses (
	user_id integer primary key not null,
	consumer_or_producer smallint not null default 1,
	address text,
	phone_number varchar(15)
);


ALTER TABLE addresses ADD CONSTRAINT foreign_key_const
foreign key (user_id) references users(user_id);

SELECT addresses.* FROM addresses;

--Randevu Tablosu
CREATE SEQUENCE increase_id start 101;

CREATE TABLE oil_appointment(
	appointment_id integer primary key not null default nextval('increase_id'),
	user_id integer not null,
	olive_order_id integer not null,
	appointment_date varchar(20) not null,
	status smallint default 1 --1: işleme alındı, 2: işleniyor. 3: tamamlandı, 4:iptal edildi
)

ALTER TABLE oil_appointment ADD CONSTRAINT fg_key
foreign key(user_id) references users(user_id);

ALTER TABLE oil_appointment ADD CONSTRAINT fg_key_olive
foreign key(olive_order_id) references olive_orders(olive_id);

--Randevu İçeriği Tablosu

CREATE TABLE olive_orders (
	olive_id integer primary key not null default nextval('increase_id'),
	olive_weight integer not null,
	time_for_weight integer, --Trigger yazılması gerek. bu tabloya her insert edildiğinde bu değer trigger tarafından eklenmeli.
	olive_type smallint default 1, --1: siyah zeytin, 2:yeşil zeytin, 3:karışık zeytin
	processing_fee numeric(10,2),--Fonksiyon yazılacak
	oil_crop numeric(10,2)
);

ALTER TABLE olive_orders ADD CONSTRAINT weight_limit check(olive_weight < 200);
ALTER TABLE olive_orders DROP CONSTRAINT weight_limit;

select * from olive_orders;
select * from oil_appointment;

DELETE FROM oil_appointment;
DELETE FROM olive_orders;

CREATE TRIGGER updateOilWaitTime
AFTER INSERT
ON olive_orders
FOR EACH ROW EXECUTE PROCEDURE update_time();

CREATE OR REPLACE FUNCTION update_time()
RETURNS TRIGGER AS $$
BEGIN
	
	UPDATE olive_orders SET time_for_weight = olive_weight * 2 WHERE olive_id = new.olive_id;
	RETURN new;
END;
$$LANGUAGE 'plpgsql';

CREATE OR REPLACE FUNCTION findPriceOfOilTransformation(taken_id olive_orders.olive_id%TYPE)
RETURNS void AS $$
DECLARE
olive_type smallint;
mul integer;

BEGIN
	SELECT olive_orders.olive_type INTO olive_type FROM olive_orders WHERE olive_id = taken_id;
	IF(olive_type = 1)THEN
		mul = 100;
	ELSIF (olive_type = 2)THEN
		mul = 200;
	ELSE
		mul = 150;
	END IF;
	
	UPDATE olive_orders SET processing_fee = mul * olive_weight WHERE olive_id = taken_id;
END;
$$ LANGUAGE 'plpgsql';

--record cursor 
CREATE OR REPLACE FUNCTION getDisabledSlots()
RETURNS timestamp[] AS $$
DECLARE
disabledDate timestamp[];
appointment_cursor CURSOR FOR SELECT appointment_date FROM oil_appointment WHERE appointment_date > CURRENT_TIMESTAMP AND status=1;
i integer;
BEGIN
	i=1;
	FOR record IN appointment_cursor LOOP
		disabledDate[i]=record.appointment_date;
		i=i+1;
	END LOOP;
RETURN disabledDate;
END;
$$ LANGUAGE 'plpgsql';

SELECT getDisabledSlots();

CREATE SEQUENCE increase_product_id start 101;

CREATE TABLE company_products(
	product_id integer primary key not null default nextval('increase_product_id'),
	product_name varchar(50) not null,
	product_stock integer not null,
	product_price_per_kilo numeric(10,2),
	product_status smallint default 1 --1: aktif, 2: stok bitti, 3: pasif
);

SELECT * FROM company_products;

CREATE OR REPLACE FUNCTION checkIfStockEnough(pro_id company_products.product_id%TYPE, requested_stock integer)
RETURNS smallint AS $$
DECLARE
isEnough integer;
stock company_products.product_stock%TYPE;
BEGIN
	SELECT product_stock INTO stock FROM company_products WHERE product_id = pro_id;
	
	IF(requested_stock > stock)THEN
		isEnough = stock;
	ELSE
		isEnough = -1;	
	END IF;
RETURN isEnough;
END;
$$ LANGUAGE 'plpgsql';

--User Orders
CREATE SEQUENCE increase_user_orders_id start 101;

CREATE TABLE user_orders (
	order_id integer primary key not null default nextval('increase_user_orders_id'),
	user_id integer not null,
	product_id integer not null,
	order_price numeric(10, 2) not null,
	product_liter integer not null,
	order_date timestamp not null,
	is_refund smallint default 0
);

SELECT * FROM user_orders;

ALTER TABLE user_orders ADD CONSTRAINT fg_key_orders
foreign key(user_id) references users(user_id);

ALTER TABLE user_orders ADD CONSTRAINT fg_key_product_orders
foreign key(product_id) references company_products(product_id);

--decrease Stock

CREATE TRIGGER updateStock
AFTER INSERT
ON user_orders
FOR EACH ROW EXECUTE PROCEDURE update_current_stock();

CREATE OR REPLACE FUNCTION update_current_stock()
RETURNS TRIGGER AS $$
BEGIN

UPDATE company_products SET product_stock = product_stock - new.product_liter WHERE product_id = new.product_id;
return new;
END;
$$LANGUAGE 'plpgsql';

SELECT * FROM summary;

CREATE TRIGGER insertOliveOrder
AFTER INSERT
ON olive_orders
FOR EACH ROW EXECUTE PROCEDURE result_oil();

CREATE OR REPLACE FUNCTION result_oil()
RETURNS TRIGGER AS $$
BEGIN	
	UPDATE olive_orders SET oil_crop = olive_weight / 3 WHERE olive_id = new.olive_id;
	RETURN new;
END;
$$LANGUAGE 'plpgsql';






















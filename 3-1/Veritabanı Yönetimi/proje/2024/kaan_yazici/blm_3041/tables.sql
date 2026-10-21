-- add owner_id as fkey
create table pet (
	id integer primary key,
	owner_id integer references person(id),
	name varchar(20) not null,
	species varchar(20) not null,
	breed varchar(20),
	age integer check (age between 0 and 30),
	sex char(1)
);

-- dropped phone number
-- her person icin sifre eklencek
create table person (
	id integer primary key,
	fname varchar(20) not null,
	lname varchar(20) not null,
	password varchar(20) not null,
	address varchar(100),
	username varchar(25) not null unique,
); 

-- owner_id might be redundant
create table appointment (
	appointment_id integer primary key,
	owner_id integer not null,
	pet_id integer not null,
	date varchar(10) not null,
	type varchar(25) not null,

	foreign key (owner_id) references person(id),
	foreign key (pet_id) references pet(id)	
);

create table product (
	id integer primary key,
	name varchar(50) not null,
	cost integer not null
);

create table storage (
	product_id integer primary key,
	quantity integer,

	foreign key (product_id) references product(id)
);

create table buy (
	order_id integer primary key,
	person_id integer not null,

	foreign key (person_id) references person(id)
);

-- pkey (order_id, product_name)
create table buy_details (
	order_id integer,
	product_name varchar(50) not null,
	quantity integer not null,

	foreign key (order_id) references buy(order_id)
);
alter table buy_details add primary key (order_id, product_name); 

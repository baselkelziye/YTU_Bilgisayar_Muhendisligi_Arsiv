create table pet (
	id integer primary key,
	name varchar(20) not null,
	species varchar(20) not null,
	breed varchar(20),
	age integer check (age between 0 and 30),
	sex char(1)
);

create table person (
	id integer primary key,
	fname varchar(20) not null,
	lname varchar(20) not null
);

-- TODO primary key sadece pet_id olacak
create table pets (
	owner_id integer,
	pet_id integer,

	primary key (pet_id),
	foreign key (owner_id) references person(id),
	foreign key (pet_id) references pet(id)
);

create table appointment (
	appointment_id integer primary key,
	owner_id integer not null,
	pet_id integer not null,
	date varchar(10) not null,

	foreign key (owner_id) references person(id),
	foreign key (pet_id) references pet(id)	
);

create table product (
	id integer primary key,
	name varchar(20) not null,
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

create table buy_details (
	order_id integer primary key,
	product_name varchar(20) not null,
	quantity integer not null,

	foreign key (order_id) references buy(order_id)
);

-- person id'leri icin sequence
create sequence person_seq
	start with 1
	increment by 1;

-- pet id'leri icin sequence
create sequence pet_seq
	start with 1
	increment by 1;

-- appointment id'leri icin sequence
create sequence appointment_seq
	start with 1
	increment by 1;

-- product id'leri icin sequence
create sequence product_seq
	start with 1
	increment by 1;

-- buy id'leri icin sequence
create sequence buy_seq
	start with 1
	increment by 1;

-- id'si verilen bir urunun eldeki stok miktari ile total fiyatini hesaplayan fonksiyon
create or replace function compute_cost(id_prod product.id%type) returns integer as $$
	declare 
		total integer := 0;
	begin
		select quantity * cost into total
		from product, storage
		where product.id = id_prod and storage.product_id = id_prod;

		return total;
	end; $$
	language plpgsql;

-- her bir person'in appointmentlerini listeleyen view
create or replace view display_appointments as
	select person.fname, person.lname, pet.name, appointment.date 
	from person, appointment, pets, pet
	where person.id = appointment.owner_id and pets.owner_id = person.id and pets.pet_id = pet.id  
	order by person.id;

-- alter table appointments rename to appointment;

-- insert into person values (nextval('person_seq'), 'kaan', 'yazici', '5533647175');
-- insert into pet values (nextval('pet_seq'), 'zeytin', 'dog', 'terrier', 6, 'M');
-- insert into pets values (1, 1);
-- insert into appointment values (nextval('appointment_seq'), 1, 1, '28/12/2024');	

-- en az bir appointmenti olan insanlari, appointment sayisiyla birlikte listeleyen view
create or replace view display_people_with_appointments as
	select person.fname, person.lname, count(*)
	from person, appointment
	where person.id = appointment.owner_id
	group by person.id
	having count(*) > 0;

-- select * from display_people_with_appointments;
-- select * from person;
-- insert into person values (nextval('person_seq'), 'mert', 'yazici', '5521231234');
-- insert into pet values (nextval('pet_seq'), 'animal2', 'cat', null, 4, 'F');

-- randevusu olmayan hayvanlari listeleyen view
create or replace view display_pets_without_appointments as
	select pet.name
	from pet
	except (
		select pet.name
		from pet, appointment
		where pet.id = appointment.pet_id
		order by pet.name); 

select * from display_pets_without_appointments;

--buy_details'e ekleme yaparken urun adinin mevcut olup olmadigini kontrol eden trigger icin fonksiyon
create or replace function check_name_buy_details() returns trigger as $$
	begin
		if not exists (select 1 from product where product.name = NEW.product_name) then
			raise exception 'Product name does not exist.';
		end if;
		return NEW;
	end; $$
	language plpgsql;

-- buy_details'e ekleme yaparken urun adinin mevcut olup olmadigini kontrol eden trigger
create trigger check_name_buy_details_trigger
before insert on buy_details
for each row
execute function check_name_buy_details();

-- insert into product values (nextval('product_seq'), 'Food', 15);
-- insert into buy values (nextval('buy_seq'), 1);
-- insert into buy_details values (1, 'Food', 2);

select * from buy;

-- bir person'in butun siparislerini detaylariyla listeleyen fonksiyon
create or replace function buy_details_of_person(p_id person.id%type) 
returns table(product_name varchar(20), quantity integer) as $$
	begin
		return query
		select buy_details.product_name, buy_details.quantity
		from buy_details, buy
		where buy_details.order_id = buy.order_id and buy.person_id = p_id;
	end; $$
language plpgsql;

-- select * from buy_details_of_person(1);

alter table person drop phone_number;
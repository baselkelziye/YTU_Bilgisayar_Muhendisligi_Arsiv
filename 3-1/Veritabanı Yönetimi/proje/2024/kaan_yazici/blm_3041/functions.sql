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

-- buy_details'e ekleme yaparken urun adinin mevcut olup olmadigini kontrol eden trigger icin fonksiyon
create or replace function check_name_buy_details() returns trigger as $$
	begin
		if not exists (select 1 from product where product.name = NEW.product_name) then
			raise exception 'Product name does not exist.';
		end if;
		raise notice 'Product is legal to buy.'
		return NEW;
	end; $$
	language plpgsql;

-- bir person'in butun siparislerini detaylariyla listeleyen fonksiyon
create type type_table as (p_name varchar(20), quantity integer);
create or replace function buy_details_of_person(p_id person.id%type)
returns type_table as $$
	declare
		retval type_table;
	begin
		select buy_details.product_name, buy_details.quantity into retval
		from buy_details, buy
		where buy.person_id = p_id and buy_details.order_id = buy.order_id;
		return retval;
	end; $$
language plpgsql;

-- function to compute grand total order cost for a person
create or replace function compute_total_cost(p_id person.id%type) returns numeric as $$
declare
    total_cost numeric := 0;
begin
    select sum((SELECT product.cost FROM product WHERE product.name = buy_details.product_name) * buy_details.quantity) into total_cost
    from buy_details
    where buy_details.order_id in (
        select buy.order_id
        from buy
        where buy.person_id = p_id
    );
    return total_cost;
end; $$
language plpgsql;

-- id ve sifre icin trigger icin fonksiyon
create or replace function login(p_username person.username%type, p_pass person.password%type)
returns boolean as $$
	begin
		if p_pass = (select password from person where username = p_username) then
			return true;
		else
			return false;
		end if;
	end; $$
language plpgsql;

-- satin alim yaparken stok kontrolu yapan trigger icin fonksiyon
create or replace function check_and_update_order_quantity()
returns trigger as $$
declare
    record RECORD;
begin
    for record in 
        select bd.product_name, bd.quantity, s.quantity as available_quantity
        from buy_details bd
        join storage s
          on bd.product_name = s.product_id
        where bd.order_id = NEW.order_id
    loop
        if record.quantity > record.available_quantity then
            raise exception 'Insufficient quantity for product: % (Requested: %, Available: %)', 
                            record.product_name, record.quantity, record.available_quantity;
        else
            update storage
            set quantity = quantity - record.quantity
            where product_id = record.product_name;
        end if;
    end loop;
	raise notice 'Products bought.'
    return NEW;
end;
$$ language plpgsql;

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

-- buy_details'e ekleme yaparken urun adinin mevcut olup olmadigini kontrol eden trigger icin fonksiyon
create or replace function check_name_buy_details() returns trigger as $$
	begin
		if not exists (select 1 from product where product.name = NEW.product_name) then
			raise exception 'Product name does not exist.';
		end if;
		raise notice 'Product is legal to buy.'
		return NEW;
	end; $$
	language plpgsql;

-- bir person'in butun siparislerini detaylariyla listeleyen fonksiyon
create type type_table as (p_name varchar(20), quantity integer);
create or replace function buy_details_of_person(p_id person.id%type)
returns type_table as $$
	declare
		retval type_table;
	begin
		select buy_details.product_name, buy_details.quantity into retval
		from buy_details, buy
		where buy.person_id = p_id and buy_details.order_id = buy.order_id;
		return retval;
	end; $$
language plpgsql;

-- function to compute grand total order cost for a person
create or replace function compute_total_cost(p_id person.id%type) returns numeric as $$
declare
    total_cost numeric := 0;
begin
    select sum((SELECT product.cost FROM product WHERE product.name = buy_details.product_name) * buy_details.quantity) into total_cost
    from buy_details
    where buy_details.order_id in (
        select buy.order_id
        from buy
        where buy.person_id = p_id
    );
    return total_cost;
end; $$
language plpgsql;

		

-- id ve sifre icin trigger icin fonksiyon
create or replace function login(p_username person.username%type, p_pass person.password%type)
returns boolean as $$
	begin
		if p_pass = (select password from person where username = p_username) then
			return true;
		else
			return false;
		end if;
	end; $$
language plpgsql;

-- satin alim yaparken stok kontrolu yapan trigger icin fonksiyon
create or replace function check_and_update_order_quantity()
returns trigger as $$
declare
    record RECORD;
begin
    for record in 
        select bd.product_name, bd.quantity, s.quantity as available_quantity
        from buy_details bd
        join storage s
          on bd.product_name = s.product_id
        where bd.order_id = NEW.order_id
    loop
        if record.quantity > record.available_quantity then
            raise exception 'Insufficient quantity for product: % (Requested: %, Available: %)', 
                            record.product_name, record.quantity, record.available_quantity;
        else
            update storage
            set quantity = quantity - record.quantity
            where product_id = record.product_name;
        end if;
    end loop;
	raise notice 'Products bought.'
    return NEW;
end;
$$ language plpgsql;

-- en az bir appointmenti olan insanlari, appointment sayisiyla birlikte listeleyen view
create or replace view display_people_with_appointments as
	select person.fname, person.lname, count(*)
	from person, appointment
	where person.id = appointment.owner_id
	group by person.id
	having count(*) > 0;

-- randevusu olmayan hayvanlari listeleyen view
create or replace view display_pets_without_appointments as
	select pet.name
	from pet
	except (
		select pet.name
		from pet, appointment
		where pet.id = appointment.pet_id
		order by pet.name); 

-- belki appointmenti olan hayvanlar
create or replace view display_pets_with_appointments as
	select pet.name
	from pet, appointment
	where pet.id = appointment.pet_id;

-- stok bilgilerini gösteren view
create or replace view display_stocks as
    select  storage.product_id, product.name, storage.quantity,
    from storage
    join  product on storage.product_id = product.id;

-- evcil hayvan türüne göre sahip sayısı
create or replace  view species_owner_count as
    select pet.species, count(distinct pet.owner_id) as owner_count
    from  pet
    group by  pet.species;

-- stok bilgilerini gösteren view (NEW)
create or replace view display_stocks as
select  storage.product_id, product.name, product.price, storage.quantity
from storage
join product on storage.product_id = product.id;

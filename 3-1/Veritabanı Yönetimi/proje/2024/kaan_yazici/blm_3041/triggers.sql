-- buy_details'e ekleme yaparken urun adinin mevcut olup olmadigini kontrol eden trigger
create trigger check_name_buy_details_trigger
before insert on buy_details
for each row
execute function check_name_buy_details();

-- satin alim yaparken stok kontrolu yapan trigger
create trigger check_and_update_order_quantity_trigger
before insert or update on buy
for each row
execute function check_and_update_order_quantity();

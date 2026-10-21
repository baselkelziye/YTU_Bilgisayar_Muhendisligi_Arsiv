select * from movie where exists (select moviename from liked where username='bilalkah' and liked.moviename=movie.name);

insert into liked(username,moviename)
values('bilalkah','ben');

select count(*) from liked where username='bilalkah';

--update kullanici set name='Bilal' where username='bilalkah';
select*from kullanici;
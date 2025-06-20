- spring.datasource.url=jdbc:postgresql://localhost:5432/listopiaBackend
- spring.datasource.username=postgres
- spring.datasource.password=savt123


Postgres icerisinde port 5432 olmali ve database ismi listopiaBackend olmali

 username default olacak degistirmeyin. 
 
 Postgres kurulurken sifreyi savt123 yapmaniz gerek

- spring.jpa.hibernate.ddl-auto=

Tablo olusturma ayari

- validate: validate the schema, makes no changes to the database.
- create-only: database creation will be generated.
- drop: database dropping will be generated.
- update: update the schema.
- create: creates the schema, destroying previous data.
- create-drop: drop the schema when the SessionFactory is closed explicitly, typically when the application is stopped.
- none: does nothing with the schema, makes no changes to the database

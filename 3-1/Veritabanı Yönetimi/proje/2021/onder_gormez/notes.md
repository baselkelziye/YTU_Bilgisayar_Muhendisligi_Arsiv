```SQL

```

```sh
# User for switch to psql command prompt
sudo -u postgres psql
```

```sh
# Creating a New Role
sudo -u postgres createuser  --no-createdb  --no-createrole --no-superuser --interactive
# Enter name of role to add: divingschooldb

# Creating a New Database
sudo -u postgres createdb divingschooldb

# Add Linux user account
sudo useradd --no-create-home divingschooldb
sudo passwd divingschooldb
# password: simple

divingschooldb@raspberrypi:~ $ psql
# divingschooldb=> ALTER USER divingschooldb PASSWORD 'SimplePassword';
```
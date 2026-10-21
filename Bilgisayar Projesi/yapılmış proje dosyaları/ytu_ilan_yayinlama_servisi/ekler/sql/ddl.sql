CREATE TABLE user_type(
  type_no smallint PRIMARY KEY,
  type_name varchar(20) UNIQUE,
  main_page varchar(50),
  unauthorized_page char(50)
);

CREATE TABLE membership_status (
  id int primary key,
  status char(70) NOT NULL
);

CREATE TABLE users (
  user_name  varchar(20) PRIMARY KEY,
  passwordFor varchar(16) NOT NULL,
  user_type_no smallint REFERENCES user_type(type_no),
  membership_status int REFERENCES membership_status(id),
  birth_date int DEFAULT 0,
);

CREATE TABLE student (
  user_name varchar(20) references users(user_name),
  name varchar(30) not null,
  surname varchar(30) not null,
  department varchar(30) not null,
  penalty_point int DEFAULT 0,
  primary key(user_name)
);

CREATE TABLE company (
  user_name varchar(20) references users(user_name),
  company_name varchar(30) not null,
  location varchar(30),
  primary key(user_name)
);

CREATE TABLE donation_accept_unit (
  unit_name varchar(40),
  balance int DEFAULT 0,
  primary key(unit_name),
  created_date timestamp
);

CREATE TABLE dau_user (
  user_name varchar(20) REFERENCES users(user_name),
  unit_name varchar(40) REFERENCES donation_accept_unit(unit_name),
  name varchar(40) NOT NULL,
  surname varchar(40) NOT NULL,
  primary key(user_name)
);

CREATE TABLE bank_account_info (
  owner_unit_name varchar(40),
  bank_name varchar(30) NOT NULL,
  branch_bank_name varchar(30) NOT NULL,
  bank_account_number numeric(16) NOT NULL,
  iban varchar(34),
  currency int not null,
  PRIMARY KEY(iban)
);

CREATE TABLE donation (
  donation_id int primary key,
  company_username varchar(30) not null,
  donate_accept_unit_username varchar(30) not null,
  packet_id int not null,
  iban varchar,
  amount int,
  approved boolean default false
);

CREATE TABLE announcement_state (
  id int primary key,
  title varchar(30) not null
);

create table announcement_type (
  id int primary key,
  title varchar(30)
);

CREATE TABLE communication_way (
  comm_type varchar(30),
  comm_value varchar(70),
  primary key(comm_type, comm_value),
  user_name varchar(20) REFERENCES users(user_name)
);

CREATE TABLE department (
  code varchar(3) primary key,
  name varchar(50) unique
);

CREATE TABLE message (
  message_no serial,
  sender_name varchar(30) NOT NULL,
  sender_surname varchar(30) NOT NULL,
  message_title varchar(30) NOT NULL,
  message_body text NOT NULL,
  sender_email_address varchar(50) NOT NULL,
  sender_ip_address varchar(16) NOT NULL,
  is_read boolean default false,
  date_time timestamp NOT NULL,
  primary key(sender_email_address, date_time)
  --time?
);

CREATE TABLE announcement_category (
  id int primary key,
  category_name varchar(70) NOT NULL UNIQUE,
  references_count int DEFAULT 0,
  parent_category_id int REFERENCES announcement_category(id)
);

CREATE TABLE announcement (
  id int primary key,
  title varchar(70),
  brief text NOT NULL,
  content text NOT NULL,
  number_of_page_views int,
  state int REFERENCES announcement_state(id),
  owner_company varchar(30) REFERENCES company(user_name),
  owner_packet int,
  announcement_type int not null,
  announcement_category int REFERENCES announcement_category(id),
  announcement_language varchar(20),
  publish_date timestamp,
  expired_date timestamp,
  proper_complaint boolean DEFAULT TRUE,
  visibility boolean
);

CREATE TABLE announcement_packet (
  packet_id int primary key,
  announcement_count int not null,
  price int not null,
  last_date_used timestamp not null,
  active_time int not null,
  currency int not null,
  condition text not null,
  bank_account_info varchar(30) REFERENCES bank_account_info(iban)
);

CREATE TABLE currency (
  id int primary key,
  title varchar(20) not null
);

CREATE TABLE announcement_packet_state (
  id int primary key,
  title varchar(50)
);

CREATE TABLE  company_own_packet (
  id int primary key,
  owner_company varchar(30) REFERENCES company(user_name),
  packet int REFERENCES announcement_packet(packet_id),
  announcement_packet_state int REFERENCES announcement_packet_state(id),
  used_announcements int,
  approved boolean,
  user_for_approved varchar(30),
  time_to_request timestamp NOT NULL,
  time_to_approved timestamp,
  time_to_expired timestamp
);

CREATE TABLE application (
  application_no serial,
  username varchar(20) REFERENCES users(user_name),
  announcement_id int REFERENCES announcement(id),
  time_to_application timestamp NOT NULL,
  ip_address char(16) NOT NULL,
  primary key(username , announcement_id)
);

CREATE TABLE accounting (
  unit_name varchar(40) REFERENCES donation_accept_unit(unit_name),
  user_name varchar(20) REFERENCES dau_user(user_name),
  date_time timestamp NOT NULL,
  amount int NOT NULL,
  description text,
  primary key(unit_name, date_time)
);

CREATE TABLE spending_request_state (
  id int primary key,
  title varchar(50)
);

CREATE TABLE spending_request (
  id int primary key,
  title varchar(60),
  content text,
  amount int,
  sent_date_time timestamp,
  dau varchar(40) REFERENCES donation_accept_unit(unit_name),
  state int REFERENCES spending_request_state(id),
  updater varchar(20) REFERENCES dau_user(user_name),
  updated_date_time timestamp,
  answer_from_updater text,
  pdf_path varchar(100),
  image_path varchar(100)
);

CREATE TABLE complaint (
  id int primary key,
  student varchar(20) REFERENCES student (user_name),
  announcement int REFERENCES announcement (id),
  description text NOT NULL,
  complaint_time timestamp,
  result varchar(40),
  result_time timestamp,
  result_reply text
);

CREATE TABLE interests (
	name varchar(20) primary key,
	student varchar(20) REFERENCES student(user_name),
	category int REFERENCES announcement_category(id),
	ann_type int REFERENCES announcement_type(id),
	language varchar,
	keywords text
);

CREATE TABLE complaint_report (
	id int primary key,
	announcement int REFERENCES announcement(id),
	operation_date timestamp NOT NULL,
	description text NOT NULL
);

CREATE TABLE verification_code (
	code char(8) primary key,
	user_name varchar(20) REFERENCES users(user_name),
	sending_time timestamp NOT NULL,
	operation_time timestamp,
	state varchar(20) NOT NULL
);

CREATE TABLE global_parameter (
	name varchar(50) primary key,
	value varchar(200) NOT NULL,
	type varchar(50) NOT NULL
);

CREATE TABLE education_info(
	id int primary key,
	student varchar(20) REFERENCES student(user_name),
	school varchar(100) NOT NULL,
	department varchar(50),
	start_date int NOT NULL,
	end_date int DEFAULT 0,
	degree varchar(40)
);

CREATE TABLE notification (
	id int primary key,
	trigger_factor varchar(50) NOT NULL,
	trigger_target varchar(20) REFERENCES users(user_name),
	description text NOT NULL,
	trigger_date timestamp NOT NULL,
	state varchar(50) NOT NULL
);
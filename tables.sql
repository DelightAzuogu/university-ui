create database if not exists logo_university;
use logo_university;

CREATE TABLE IF NOT EXISTS faculty (
    faculty_name CHAR(50),
    status BOOLEAN DEFAULT TRUE,
    comment VARCHAR(500),
    PRIMARY KEY (faculty_name)
);

CREATE TABLE IF NOT EXISTS department (
    dept_name CHAR(50),
    building VARCHAR(50),
    faculty CHAR(50),
    status boolean default true,
    PRIMARY KEY (dept_name),
    FOREIGN KEY (faculty)
        REFERENCES faculty (faculty_name)
);

CREATE TABLE IF NOT EXISTS inactive_department (
    dept_name CHAR(50) PRIMARY KEY,
    FOREIGN KEY (dept_name)
        REFERENCES department (dept_name)
);

CREATE TABLE IF NOT EXISTS instructor (
    id SMALLINT UNSIGNED AUTO_INCREMENT,
    first_name VARCHAR(20),
    last_name VARCHAR(20),
    dept_name CHAR(50),
    email VARCHAR(50),
    status boolean default true,
    password VARCHAR(10),
    phone_number INT,
    office VARCHAR(10),
    salary INT UNSIGNED,
    passport_no CHAR(10),
    country varchar(20),
    country_of_res VARCHAR(20),
    city VARCHAR(20),
    street VARCHAR(20),
    address VARCHAR(50),
    yob YEAR NOT NULL,
    mob VARCHAR(10),
    dob TINYINT UNSIGNED,
    PRIMARY KEY (id),
    FOREIGN KEY (dept_name)
        REFERENCES department (dept_name)
);

create table if not exists coordinator(
	i_id SMALLINT UNSIGNED,
    faculty_name CHAR(50) primary key,
    password VARCHAR(10),
    foreign key(i_id) references instructor(id),
    foreign key(faculty_name) references faculty(faculty_name)
);

CREATE TABLE IF NOT EXISTS inactive_instructor (
    i_id SMALLINT UNSIGNED PRIMARY KEY,
    FOREIGN KEY (i_id)
        REFERENCES instructor (id)
);

create table if not exists retired_instructor (
    i_id SMALLINT UNSIGNED PRIMARY KEY,
    FOREIGN KEY (i_id)
        REFERENCES instructor (id)
);

CREATE TABLE IF NOT EXISTS head_of_department (
    i_id SMALLINT UNSIGNED,
    dept_name CHAR(50),
    PRIMARY KEY (dept_name),
    FOREIGN KEY (i_id)
        REFERENCES instructor (id),
    FOREIGN KEY (dept_name)
        REFERENCES department (dept_name)
);

CREATE TABLE IF NOT EXISTS student (
    id SMALLINT UNSIGNED AUTO_INCREMENT,
    first_name VARCHAR(20),
    last_name VARCHAR(20),
    dept_name CHAR(50),
    cgpa numeric(7 , 6 ) default 0,
    email VARCHAR(50),
    passport_number char(10),
    phone_number bigint,
    semester_no SMALLINT DEFAULT 1,
    status boolean default true,
    current_semester boolean default true,
    password VARCHAR(10),
    yob YEAR NOT NULL,
    mob VARCHAR(10),
    dob TINYINT UNSIGNED,
    country varchar(20),
    country_of_res VARCHAR(20),
    city VARCHAR(20),
    street VARCHAR(20),
    address VARCHAR(50),
    PRIMARY KEY (id),
    FOREIGN KEY (dept_name)
        REFERENCES department (dept_name)
);

CREATE TABLE IF NOT EXISTS graduated_student (
    s_id SMALLINT UNSIGNED PRIMARY KEY,
    FOREIGN KEY (s_id)
        REFERENCES student (id)
);

CREATE TABLE IF NOT EXISTS frozen_student (
    s_id SMALLINT UNSIGNED PRIMARY KEY,
    FOREIGN KEY (s_id)
        REFERENCES student (id)
);
create table if not exists inactive_student (
    s_id SMALLINT UNSIGNED PRIMARY KEY,
    FOREIGN KEY (s_id)
        REFERENCES student (id)
);

CREATE TABLE IF NOT EXISTS student_gpa (
    s_id SMALLINT UNSIGNED,
    gpa NUMERIC(7 , 6 ),
    semester CHAR(10),
    grade_earned NUMERIC(9 , 6 ) DEFAULT 0,
    year YEAR,
    PRIMARY KEY (s_id , semester , year),
    FOREIGN KEY (s_id)
        REFERENCES student (id)
);

CREATE TABLE IF NOT EXISTS advisor (
    s_id SMALLINT UNSIGNED,
    i_id SMALLINT UNSIGNED,
    PRIMARY KEY (s_id),
    FOREIGN KEY (s_id)
        REFERENCES student (id),
    FOREIGN KEY (i_id)
        REFERENCES instructor (id)
);

CREATE TABLE IF NOT EXISTS course (
    course_code CHAR(10),
    title CHAR(50),
    dept_name CHAR(50),
    credit TINYINT UNSIGNED,
    status BOOLEAN DEFAULT TRUE,
    textbook VARCHAR(100),
    comment VARCHAR(1000),
    PRIMARY KEY (course_code),
    FOREIGN KEY (dept_name)
        REFERENCES department (dept_name)
);

CREATE TABLE IF NOT EXISTS prereq (
    prereq_code CHAR(10),
    course_code CHAR(10),
    PRIMARY KEY (prereq_code , course_code),
    FOREIGN KEY (prereq_code)
        REFERENCES course (course_code),
    FOREIGN KEY (course_code)
        REFERENCES course (course_code)
);

CREATE TABLE IF NOT EXISTS classroom (
    building CHAR(50),
    room_number SMALLINT UNSIGNED,
    capacity SMALLINT UNSIGNED,
    PRIMARY KEY (building , room_number)
);

CREATE TABLE IF NOT EXISTS time_slot (
    time_slot_id SMALLINT UNSIGNED AUTO_INCREMENT,
    day CHAR(19),
    start_time TIME,
    end_time TIME,
    PRIMARY KEY (time_slot_id)
);

CREATE TABLE IF NOT EXISTS section (
    course_code CHAR(10),
    group_number SMALLINT UNSIGNED,
    semester CHAR(10),
    year YEAR,
    building CHAR(50),
    room_number SMALLINT UNSIGNED,
    time_slot_id SMALLINT UNSIGNED,
    PRIMARY KEY (course_code , group_number , semester , year),
    FOREIGN KEY (building , room_number)
        REFERENCES classroom (building , room_number),
    FOREIGN KEY (course_code)
        REFERENCES course (course_code),
    FOREIGN KEY (time_slot_id)
        REFERENCES time_slot (time_slot_id)
);

CREATE TABLE IF NOT EXISTS takes (
    s_id SMALLINT UNSIGNED,
    course_code CHAR(10),
    group_number SMALLINT UNSIGNED,
    semester CHAR(10),
    year YEAR,
    grade CHAR(2) DEFAULT '*',
    PRIMARY KEY (s_id , course_code , group_number , semester , year),
    FOREIGN KEY (s_id)
        REFERENCES student (id),
    FOREIGN KEY (course_code , group_number , semester , year)
        REFERENCES section (course_code , group_number , semester , year)
);

CREATE TABLE IF NOT EXISTS teaches (
    i_id SMALLINT UNSIGNED,
    course_code CHAR(10),
    group_number SMALLINT UNSIGNED,
    semester CHAR(10),
    year YEAR,
    PRIMARY KEY (i_id , course_code , group_number , semester , year),
    FOREIGN KEY (i_id)
        REFERENCES instructor (id),
    FOREIGN KEY (course_code , group_number , semester , year)
        REFERENCES section (course_code , group_number , semester , year)
);
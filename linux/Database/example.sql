    CREATE TABLE test1   
    (   
    name VARCHAR(32) NOT NULL,   
    city VARCHAR(32) NOT NULL   
    ); 
    insert into TABLE1(name, city) values ('Person A', 'BJ');   
    insert into TABLE1(name, city) values ('Person B', 'BJ');   
    insert into TABLE1(name, city) values ('Person C', 'SH');   
    insert into TABLE1(name, city) values ('Person D', 'SZ');   
    commit ;    
    CREATE TABLE test2   
    (   
    name VARCHAR(32) NOT NULL,   
    city VARCHAR(32) NOT NULL   
    ) ;
    insert into TABLE2(name, city) values ('Person W', 'BJ');   
    insert into TABLE2(name, city) values ('Person X', 'SH');   
    insert into TABLE2(name, city) values ('Person Y', 'SH');   
    insert into TABLE2(name, city) values ('Person Z', 'NJ');   
    commit;
    show tables ;
    select  * from test1 a inner join test2 b on a.city = b.city 
   
    select * from table1 a join table2 b on a.city = b.city 
      
   
    copy wheeltread(
    index_id ,
    check_date ,
    train_id ,
    vehicle_id,
    vehicle_no , 
    alxi_no ,
    project_name ,
    value 
    ) 
    from  '/home/postgres/2012.4-7.csv'   delimiter ',' ;
 
 
 create table  tred (
 index_id    character varying(200) , 
 check_date    character varying(200) , 
 train_id      character varying(200) , 
 vehicle_id    character varying(200) , 
 vehicle_no    character varying(200) , 
 alxi_no       character varying(200) , 
 project_name  character varying(200)                   , 
 value         numeric                , 
 work_date     character varying(40) 
 ) 
 update table tred 
 set trans_date = concat(substring(check_date,1 ,4),
 '-',
 substring(check_date ,5,3 ),
 '-',
 substring(check_date,6,3))
 
 load data local infile  '/tmp/all.csv' into table wheeltred ;
 
 LOAD DATA INFILE '/tmp/all.csv'  
 INTO TABLE wheeltred   
 FIELDS TERMINATED BY ','   
 OPTIONALLY ENCLOSED BY '"'   
 LINES TERMINATED BY '\n'; 
 
 ALTER TABLE wheeltread DROP COLUMN work_date;
 
-- Table: wheeltread

-- DROP TABLE wheeltread;

CREATE TABLE wheeltread
(
  index_id character varying(50),
  check_date character varying(50),
  train_id character varying(50),
  vehicle_id character varying(50),
  vehicle_no character varying(50),
  alxi_no character varying(50),
  project_name text,
  value numeric,
)
WITH (
  OIDS=FALSE
);
ALTER TABLE wheeltread
  OWNER TO postgres;
  
  
  

CREATE TABLE trainaxledata
(
  train_axle integer NOT NULL,
  key character varying(500) NOT NULL,
  value character varying(250) NOT NULL,
  note character varying(50) NOT NULL DEFAULT ''::character varying,
  CONSTRAINT trainaxledata_pkey PRIMARY KEY (train_axle , key ),
  CONSTRAINT fk_trainaxledata_train_axle_id FOREIGN KEY (train_axle)
      REFERENCES train_axle (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION
)
WITH (
  OIDS=FALSE
);
ALTER TABLE trainaxledata
  OWNER TO postgres;
  
CREATE TABLE trainaxledata
(
  train_axle integer NOT NULL,
  key character varying(500) NOT NULL,
  value character varying(250) NOT NULL,
  note character varying(50) NOT NULL DEFAULT ''::character varying,
  CONSTRAINT trainaxledata_pkey PRIMARY KEY (train_axle , key ),
  CONSTRAINT fk_trainaxledata_train_axle_id FOREIGN KEY (train_axle)
      REFERENCES train_axle (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION
)
WITH (
  OIDS=FALSE
);
ALTER TABLE trainaxledata
  OWNER TO postgres;


CREATE TABLE trainaxledata
(
  train_axle integer NOT NULL,
  key character varying(500) NOT NULL,
  value character varying(250) NOT NULL,select   wheeltread.date1,wheeltread.train_id ,wheeltread.vehicle_id ,wheeltread.vehicle_no ,wheeltread.axis_no, wheeltread.project_name , wheeltread.value  ,wheeltread.falg , scheduling.train_id scheduling.run_length,scheduling.trans_date   from  wheeltread left join on  scheduling  where wheeltread.train_id =  scheduling.train_id and wheeltread.trans_date  = scheduling.check_date 
  note character varying(50) NOT NULL DEFAULT ''::character varying,
  CONSTRAINT trainaxledata_pkey PRIMARY KEY (train_axle , key ),
  CONSTRAINT fk_trainaxledata_train_axle_id FOREIGN KEY (train_axle)
      REFERENCES train_axle (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION
)
WITH (
  OIDS=FALSE
);

ALTER TABLE trainaxledata
  OWNER TO postgres;
  
  ALTER TABLE scheduling DROP COLUMN table_date;
  ALTER TABLE products ADD COLUMN description text;
  alter table dbo.titemtype alter column id type integer using to_number(id,'9');

               Table "public.wheeltread"
    Column    |            Type             | Modifiers 
--------------+-----------------------------+-----------
 index_id     | integer                     | 
 check_date   | timestamp without time zone | 
 train_id     | character varying(20)       | 
 vehicle_id   | integer                     | 
 vehicle_no   | integer                     | 
 alxi_no      | integer                     | 
 project_name | character varying(20)       | 
 value        | numeric(18,6)               | 


select * from wheeltred  limit 10 into outfile './output4.csv' fields terminated by ','optionally enclosed by ''lines terminated by '\n';

select count (distinct(train_id ) ) from wheeltread ;
sudo apt-get install postgresql-9.1 
select trans_date from scheduling order by  trans_date ;
select distinct (train_id ) from scheduling order by  train_id ;

su postgres
psql
alter user postgres with password 'ia' ;
linux  给用户设置密码：
     NAME
    passwd – update a user’s authentication tokens(s)

    SYNOPSIS
    passwd [-k] [-l] [-u [-f]] [-d] [-n mindays] [-x maxdays] [-w warndays] [-i inactivedays] [-S]
    [--stdin] [username] 


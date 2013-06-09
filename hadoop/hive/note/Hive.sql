--HiveQL例子
--创建数据库。
CREATE DATABASE IF NOT EXISTS financials;
--类似于MySQL，从当前数据库切换到另一个数据库。
USE financials ;
--创建表。
CREATE TABLE employees ( 
name  STRING,
salary FLOAT,
subordinates  ARRAY<STRING>,
deductions  MAP<STRING, FLOAT>,
address  STRUCT<street:STRING, city:STRING, state:STRING, zip:INT>);
--创建表并指定一些参数，间隔符等。
CREATE TABLE employees (
name  STRING,
salary FLOAT,
subordinates  ARRAY<STRING>,
deductions  MAP<STRING, FLOAT>,
address  STRUCT<street:STRING, city:STRING, state:STRING, zip:INT>
)
ROW FORMAT DELIMITED   FIELDS TERMINATED BY '\001'
COLLECTION ITEMS TERMINATED BY '\002'
MAP KEYS TERMINATED BY '\003'
LINES TERMINATED BY '\n'
STORED AS TEXTFILE;
--创建数据库并添加属性。
CREATE DATABASE financials
WITH DBPROPERTIES ('creator' = 'Mark Moneybags', 'date' = '2012-01-02');
--查看数据库的属性。
DESCRIBE DATABASE financials;
DESCRIBE DATABASE EXTENDED financials;
--创建表,并添加列的属性。
CREATE TABLE IF NOT EXISTS  mydb.employees (
name  STRING  COMMENT 'Employee name',
salary  FLOAT COMMENT 'Employee salary',
subordinates ARRAY<STRING>  COMMENT 'Names of subordinates',
deductions MAP<STRING, FLOAT>  COMMENT 'Keys are deductions names, values are percentages',
address  STRUCT<street:STRING, city:STRING, state:STRING, zip:INT> COMMENT 'Home address')
COMMENT 'Description of the table'
TBLPROPERTIES ('creator'='me', 'created_at'='2012-01-02 10:00:00', ...)
LOCATION '/user/hive/warehouse/mydb.db/employees';
--查看表属性
SHOW TBLPROPERTIES
--根据一张表的结构创建另一张表
CREATE TABLE IF NOT EXISTS mydb.employees2
LIKE mydb.employees;
--创建外部表,指定表的存储位置。
CREATE EXTERNAL TABLE IF NOT EXISTS stocks (
exchange STRING,
symbol  STRING,
ymd STRING,
price_open FLOAT,
price_high FLOAT,
price_low FLOAT,
price_close FLOAT,
volume INT,
price_adj_close FLOAT)
ROW FORMAT DELIMITED FIELDS TERMINATED BY ','
LOCATION '/data/stocks';
--表的管理。
--删除表。
DROP TABLE IF EXISTS employees;
--修改表名
ALTER TABLE  log_messages RENAME TO logmsgs;
--添加分区
ALTER TABLE log_messages ADD IF NOT EXISTS
PARTITION (year = 2011, month = 1, day = 1) LOCATION '/logs/2011/01/01'
PARTITION (year = 2011, month = 1, day = 2) LOCATION '/logs/2011/01/02'
PARTITION (year = 2011, month = 1, day = 3) LOCATION '/logs/2011/01/03'
--修改分区。
ALTER TABLE log_messages PARTITION(year = 2011, month = 12, day = 2)
SET LOCATION 's3n://ourbucket/logs/2011/01/02';
--删除分区。
ALTER TABLE log_messages DROP IF EXISTS PARTITION(year = 2011, month = 12, day = 2);
--修改列名。
ALTER TABLE log_messages
CHANGE COLUMN hms hours_minutes_seconds INT
COMMENT 'The hours, minutes, and seconds part of the timestamp'
AFTER severity;
--添加列
ALTER TABLE log_messages ADD COLUMNS (
app_name STRING COMMENT 'Application name',
session_id LONG COMMENT 'The current session id');
--更新表。
ALTER TABLE  log_messages  REPLACE COLUMNS (
hours_mins_secs  INT COMMENT 'hour, minute, seconds from timestamp',
severity     STRING COMMENT 'The message severity'
message      STRING COMMENT 'The rest of the message');
--数据管理
LOAD DATA LOCAL INPATH '${env:HOME}/california-employees'
OVERWRITE INTO TABLE employees
PARTITION (country = 'US', state = 'CA');

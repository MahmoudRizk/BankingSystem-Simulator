# BankingSystem-Simulator.
## Overview:
* <b>BankingSystem-Simulator</b> is a <b>Toy-project</b> for learning & fun, combining both of <b>qt</b> with <b>MySQL</b> database server and showing how we can combine both of them in one project.<br/>
* This project was <b>built</b> using <b>Linux</b> OS, so you will <b>mantain</b> any <b>differences</b> faced in case of using another operating systems like <b>Windows</b> or <b>Mac</b>. Since <b>qt</b> is a crossplatform framework so there will be no problems with the GUI, the diffrences you may face will be concerning <b>MySQL</b> database server. 
* The <b>Code</b> is commented making it easy keeping up with and clearing any ambiguity might be faced.
* <b>Screenshots:</b> <br/> <br/>
<a href="https://imgbb.com/"><img src="https://image.ibb.co/kcOOAF/c.png" alt="c" border="0"></a><br /><a target='_blank' href='https://imgbb.com/'></a><br />
<a href="https://imgbb.com/"><img src="https://image.ibb.co/dfdeja/b.png" alt="b" border="0"></a><br /><a target='_blank' href='https://imgbb.com/'></a><br />
## Requirements:
* <b>qt5</b>.
* <b>MySQL Server</b> V:5.5.
## Installation & Usage:
#### 1) Setup your database: 
* After the installation of MySQL server, run it.
```
mysql -u USERNAME -p PASSWORD
```
* Create your database then use it.
```
mysql> CREATE DATABASE bank;
mysql> use bank;
```
* Populate your database with some fake Data. Run <b>banking_mysql.sql</b> file which will create the tables for you and will insert 1000 entry.
```
mysql> source FILEPATH/banking_mysql.sql
```
* <b>Now</b> your DataBase is up and running.
#### 2) qt files:
* Open the main.cpp file, then edit the database parameters.
```c++
 DataBaseManager db("QMYSQL", "localhost", "DB_NAME", "YOUR_DB_USERNAME" ,"DB_PASSWORD" ); // Establishing connection with mysql DB.
```
```c++
"DB_NAME" ---> The name of the database in MySQL server which we created before : "bank".
"YOUR_DB_USERNAME" ---> Your username of MySQL server.
"DB_PASSWORD" ---> Your password of MySQL server.
```
* Build the project using <b>Qt creator</b> or using <b>qmake</b> command from the <b>terminal</b> then run it.

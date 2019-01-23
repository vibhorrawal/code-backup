# vibhor Rawal
import sqlite3

connection=sqlite3.connect("db3")

command="create table table2(name varchar(20),age int)"
connection.execute(command)


command="insert into table2 values('vibhor',20),('shivam',21),('shashwat',19),('ashish',24)"
connection.execute(command)

cursor = connection.cursor()
cursor.execute("SELECT * FROM table2")
 
rows = cursor.fetchall()

for row in rows:
    print(row)

deleteID=input("Enter name to be deleted: ")


command="Delete from table2 where name='"+deleteID+"'"
connection.execute(command)

updateID=input("Now Enter name to be updated: ")
age=int(input("Enter new age:"))

command="Update table2 set age="+ str(age) +" where name='"+updateID+"'"
connection.execute(command)

cursor.execute("SELECT * FROM table2")
 
rows = cursor.fetchall()

for row in rows:
    print(row)
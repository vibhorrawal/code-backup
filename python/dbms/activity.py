from flask import Flask, redirect, render_template, request, url_for, abort, session
from flask_session import Session
from db import *
app = Flask(__name__)
app.secret_key = 'Vibhor and Rahul'
date = 'string'

@app.route('/')
def index():
	return render_template('index.html')

	if session['logged_in'] is True or False:
		return render_template('index.html')
	else:
		abort(401)	
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
@app.route('/login', methods = ['GET', 'POST'])
def login():
	if request.method == 'POST':
		customer_ID = request.form['userName']
		entered_password = request.form['userPass']

	session['id']	= customer_ID

	cmd = "SELECT customer_password,customer_firstname FROM customer WHERE customer_ID = %s;" %customer_ID 

	rows = db(cmd)
	
	#return str(rows)
	if rows:
		#return '1'
		(customer_password,customer_firstname)= rows[0]		

   
		if entered_password == customer_password:
			#return customer_firstname
			#return redirect(url_for('/main'),id = customer_ID)
			session['logged_in'] = True
			return redirect(url_for('mainpage'))
			#, id = customer_ID, name = customer_firstname)
			
		else:
  			return render_template('recordnotexist.html')

	else:
  		return render_template('recordnotexist.html')
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
@app.route('/mainpage')
def mainpage():
	id = session['id']
	if session['logged_in'] is False:
		abort(401)
	cmd = "SELECT customer_firstname from customer where customer_ID = %s;" %id
	rows = db(cmd)
	customer_firstname = rows[0][0]
	#return str(customer_firstname)
	return render_template("main.html", id = id, name = customer_firstname)


#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
@app.route('/main', methods = ['GET', 'POST'])
def main():
	#return str(session['id'])
	id = session['id']
	#id = request.form['id']
	try:
		value = request.form['btn1']
	except:
		value = request.form['btn2']

	if value == 'book':
		return render_template('book.html', id = id)
	else :
		return redirect(url_for('previous'))
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
@app.route('/logout')
def logout():
	session['logged_in'] = False
	return render_template('index.html')

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
@app.route('/book', methods = ['GET', 'POST'])
def book():
	id = session['id']
	fplace = request.form['from-place']
	tplace = request.form['to-place']
	date = request.form['date1']
	#return str(fplace+' '+tplace)
	cmd = "SELECT * from bus where bus_ID in (SELECT bus_ID from route where route_origin = '%s' and route_destination = '%s');" %(fplace,tplace)
	rows = db(cmd)
	#return str(rows)

	return render_template('available.html', rows = rows, date = date, fplace = fplace, tplace = tplace)

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
@app.route('/selected', methods = ['GET', 'POST'])
def selected():
	id = session['id']
	bus_ID = request.form['bus_ID']
	fplace = request.form['fplace']
	tplace = request.form['tplace']
	date = request.form['date']
	#return str(bus_ID)
	cmd = "SELECT * from bus WHERE bus_ID = '%s';" %bus_ID
	rows = db(cmd)
	#return str(rows)
	return render_template('businfo.html', rows = rows, fplace = fplace, tplace = tplace, date = date, bus_ID = bus_ID)

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
@app.route('/reserve', methods = ['GET', 'POST'])
def reserve():
	id = session['id']
	seats = request.form['selected_seats']
	#return str(seats)
	bus_ID = request.form['bus_ID']
	fplace = request.form['fplace']
	tplace = request.form['tplace']
	date = request.form['date']
	#return date
	cmd = "SELECT bus_no_of_seats_available from bus where bus_ID = '%s';" %bus_ID
	rows = db(cmd)
	#return str(rows)
	row = int(rows[0][0]) -  int(seats)
	row = str(row)
	cmd = "UPDATE bus set bus_no_of_seats_available = %s where bus_ID = '%s';" %(row,bus_ID)
	db(cmd)
	cmd = "SELECT * from bus where bus_ID = '%s';" %bus_ID
	#return str(db(cmd))
	#cmd = "SELECT route_ID from route where bus_ID"
	cmd = "INSERT into reservation(customer_ID,bus_ID,route_origin,route_destination,res_no_of_seats,res_timestamp) values (%s,'%s','%s','%s',%s,'%s');" %(id,bus_ID,fplace,tplace,seats,date)
	db(cmd)
	cmd = "SELECT customer_firstname from customer where customer_ID = %s;" %id
	rows = db(cmd)
	name = rows[0][0]

	cmd= "SELECT * from reservation where customer_ID = %s and res_timestamp = '%s';" %(id,date)
	rows = db(cmd)
	#return str(rows)

	return render_template('ticketbooked.html', rows = rows, name = name)

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
@app.route('/previous')
def previous():
	id = session['id']
	cmd = "SELECT customer_firstname from customer where customer_ID = %s;" %id
	rows = db(cmd)
	name = rows[0][0]	
	cmd = "SELECT * from reservation where customer_ID = '%s';" %id
	rows = db(cmd)
	return render_template('bookings.html', rows = rows, name = name)
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
@app.route('/createaccount', methods=["GET","POST"])
def createaccount():
	firstname = request.form['userName']
	lastname = request.form['lastname']
	email = request.form['email']
	password = request.form['password']
	age = request.form['age']
	phone = request.form['phone']

	cmd = "INSERT INTO customer(customer_firstname,customer_lastname,customer_email,customer_password,customer_age,customer_phonenumber) values('%s','%s','%s','%s',%s,%s);" %(firstname,lastname,email,password,age,phone)
	db(cmd)
	return render_template('index.html')
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
@app.route('/contact')
def contact():
	return render_template('contact.html')
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

if __name__ == "__main__":
	app.run()
LAB 2
PROGRAM 1 : FAN
	-> this fan can have speeds of 10,20,30,40,50rpm.
	-> the variable state does the task of a switch, it stores the state of fa.
	-> rotateCCW is similar to rotating regulator. CW increase speed by 1, CCW decreases speed by 1.
	-> the variable no_of_turns and array speed play main role in these functions.
	-> it is assumed that it can only range from 1 to 5.
	-> attempt of crossing these limits prints a message.
	-> attempt of rotating regulator when fan is switched off prints a message.
	-> getSpeed and getState functions return the present speed and state respectively.
	
PROGRAM 2 : ATM
	-> this atm can withdraw,deposit and transfer money, it can also display current account balance.
	-> accno.s are similar to our LDAP no.s
	-> creating an array of 176 elements assuming no.of accounts will be less than that.
	-> if users try to withdraw amount greater than their balance, it prints a message and asks users if they want to withdraw complete money 
	and proceeds according to their response.
	-> tried to automate features to instantiate them in main(). But some need responses of user so mentioning them here.
	
PROGRAM 3 : VENDING
	-> the struct drink holds all the variables related to the drink.
	-> wallet_money keeps track of money earned by vending machine.
	-> assumed max no. of drinks can be 10 and initiated by 5 drinks.
	-> customer gets a display consisting the menu of the drinks with details like name, cost, stock, availability.
	-> the function display_dink takes cae of the display of single drink which is called in the menu functio for display of all drinks.
	-> if customer buying the drink inserts wrong coin a message gets printed.
	-> assuming that to get a drink of 10 rupees only 10 rupees coin is allowed and no other combinations of lower value coins or a higher value coin work.
	-> stock of drinks can be replenished and a drink of new kind can also be added to the list which gets added to the display from next time.
	
PROGRAM 4 : DICE
	-> random number generator takes care of getting different toss value.
	-> setting the dice top face to 1 at the start.
	-> toss function returns the face value of the top face of dice after n tosses.
	-> get_face_value function returns the present face value, eventhough it seems less important , it helps the user know the face_value of the dice at the start when dice is not tossed yet.

PROGRAM 5 : TUPLESPACE
	-> used structs and arrays
	-> the struct pair contains the key value pair.
	-> formed the array of a large no.(1000) of pair and initialized firstten to some non-zero values and set all other to 0.
	-> pairs can be added, replacd and deleted.
	-> if user tries to add an element with  a pre-existing key a message gets printed and user will be asked if they like to replace it and proceeds according to their response.
	-> deleting the element function actually changes the key and value to 0.

PROBLEM 6 : LIFT
	-> assuming that there are 5 floors including ground and terrace.
	-> member functions related to outer and inner inerface are seperated.
	-> person_floor is the floor where the person waiting for the lift is present.
	-> current_floor is the floor where the lift is currently present.
	-> if the person waiting wants to go up but if there is no floor above a msg gets printed similar is the case for want to go down.
	-> lift comes to the floor the person is waiting and gets the person to the floor desired.
	-> trying to generalize the variables so that any change which is desired to made can be made after easily.
	
PROBLEM 7 : ROOM SCHEDULER
	-> used structs to store the variables.
	-> assuming that room can be booked for only one complete day for one request.
	-> both the displays of schedule of a day and a week can be displayed as per need of user.
	-> rooms of 3 departments namely lecture halls, conference halls, faculty lounge are considered.
	-> assuming ther are only 5 rooms.
	-> display contains the department, name, status get displayed.
	-> if the user tries to book a room which is aldready booked a message gets printed.
	 
	
	
	   

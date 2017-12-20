#pragma once
#ifndef MANAGER_H
#define MANAGER_H

//Declare structure type named manager containing a variable for each of the details to be stored 
struct manager {
	int pricefor1, pricefor2, pricefor3, pricefor4;  //store the price for each classes
	int discountperroom;							//store the discount for booking each one room
	long total_benefit;								//store the total benefit of the hotel
};

//Declare structure type named room containing a variable for each of the details to be stored 
struct room {
	int num;							//store the room number
	int classtype;						//store the room type 1. Single 2. Double 3. King Size 4. VIP
	int price;							//store the price for each room
	int occupied;						//store if the room is occupied
	int period;							//Store how long will the room be occupied
	int discount;						//store the discount for each room

};

//Function prototype

//A function to enter the manager account and obtain manager access
void manager();
		//A function to check manager's password
		int checkmanager();

//A function to view or change the price or classtype of the rooms
void setroom();
		//A function to view or change the price of certain classtype
		void change_view_class();
		//A function to change the price, classtype or discount of certain room
		void change_room_price_discount(int judge);
		//A function to view the info of certain room
		void view_roominfo();
		//A fuction to change the price of all the rooms with the same classtype
		void change_for_all_room(int option, int new, int old);
		//A function to change the price of certain classtype chosen by user
		void change_class_price();

//A function to view or set the discount 
void setdiscount();
		//A function to change the discount of groupbooking
		void change_discount_perroom();

//A function to view the statistic of the hotel
void viewstatistic();
		//A function to view the customers' list in terms of different requirements
		void viewcus(int judge);
		//A function to view the total benefit of the hotel
		void viewbenefit();

//A function to manage the customers accounts
void mancusdat();


/*Functions for groupbooking*/
//A function to enter the menu of groupbooking
void group_book();
//A function to make a groupbooking
void creat_group();
//A function to view the info of all the groupbooking customers
void view_group();


/*Functions need to be call for many times*/
//A function to set the room state as occupied
void occupy_room(int num);
//A function to find certian room in the file
long find_room(int num);
//A function to check if the room has been occupied
int checkroom(int num);
//A function to list all the vacant rooms with certain classtype
void list_all_vacant();
//A function to list certain kind of customer according to the value of judge
int listcus(int judge);
//A function to list one customer
void listpart(struct customer *current);

#endif // !MANAGER_H

#pragma once
#ifndef BOOKING_H
#define BOOKING_H
struct customer					/*Declare structure type named customer containing a variable for each of the customer's details to be stored*/
{
	char name[31];				/*To store the customer's name*/
	char address[31];			/*To store the customer's address*/
	char phone_number[15];		/*To store the customer's phone number*/
	int membership;				/*To store the customer's membership*/
	int room_num;				/*To store the customer's room_number*/
	int arrival;				/*To store the customer's arrival days*/
	int days;					/*To store the customer's living day*/
};

struct group					/*Declare structure type named group containing a variable for each of the customer's details to be stored*/
{
	char name[30];				/*To store the group's name*/
	char address[30];			/*To store the group's address*/
	char phonenumber[15];		/*To store the group's phonenumber*/
	int arrival;				/*To store the group's arrial*/
	int days;					/*To store the group's stay days*/
	int rooms;					/*To store the group's room numbers*/
	int room_num[5];			/*To store the number of the order rooms*/
};


void booking();					/* Define a function named booking which could create a booking system*/
void register_guest();			/* Define a function named register_guest which could register the guest information to the system*/
void edit_guest();				/* Define a function named edit_guest which could edit the guest's information in the system*/
void remove_guest();			/* Define a function named remove_guest which could remove a guest information from booking system*/
int search();					/* Define a function named search which could search a custombooking system*/
void book();					/* Define a function named book which could book a room in the booking system*/
void list_all(int *flagB, int *list);/* Define a function named list_all which could identify whether there an empty room in the booking system*/
int checkroom(int num);			/* To use a function from manager.h The function can check if the room still remain*/
#endif // !GUEST_H

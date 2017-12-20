#pragma once

#ifndef MENU_H
#define MENU_H


//copyright (Encrypted)
//Form of Encryption: DES  Password: 19980211 
#define cr "U2FsdGVkX19N1otgQ/zhMncSRBiIQ1wD0u6Zc8KfZDyPc44DYEBuJ/uTgJ4K4tDQ"  // ciphertext


#include<stdio.h>                     	//header file 
#include<windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>

//define some constant value
#define Single 1							//single,double kingsize and VIP room, used for judgement
#define Double 2
#define KingSize 3
#define VIP 4
#define VIPcus 5							//used when list all VIP customers
#define all 99								//used when list all customers
#define VIP_membership 1613489				//VIP membership number
#define disfordisatisfied 80						//discount for disatisfied customer

#define employee_number "1611548"					//staff log in number
#define employee_pass "1613453"						//staff log in passward
#define manager_pass "1611135"						//manager password

//Define four file name for room,customer, manager and groupbooking
#define roominfo "room.dat"					
#define customerinfo "costumer.dat"
#define managerinfo "manager.dat"
#define groupinfo "group.dat"

//Function prototype

//A function to choose booking a room or check in/out a customer.
void staff();

//A function to check the staff employee number and password
int checkstaff();

//Four function to initialize the file for room, customer, manager and groupbooking
//PS: Just for debuging, have nothing to do with the final code
void initialize_room();
void initialze_customer();
void initialize_manager();
void initialize_group();

//A fundtion to press any key to continue
void continue1();

#endif
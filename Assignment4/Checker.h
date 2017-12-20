#pragma once
#ifndef CHECKER_H
#define CHECKER_H

int checker();                     /*A function to perform the  whole checker function of checking in, editing the room information, checking out for the individual or group customer.*/
void printftime();                 /*A function to print the current time.*/
void arrive_customer();            /*A function to check in for the individual customer who is booked.*/
void arrive_group();               /*A function to check in for the group customer who is booked.*/
void edit_customer();              /*A function to edit the stay time, upadating to VIP or room change for the individual customer.*/
void edit_customer_time(position); /*A function to edit the stay time for the individual customer.*/
void edit_customer_VIP(position);  /*A function to edit the information of upadating to VIP for the individual customer.*/
void edit_customer_room(position); /*A function to edit the room number for the individual customer.*/
void checkout_customer();          /*A function to check out and figure out the whole fee for the individual customer who is booked.*/
void checkout_group();             /*A function to check out and figure out the whole fee for the group customer who is booked.*/
void list_validroom();             /*A function to print the specific and vilid room according to the type of room.*/
void toolong(char *search);        /*A function to check out the input of name whether is exceeding the limit of the array of char.*/
#endif // !CHECKER_H

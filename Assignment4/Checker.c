#include "Booking.h"
#include "Menu.h"
#include "Checker.h"
#include "Manager.h"



int checker()                                     /*A function to perform the  whole checker function of checking in, editing the room information, checking out for
												  the individual or group customer. Additionally, it also apply a approach to return the staff menu.*/
{

	int option, flag = 0;                         /*Declare two int variables. option story the choice of performing which specific function.*/
	system("cls");                                /*flag is used to peform the checker menu or return to the staff menu.*/
	while (flag == 0)
	{
		printf("%s\n", "What would you like to do?");
		printf("1) Check in a customer \t\t2) Check in a group \n3) Edit customer information\t");
		printf("4) Check out a customer\n5) Check out a group\t\t6) Back\n");

		while (scanf("%d", &option) != 1 || (option < 1 || option>6))
		{                                         /*Store the input into variable of option and check out the input to exclude the illegal input.*/
			system("cls");
			printf("Input error.\tplease enter again\n");
			printf("1) Check in a customer \t\t2) Check in a group \n3) Edit customer information\t");
			printf("4) Check out a customer\n5) Check out a group\t\t6) Back\n");
			fflush(stdin);
		}
		fflush(stdin);

		switch (option)
		{
		case 1:arrive_customer();                 /*A function to check in for the individual customer who is booked.*/
			break;
		case 2:arrive_group();                    /*A function to check in for the group customer who is booked.*/
			break;
		case 3:edit_customer();                   /*A function to edit the stay time, upadating to VIP or room change for the individual customer.*/
			break;
		case 4:checkout_customer();               /*A function to check out and figure out the whole fee for the individual customer who is booked.*/
			break;
		case 5:checkout_group();                  /*A function to check out and figure out the whole fee for the group customer who is booked.*/
			break;
		case 6:flag = 1;                          /*Change the value of the variable of flag in order to return to the staff menu.*/
			return -1;
		}
	}

	return 0;
}



void printftime()                                 /*Print the current time.*/
{
	time_t t;                                     /*time_t is a type that defines a time_t type of t.*/
	time(&t);                                     /*Obtain the current time.*/
	printf("%s", ctime(&t));                      /*ctime (&t) turns the date into a string and prints it.*/
}

void arrive_customer()                            /*A function to check in for the individual customer who is booked.*/
{
	system("cls");
	FILE *fptr;                                   /*Declare a file pointer called fptr*/
	struct customer current;                      /*Declare a structure called current*/
	long position;                                /*Declare a variable of long called position to temporarily store the address of rogatory successfully individual customer.*/
	char search[31];                              /*Declare an array of char called search to store the name of rogatory customer.*/

	printf("Please enter the booking customer name in order to verify\n");
	toolong(search);                              /*A function to check out the input of name whether is exceeding the limit of the array of char.*/

	fptr = fopen(customerinfo, "rb+");	          /*Open the file called fprt which is store the customer information by reading and writing.*/

	if (fptr == NULL)				              /*Test success of file opening*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program.\n\n");
		continue1();                              /*Call the function called continue1 for pushing the bottom to continue.*/
		exit(0);

	}
	else
	{                                             /*Search for customer by making a comparison between input and the name from reading the struct called current one by one.*/
		while (fread(&current, sizeof(struct customer), 1, fptr) == 1 && (strcmp(current.name, search)))
		{
			continue;	                          /*Continues the loop when the end of the file hasn't been reached and the name values don't both match*/
		}
	}


	if (!(strcmp(current.name, search)))	      /*Test to see if the loop finished because the name was found*/
	{
		if (current.arrival == 1 || current.room_num == 0)     /*Check out whether the customer is already checking in or booking successfully.*/
		{
			if (current.arrival == 1)                         /*For the customer is not checking in.*/
			{
				printf("This customer had checked in earlier.\n");        /*If so, remind that the customer is already checked in earlier.*/
				fclose(fptr);                                             /*Close the file*/
				continue1();                                              /*Call the function called continue1 for pushing the bottom to continue.*/
				system("cls");
			}
			if (current.room_num == 0)                                   /*For the customer is not booking.*/
			{
				printf("Sorry.\tThis customer does not have the record of room.\nTherefore,it could not perform the function.\n");
				fclose(fptr);
				continue1();
				system("cls");
			}
		}
		else
		{

			position = ftell(fptr);                                   /*Return the current file position from the beginning of the file in the type of a long int.*/
			fseek(fptr, position - sizeof(struct customer), SEEK_SET);/*Move the pointer of fptr file the value of position minus total length units from the start of file.*/
			fread(&current, sizeof(struct customer), 1, fptr);        /*From the file, read the value.*/

			printf("The check-in for the customer successfully\n");
			printf("This is your check-in time\t");
			printftime();                                             /*Print and show the current time to customer.*/


			fseek(fptr, position - sizeof(struct customer), SEEK_SET);/*Then move the pointer to previous place*/
			current.arrival = 1;                                      /*Change the information of that of customer into arrival.*/
			fwrite(&current, sizeof(struct customer), 1, fptr);       /*Store the new value into it.*/
			fclose(fptr);                                             /*Close the file*/

			continue1();                                              /*Call the function called continue1 for pushing the bottom to continue.*/
			system("cls");

		}
	}
	else                                                          /*If the loop finished but the name was not found, force to return the previous checker menu.*/
	{
		printf("The customer is not existing.\n");
		printf("The system would force to return the previous\n");
		continue1();                                              /*Call the function called continue1 for pushing the bottom to continue.*/
		system("cls");
		fclose(fptr);                                             /*Close the file.*/
	}
}



void arrive_group()                                               /*A function to check in for the group customer who is booked.*/
{
	system("cls");
	FILE *fptr;                                                   /*Declare a file pointer called fptr*/
	struct group current;                                         /*Declare a structure called current*/
	long position;                                                /*Declare a variable of long called position to temporarily store the address of rogatory successfully group customer.*/
	char search[31];                                              /*Declare an array of char called search to store the name of rogatory group customer.*/

	printf("Please enter the booking group name in order to verify\n");
	toolong(search);                                              /*A function to check out the input of name whether is exceeding the limit of the array of char.*/

	fptr = fopen(groupinfo, "rb+");	                              /*Open the file which is stored the information of group by readingand writing.*/

	if (fptr == NULL)				                              /*Test success of file opening*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program.\n\n");
		continue1();                                              /*Call the function called continue1 for pushing the bottom to continue.*/
		exit(0);                                                  /*If open the file unsuccessfully, program would force to quit.*/

	}
	else
	{                                                             /*Search for account by making a comparison with the values form reading the struct arrays user and code one by one*/

		while (fread(&current, sizeof(struct group), 1, fptr) == 1 && (strcmp(current.name, search)))
		{
			continue;	                                          /*Continues the loop when the end of the file hasn't been reached and the name values don't both match*/
		}
	}

	if (!(strcmp(current.name, search)))	                      /*Test to see if the loop finished because the name was found*/
	{
		if (current.arrival == 1)                                 /*Verify the customer whether is already checked in earlier.*/
		{
			printf("This group had checked in earlier.\n");       /*If so, remind that the customer is already checked in earlier.*/
			fclose(fptr);
			continue1();
			system("cls");
		}
		else                                                      /*If not, change the information of that of customer into arrival.*/
		{
			position = ftell(fptr);
			fseek(fptr, position - sizeof(struct group), SEEK_SET);   /*Move the pointer of fptr file the value of position minus total length units from the start of file.*/
			fread(&current, sizeof(struct group), 1, fptr);           /*From the file, read the value*/

			printf("The check-in for the group successfully\n");
			printf("This is your check-in time\t");
			printftime();

			fseek(fptr, position - sizeof(struct group), SEEK_SET);/*Then move the pointer to previous place of finded group.*/
			current.arrival = 1;                                   /*Change the information of that of customer into arrival.*/
			fwrite(&current, sizeof(struct group), 1, fptr);       /*Store the new value into it.*/
			fclose(fptr); 		                                   /*close the file*/
			continue1();
			system("cls");
		}

	}
	else                                                           /*If the loop finished but the name was not found, force to return the previous checker menu.*/
	{
		printf("The group is not existing.\n");
		printf("The system would force to return the previous\n");
		continue1();
		system("cls");
		fclose(fptr);                                              /*close the file*/

	}
}



void edit_customer()                                               /*A function to edit the stay time, upadating to VIP or room change for the individual customer.*/
{
	system("cls");

	FILE *fptr;                                                    /*Declare a file pointer called fptr*/
	FILE *fptr1;                                                   /*Declare another file pointer called fptr1*/

	struct customer current;                                       /*Declare a structure called current*/
	struct room current1;                                          /*Declare a structure called current1*/
	long position;                                                 /*Declare a variable of long called position to temporarily store the address of logging account*/
	char search[31];                                               /*Declare an array of char called search to store the name of rogatory group customer.*/
	int option, flag = 0;

	printf("Please enter the booking customer name in order to verify\n");
	toolong(search);                                               /*A function to check out the input of name whether is exceeding the limit of the array of char.*/

	fptr = fopen(customerinfo, "rb+");	                           /*Open the file which is stored the information of customer by reading and writing.*/

	if (fptr == NULL)				                               /*Test success of file opening*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program.\n\n");
		continue1();
		exit(0);

	}
	else
	{                                                              /*Search for account by making a comparison with the values form reading the struct arrays user and code one by one*/
		while (fread(&current, sizeof(struct customer), 1, fptr) == 1 && (strcmp(current.name, search)))
		{
			continue;	                                           /*Continues the loop when the end of the file hasn't been reached and the name values don't both match*/
		}
	}
	if (!(strcmp(current.name, search)))	                   /*Test to see if the loop finished because the name was found.*/
	{
		if (current.arrival == 0 || current.room_num == 0)     /*Check out whether the customer is already checking in or booking successfully.*/
		{
			if (current.arrival == 0)                          /*For the customer is not checking in.*/
			{
				printf("Sorry.\tThis customer does not have the record of booking or checking in.\nTherefore,it could not perform the function.\n");
				continue1();
				system("cls");
			}
			else                                              /*For the customer is not booking.*/
			{
				printf("Sorry.\tThis customer does not have the record of room.\nTherefore,it could not perform the function.\n");
				continue1();
				system("cls");
			}
		}
		else
		{

			position = ftell(fptr);
			fclose(fptr);
			printf("\n\tAlready find the information of this customer\n");
			continue1();

			while (flag == 0)                                      /*Inquire to perform specific functions of edit the stay time, updating to VIP or room change.*/
			{
				system("cls");
				printf("Please select which information would need to modify\n");
				printf("%s\n%s\n%s\n%s\n", "1) Stay time", "2) Update to VIP", "3) Room change", "4) Back");


				while (scanf("%d", &option) != 1 || (option < 1 || option>4)) /*Store the input into variable of option and check out the input to exclude the illegal input.*/
				{
					system("cls");
					printf("Input error.\tplease enter again\n");
					printf("Please select which information would need to modify\n");
					printf("%s\n%s\n%s\n%s\n", "1) Stay time", "2) Update to VIP", "3) Room change", "4) Back");
					fflush(stdin);
				}
				fflush(stdin);

				switch (option)                                               /*Perform specific functions of edit the stay time, updating to VIP or room change.*/
				{
				case 1:                                                       /*Perform specific functions of edit the stay time.*/
					edit_customer_time(position);                             /*A function to edit the stay time for the individual customer.*/
					break;

				case 2:                                                       /*Perform specific functions of updating to VIP.*/
					edit_customer_VIP(position);                              /*A function to edit the information of upadating to VIP for the individual customer.*/
					break;

				case 3:                                                       /*Perform specific functions of room change.*/
					edit_customer_room(position);                             /*A function to edit the room number for the individual customer.*/
					break;

				case 4: flag = 1;                                             /*Change the value of the variable of flag in order to return to the checker menu.*/
					system("cls");
					break;
				}
			}
		}
	}
	else                                                                  /*If the loop finished but the name was not found, force to return the previous checker menu.*/
	{
		printf("The customer is not existing.\n");
		printf("The system would force to return the previous\n");
		continue1();
		system("cls");
		fclose(fptr);
	}

}

void edit_customer_time(position)                             /*A function to edit the stay time for the individual customer.*/
{
	FILE *fptr;                                               /*Declare a file pointer called fptr*/
	struct customer current;                                  /*Declare a structure called current*/
	int  changedays = 0;                                      /*Declare an int variable that is used to store temporarily the current stay time wanted.*/
	fptr = fopen(customerinfo, "rb+");	                      /*Open the file which is stored the information of customer by reading and writing.*/

	fseek(fptr, position - sizeof(struct customer), SEEK_SET);/*Move the pointer of fptr file the value of position minus total length units from the start of file.*/
	fread(&current, sizeof(struct customer), 1, fptr);        /*From the file, read the value*/

	printf("Previous period is %d\n", current.days);
	printf("Please enter the current period wanted.\n");


	while (scanf("%d", &changedays) != 1)                     /*Check out the input to exclude the illegal input.*/
	{
		system("cls");
		printf("Input error.\tplease enter again\n");
		printf("Previous period is %d\n", current.days);
		printf("Please enter the current period wanted.\n");

		fflush(stdin);
	}
	fflush(stdin);

	current.days = changedays;                                /*Store the current stay time into the variable of struct.*/
	fseek(fptr, position - sizeof(struct customer), SEEK_SET);/*Then move the pointer to previous place of the current customer.*/
	fwrite(&current, sizeof(struct customer), 1, fptr);       /*Store the new value into the file.*/
	fclose(fptr);                                             /*Close the file.*/

	printf("Modify successfully");
	continue1();
	system("cls");
}

void edit_customer_VIP(position)                              /*A function to edit the information of upadating to VIP for the individual customer.*/
{
	FILE *fptr;                                               /*Declare a file pointer called fptr*/
	struct customer current;                                  /*Declare a structure called current*/
	fptr = fopen(customerinfo, "rb+");	                      /*Open the file which is stored the information of customer by reading and writing.*/

	fseek(fptr, position - sizeof(struct customer), SEEK_SET);/*Move the pointer of fptr file the value of position minus total length units from the start of file.*/
	fread(&current, sizeof(struct customer), 1, fptr);        /*From the file, read the value*/

	if (current.membership == 1613489)                        /*Verify whether the customer is already VIP.*/
	{                                                         /*If so, remind that the customer is already VIP.*/
		printf("This customer is already VIP\n");
		continue1();
		system("cls");
	}
	else                                                          /*If not, change the information into VIP.*/
	{
		current.membership = 1613489;
		fseek(fptr, position - sizeof(struct customer), SEEK_SET);/*Then move the pointer to previous place*/
		fwrite(&current, sizeof(struct customer), 1, fptr);       /*Store the new value into it.*/
		fclose(fptr); 		                                      /*close the file*/

		printf("Modify successfully\n");
		continue1();
		system("cls");
	}
}

void edit_customer_room(position)                                 /*A function to edit the room number for the individual customer.*/
{
	FILE *fptr;                                                   /*Declare a file pointer called fptr*/
	FILE *fptr1;                                                  /*Declare another file pointer called fptr1*/

	struct customer current;                                      /*Declare a structure called current*/
	struct room current1;                                         /*Declare a structure called current1*/
	long previous_roomposition, current_roomposition;             /*Declare two variables of long. They are for storing the position of previous room and current room.*/
	int previous_num, current_num = 0;                            /*Declare two varibales of int. They are fir storing the previous room number and current room number.*/
	fptr = fopen(customerinfo, "rb+");	                          /*Open the file which is stored the information of customer by reading and writing.*/

	fseek(fptr, position - sizeof(struct customer), SEEK_SET);    /*Move the pointer of fptr file the value of position minus total length units from the start of file.*/
	fread(&current, sizeof(struct customer), 1, fptr);            /*From the file, read the value*/

	system("cls");
	if (current.membership == 1613489)
	{
		printf("This customer is VIP, please input the valid VIP room.\n");
	}
	else
	{
		printf("This customer is not VIP, please input the valid ordinary room.\n");
	}

	list_validroom();                                             /*A function to print the specific and vilid room according to the type of room.*/
	previous_num = current.room_num;
	printf("\nPrevious room number is %d\t", current.room_num);
	printf("Please enter the roomnumber wanted.\n");

	if (current.membership == 1613489)                            /*If the customer is VIP, he must choose the VIP room for room change.*/
	{                                                             /*Check out the input of room number wanted whether is valid for VIP.*/
		while ((scanf("%d", &current_num) == 0) || ((checkroom(current_num) == 1) || (current_num<580 || current_num>599)))
		{                                                         /*If not, the program would inquire to re-type.*/
			fflush(stdin);

			printf("\nThis customer is VIP, please input the valid VIP room.\n");
			printf("Error input.\nPlease enter again.\n");

			continue1();
			system("cls");
			printf("This customer is VIP, please input the valid VIP room.\n");
			list_validroom();                                     /*A function to print the specific and vilid room according to the type of room.*/
			printf("Please enter the roomnumber wanted.\n");
			continue;
		}
		fflush(stdin);
	}
	else                                                          /*If the customer is not VIP, he must choose the ordinary room for room change.*/
	{                                                             /*Check out the input of room number wanted whether is valid for ordinary customer.*/
		while ((scanf("%d", &current_num) == 0) || ((checkroom(current_num) == 1) || (current_num<100 || current_num>479)))
		{                                                         /*If not, the program would inquire to re-type.*/
			fflush(stdin);

			printf("Error input.\nPlease enter again.\n");
			printf("\nThis customer is not VIP, please input the valid ordinary room.\n");
			continue1();
			system("cls");
			printf("This customer is not VIP, please input the valid ordinary room.\n");
			list_validroom();                                     /*A function to print the specific and vilid room according to the type of room.*/
			printf("Please enter the roomnumber wanted.\n");
			continue;
		}
		fflush(stdin);
	}

	fseek(fptr, position - sizeof(struct customer), SEEK_SET);/*Move the pointer of fptr file the value of position minus total length units from the start of file.*/
	fread(&current, sizeof(struct customer), 1, fptr);        /*From the file, read the value*/
	current.room_num = current_num;
	fseek(fptr, position - sizeof(struct customer), SEEK_SET);/*Move the pointer of fptr file the value of position minus total length units from the start of file.*/
	fwrite(&current, sizeof(struct customer), 1, fptr);       /*From the file, read the value*/
	fclose(fptr);

	fptr1 = fopen(roominfo, "rb+");	                          /*Open the file1 which is stored the information of room by reading and writing.*/
	previous_roomposition = find_room(previous_num);          /*Call the function called find_room by bringing the value of previous_num to obtain the position of later room.*/
	current_roomposition = find_room(current_num);            /*Call the function called find_room by bringing the value of current_num to obtain the position of current room.*/


	fseek(fptr1, previous_roomposition, SEEK_SET);            /*Move the pointer of fptr1 file the value of previous_roomposition units from the start of file.*/
	fread(&current1, sizeof(struct room), 1, fptr1);          /*From the file, read the value*/
	current1.occupied = 0;                                    /*Cancel the occupation of previous room.*/
	fseek(fptr1, previous_roomposition, SEEK_SET);            /*Move the pointer of fptr1 file the value of previous_roomposition units from the start of file.*/
	fwrite(&current1, sizeof(struct room), 1, fptr1);         /*From the file, read the value*/


	fseek(fptr1, current_roomposition, SEEK_SET);             /*Move the pointer of fptr1 file the value of current_roomposition units from the start of file.*/
	fread(&current1, sizeof(struct room), 1, fptr1);          /*From the file, read the value*/
	current1.occupied = 1;                                    /*Add the occupation of current room.*/
	fseek(fptr1, current_roomposition, SEEK_SET);             /*Move the pointer of fptr1 file the value of current_roomposition units from the start of file.*/
	fwrite(&current1, sizeof(struct room), 1, fptr1);         /*From the file, read the value*/


	printf("Modify successfully");
	continue1();
	system("cls");
}

void checkout_customer()                                      /*A function to check out and figure out the whole fee for the individual customer who is booked.*/
{
	system("cls");

	FILE *fptr;                                               /*Declare a file pointer called fptr*/
	FILE *fptr1;                                              /*Declare another file pointer called fptr1*/
	struct customer current;                                  /*Declare a structure called current*/
	struct room current1;                                     /*Declare a structure called current1*/

	int satisfied, temp;                                      /*Declare two variables of int. satisfied is storing the input of whether is satisfied with the accommodation.
															  temp is storing the current room number.*/
	double customercost;                                      /*Declare a variable of double called customercost to store the cost of this customer.*/
	long position, position_room;                             /*Declare two variables of long.one is called position to store the address of customer.
															  The other is called position_room to store the address of current room.*/
	char search[31];                                          /*Declare an array of char called search to store the input ot customer name.*/


	printf("Please enter the booking customer name in order to verify\n");
	toolong(search);

	fptr = fopen(customerinfo, "rb+");	                      /*Open the file which is stored the information of customer by reading and writing.*/
	if (fptr == NULL)				                          /*Test success of file opening*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program.\n\n");
		continue1();
		exit(0);

	}
	else
	{                                                         /*Search for customer by making a comparison with the values form reading the struct arrays one by one*/
		while (fread(&current, sizeof(struct customer), 1, fptr) == 1 && (strcmp(current.name, search)))
		{
			continue;	                                      /*Continues the loop when the end of the file hasn't been reached and the name values don't both match*/
		}
	}
	if (!(strcmp(current.name, search)))	                  /*Test to see if the loop finished because the name was found*/
	{
		if (current.arrival == 0 || current.room_num == 0)     /*Check out whether the customer is already checking in or booking successfully.*/
		{
			if (current.arrival == 0)                         /*For the customer is not checking in.*/
			{
				printf("Sorry.\tThis customer does not have the record of checking in.\nTherefore,it could not perform the function of checking out.\n");
				continue1();
				system("cls");
			}
			else                                              /*For the customer is not booking.*/
			{
				printf("Sorry.\tThis customer does not have the record of room.\nTherefore,it could not perform the function of checking out.\n");
				continue1();
				system("cls");
			}
		}
		else
		{
			position = ftell(fptr);                                   /*Store the address of customer into position.*/
			printf("\n\tAlready find the information of this customer\n");

			continue1();
			system("cls");

			fseek(fptr, position - sizeof(struct customer), SEEK_SET);/*Move the pointer of fptr file the value of position minus total length units from the start of file.*/
			fread(&current, sizeof(struct customer), 1, fptr);        /*From the file, read the value*/
			temp = current.room_num;                                  /*Store the room number into the temp.*/
			fclose(fptr);


			fptr1 = fopen(roominfo, "rb+");                           /*Open the file which is stored the information of room by reading and writing.*/
			/*Search for room by making a comparison with the values form reading the struct arrays one by one*/
			while (fread(&current1, sizeof(struct room), 1, fptr1) == 1 && (current1.num != temp))
			{
				continue;	                                          /*Continues the loop when the end of the file hasn't been reached and the name values don't both match*/
			}

			position_room = ftell(fptr1);                             /*Store the address of room into position_room.*/
			fseek(fptr1, position_room - sizeof(struct room), SEEK_SET);/*Move the pointer of fptr1 file the value of position_room minus total length units from the start of file.*/
			fread(&current1, sizeof(struct room), 1, fptr1);            /*From the file, read the value*/
			customercost = current1.price * current1.discount * 0.01;   /*According to the information of room to figure out the cost of accommodation.*/
			printf("The expenditure of this customer is %.0lf\n\n", customercost);
			printf("Is the customer is satisfied with the room?\n\t'1' is Yes.\tother is NO\n");
			scanf("%d", &satisfied);                                    /*Ask whether is satisfied with the accommodation.*/
			fflush(stdin);
			if (satisfied == 1)                                         /*If so, thanks.*/
			{
				printf("Thanks understand\n");
				printf("\tThe final cost of this customer is %.0lf\n\n", customercost);
				printf("Check out successfully. Welcome next time\n");
				continue1();
				system("cls");
			}
			else                                                        /*If not, supply an extra discount for the customer.*/
			{
				printf("I am sorry to hear that.\n\n\tWe will supply an extra discount of 0.8 for this customer.");
				customercost = customercost * 0.8;                      /*Figure out the final fee.*/
				printf("\n\tThe final cost of this customer is %.0lf\n\n", customercost);
				printf("Check out successfully. Welcome next time\n");
				continue1();
				system("cls");
			}


			fseek(fptr1, position_room - sizeof(struct room), SEEK_SET);/*Move the pointer of fptr1 file the value of position1 minus total length units from the start of file.*/
			fread(&current1, sizeof(struct room), 1, fptr1);            /*From the file, read the value*/
			current1.occupied = 0;
			current1.period = 0;
			fseek(fptr1, position_room - sizeof(struct room), SEEK_SET);/*Then move the pointer to previous place*/
			fwrite(&current1, sizeof(struct room), 1, fptr1);           /*Store the new value into it.*/
			fclose(fptr1);


			fptr = fopen(customerinfo, "rb+");	                        /*Open the file which is stored the information of customer by reading and writing.*/
			fseek(fptr, position - sizeof(struct customer), SEEK_SET);  /*Move the pointer of fptr file the value of position minus total length units from the start of file.*/
			fread(&current, sizeof(struct customer), 1, fptr);          /*From the file, read the value*/


			if (current.membership == 1613489)                          /*If this customer is VIP, perform the VIP mode. Keep the indivudual information but remove
																		relevant information of accommodation.*/
			{
				current.room_num = 0;
				current.arrival = 0;
				current.days = 0;
				fseek(fptr, position - sizeof(struct customer), SEEK_SET);/*Then move the pointer to previous place*/
				fwrite(&current, sizeof(struct customer), 1, fptr);       /*Store the new value into it.*/
				fclose(fptr);
			}
			else                                                          /*If this customer is not VIP, remove all information.*/
			{
				strcpy(current.name, "0");
				strcpy(current.address, "0");
				strcpy(current.phone_number, "0");
				current.membership = 0;
				current.room_num = 0;
				current.arrival = 0;
				current.days = 0;
				fseek(fptr, position - sizeof(struct customer), SEEK_SET);/*Then move the pointer to previous place*/
				fwrite(&current, sizeof(struct customer), 1, fptr);       /*Store the new value into it.*/
				fclose(fptr);

			}
		}

	}
	else
	{
		printf("The customer is not existing.\n");
		printf("The system would force to return the previous\n");
		continue1();
		system("cls");
		fclose(fptr);
	}
}



void checkout_group()                                          /*A function to check out and figure out the whole fee for the group customer who is booked.*/
{
	system("cls");

	FILE *fptr;                                                /*Declare a file pointer called fptr*/
	FILE *fptr1;                                               /*Declare a file pointer called fptr1*/
	FILE *fptr2;                                               /*Declare a file pointer called fptr2*/
	struct group current;                                      /*Declare a structure called current*/
	struct room current1;                                      /*Declare a structure called current1*/
	struct manager current2;                                   /*Declare a structure called current2*/

	int temp[5];                                               /*Declare an array of int called temp to store the current room numbers of group.*/
	long position, position_room;                              /*Declare two variable of long. One called position to store the address of group.
															   the other is called porsition_room to store the address of room.*/
	char search[31];                                           /*Declare an array of char called search to store the input of name of group.*/
	double groupcost = 0.0;                                    /*Declare a variable called groupcost to store the whole cost of the group.*/

	printf("Please enter the booking group name in order to check out\n");
	toolong(search);

	fptr = fopen(groupinfo, "rb+");	                           /*Open the file which is stored the information of group by reading and writing.*/

	if (fptr == NULL)				                           /*Test success of file opening*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program.\n\n");
		continue1();
		exit(0);

	}
	else
	{                                                          /*Search for group by making a comparison with the values form reading the struct one by one*/
		while (fread(&current, sizeof(struct group), 1, fptr) == 1 && (strcmp(current.name, search)))
		{
			continue;	                                       /*Continues the loop when the end of the file hasn't been reached and the name values don't both match*/
		}
	}
	if (!(strcmp(current.name, search)))	                   /*Test to see if the loop finished because the name was found*/
	{
		if (current.arrival == 0)                              /*Check out whether the group is already checking in successfully.*/
		{
			printf("Sorry.\tThis group does not have the record of checking in.\nTherefore,it could not perform the function.\n");
			continue1();
			system("cls");

		}
		else
		{

			position = ftell(fptr);                                /*Store the address of group into position.*/
			printf("\n\tAlready find the information of this group\n");

			continue1();
			system("cls");

			fseek(fptr, position - sizeof(struct group), SEEK_SET);/*Move the pointer of fptr file the value of position minus total length units from the start of file.*/
			fread(&current, sizeof(struct group), 1, fptr);        /*From the file, read the value*/
			for (int i = 0; i < 5; i++)
			{
				temp[i] = current.room_num[i];                     /*Respectively store each room number into the temp.*/
			}

			fclose(fptr);


			fptr1 = fopen(roominfo, "rb+");                        /*Open the file which is stored the information of room by reading and writing.*/

			for (int i = 0; i < 5; i++)                            /*Respectively add each fee of room to the whole cost and clean the information of each
																   room accorind to the room number.*/
			{

				while (fread(&current1, sizeof(struct room), 1, fptr1) == 1 && (current1.num != temp[i]))
				{
					continue;	                                   /*Continues the loop when the end of the file hasn't been reached and the name values don't both match*/
				}
				if (current1.num == temp[i])
				{

					position_room = ftell(fptr1);                               /*Store the address of room into position_room.*/
					fseek(fptr1, position_room - sizeof(struct room), SEEK_SET);/*Move the pointer of fptr file the value of position minus total length units from the start of file.*/
					fread(&current1, sizeof(struct room), 1, fptr1);            /*From the file, read the value.*/

					fptr2 = fopen(managerinfo, "rb");	                        /*Open the file which is stored the information of manager by reading.*/
					fread(&current2, sizeof(struct manager), 1, fptr2);         /*From the file, read the value.*/

					/*Figure out the whole fee of group.*/
					groupcost += current1.price * current1.discount * 0.01* (100 - current2.discountperroom*current.rooms) * 0.01;
					fclose(fptr2);

					/*Clear information of room*/
					current1.occupied = 0;
					current1.period = 0;
					fseek(fptr1, position_room - sizeof(struct room), SEEK_SET);/*Then move the pointer to previous place.*/
					fwrite(&current1, sizeof(struct room), 1, fptr1);           /*Store the new value into it.*/
					fclose(fptr1);
				}
			}


			printf("Thanks for living.\n\tThe final cost of this group is %.0lf\n\nCheck out successfully. Welcome next time\n", groupcost);
			continue1();
			system("cls");


			fptr = fopen(groupinfo, "rb+");	                             /*Open the file which is stored the information of group by reading and writing.*/
			fseek(fptr, position - sizeof(struct group), SEEK_SET);      /*Move the pointer of fptr file the value of position minus total length units from the start of file.*/
			fread(&current, sizeof(struct group), 1, fptr);              /*From the file, read the value*/

			strcpy(current.name, "0");                                   /*Clean the information of group.*/
			strcpy(current.address, "0");
			strcpy(current.phonenumber, "0");

			for (int i = 0; i < 5; i++)                                   /*Respectively clean the information of each room number of group.*/
				current.room_num[i] = 0;

			current.arrival = 0;
			current.days = 0;

			fseek(fptr, position - sizeof(struct group), SEEK_SET);      /*Then move the pointer to previous place*/
			fwrite(&current, sizeof(struct group), 1, fptr);             /*Store the new value into it.*/
			fclose(fptr);
		}
	}
	else
	{
		printf("The group is not existing.\nThe system would force to return the previous\n");
		continue1();
		system("cls");
		fclose(fptr);
	}

}


void list_validroom()                               /*A function to print the specific and vilid room according to the type of room.*/
{
	FILE *file;                                   /*Declare a file pointer called file.*/
	struct room check;                            /*Declare a structure called check.*/
	struct room tmp;                              /*Declare a structure called tmp.*/

	int i = 0;                                    /*Declare a variable of int called i to control the number of row for showing the room.*/

	file = fopen(roominfo, "rb");             	/*Open the file which is stored the information of room by reading.*/
	if (file == NULL) 		                    /*Test the success of opening the file.*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program\n\n");
		continue1();
		exit(0);			                    /*Exit the program if it is not successful*/
	}

	fread(&tmp, sizeof(struct room), 1, file);    /*Read information of one struct from file to tmp*/
	fflush(stdin);


	printf("Please enter the type of room you want to search:\n\n\tIf you are not a VIP, you cannot book a VIP room:\n\n\t1. Single room \n\t2. Double room \n\t3. KingSize room\n\t4. VIP room\n");

	while (scanf("%d", &check.classtype) == 0)    /*Check out the input whether is illegal input.*/
	{
		printf("Invalid entry. Please try again!");
		fflush(stdin);
		continue1();
		system("cls");
		printf("Please enter the type of room you want to live:\n\n\tIf you are not a VIP, you cannot book a VIP room:\n\n\t1. Single room \n\t2. Double room \n\t3. KingSize room\n\t4. VIP room\n");
	}

	printf("The empty rooms are followed:\n");
	while (1)
	{
		/*Ensure whether there is existed residual room*/
		if (check.classtype == tmp.classtype && tmp.occupied == 0 && !feof(file))
		{
			printf("\t%d ", tmp.num);
			if (i == 4)
			{
				printf("\n\n");
				i = 0;
			}
			else
				i++;

			if (!feof(file))	                /*Ensure the information read is not at the end of file*/
			{
				fread(&tmp, sizeof(struct room), 1, file);
			}
			else							    /*The room does not exist*/
			{
				break;
			}
		}
		else
		{
			if (!feof(file))				    /*Ensure the information read is not at the end of file*/
			{
				fread(&tmp, sizeof(struct room), 1, file);
			}
			else							    /*The room does not exist*/
			{
				printf("\nThere is no other empty room of this type.");
				break;
			}
		}
	}
}

void toolong(char*search)                           /*A function to check out the input of name whether is exceeding the limit of the array of char.*/
{

	while ((scanf("%s", search) == 0) || (strlen(search) > 30))
	{                                               /*Store the input into the array of search and check out the input whether is too long to exceed the limit.*/
		printf("Please try again and make sure the names is less than 30 characters long.\n");
		fflush(stdin);
		continue1();                                /*Call the function called continue1 for pushing the bottom to continue.*/
		system("cls");
		printf("Please enter the booking customer name again in order to verify\n");
	}
	fflush(stdin);
}

#include "Booking.h"						//Details about head file is explaned in each head file
#include "Menu.h"
#include "Checker.h"
#include "Manager.h"



//A function to enter the manager account and obtain manager access
void manager() {

	system("cls");
	fflush(stdin);

	int option = 0, stage = 0;						//receive the option and detect the status
	char choice;									//also use to receive the option


	if (checkmanager() == -1) {						//check if the user enter the correct password
		return;
	}

	else {											//password correct

		while (stage == 0) {						//enter a loop to keep the program till the user selects quit
			system("cls");
			fflush(stdin);
			//ask for a choice
			printf("Hello boss,\nWhat do you want to do?"
				"\n\t1. View or set the room info or the price of each classtype\n\t2. Set the discount\n\t3. Manage the customer database"
				"\n\t4. View hotel business statistics\n\t5. Initialize the system\n\t6. Back to Menu\n");

			// Get user's choice and check user input validity
			while (scanf("%d", &option) != 1 || (option < 1 || option>6)) {
				system("cls");
				printf("Invalid input\nHello boss,\nWhat do you want to do?"
					"\n\t1. View or set the room info or the price of each classtype\n\t2. Set the discount\n\t3. Manage the customer database"
					"\n\t4. View hotel business statistics\n\t5. Initialize the system\n\t6. Back to Menu\n");
				fflush(stdin);
			}


			fflush(stdin);

			switch (option)														//switch used to perform selection	
			{
			case 1: setroom();													//for each case, call the correspond function
				break;
			case 2:setdiscount();
				break;
			case 3:mancusdat();
				break;
			case 4:viewstatistic();
				break;
			case 5:printf("Are you sure to initialize the system?\nPress 'Y' or other keys to return.");		//initialize the system by call four functions
				scanf("%c", &choice);
				if (choice == 'y' || choice == 'Y') {
					initialize_room();
					initialize_manager();
					initialze_customer();
					initialize_group();
					printf("Success!");
					continue1();
				}
				break;

			case 6: stage = 1;													//back to last menu
				break;
			}
		}
	}
}

/*A function to check manager's password
return 1 represent correct, -1 represent give up log in*/
int checkmanager() {
	char pass[8];																//reveive the user's input
	int i = 0;																	//store the number of the input

	printf("\n\nPlease enter your password(7 digit) or press 'q' to quit: ");	//ask for the password

	while (1) {

		while (i < 8 && (pass[i++] = getch()) != '\r') {						//Enter a loop to value the employee number string, the loop end when over 6 digits or enter '\r'
			putchar('*');
			if (pass[0] == 'q' || pass[0] == 'Q')								//press q to quit
				return -1;
		}
		if (pass[7] == '\r') {
			pass[7] = '\0';														//Set the last element of the string and the counter
			i = 0;
		}

		if (!strcmp(pass, manager_pass)) {										//correct password
			return 1;
		}
		else {
			printf("\nWrong password. Please try again or press '!' to quit");	//ask for another input
			i = 0;
		}
	}
}

//A function to manage the customers accounts
void mancusdat() {
	int option = 0, i, stage = 0;

	while (stage == 0){
		system("cls");																//ask for input
		printf("What would you like to do?\n"
			"\t1. Add a guest\n\t2. Edit guest information"
			"\n\t3. Remove a guest\n\t4. List guest info\n\t5. View the group booking\n\t6. Back to last menu\n");

		// Get user's choice and check user input validity
		while (scanf("%d", &option) != 1 || (option < 1 || option>6)) {
			system("cls");
			printf(" Invalid input\nWhat do you want to do,\n\t"
				"What would you like to do?\n"
				"\t1. Add a guest\n\t2. Edit guest information"
				"\n\t3. Remove a guest\n\t4. List guest info\n\t5. View the group booking\n\t6. Back to last menu\n");
			fflush(stdin);
		}

		switch (option)																//switch used to perform selection	
		{
		case 1: register_guest();													//call function to add a guest
			break;
		case 2:edit_guest();														//call function to edit the existed account
			break;
		case 3:remove_guest();														//call function remove an account
			break;
		case 4:
			viewcus(2);															//call function to list all the customes
			continue1();
			break;
		case 5:view_group();														//call functiont to list all groupbooking
			continue1();
			break;
		case 6:stage = 1;															//back to last menu
			break;
		}
	}
}

//A function to list all the vacant rooms with certain classtype
void list_all_vacant()
{
	int check, stage = 0;
	struct room tmp;
	FILE *fptr;

	fptr = fopen(roominfo, "rb");	/*the file is opened to check the entries existed in it*/

	if (fptr == NULL) 		/*Test the success of opening the file*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program\n\n");
		Sleep(2000);
		exit(0);			/*exit the program if it is not successful*/
	}



	while (stage == 0){
		rewind(fptr);									/*rewind the file pointer every time start the loop*/
		fread(&tmp, sizeof(struct room), 1, fptr);		/*read information of one struct from file to tmp*/

		fflush(stdin);
		system("cls");
		printf("Please enter the type of room you want to search:\n\n\t");			/*Obtain each structure member' playername checking each for validity*/
		printf("1. Single room \n\t2. Double room \n\t3. KingSize room\n\t4. VIP room\n\t5. Back\n ");
		while (scanf("%d", &check) == 0 || check<1 || check>5){
			fflush(stdin);
			system("cls");
			printf("Invalid entry. Please try again!");
			printf("Please enter the type of room you want to live:\n\n\t");
			printf("1. Single room \n\t2. Double room \n\t3. KingSize room\n\t4. VIP room\n\t5. Back\n");
		}
		int i = 0;
		switch (check)
		{
		case 5:stage = 1;																	/*jump out of the loop*/
			break;
		default:	printf("The empty rooms are followed:\n");
			while (1){

				if (check == tmp.classtype && tmp.occupied == 0 && !feof(fptr))			/*Ensure whether there is existed player name*/
				{

					printf("\t%d ", tmp.num);								/*print 5 rooms on one line*/
					if (i == 4) {
						printf("\n\n");
						i = 0;
					}
					else
						i++;

					if (!feof(fptr))										/*Ensure the information read is not at the end of file*/
						fread(&tmp, sizeof(struct room), 1, fptr);
					else
						break;
				}
				else{

					if (!feof(fptr))										/*Ensure the information read is not at the end of file*/
						fread(&tmp, sizeof(struct room), 1, fptr);
					else{
						printf("\nThere is no other empty room of this type.");			/*Reach the end of the file*/
						break;
					}
				}
			}
			continue1();
			break;
		}
	}
	fclose(fptr);
	continue1();
	return;
}

//A function to view the statistic of the hotel
void viewstatistic() {
	int option, stage = 0;																//receive choice

	while (stage == 0) {
		system("cls");
		fflush(stdin);

		printf("What do you want to do,\n\t"										//ask for input
			"1. View the VIP customers' information\n\t"
			"2. View other customers' informaton\n\t"
			"3. View group booking\n\t"
			"4. View one certain room information\n\t"
			"5. View vacant room\n\t"
			"6. View total benefit\n\t"
			"7. Back to last menu\n");

		// Get user's choice and check user input validity
		while (scanf("%d", &option) != 1 || (option < 1 || option>7)) {
			system("cls");
			printf(" Invalid input\n\t"
				"What do you want to do,\n\t"
				"1. View the VIP customers' information\n\t"
				"2. View other customers' informaton\n\t"
				"3. View group booking\n\t"
				"4. View one certain room information\n\t"
				"5. View vacant room\n\t"
				"6. View total benefit\n\t"
				"7. Back to last menu\n");
			fflush(stdin);
		}

		switch (option) {																//perform a selection

		case 1: viewcus(1);																//call function to view VIP customer
			continue1();
			break;
		case 2: viewcus(2);																//call function to view common customer									
			continue1();
			break;
		case 3:view_group();															//call function to view groupbooking customer
			continue1();
			break;
		case 4:view_roominfo();															//call function to view one certain room's info
			continue1();
			break;
		case 5:list_all_vacant();														//call fucntionlist all the vacant room of certain classtype
			break;
		case 6:viewbenefit();															//call fucntion to view the total benefit
			continue1();
			break;
		case 7:stage = 1;																//back to last menu
			break;
		}
	}
}

//view the total benefit of the hotel
void viewbenefit() {														//open the manager account and read the benefit from the file
	FILE *fptr;
	int new;
	struct manager current;
	fptr = fopen(managerinfo, "rb");
	fread(&current, sizeof(struct manager), 1, fptr);
	printf("The current total benefit is %d", current.total_benefit);		//print out the benefit on the screen
}

/*A function to view the customers' list in terms of different requirements
receive the judge to type different kinds of customers*/
void viewcus(int judge) {
	FILE *fptr;
	int option, stage = 0, count;
	struct customer current;

	fopen(customerinfo, "rb");

	if (judge == 1) {														//list all the VIP
		int count;
		count = listcus(VIPcus);												//call funciton to list VIP
		if (count == 0) {
			printf("\n\nNo VIP customer now.");								//count==0 means ther's no VIP customer
		}
		else{
			printf("There are %d VIP customers in total.", count);				//print the number of the VIP
		}
	}

	if (judge == 2) {														//list common customer 

		while (stage == 0) {
			system("cls");
			fflush(stdin);

			printf("You want to view the customer living in:\n"				//ask for choice
				"\n\t1. Single\n\t2. Double\n\t3. KingSize\n\t4. VIP\n\t5. List all"
				"\n\t6. Back to last menu\n");

			// Get user's choice and check user input validity
			while (scanf("%d", &option) != 1 || (option < 1 || option>6)) {
				system("cls");
				printf(" Invalid input\nWhat do you want to do,\n\t"
					"You want to view the customer living in:\n"
					"\n\t1. Single\n\t2. Double\n\t3. KingSize\n\t4. VIP\n\t5. List all"
					"\n\t6. Back to last menu\n");
				fflush(stdin);
			}

			switch (option){																//perfomer a selection
			case 1:count = listcus(Single);													//call function and pass Single to list the customer live in Single Room
				if (count == 0)																//count==0 means ther's no common customer
					printf("\nNo one live in Single Room.");

				else
					printf("\nThere are %d people living in Single Room.", count);			//print the number of people living in Single Room

				continue1();
				break;
			case 2:count = listcus(Double);													//all the same as before
				if (count == 0)
					printf("\nNo one live in Double Room.");

				else
					printf("\nThere are %d people living in Double Room.", count * 2);

				continue1();
				break;
			case 3:count = listcus(KingSize);												//all the same as before
				if (count == 0)
					printf("\nNo one live in KingSize Room.");

				else
					printf("\nThere are %d people living in KingSize Room.", count * 2);

				continue1();
				break;
			case 4:count = listcus(VIP);													//all the same as before
				if (count == 0)
					printf("\nNo one live in VIP Room.");

				else
					printf("\nThere are %d people living in VIP Room.", count * 2);

				continue1();
				break;
			case 5:count = listcus(all);													//all the same as before
				if (count == 0)
					printf("\nThere is no rooms has been occupied.");

				else
					printf("\nThere are %d rooms has been occupied.", count);

				continue1();
				break;
			case 6:stage = 1;																//back to last menu
				break;

			}
		}
	}
}

/*A function to list certain kind of customer according to the value of judge
receive the kinds of the customer needs to be listed
return how many customers are printed out*/
int listcus(int judge) {
	FILE *fptr, *fptr_room;
	struct customer current;
	struct room current_room;
	int count = 0;
	long position;																	//store the position of certain room in the file


	fptr = fopen(customerinfo, "rb");
	fptr_room = fopen(roominfo, "rb");

	while (fread(&current, sizeof(struct customer), 1, fptr) == 1) {				//traverse all the customers in the file 

		if ((current.phone_number != 0) && judge != 99) {							//if the customer hasn't been check out of the user don't want to list all the customers

			position = find_room(current.room_num);									//find the position of the room by calling find_room()

			fseek(fptr_room, position, SEEK_SET);									//move the file pointer to that room
			fread(&current_room, sizeof(struct room), 1, fptr_room);				//read the room info


			if (judge == VIPcus){														//list VIP customers
				switch (current.membership) {
				case 0:																//don't need to list the common customer
					break;
				default:listpart(&current);											//call listpart() to list the current customer
					count++;														//count this customer
					break;
				}
			}
			else{
				if (judge == current_room.classtype) {								//list the common customer living in the certain classtypes
					listpart(&current);
					count++;
				}
			}
		}

		else {																		//judge==99 means list all customers
			if (current.phone_number != 0) {
				listpart(&current);
				count++;
			}
		}
	}

	fclose(fptr);
	return count;																	//return how many customers has been printed out
}

/*A function to list one customer
receive the address of the struct needs to be printed*/
void listpart(struct customer *current) {

	printf("\tName: %s\n\t"																//print out the name, room number and living days of this customer
		"Room Number: %d\n\t"
		"Living Days: %d\n\t", current->name, current->room_num, current->days);
	if (current->arrival == 1) {														//print if the customer has arrived
		printf("Has arrived\n\n");
	}
	else {
		printf("Hasn't arrived\n\n");
	}
	return;
}

//A function to view or set the discount 
void setdiscount() {
	system("cls");
	fflush(stdin);

	int stage = 0, option = 0;

	while (stage == 0) {
		system("cls");
		fflush(stdin);

		printf(" What do you want to do,\n\t"													//ask for choice
			"1. View the discount of certain room\n\t"
			"2. Change the discout of certain room\n\t"
			"3. Change the groupbooking discount\n\t"
			"4. Back to last menu\n");

		// Get user's choice and check user input validity
		while (scanf("%d", &option) != 1 || (option < 1 || option>4)) {
			system("cls");
			printf(" Invalid input\nWhat do you want to do,\n\t"
				" What do you want to do,\n\t"
				"1. View the discount of certain room\n\t"
				"2. Change the discout of certain room\n\t"
				"3. Change the groupbooking discount\n\t"
				"4. Back to last menu\n");
			fflush(stdin);
		}


		//perform a selection by call correspond function
		switch (option) {
		case 1: view_roominfo();
			continue1();
			break;
		case 2: change_room_price_discount(3);
			continue1();
			break;
		case 3:change_discount_perroom();
			continue1();
			break;
		case 4:stage = 1;
			break;
		}
	}
}

//A function to change the discount of groupbooking
void change_discount_perroom() {
	FILE *fptr;
	struct manager current;
	int new;

	fptr = fopen(managerinfo, "rb+");
	fread(&current, sizeof(struct manager), 1, fptr);
	printf("The current discount is %d %%, \nPlease enter the new discount per room (over 0)", current.discountperroom);  //read the current diacount from the file

	while (scanf("%d", &new) != 1 || (new<1)) {																			//ask for a new discount
		system("cls");
		printf("Invalid input\nThe current discount is %d %%,"
			"\nPlease enter the new discount per room or press 0 to quit", current.discountperroom);
		fflush(stdin);
	}
	if (new == 0) {
		fclose(fptr);
		return;
	}

	current.discountperroom = new;
	rewind(fptr);
	fwrite(&current, sizeof(struct manager), 1, fptr);																		//rewrite the file with new discount
	fclose(fptr);

	printf("Success!");
	return;
}

//A function to view or change the price or classtype of the rooms
void setroom() {

	system("cls");
	fflush(stdin);

	int stage = 0, option = 0;

	while (stage == 0) {
		system("cls");
		fflush(stdin);

		printf(" What do you want to do,\n\t"															//ask for choice
			"1. View the information of the room\n\t"
			"2. Change the price of the room\n\t"
			"3. Change the class of the room \n\t"
			"4. Change the price of one classtype\n\t"
			"5. Back to last menu\n");

		// Get user's choice and check user input validity
		while (scanf("%d", &option) != 1 || (option < 1 || option>5)) {
			system("cls");
			printf(" Invalid input\nWhat do you want to do,\n\t"
				"1. View the information of the room\n\t"
				"2. Change the price of the room\n\t"
				"3. Change the class of the room \n\t"
				"4. Change the price of one classtype\n\t"
				"5. Back to last menu");
			fflush(stdin);
		}


		switch (option) {
		case 1: view_roominfo();																	//view certain room's info
			continue1();
			break;
		case 2:change_room_price_discount(1);														//1 represent change price of room
			continue1();
			break;
		case 3:change_room_price_discount(2);														//2 represent change the of room
			continue1();
			break;
		case 4: change_view_class();																//view or change price for certain class
			continue1();
			break;
		case 5:stage = 1;																			//back to last menu
			break;
		}
	}
}

//A function to view or change the price of certain classtype
void change_view_class() {
	FILE *fptr;
	int option = 0, stage = 0;
	struct manager managercount;
	char class[10];

	fptr = fopen(managerinfo, "rb+");
	rewind(fptr);
	fread(&managercount, sizeof(struct manager), 1, fptr);

	system("cls");
	fflush(stdin);
	while (stage == 0) {																						//ask for choice
		system("cls");
		printf("Please choose: \n\t1.View the price of all the class\n\t"
			"2.Change the price for certain class\n\t3.Back to last menu\n");

		// Get user's choice and check user input validity
		while (scanf("%d", &option) != 1 || (option < 1 || option>3)) {
			system("cls");
			printf("Invalid input\nPlease choose: \n\t1.View the price of all the class\n\t"
				"2.Change the price for certain class\n\t3.Back to last menu\n");
			fflush(stdin);
		}


		switch (option) {
		case 1:system("cls");																					//open the manager account and display the price for all classtypes
			rewind(fptr);
			fread(&managercount, sizeof(struct manager), 1, fptr);
			printf("The prices for each class are as followed"
				"\n\tSingle Room %d \n\tDouble Room %d\n\tKingSize Room %d \n\tVIP Room %d\n\t"
				, managercount.pricefor1, managercount.pricefor2, managercount.pricefor3, managercount.pricefor4);
			continue1();
			break;
		case 2:change_class_price();													//call function to change the pricr for certain classtype
			continue1();
			break;
		case 3: stage = 1;																						//back to last menu
			break;
		}
	}
}

//A function to change the price of certain classtype chosen by user
void change_class_price() {
	FILE *fptr;
	int new, old, option = 0;																		//two variables to store the new and the old price
	char class[10];																				//store the classtype name
	struct manager managercount;
	system("cls");

	fptr = fopen(managerinfo, "rb+");
	rewind(fptr);
	fread(&managercount, sizeof(struct manager), 1, fptr);


	printf("Please choose whose price do you want to change: "								//ask for choice
		"\n\t1. Single Room\n\t2. Double Room\n\t3. KingSize Room\n\t"
		"4. VIP Room\n\t5. Back to last menu\n");

	// Get user's choice and check user input validity
	while (scanf("%d", &option) != 1 || (option < 1 || option>5)) {
		system("cls");
		printf("Invalid input\nPlease choose whose price do you want to change: "
			"\n\t1. Single Room\n\t2. Double Room\n\t3. KingSize Room\n\t"
			"4. VIP Room\n\t5. Back to last menu\n");
		fflush(stdin);
	}

	//value the string with the classtype name chosen by user, and achieve the original price
	switch (option) {
	case 1:strcpy(class, "Single");
		new = managercount.pricefor1;
		break;
	case 2:strcpy(class, "Double");
		new = managercount.pricefor2;
		break;
	case 3:strcpy(class, "KingSize");
		new = managercount.pricefor3;
		break;
	case 4:strcpy(class, "VIP");
		new = managercount.pricefor4;
		break;
	case 5:return;
	}

	printf("The price for %s is %d. Please enter the new price(over 0): ", class, new);					//ask for a new price

	// Get user's choice and check user input validity
	while (scanf("%d", &new) != 1 || new<0) {
		system("cls");
		printf("Invalid input\nThe price for %s is %d. Please enter the new price or press 0 to quit: ", class, new); //press 0 to quit
		fflush(stdin);
	}
	if (new == 0) {
		fclose(fptr);
		return;
	}

	//store the old price for later use, value the new price into the struct
	switch (option) {
	case 1:old = managercount.pricefor1;
		managercount.pricefor1 = new;
		break;
	case 2:old = managercount.pricefor2;
		managercount.pricefor2 = new;
		break;
	case 3:old = managercount.pricefor3;
		managercount.pricefor3 = new;
		break;
	case 4:old = managercount.pricefor4;
		managercount.pricefor4 = new;
		break;
	}

	rewind(fptr);
	fwrite(&managercount, sizeof(struct manager), 1, fptr);								//update the manager file
	fclose(fptr);
	change_for_all_room(option, new, old);												//call function to change the price of room of the classtype chosen before,using the new price
	printf("Success!");
	return;
}

/*A fuction to change the price of all the rooms with the same classtype
receive the old and the new price and the classtype chosen by user*/
void change_for_all_room(int option, int new, int old) {
	FILE *fptr;
	struct room current;

	fptr = fopen(roominfo, "rb+");

	while (fread(&current, sizeof(struct room), 1, fptr) == 1){					//	traverse all the rooms in the file

		if ((option == current.classtype) && (current.price == old)){				//if the current room has the same classtype and its price haven't been changed by manager
			current.price = new;												//change to the new value

			fseek(fptr, -sizeof(struct room), SEEK_CUR);
			fwrite(&current, sizeof(struct room), 1, fptr);						//update the room info
			fseek(fptr, 0, SEEK_CUR);
		}
	}
	fclose(fptr);
}

//A function to change the discount of groupbooking
void change_room_price_discount(int judge) {											//judge==1 change price ,2 change class , 3 change discount
	system("cls");
	fflush(stdin);

	FILE *fptr;

	int roomnum, new;																	//store the room number and the new discount
	long position;																	//store the posotion of the file pointer
	struct room currentroom;
	char class[10];																		//store the classtype name


	position = find_room(-1);                                                           //find the position of the file pointer of the certain room
	if (position == -1) {
		printf("The room you find does not exit.");										//didn't find it
		return;
	}
	else {

		fptr = fopen(roominfo, "rb+");

		fseek(fptr, position, SEEK_SET);
		fread(&currentroom, sizeof(struct room), 1, fptr);

		if (judge == 1) {
			printf("The real time prices is %d.\nPlease enter the new price(over 0): "			//ask for new price
				, currentroom.price);

			// Get user's choice and check user input validity
			while (scanf("%d", &new) != 1 || new < 0) {
				system("cls");
				printf("Invalid input\nThe real time prices is %d.\n"
					"Please enter the new price or press 0 to quit", currentroom.price);
				fflush(stdin);
			}
			if (new == 0) {
				fclose(fptr);																//press 0 to quit
				return;
			}

			currentroom.price = new;
			fseek(fptr, position, SEEK_SET);
			fwrite(&currentroom, sizeof(struct room), 1, fptr);								//update the room file
			fclose(fptr);
			printf("Success!");


		}

		if (judge == 2) {																	//change the class of the certain room

			//value the string with the classtype name chosen by user
			switch (currentroom.classtype) {
			case 1: strcpy(class, "Single");
				break;
			case 2: strcpy(class, "Double");
				break;
			case 3: strcpy(class, "KingSize");
				break;
			case 4: strcpy(class, "VIP");
				break;
			}

			printf("The class of is %s.\nPlease choose the new class:\n"
				"\t1. Single\n\t2. Double\n\t3. KingSize\n\t4. VIP\n"						//ask for a new classtype
				, class);

			// Get user's choice and check user input validity
			while (scanf("%d", &new) != 1 || (new<1 || new>4)) {
				system("cls");
				printf("The real time prices is %d.\n"
					"Please enter the new price or press 0 to quit", currentroom.price);
				fflush(stdin);
			}
			if (new == 0) {																	//press 0 to quit
				fclose(fptr);
				return;
			}

			currentroom.classtype = new;
			fseek(fptr, position, SEEK_SET);
			fwrite(&currentroom, sizeof(struct customer), 1, fptr);							//update the file
			fclose(fptr);
			printf("Success!");
		}

		if (judge == 3) {																		//ask for a new discount
			printf("The real time discount is %d %%.\nPlease enter the new price: "
				, currentroom.discount);

			// Get user's choice and check user input validity
			while (scanf("%d", &new) != 1 || (new<0 || new>100)) {
				system("cls");
				printf("The real time discount is %d (over 0).\n"
					"Invalid input\nPlease enter the new price or press 0 to quit", currentroom.price);
				fflush(stdin);
			}
			if (new == 0) {																	//press 0 to quit
				fclose(fptr);
				return;
			}

			currentroom.discount = new;
			fseek(fptr, position, SEEK_SET);
			fwrite(&currentroom, sizeof(struct room), 1, fptr);								//update the file
			fclose(fptr);
			printf("Success!");
		}

	}
}

//A function to view the info of certain room
void view_roominfo() {

	system("cls");
	fflush(stdin);

	FILE *fptr;

	int roomnum;																		//store the room number
	long position;																		//store the posotion of the file pointer
	struct room currentroom;
	char class[10];																		//store the classtype name

	position = find_room(-1);															//find the position of the room in the ffile

	if (position == -1) {																//didn't find it
		printf("\nThe room you find does not exit.\n");
		Sleep(1500);
		return;
	}
	else {

		fptr = fopen(roominfo, "rb+");
		fseek(fptr, position, SEEK_SET);

		fread(&currentroom, sizeof(struct room), 1, fptr);

		//value the string with the classtype name chosen by user
		switch (currentroom.classtype) {
		case 1: strcpy(class, "Single");
			break;
		case 2: strcpy(class, "Double");
			break;
		case 3: strcpy(class, "KingSize");
			break;
		case 4: strcpy(class, "VIP");
			break;
		}
		fflush(stdin);

		printf("\tRoom %d \n\tClass %s\n\tPrice %d\n\tDiscount %d %%\n\t",					//display all the info read from the file
			currentroom.num, class, currentroom.price, currentroom.discount);

		if (currentroom.occupied == 0) {
			printf("Available\n\t");
		}
		else {
			printf("Has been reserved for %d day", currentroom.period);
		}
	}
	return;
}


/*Find a certain room
Receive the roomnumber
return the position of FILE pointer if room exit*/
long find_room(int num) {

	long position = 0;					//Declare a long variable to store the position of the file pointer
	int roomnum;
	char choice;
	struct room currentroom;

	fflush(stdin);

	FILE *fptr;						//Declare a file pointer

	if (num == -1) {				//means the room number needs to entered by user
		printf(" Please enter the room you want to search(100-599): ");

		// Get user's choice and check user input validity
		while (scanf("%d", &roomnum) != 1 || (roomnum < 100 || roomnum>599)) {
			system("cls");
			fflush(stdin);
			printf(" Invalid input.\n Please try again or press 0 to quit. ");
		}
		if (roomnum == 0)				//press 0 to quit
			return -1;
	}
	else
		roomnum = num;


	fptr = fopen(roominfo, "rb");	//Having read the user-wanted room number, open the file (read binary only)

	if (fptr == NULL) {				//Test success of file opening
		printf("\nSomething wrong with opening the file, please restart the program\n\n");
		exit(1);
	}

	else {
		/*Read the "struct room" from the file one by one and store in variable "current" of the type of struct room'
		Then make comparison between current.num with
		the player-wanted room num entered before, the loop end if two num are the same,
		or the end of the file is reached and return the EOF value.*/
		while (fread(&currentroom, sizeof(struct room), 1, fptr) == 1 && currentroom.num != roomnum)
			continue;		//Continue the loop when the name value don't match or the end of the file hasn't been reached
	}

	position = ftell(fptr);		//Record the number of bytes from the beginning of the file.
	position -= sizeof(struct room);
	fclose(fptr);				//Close the file


	if (currentroom.num == roomnum)		//If find the room number 
		return position;							//return the position of file pointer
	else
		return -1;									//else return failure
}

//A function to enter the menu of groupbooking
void group_book() {
	int option, stage = 0;																			//reveive the option and detect status

	while (stage == 0) {

		system("cls");
		fflush(stdin);
		//ask for option
		printf("What do you want to do?"
			"\n\t1. Create a new group booking"
			"\n\t2. View the existed group booking\n\t3. Back to last menu\n");
		// Get user's choice and check user input validity
		while (scanf("%d", &option) != 1 || (option<1 || option>5)) {
			system("cls");
			printf("Invalid input\nHello boss,\nWhat do you want to do?"
				"What do you want to do?"
				"\n\t1. Create a new group booking"
				"\n\t2. View the existed group booking\n\t3. Back to last menu\n");
			fflush(stdin);
		}

		//perform the funciton by call correspond function
		switch (option)
		{
		case 1:creat_group();
			continue1();
			break;
		case 2:view_group();
			continue1();
			break;
		case 3:stage = 1;
			break;
		}
	}
	return;
}

//A function to view the info of all the groupbooking customers
void view_group() {
	FILE *fptr;
	struct group current;
	fptr = fopen(groupinfo, "rb");
	if (fread(&current, sizeof(struct group), 1, fptr) == 0) {											//no groupbooking in the file
		printf("There's no group booking");
	}
	else {
		rewind(fptr);
		printf("All the group booking are as followed");

		while (fread(&current, sizeof(struct group), 1, fptr) == 1) {									//traverse all the group booking and print them out

			printf("\n\tName: %s\n\tPhone number: %s\n\tRoom:", current.name, current.phonenumber);		//display name and phone number

			for (int i = 0; i < 5; i++) {
				if (current.room_num[i] != 0) {
					printf("%d  ", current.room_num[i]);												//display room number
				}
			}
			printf("\n\tBook for %d days\n\t", current.days);											//display booking days

			if (current.arrival == 0)
				printf("Hasn't arrived\n\n");
			else
				printf("Has arrived\n\n");
		}
	}
}

//A function to make a groupbooking
void creat_group() {
	FILE *fptr_gr, *fptr_ro;																		//file pointer for room file and group file
	struct group current_gr;
	struct room current_ro;
	char current_name[31], choice;
	int stage = 1, count;
	long position;

	fflush(stdin);
	system("cls");
	printf("!!!!The group can't be canceled or edited. Please be careful when booking!!!!\n");

	printf("\n\nPlease enter your name: ");					//Ask for new account's name
	fptr_gr = fopen(groupinfo, "rb");							//Open the file in read binary only

	if (fptr_gr == NULL) {										//Test the success of file opening
		printf("\nSomething wrong with opening the file, please restart the program\n\n");
		exit(1);
	}

	else {
		while (1) {												//Enter a while loop to keep the program running until receive a vaild new account name

			scanf("%s", current_name);					//Read a user-wanted name from keyboard
			//Check if the name has existed. The logic is the same as previous one in line 159
			while (fread(&current_gr, sizeof(struct group), 1, fptr_gr) == 1 && ((strcmp(current_name, current_gr.name))))
				continue;

			if (!(strcmp(current_name, current_gr.name))) {	//If the name has been occupied, remind the user
				printf("\n\nThis account has been created, please try another: ");
			}

			else {
				//If the name dosen't be used, check the validity of it
				if (strlen(current_name) > 30 || strlen(current_name) < 1) {
					system("cls");
					fflush(stdin);
					printf("\n\nInvalid input,\nPlease enter your name again: ");
				}
				else {
					strcpy(current_gr.name, current_name);
					break;				//If the name is either repeated or invalid, break the while and set the password
				}
			}
		}
	}

	fflush(stdin);
	fclose(fptr_gr);
	system("cls");

	printf("Dear %s \nPlease enter how many rooms do you want to book(2-5): ", current_gr.name);   //ask for the room number

	// Get user's choice and check user input validity
	while (scanf("%d", &current_gr.rooms) != 1 || (current_gr.rooms < 2 || current_gr.rooms>5)) {
		system("cls");
		printf("Invalid input\n"
			"Dear %s \nPlease enter how many rooms do you want to book(2-5): ", current_gr.name);
		fflush(stdin);
	}

	fflush(stdin);
	fptr_ro = fopen(roominfo, "rb");

	for (int j = current_gr.rooms; j < 5; j++)						//initilize the room that won't be entered by user
		current_gr.room_num[j] = 0;

	for (int i = 0; i < current_gr.rooms; i++) {
		fflush(stdin);
		system("cls");
		printf("\nPlease enter the %dth room you want to book (100-599): ", i + 1);
		printf("\n\nYou can view the vacant room here.\nPress 'Y' or other keys to continue.");
		scanf("%c", &choice);
		if (choice == 'y' || choice == 'Y') {
			list_all_vacant();																		//view the vacant room
		}
		system("cls");
		printf("\nPlease enter the %dth room you want to book (100-599): ", i + 1);

		stage = 1;

		while (stage) {
			scanf("%d", &current_gr.room_num[i]);													//set the i th room

			if ((current_gr.room_num[i] < 100 || current_gr.room_num[i]>599)) {
				printf("Invalid input"
					"\n\nPlease try again (100-599): ");
			}
			else {

				if (checkroom(current_gr.room_num[i])) {											//ask for room num
					printf("The room you chose has been occupied or don't exist"
						"\nPlease try again: ");
				}
				else {
					occupy_room(current_gr.room_num[i]);											//undate the room info
					stage = 0;
					break;
				}
			}
		}
	}

	system("cls");
	fflush(stdin);
	printf("Dear %s\nPlease enter your address: ", current_gr.name);

	while (scanf("%s", current_gr.address) == 0 || strlen(current_gr.address) > 30) {								//set address
		printf("Invalid input\nDear %s\nPlease enter your address or press 0 to quit : ", current_gr.name);
		fflush(stdin);
	}
	if (current_gr.address[0] == 0)
		return;

	system("cls");
	fflush(stdin);
	printf("Dear %s\nPlease enter your phone number(less than 15 digit): ", current_gr.name);	//set phonenumber
	while (scanf("%s", current_gr.phonenumber) == 0 || strlen(current_gr.phonenumber) > 15 || (strspn(current_gr.phonenumber, "0123456789") != strlen(current_gr.phonenumber))) {
		system("cls");
		printf("Invalid input\nHello boss,\nWhat do you want to do?"
			"Dear %s\nPlease enter your phone number(less than 15 digit): ");
		fflush(stdin);
	}

	system("cls");
	fflush(stdin);
	printf("Dear %s\nPlease enter how many days do you want to live: ", current_gr.name);					//set living days
	while (scanf("%d", &current_gr.days) != 1 || current_gr.days < 1) {
		system("cls");
		printf("Invalid input\nHello boss,\nWhat do you want to do?"
			"What do you want to do?"
			"Dear %s\nPlease enter how many days do you want to live: ");
		fflush(stdin);
	}

	current_gr.arrival = 0;

	fclose(fptr_ro);
	fopen(groupinfo, "ab+");
	fwrite(&current_gr, sizeof(struct group), 1, fptr_gr);													//write into the file
	fclose(fptr_gr);

}

//A function to set the room state as occupied
void occupy_room(int num){
	FILE *fptr;
	struct  room current;

	fptr = fopen(roominfo, "rb+");
	long position;																			//Declare a long variable to store the position of the file pointer

	position = find_room(num);																	//change the occupied from to 1
	fseek(fptr, position, SEEK_SET);
	fread(&current, sizeof(struct room), 1, fptr);
	current.occupied = 1;
	fseek(fptr, position, SEEK_SET);
	fwrite(&current, sizeof(struct room), 1, fptr);												//update the file

	fclose(fptr);
}

/*A function to check if the room has been occupied
receive the room num
return 1 represent occupied, 0 represent vavant*/
int checkroom(int num) {
	FILE  *fptr_ro;

	struct room current_ro;
	long position;
	int stage = 0;
	fptr_ro = fopen(roominfo, "rb");

	if (find_room(num) == -1)													//try to find the proom
		return 1;																//didn't find it
	else {
		position = find_room(num);												//find the position of file pointer
		fseek(fptr_ro, position, SEEK_SET);
		fread(&current_ro.num, sizeof(struct room), 1, fptr_ro);

		if (current_ro.occupied == 1) {
			return 1;															//occupied
		}
		else {
			return 0;															//vacant

		}
	}
}


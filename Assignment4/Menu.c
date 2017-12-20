#include "Booking.h"		//Details about head file is explaned in each head file
#include "Menu.h"
#include "Checker.h"
#include "Manager.h"


int main() {
	int option=0,stage=0;                                                      //two int variable to receive option and detect status
	char choice;

	while (stage==0)													//enter a loop to keep the program till the user selects quit
	{
		system("cls");
		printftime();													//print the time at present
		
		printf("\nWelcome to EEE HOTEL"									//ask for a choice
				". \nPlease choose your role"
				"\n\t1. Manager\n\t2. Staff\n\t3. Exit\n");

		// Get user's choice and check user input validity
		while (scanf("%d", &option) != 1 || (option<1 || option>4)) {
			system("cls");
			printf("\n\nInvalid choice\n\nWelcome to EEE HOTEL"
				"\n\tPlease choose your role"
				"\n\t1. Manager\n\n2. Staff\n\n3. Exit");
			fflush(stdin);
		}

		fflush(stdin);

		switch (option)													//switch used to perform selection	
		{
		case 1: manager();												//call function manager() to obtain manager access
			break;
		case 2: staff();												//call function booking() to make a book or check in/out a customer
			break;
		case 3: stage = 1;												//close the program	
			break;
		case 4: 
											    /*!!!Hidden function, used to initialize the system!!!*/
			printf("!!Hidden Function!!\nAre you sure to initialize the system?\nPress 'Y' or other keys to return.");
			scanf("%c", &choice);
			if (choice == 'y' || choice == 'Y') {
				initialize_room();										//call four functions to initialize four files
				initialize_manager();
				initialze_customer();
				initialize_group();
				printf("Success!");
				continue1();
			}
			break;
		}
	}
	return 0;
}

//A fundtion to press any key to continue
void continue1() {
	printf("\nPress any key to continue\n");
	getch();
	fflush(stdin);
}

//log in a staff account choose to book a room or check on/out a customer
void staff() {
	int option = 1, stage = 0;																	// two int variable to receive option and judge status
	system("cls");
	if (checkstaff() == -1) {																	//all function to check the input password till correct or user choose to quit
		return;																					
	}
	else {																						//password is correct
		while (stage == 0)																		//enter a loop to keep the program till the user selects quit
		{
			system("cls");
			printftime();																		//ask for inout
			printf("Hello \nWhat do you want to do?"
				"\n\t1. Make a booking\n\t2. Check in/out\n\t3. Back to last menu\n");

			// Get user's choice and check user input validity
			while (scanf("%d", &option) != 1 || (option < 1 || option>3)) {
				system("cls");
				printf("Invalid input\nHello boss,\nWhat do you want to do?"
					"Hello \nWhat do you want to do?"
					"\n\t1. Make a booking\n\t2. Check in/out\n\t3. Back to last menu\n");
				fflush(stdin);
			}
			system("cls");
			fflush(stdin);

			switch (option)																		//switch used to perform selectiom
			{
			case 1:booking();																	//call booking()
				break;
			case 2:checker();																	//call checker
				break;
			case 3:stage = 1;																	//back to last menu
				break;
			}
		}
	}
}

//check if the password is cirrect,
//return 1 represent correct, -1 represent user choose to quit
int checkstaff() {
	char pass[8];																				//reveive the user's input
	int i=0;																					//store the number of the input

	printf("Hello,\n\nPlease enter your Employee Number(7 digit) or press 'q' to quit: ");		//ask for input

	//Receive the input and check validity
	while (1) {
		while (i < 8 && (pass[i++] = getch()) != '\r') {									//Enter a loop to value the employee number string, the loop end when over 6 digits or enter '\r'
			printf("%c", pass[i - 1]);
			if (pass[0] == 'q' || pass[0] == 'Q')									//press q to quit
				return -1;
		}
		if (pass[7] == '\r') {																	//Set the last element of the string and the counter
			pass[7] = '\0';
			i = 0;
		}


		if (!strcmp(pass, employee_number)) {													//check if the input password match the correct one
			i = 0;																				//correct, break, zero the counter for
			break;
		}
		else {
			printf("\nYou are not our staff. Please try again or press 'q' to quit: ");			//ask for another try
			i = 0;
		}

	}

	printf("\n\nPlease enter your password(7 digit): ");										//same as before

	while (1) {

		while (i < 8 && (pass[i++] = getch()) != '\r') {
			putchar('*');																		//Encrypt the password by '*'
			if (pass[0] == 'q' || pass[0] == 'Q')
				return -1;
		}
		if (pass[7] == '\r') {
			pass[7] = '\0';
			i = 0;
		}


		if (!strcmp(pass, employee_pass)) {
			return 1;
		}
		else {
			printf("\nWrong password. Please try again or press 'q' to quit");
			i = 0;
		}
	}
}

//initialize the room info
void initialize_room() {
	FILE *fptr;

	struct room initial[100];								//100 rooms in total

	for (int i = 0; i < 40; i++) {							//40 Double Rooms 
		initial[i].num = ((i / 20) + 1)*100 + i;			//set room number
		initial[i].classtype = 2;							//2 represent Double Room
		initial[i].discount = 100;							//no discount
		initial[i].occupied = 0;							//avaliable for booking
		initial[i].period = 0;								
		initial[i].price = 450;								//price 450
	}
	for (int i = 40; i < 60; i++) {							//same as before,20 Single Room
		initial[i].num = ((i / 20) + 1) * 100 + i;
		initial[i].classtype = 1;
		initial[i].discount = 100;
		initial[i].occupied = 0;
		initial[i].period = 0;
		initial[i].price = 300;
	}
	for (int i = 60; i < 80; i++) {							//same as before,20 KingSize Room
		initial[i].num = ((i / 20) + 1) * 100 + i;
		initial[i].classtype = 3;
		initial[i].discount = 100;
		initial[i].occupied = 0;
		initial[i].period = 0;
		initial[i].price = 350;
	}
	for (int i = 80; i < 100; i++) {						//same as before,20 VIP Room
		initial[i].num = ((i / 20) + 1) * 100 + i;
		initial[i].classtype = 4;
		initial[i].discount = 100;
		initial[i].occupied = 0;
		initial[i].period = 0;
		initial[i].price = 500;
	}

	fptr=fopen(roominfo, "wb+");							//rewrite the file "room.date"
	if (fptr == NULL) {										//Test the success of file opening
		printf("\nSomething wrong with opening the file, please restart the program\n\n");
		exit(1);
	}
	else 
		fwrite(initial, sizeof(struct room), 100, fptr);	//write all 100 rooms into the file "room.dat"
	
	fclose(fptr);
}

//initialize the manager info
void initialize_manager() {
	FILE *fptr;
	struct manager newm;
	newm.pricefor1 = 300;									//set the price for each classtype
	newm.pricefor2 = 450;
	newm.pricefor3 = 350;
	newm.pricefor4 = 500;
	newm.discountperroom = 10;								//discount for groupbooking
	newm.total_benefit = 0;									//reset total benefit

	fptr = fopen(managerinfo, "wb+");

	fwrite(&newm, sizeof(struct manager), 1, fptr);			//rewrite into the file "manager.dat"
	
	fclose(fptr);


}

//initialize the customer info
void initialze_customer() {
	FILE *fptr;
	struct customer new[5];								//initialize 5 customers
	struct customer current;

	for (int i = 0; i < 2; i++) {						
		strcpy(new[i].address, "wenxin");
		new[i].arrival = i;
		new[i].days = 2;
		new[i].membership = 1;
		new[i].room_num = 100 + i;						//set the room number
		occupy_room(100 + i);							//set the room status as occupied
		strcpy(new[i].phone_number, "7654321");
	}

	for (int i = 2; i < 5; i++) {						//same as before
		strcpy(new[i].address, "XJTLU");
		new[i].arrival = 0;
		new[i].days = 3;
		new[i].membership = 0;
		new[i].room_num = 340 + i;
		occupy_room(340 + i);
		strcpy(new[i].phone_number, "1234567");
	}

	//set the name respectively
	strcpy(new[0].name, "wmn");							//vip customer hasn't arrived
	strcpy(new[1].name, "zyy");							//vip customer hasn arrived
	strcpy(new[2].name, "cz");							//common customer has arrived
	new[2].arrival = 1;									
	strcpy(new[3].name, "wt");							//common customer hasn't arrived
	strcpy(new[4].name, "qzy");							//common customer hasn't arrived

	fptr = fopen(customerinfo, "wb+");
	if (fptr == NULL) {										//Test the success of file opening
		printf("\nSomething wrong with opening the file, please restart the program\n\n");
		exit(1);
	}
	else 
		fwrite(new, sizeof(struct customer), 5, fptr);		//rewrite the customers intofile"manager.dat"

	fclose(fptr);
}

//initialize the groupbooking info
void initialize_group() {
	FILE *fptr;
	struct group new[5];								//initialize five groupbooking

	for (int i = 0; i < 5; i++) {						//set all the info and asign the room number
		strcpy(new[i].address, "XJTLU");
		strcpy(new[i].phonenumber, "1611548");
		new[i].days = i + 1;
		new[i].rooms = 5;
		new[i].arrival = 0;

		new[i].room_num[0] = 119-i;
		occupy_room(199 - i);
		new[i].room_num[1] = 359-i;
		occupy_room(359 - i);
		new[i].room_num[2] = 460+i;
		occupy_room(460 + i);
		new[i].room_num[3] = 598-i;
		occupy_room(598 - i);
		new[i].room_num[4] = 220+i;
		occupy_room(220 + i);
	}

	//set the name respectively
	strcpy(new[0].name, "ee");
	strcpy(new[1].name, "te");
	strcpy(new[2].name, "ics");
	strcpy(new[3].name, "cst");
	strcpy(new[4].name, "xjtlu");



	fptr = fopen(groupinfo, "wb+");
	if (fptr == NULL) {										//Test the success of file opening
		printf("\nSomething wrong with opening the file, please restart the program\n\n");
		exit(1);
	}
	else {
		for (int i = 0; i < 5; i++) {
			fwrite(&new[i], sizeof(struct group), 1, fptr);   //rewrite the group into file "group.dat"
		}
	}

	fclose(fptr);
}



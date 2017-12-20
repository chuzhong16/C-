#include "Booking.h"
#include "Menu.h"
#include "Checker.h"
#include "Manager.h"




void booking()
{

	system("cls");
	fflush(stdin);									/*empty the input buffer*/
	char option1, option2;							/*Declare two character variables which will be used in choose option*/
	int flagA = 0, flagB = 0;						/*Declare one integer variables: one used as flag for detecting status*/
	FILE *database;									/*Declare a file pointer*/
	int list = 0;									/*Declare a integral variable which will be used in list_all function*/

	database = fopen(customerinfo, "ab");			/*Try to open the file for writing or create the file if it doesn't exist - openmode is binary*/
	if (database == NULL)							/*Test the success of fopen - close the program if failed*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program\n\n");
		continue1();								/*Use functin in Menu.h to let the user enter any press to continue*/
		exit(0);									/*exit the program if it is not successful*/
	}
	fclose(database);								/*close the file*/

	while (flagA == 0)
	{
		system("cls");
		printftime();
		printf("What would you like to do?\n");
		printf("\t1. Register a new customer \n\t2. Search the customer and book a room \n\t3. Edit information of customer\n\t4. Remove a customer \n\t5. Group Booking\n\t6. Back to last menu\n");

		fflush(stdin);								/*empty the input buffer*/
		option1 = getchar();						/* To get the input character for option1*/
		getchar();
		while (option1 != '1' && option1 != '2' && option1 != '3'&& option1 != '4' && option1 != '5' && option1 != '6')		/*check user entry validity*/
		{
			printf("Invalid entry\n\n");
			continue1();							/*Use functin in Menu.h to let the user enter any press to continue*/
			fflush(stdin);							/*empty the input buffer*/
			system("cls");
			printf("What would you like to do?\n");
			printf("\t1. Register a new customer \n\t2. Search the customer and book a room\n\t3. Edit information of customer\n\t4. Remove a customer \n\t5. Group Booking\n\t6. Back to last menu\n");
			option1 = getchar();					/* To get the input character for option1*/
			getchar();
		}

		switch (option1)
		{
		case '1':
			register_guest();						/*To register a new guest*/
			break;
		case '2':
			flagB = search();						/*To search the customer information in the system*/
			if (flagB == 1 || flagB == 2)			/*Find out the information in the system*/
			{
				printf("\nWhat would you like to do?\n\n\t1. Book a room \n\t2. Back to last menu\n\n");
				fflush(stdin);						/*empty the input buffer*/
				option2 = getchar();				/*To get the input of option2*/
				getchar();
				while (option2 != '1' && option2 != '2')		/*check user entry validity*/
				{
					printf("Invalid entry\n\n");
					continue1();					/*Use functin in Menu.h to let the user enter any press to continue*/
					fflush(stdin);
					system("cls");
					printf("\nWhat would you like to do?\n\n\t1. Book a room \n\t2. Back to last menu\n\n");
					option2 = getchar();
					getchar();
				}

				switch (option2)
				{
				case '1':
					list_all(&flagB, &list);			/*list all the type of rooms that the customer can live in*/
					if (list == 1)						/*The customer can book the room*/
					{
						book();							/*Book the room and record it to the system*/
					}

					break;
				case '2':
					fflush(stdin);						/*empty the input buffer*/
					continue1();						/*Use functin in Menu.h to let the user enter any press to continue*/
					system("cls");
					break;
				default:
					break;
				}
			}
			else                                        /*Conldn't find the information from the system*/
			{
				{
					printf("\nPlease choose a registered name!\n");
					fflush(stdin);						/*empty the input buffer*/
					continue1();						/*Use functin in Menu.h to let the user enter any press to continue*/
					system("cls");
				}
			}
			break;
		case '3':
			edit_guest();								/*To edit the guest information from the system*/
			break;
		case '4':
			remove_guest();								/*To remove guest information from the system*/
			break;
		case '5':
			group_book();								/*Use a function from Manager.h to create groupbooking or see existed groupbooking*/
			break;
		case '6':
			return;									/*Back to last menu*/
		}
	}
}

void register_guest()
{
	struct customer tmp, global;						/*declare a temporary structure type of player and a global structure type of player*/
	FILE *file;											/*declare a file pointer*/
	int check = 0;										/*declare a integer to check whether user has successfully created an account*/
	int cardnumber = 0;									/*declare a integal named cardnumber which will*/

	file = fopen(customerinfo, "r");				/*the file is opened to check the entries existed in it*/

	while (check == 0)									/*Use a while loop to keep the program running till the user has successfully created an account*/
	{
		rewind(file);

		if (file == NULL) 								/*Test the success of opening the file*/
		{
			printf("\n\nThere was a problem opening the file, please restart the program\n\n");
			continue1();								/*Use functin in Menu.h to let the user enter any press to continue*/
			exit(0);									/*exit the program if it is not successful*/
		}

		fread(&tmp, sizeof(struct customer), 1, file);		/*read information of one struct from file to tmp*/
		fflush(stdin);
		system("cls");

		printf("Please enter the name of customer:\n\n\t");			/*Obtain each structure member' playername checking each for validity*/
		while (scanf("%s", global.name) == 0 || strlen(global.name)>31)
			/*The logic expression is evaluated from left to right so the scanf is evaluated first to ensure the string is read*/
			/*the right hand side checks the value obtained by the scanf to ensure the length of the string is less than maximum length*/

		{
			printf("Please try again and make sure the name has less than 31 characters");
			fflush(stdin);										/*Ensure input buffer is empty*/
			continue1();										/*Use functin in Menu.h to let the user enter any press to continue*/
			system("cls");
			printf("Please enter the name of customer:\n\n\t");
		}

		if (global.name[0] == '!')
		{
			fflush(stdin);										/*Ensure input buffer is empty*/
			continue1();										/*Use functin in Menu.h to let the user enter any press to continue*/
			system("cls");
			return;
		}

		while (1)
		{
			if (strcmp(global.name, tmp.name)) { 						/*Ensure whether there is existed player name*/
				if (!feof(file)) {										/*Ensure the information read is not at the end of file*/
					fread(&tmp, sizeof(struct customer), 1, file);		/*Read the information of the customer from the file*/
				}
				else
				{
					{
						check = 1;										/*If it is not existed, then quit the while loop*/
						break;
					}
				}
			}
			else {   													/*The account is already existed*/
				{
					printf("The name has already existed!\n");
					fflush(stdin);										/*Ensure input buffer is empty*/
					continue1();										/*Use functin in Menu.h to let the user enter any press to continue*/
					system("cls");
					printf("Please enter the name of player:\n\n\t");

					break;
				}
			}
		}
	}
	fclose(file);										/*Close the file*/

	fflush(stdin);													/*Ensure input buffer is empty*/
	printf("Please enter the address of customer:\n\n\t");			/*Obtain each structure member' playername checking each for validity*/
	while (scanf("%s", global.address) == 0 || strlen(global.address)>81)
		/*The logic expression is evaluated from left to right so the scanf is evaluated first to ensure the string is read*/
		/*the right hand side checks the value obtained by the scanf to ensure the length of the string is less than maximum length*/
	{
		printf("Please try again and make sure the address has less than 81 characters");
		fflush(stdin);								/*Ensure input buffer is empty*/
		continue1();								/*Use functin in Menu.h to let the user enter any press to continue*/
		system("cls");
		printf("Please enter the address of customer:\n\n\t");
	}

	fflush(stdin);									/*Ensure input buffer is empty*/
	printf("Please enter the phone number of the customer:\n\n\t");			/*Obtain each structure member' password checking each for validity*/
	while ((scanf("%d", global.phone_number)) != 1 || strlen(global.phone_number)>30)
		/*The logic expression is evaluated from left to right so the scanf is evaluated first to ensure the string is read*/
		/*the right hand side checks the value obtained by the scanf to ensure the length of the string is less than maximum length*/
	{
		printf("Please try again and make sure the phone number has less than 30 characters.");
		fflush(stdin);								/*Ensure input buffer is empty*/
		continue1();								/*Use functin in Menu.h to let the user enter any press to continue*/
		system("cls");
		printf("Please enter the phone number of the customer:\n\n\t");
	}

	fflush(stdin);									/*Ensure input buffer is empty*/
	printf("Please enter the member card number of the customer\n\n\t");
	while ((scanf("%d", &cardnumber)) != 1)			/*check user entry validity*/
	{
		printf("Invalid input. Please try again!");
		fflush(stdin);								/*Ensure input buffer is empty*/
		continue1();								/*Use functin in Menu.h to let the user enter any press to continue*/
		system("cls");
		printf("Please enter the member card number of the customer\n\n\t");
	}

	if (cardnumber == 1613489)
	{
		global.membership = 1;						/*Find out the membership of the customer successfully*/
	}
	else if (cardnumber != 1613489)
	{
		global.membership = 0;						/*No card number in the file*/
	}

	printf("You have registered successfully:\n\n\t");
	continue1();							/*Use functin in Menu.h to let the user enter any press to continue*/
	system("cls");

	file = fopen(customerinfo, "ab");		/*the file is ready to append the new entry at the end of the file*/

	if (file == NULL) 		/*Test the success of opening the file*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program\n\n");
		continue1();	/*Use functin in Menu.h to let the user enter any press to continue*/
		exit(0);		/*exit the program if it is not successful*/
	}
	else				/*On successfully opening the file the structure is written to the file*/
	{
		global.arrival = 0;										/*initialize the value of arrival*/
		global.days = 0;										/*initialize the value of days*/
		global.room_num = 0;									/*initialize the value of room_num*/
		fwrite(&global, sizeof(struct customer), 1, file);		/*the structure is written to the file*/
	}

	fclose(file); 		/*Close the file*/

	return;
}

void edit_guest()
{
	struct customer tmp, global;						/*declare a temporary structure type of player and a global structure type of customer*/
	FILE *file;											/*declare a file pointer*/
	int check = 0;										/*declare a integral variable named check which will be used in while loop*/

	file = fopen(customerinfo, "r");	/*the file is opened to check the entries existed in it*/
	while (check == 0)
	{							/*Use a while loop to keep the program running till the user has successfully created an account*/

		rewind(file);
		if (file == NULL) 		/*Test the success of opening the file*/
		{
			printf("\n\nThere was a problem opening the file, please restart the program\n\n");
			continue1();		/*Use functin in Menu.h to let the user enter any press to continue*/
			exit(0);			/*exit the program if it is not successful*/
		}

		fread(&tmp, sizeof(struct customer), 1, file);		/*read information of one struct from file to tmp*/
		fflush(stdin);										/*Ensure input buffer is empty*/
		system("cls");

		printf("Please enter the name of customer you want to edit:\n\n\t");			/*Obtain each structure member' playername checking each for validity*/
		while (scanf("%s", global.name) == 0 || strlen(global.name)>31)
			/*The logic expression is evaluated from left to right so the scanf is evaluated first to ensure the string is read*/
			/*the right hand side checks the value obtained by the scanf to ensure the length of the string is less than maximum length*/

		{
			printf("Please try again and make sure the name has less than 31 characters.");
			fflush(stdin);				/*Ensure input buffer is empty*/
			continue1();				/*Use functin in Menu.h to let the user enter any press to continue*/
			system("cls");
			printf("Please enter the name of customer you want to edit:\n\n\t");
		}

		if (global.name[0] == '!')		/*invalid input*/
		{
			fflush(stdin);				/*Ensure input buffer is empty*/
			continue1();				/*Use functin in Menu.h to let the user enter any press to continue*/
			system("cls");
			return;
		}

		while (1)
		{
			if (strcmp(global.name, tmp.name) == 0)			/*Ensure whether there is existed player name*/
			{
				check = 1;									/*make the while loop stop*/
				break;
			}
			else
			{
				if (!feof(file))										/*Ensure the information read is not at the end of file*/
				{
					fread(&tmp, sizeof(struct customer), 1, file);		/*read the customer's information from the file*/
				}
				else												/*The account does not exist*/
				{
					printf("The name does not exist!\n");
					printf("You can enter '!' to return to the last menu.");
					continue1();									/*Use functin in Menu.h to let the user enter any press to continue*/
					fflush(stdin);									/*Ensure input buffer is empty*/
					system("cls");
					check = 0;										/*Keep the while loop running*/
					break;
				}
			}
		}
	}
	fclose(file);													/*Close the file*/

	printf("You have successfully found the customer.\n\n");
	fflush(stdin);													/*Ensure input buffer is empty*/

	printf("Please edit the address of customer:\n\n\t");			/*Obtain each structure member' playername checking each for validity*/
	while (scanf("%s", global.address) == 0 || strlen(global.address)>81)
		/*The logic expression is evaluated from left to right so the scanf is evaluated first to ensure the string is read*/
		/*the right hand side checks the value obtained by the scanf to ensure the length of the string is less than maximum length*/
	{
		printf("Please try again and make sure the address has less than 81 characters\n");
		fflush(stdin);											/*Ensure input buffer is empty*/
		continue1();											/*Use functin in Menu.h to let the user enter any press to continue*/
		system("cls");
		printf("Please try again:\n\n\t");
	}

	fflush(stdin);															/*Ensure input buffer is empty*/
	printf("Please edit the phone number of the customer:\n\n\t");			/*Obtain each structure member' password checking each for validity*/
	while ((scanf("%s", global.phone_number)) == 0 || (strspn(global.phone_number, "0123456789") != strlen(global.phone_number)) || strlen(global.phone_number)>30)
		/*The logic expression is evaluated from left to right so the scanf is evaluated first to ensure the string is read*/
		/*the right hand side checks the value obtained by the scanf to ensure the length of the string is less than maximum length*/
	{
		printf("Please try again and make sure the phone number has less than 30 characters.");
		fflush(stdin);											/*Ensure input buffer is empty*/
		continue1();											/*Use functin in Menu.h to let the user enter any press to continue*/
		system("cls");
		printf("Please try again:\n\n\t:\n\n\t");
	}

	fflush(stdin);												/*Ensure input buffer is empty*/
	printf("Please edit the member card number of the customer\n\n\t");
	while ((scanf("%d", &global.membership)) != 1)				/*Check the validity of input */
	{
		printf("Invalid input. Please try again!");
		fflush(stdin);											/*Ensure input buffer is empty*/
		continue1();											/*Use functin in Menu.h to let the user enter any press to continue*/
		system("cls");
		printf("Please try again\n\n\t");
	}

	file = fopen(customerinfo, "rb+");							/*Open the customerinfo binary file for reading*/
	if (file == NULL) 		/*Test the success of opening the file*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program\n\n");
		continue1();		/*Use functin in Menu.h to let the user enter any press to continue*/
		exit(0);			/*exit the program if it is not successful*/
	}

	printf("You have edited successfully:\n\n\t");
	continue1();			/*Use functin in Menu.h to let the user enter any press to continue*/
	system("cls");

	fseek(file, (long)(0 - sizeof(struct customer)), SEEK_CUR);	/*Locate the position to the asked entry's position*/
	fwrite(&global, sizeof(struct customer), 1, file);			/*Write the updated information of org into file*/
	fclose(file);												/*close the file*/

	return;
}

void remove_guest()
{
	struct customer tmp, global;						/*Declare a temporary structure type of player and a global structure type of player*/
	FILE *file;											/*Declare a file pointer*/
	int check = 0;										/*Declare a integral variable which could be used in while loop*/

	fflush(stdin);										/*Ensure input buffer is empty*/
	system("cls");

	printf("Please enter the name of customer you want to remove:\n\n\t");			/*Obtain each structure member' playername checking each for validity*/

	file = fopen(customerinfo, "rb+");	/*the file is opened to check the entries existed in it*/
	while (check == 0)
	{				/*Use a while loop to keep the program running till the user has successfully created an account*/

		rewind(file);
		if (file == NULL) 		/*Test the success of opening the file*/
		{
			printf("\n\nThere was a problem opening the file, please restart the program\n\n");
			continue1();		/*Use functin in Menu.h to let the user enter any press to continue*/
			exit(0);			/*exit the program if it is not successful*/
		}

		fread(&tmp, sizeof(struct customer), 1, file);		/*read information of one struct from file to tmp*/

		while (scanf("%s", global.name) == 0 || strlen(global.name)>31)
			/*The logic expression is evaluated from left to right so the scanf is evaluated first to ensure the string is read*/
			/*the right hand side checks the value obtained by the scanf to ensure the length of the string is less than maximum length*/

		{
			printf("Please try again and make sure the name has less than 31 characters");
			fflush(stdin);				/*Ensure input buffer is empty*/
			continue1();				/*Use functin in Menu.h to let the user enter any press to continue*/
			system("cls");
			printf("Please enter the name of customer you want to remove:\n\n\t");
		}

		if (global.name[0] == '!')
		{
			fflush(stdin);				/*Ensure input buffer is empty*/
			continue1();				/*Use functin in Menu.h to let the user enter any press to continue*/
			system("cls");
			return;
		}

		while (1)
		{
			if (strcmp(global.name, tmp.name) == 0)			/*Ensure whether there is existed player name*/
			{
				check = 1;											/*make the while loop stop*/
				break;
			}
			else
			{
				if (!feof(file))										/*Ensure the information read is not at the end of file*/
				{
					fread(&tmp, sizeof(struct customer), 1, file);	/*read the customer's information from the system*/
				}
				else												/*The account does not exist*/
				{
					fflush(stdin);									/*Ensure input buffer is empty*/
					system("cls");
					printf("The name does not exist!\n");
					printf("Please try again or press '!' to return to the last menu.");

					check = 0;										/*Keep the while loop running*/
					break;
				}
			}
		}
	}

	printf("You have successfully removed the customer.\n\n\t");
	continue1();									/*Use functin in Menu.h to let the user enter any press to continue*/
	fflush(stdin);									/*Ensure input buffer is empty*/
	system("cls");

	global.name[0] = '0';							/*remove the information of the customer*/
	global.address[0] = '0';
	global.phone_number[0] = '0';
	global.membership = 0;
	global.arrival = 0;
	global.days = 0;
	global.room_num = 0;


	if (file == NULL) 		/*Test the success of opening the file*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program\n\n");
		continue1();		/*Use functin in Menu.h to let the user enter any press to continue*/
		exit(0);			/*exit the program if it is not successful*/
	}

	fseek(file, (long)(0 - sizeof(struct customer)), SEEK_CUR);	/*Locate the position to the asked entry's position*/
	fwrite(&global, sizeof(struct customer), 1, file);			/*Write the updated information of org into file*/
	fclose(file);												/*close the file*/

	return;
}

int search()
{
	struct customer tmp, global;						/*declare a temporary structure type of player and a global temopary structure type of player*/
	FILE *file;											/*declare a file pointer*/

	file = fopen(customerinfo, "r");					/*the file is opened to check the entries existed in it*/

	if (file == NULL) 									/*Test the success of opening the file*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program\n\n");
		continue1();									/*Use functin in Menu.h to let the user enter any press to continue*/
		exit(0);										/*exit the program if it is not successful*/
	}

	fread(&tmp, sizeof(struct customer), 1, file);		/*read information of one struct from file to tmp*/
	fflush(stdin);										/*Ensure input buffer is empty*/
	system("cls");

	printf("Please enter the name of customer you want to search:\n\n\t");			/*Obtain each structure member' playername checking each for validity*/
	while (scanf("%s", global.name) == 0 || strlen(global.name)>31)
		/*The logic expression is evaluated from left to right so the scanf is evaluated first to ensure the string is read*/
		/*the right hand side checks the value obtained by the scanf to ensure the length of the string is less than maximum length*/

	{
		printf("Please try again and make sure the name has less than 31 characters");
		fflush(stdin);							/*Ensure input buffer is empty*/
		continue1();							/*Use functin in Menu.h to let the user enter any press to continue*/
		system("cls");
		printf("Please enter the name of customer you want to search:\n\n\t");
	}

	while (1)
	{
		if (strcmp(global.name, tmp.name) == 0)			/*Ensure whether there is existed player name 0 means there exists*/
		{
			printf("Find your account successfully!\n\n");					/*make the while loop stop*/
			if (tmp.membership == 1)
			{
				printf("You are our VIP customer");
				return 2;
			}
			else if (tmp.membership == 0)
			{
				printf("You are not our VIP customer");
				return 1;
			}
		}
		else
		{
			if (!feof(file))										/*Ensure the information read is not at the end of file*/
			{
				fread(&tmp, sizeof(struct customer), 1, file);	/*reand the customer'information from the file*/
			}
			else												/*The account does not exist*/
			{
				return 0;										/*The account does not exist*/
			}
		}
	}
	fclose(file);
}

void book()
{
	int choice = 0;					/*declare a integral variable named choice which will be used to choose room number*/
	char arrive;					/*declare a character variable named arrive which will be used*/
	FILE *file;						/*declare a file pointer */
	struct customer global;
	printf("Please choose the room number shown\n\n");
	fflush(stdin);								/*Ensure input buffer is empty*/
	while (scanf("%d", &choice) == 0 || checkroom(choice) == 1 || choice<100 || choice>599)/*Ensure the input validity*/
	{

		printf("Invalid entry or room doesn't exist or has been occupied. \nPlease try again!");
		fflush(stdin);							/*Ensure input buffer is empty*/
		continue1();							/*Use functin in Menu.h to let the user enter any press to continue*/
		system("cls");
		printf("Please choose the room number shown\n\n");
	}
	global.room_num = choice;					/*give the global.room value*/
	occupy_room(choice);						/*To save the choice to the file*/

	printf("Will the customer arrive the day he books the room:\n\n\t1. Yes \n\t2. No\n\n");
	fflush(stdin);								/*Ensure input buffer is empty*/
	arrive = getchar();							/*get the input character for arrive*/
	getchar();
	while (arrive != '1' && arrive != '2')		/*check user entry validity*/
	{
		printf("Invalid entry\n\n");
		continue1();							/*Use functin in Menu.h to let the user enter any press to continue*/
		fflush(stdin);							/*Ensure input buffer is empty*/
		system("cls");
		printf("\nWill the customer arrive the day he books the room:\n\n");
		arrive = getchar();						/*Get the input character for arrive*/
		getchar();
	}
	switch (arrive)
	{
	case '1':
		global.arrival = 1;						/*The customer can arrive the hotel in the day*/
		break;
	case '2':
		global.arrival = 0;						/*The customer can't arrive the hotel in the day*/
		break;
	default:
		break;
	}

	printf("Number of days will the customer live:\n\n");
	fflush(stdin);								/*Ensure input buffer is empty*/
	while (scanf("%d", &global.days) == 0)		/*Ensure the input validity*/
	{
		printf("Invalid entry. Please try again!");
		fflush(stdin);							/*Ensure input buffer is empty*/
		continue1();							/*Use functin in Menu.h to let the user enter any press to continue*/
		system("cls");
		printf("Number of days will the customer live:\n\n");
	}

	file = fopen(customerinfo, "rb+");			/*open the customerinfo binary file for reading*/
	if (file == NULL) 							/*Test the success of opening the file*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program\n\n");
		continue1();							/*Use functin in Menu.h to let the user enter any press to continue*/
		exit(0);								/*exit the program if it is not successful*/
	}

	fseek(file, (long)(0 - sizeof(struct customer)), SEEK_CUR);	/*Locate the position to the asked entry's position*/
	fwrite(&global, sizeof(struct customer), 1, file);			/*Write the updated information of org into file*/
	fclose(file);			/*close the file*/
	fflush(stdin);			/*Ensure input buffer is empty*/
	continue1();			/*Use functin in Menu.h to let the user enter any press to continue*/
	system("cls");

	return;
}

void list_all(int *flagB, int *list)
{
	struct room check;				/*declare a temporary structure type of room */
	struct room tmp;				/*declare a temporary structure type of room */
	FILE *file;						/*declare a file pointer */
	int i = 0;						/*declare a integral variable named i which will be used in for loop*/

	file = fopen(roominfo, "r");	/*the file is opened to check the entries existed in it*/

	if (file == NULL) 		/*Test the success of opening the file*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program\n\n");
		continue1();		/*Use functin in Menu.h to let the user enter any press to continue*/
		exit(0);			/*exit the program if it is not successful*/
	}

	fread(&tmp, sizeof(struct room), 1, file);		/*read information of one struct from file to tmp*/
	fflush(stdin);									/*Ensure input buffer is empty*/
	system("cls");

	printf("Please enter the type of room you want to live:\n\n\t");			/*Obtain each structure member' playername checking each for validity*/
	printf("If you are not a VIP, you cannot book a VIP room:\n\n\t");
	printf("1. Single room \n\t2. Double room \n\t3. Big bed room\n\t4. VIP room\n");

	if (*flagB == 2)
	{
		while (scanf("%d", &check.classtype) == 0)								/*check user entry validity*/
		{
			printf("Invalid entry. Please try again!");
			fflush(stdin);														/*Ensure input buffer is empty*/
			continue1();														/*Use functin in Menu.h to let the user enter any press to continue*/
			system("cls");
			printf("Please enter the type of room you want to live:\n\n\t");			/*Obtain each structure member' playername checking each for validity*/
			printf("If you are not a VIP, you cannot book a VIP room:\n\n\t");
			printf("1. Single room \n\t2. Double room \n\t3. Big bed room\n\t4. VIP room\n");
		}
	}
	else if (*flagB == 1)
	{
		while (scanf("%d", &check.classtype) == 0 || check.classtype == 4)				/*check user entry validity*/
		{
			printf("Invalid entry or you are not VIP. Please try again!");
			fflush(stdin);																/*Ensure input buffer is empty*/
			continue1();																/*Use functin in Menu.h to let the user enter any press to continue*/
			system("cls");
			printf("Please enter the type of room you want to live:\n\n\t");			/*Obtain each structure member' playername checking each for validity*/
			printf("If you are not a VIP, you cannot book a VIP room:\n\n\t");
			printf("1. Single room \n\t2. Double room \n\t3. Big bed room\n\t4. VIP room\n");
		}
	}

	printf("The empty room are followed:\n");
	while (1)
	{
		if (check.classtype == tmp.classtype && tmp.occupied == 0 && !feof(file))			/*Ensure whether there is existed player name*/
		{
			*list = 1;
			printf("\t%d", tmp.num);
			if (i == 4)
			{
				printf("\n\n");
				i = 0;
			}
			else
			{
				i++;
			}

			if (!feof(file))										/*Ensure the information read is not at the end of file*/
			{
				fread(&tmp, sizeof(struct room), 1, file);
			}
			else
			{
				break;
			}
		}
		else
		{
			if (!feof(file))										/*Ensure the information read is not at the end of file*/
			{
				fread(&tmp, sizeof(struct room), 1, file);			/*read the information of the room from the file*/
			}
			else												/*The account does not exist*/
			{
				{
					printf("\nThere is no other empty room of that type.\n\n");
					return;
				}
			}
		}
	}
	return;
}

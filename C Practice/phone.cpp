/* Telephone Directory - A simple example of how to create and access data files using a structure */
/* Note that in each case, the file contents are accessed by copying data into a single structure variable*/
/* It is possible to declare an array of structures and read the whole contents of the file into an array*/
/* but this is an unecessary use of memory and array size restricts the length of your database*/

#include<stdio.h>		/*C libraries used in this program */
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<string.h>

struct entry			/*Declare structure type named entry containing a variable for each of the details to be stored*/
{
	char surname[31];
	char given_name[31];
	long long number;	   /*use of an long long for the phone number to make sure there are enough digits available*/
	char email[41];
};

/*Function protoypes*/
void create(char *filename);					/*A function to create a new item in the telephone directory*/
int find(struct entry *person, char *filename); /*A function that finds an entry in the file and returns the information*/
void list(char *filename);						/*A function that lists the whole contents ofthe file*/


/*Start of function main which takes arguments from the command line (note it can be run with only the executable name)*/
/*see lecture notes on what this means - note you do not need to have this functionality in your program, you can ask*/
/*the user to enter the name of the file when the program is running or just assume the same filename will always be used*/

int main(int argc, char *argv[])
{
	int flag1 = 0, flag2, option;	/*Declare some integer variables: two used as flags for detecting status and one to accept user input*/
	struct entry person;			/*Declare a strucutre of tupe entry*/
	FILE *fptr;					/*Declare a file pointer*/
	char filename[21] = "admin.dat";		/*Declare an initialise a character array containing a default filename (limited to 20 characters*/

	if (argc>1)						/*Check if an additional argument (filename) has been added to the excution list*/
	{
		strcpy(filename, argv[1]);	/*If there is a filename copy it to the filename variable contining the default name*/
	}

	fptr = fopen(filename, "ab");	/*Try to open the file for writing or create the file if it doesn't exist - openmode is binary*/

	if (fptr == NULL)				/*Test the success of fopen - close the program if failed*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program\n\n");
		Sleep(2000);
		exit(0);
	}

	fclose(fptr);					/*close the file*/

	while (flag1 == 0)				/*enter a while loop to keep the program running till the user selects option 4*/
	{
		Sleep(2000);
		system("cls");
		printf("\nPlease select one of the following options:\n\t1. Create a new entry\n\t2. Find a number\n\t3. Print all file entries\n\t4. Close the program\n\n");

		while (scanf("%d", &option) != 1 && (option<1 || option>4))		/* Display menu and get user entry - check user entry validity*/
		{
			printf("Invalid entry\n\n");
			Sleep(2000);
			fflush(stdin);
			system("cls");
			printf("Please select one of the following options:\n\t1. Create a new entry\n\t2. Find a number\n\t3. Print all file entries\n\t4. Close the program\n\n");
		}

		switch (option)					/*switch used to perform selection - send the filename*/
		{
		case 1: create(filename);	/*call function create*/
			break;

		case 2: flag2 = find(&person, filename);		/*call function find - send the filename and the address of the structure obtain int return*/

			if (flag2 == 0)			/*decide if persons details were found and print*/
				{
				system("cls");
				printf("\n\n%s %s contact details are:\ntelephone:%lli\nemail:%s", person.surname, person.given_name, person.number, person.email);
				}
			else
				printf("\n\nThe name does not exist in your phonebook\n\n");
			break;

		case 3: list(filename);	/*call function list - send the filename*/
			break;

		case 4: flag1 = 1;			/*set flag 1 to end the program loop and close the program*/
			break;
		}

	}

	printf("\n\nThank you for using the phone book");
	Sleep(2000);

	return 0;			/*return 0 to the system indicating successful program execution and termination*/
}

void create(char *filename)		/*function create definition*/
{
	struct entry person;			/*declare a structure*/

	FILE *fptr;					/*declare a file pointer*/

	fflush(stdin);
	system("cls");

	printf("Please enter the surname of the person:\n\n\t");			/*Obtain each structure member information checking each for validity*/
	while (scanf("%s", person.surname) == 0 || strlen(person.surname)>30)  /*The logic expression is evaluated from left to right so the scanf is evaluated first to ensure the string is read*/
	{																/*the right hand side checks the value obtained by the scanf to ensure the length of the string is less than maximum length*/
		printf("Please try again and make sure the name has less than 30 characters");
		fflush(stdin);
		Sleep(2000);
		system("cls");
		printf("Please enter the surname of the person\n\n\t");
	}

	fflush(stdin);		/*Ensure input buffer is empty*/

	printf("Please enter the given name of the person:\n\n\t");
	while (scanf("%s", person.given_name) == 0 || strlen(person.given_name)>30)
	{
		printf("Please try again and make sure the name has less than 30 characters");
		fflush(stdin);
		Sleep(2000);
		system("cls");
		printf("Please enter the given name of the person:\n\n\t");
	}

	fflush(stdin);

	printf("Please enter the phone numner of the person:\n\n\t");
	while (scanf("%lli", &person.number) == 0)							/*note %lli is the format type for a long long*/
	{
		printf("Please try again and make sure the number has less than 19 digits");
		fflush(stdin);
		Sleep(2000);
		system("cls");
		printf("Please enter the phone number of the person");
	}

	fflush(stdin);

	printf("Please enter the phone number of the person:\n\n\t");
	while (scanf("%s", person.email) == 0 || strlen(person.email)>40)
	{
		printf("Please try again and make sure the email address has less than 30 characters");
		fflush(stdin);
		Sleep(2000);
		system("cls");
		printf("Please enter the phone number of the person:\n\n\t");
	}
	/*Once all of the member information has been collected, the file is opened ready to append the new entry at the end of the file*/
	fptr = fopen(filename, "ab");

	if (fptr == NULL) 		/*Test the success of opening the file*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program\n\n");
		Sleep(2000);
		exit(0);
	}
	else				/*On successfully opening the file the structure is written to the file*/
	{
		fwrite(&person, sizeof(struct entry), 1, fptr);
	}

	fclose(fptr); 		/*Close the file*/

}

int find(struct entry *person, char *filename)	/*function find definition - received the address of the structure defined in main*/
{												/*also receives the file name*/

	FILE *fptr;

	char searchs[31], searchg[31];

	fflush(stdin);

	printf("Please enter the surname and given_name of the person you are looking for\n");
	while (scanf("%s", searchs) == 0 || strlen(searchs)>30 || scanf("%s", searchg) == 0 || strlen(searchg)>30) /*Test the entry of the persons name*/
	{
		printf("Please try again and make sure the names are seperated by a space and both are less than 30 characters long");
		fflush(stdin);
		Sleep(2000);
		system("cls");
		printf("Please enter the surname and given_name of the person\n\n");
	}

	fflush(stdin);

	fptr = fopen(filename, "rb");	/*Having entered the persons name the file can be opened to search..read only*/

	if (fptr == NULL)				/*Test success of file opening*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program\n\n");
		Sleep(2000);
		exit(0);
	}
	else		/*On success of opening the file start reading structures into the structure variable, note the lack of the & on the variable person*/
	{		/*the variable person in this function is a pointer to the actual variable in function main, note the use of -> instead of . to access structure member*/
		/*each read from the file is checked and the return value captured by flag*/
		/*the value of the surname and given_name members are checked against those entered above, if both are equal the loop will end*/
		/*the loop also ends if the end of the file is reached and the value returned by fread is the EOF value*/
		/*note that on each read, the file pointer moves through the file to the beginning of the next structure*/
		while (fread(person, sizeof(struct entry), 1, fptr) == 1 && ((strcmp(person->surname, searchs)) || (strcmp(person->given_name, searchg))))
		{
			continue;	/*continues the loop when the end of the file hasn't been reached and the name values don't both match*/
		}
	}

	fclose(fptr);	/*close the file*/

	if (!(strcmp(person->surname, searchs)) && !(strcmp(person->given_name, searchg)))	/*test to see if the loop finished because the name was found*/
	{
		return 0;	/*return 0 to indicate the name was found and that the values have been written to the variable in function main*/
	}
	else
	{
		return 1;	/*return 1 to indicate end of file reached hence the name doesn't exist*/
	}
}

void list(char *filename)	/*defined function list*/
{
	struct entry person;		/*declare a structure*/

	FILE *fptr;				/*declare a file pointer*/

	fptr = fopen(filename, "rb");	/*open the file*/

	if (fptr == NULL)				/*test success of opening file*/
	{
		printf("\n\nThere was a problem opening the file, please restart the program\n\n");
		Sleep(2000);
		exit(0);
	}
	else		/*on successful opening of the file, read structures from file into the structure variable then print the values on the screen*/
	{
		while (fread(&person, sizeof(struct entry), 1, fptr) == 1)	/*while loop ends when reading the file returns the EOF marker value*/
		{
			printf("Surname:\t\t%s\n", person.surname);
			printf("Given name:\t\t%s\n", person.given_name);
			printf("Telephone number:\t%lli\n", person.number);
			printf("Email:\t\t\t%s\n\n", person.email);
		}
	}

	fclose(fptr); 		/*close the file*/
}


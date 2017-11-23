#include <stdio.h>
struct book{
	char title[20];
	char author[20];
	float value;
};

int main(int argc, char *argv[]) 
{
	struct book my_book={"Dracula","Bram stoker",9.99};
	float price;
	price=my_book.value;
	printf("%f",price);	
}
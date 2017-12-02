#include<stdio.h>
struct funds
{
	double current;
	double savings;
};
double sum(struct funds);
int main()
{
	struct funds ABC;
	ABC.current=1005;
	ABC.savings=34.5;
	printf("Total funds in ABC %lf",sum(ABC));
} 
double sum(struct funds my_funds)
{
	double total;
	total=my_funds.current+my_funds.savings;
	return total;
}

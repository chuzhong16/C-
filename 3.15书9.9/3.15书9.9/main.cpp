#include<stdio.h>
#include "hotel.h"
int main(void)
{
    int nights;
    double hotel_rate;
    int code;
    while((code=menu())!=QUIT)
    {
        switch(code)
        {
            case 1: hotel_rate=HOTEL1;
                break;
            case 2: hotel_rate=HOTEL2;
                break;
            case 3: hotel_rate=HOTEL3;
                break;
            case 4: hotel_rate=HOTEL4;
                break;
            default:hotel_rate=0.0;
                printf("Oops!\n");
                break;
        }
        nights=getnight();
        showprice(hotel_rate,nights);
    }
    printf("Thanke you and goodbye.\n");
    return 0;
}
#include<stdio.h>
#include"hotel.h>
int menu(void)
{
    int code,status;
    printf("\n%s%s\n",STARS,STARS);
    printf("Enter the number of the desired hotel:\n");
    
}

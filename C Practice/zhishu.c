#include <stdio.h>
int zhishu(int a){
	int i=1;
	int k;
	for(k=2;k<a;k++){
		if(a%k==0){
			i=0;
			break;
		}
	}
	return i;
}
int main(){
	int a;
	scanf("%d",&a);
	printf("%d=",a);
	if(zhishu(a))
		printf("%d",a);
	else {
		for(int i=2;i<=a;i++)
		{
			while(i!=a)
			{
				if(a%i==0)
				{
					printf("%dx",i);
					a=a/i;
				}
				else
					break;
			}
		
		}
		printf("%d",a);
	}
	
}
#include <stdio.h>
int a[105],b[105];
int main(){
	int x,y;
	while (scanf("%d%d",&x,&y)){
		a[x]=y;
		if (x==0) break;
	}f("%d%d",&x,&y)){
		b[x]=y;
		if (x==0) break;
	}
	for (int i=0;i<=100;i++)
		a[i]=a[i]+b[i];
	int flag=0;
	for (int i=100;i>1;i--){
		if (a[i]){
			if (a[i]>0){
				if (a[i]==1){
					if (flag==0){
						printf("x%d",i);
						flag=1;
					}
					else printf("+x%d",i);
				}
				else{
					if (flag==0){
						printf("%dx%d",a[i],i);
						flag=1;
					}
					else printf("+%dx%d",a[i],i);
				}
			}
			else{
				if (a[i]==-1)
					printf("-x%d",i);
				else printf("%dx%d",a[i],i);
			}
		}
	}
	if (a[1]){
		if (a[1]>0){
			if (a[1]==1){
				if (flag==0){
					printf("x");
					flag=1;
				}
				else printf("+x");
			}
			else{
				if (flag==0){
					printf("%dx",a[1]);
					flag=1;
				}
				else printf("+%dx",a[1]);
			}
		}
		else{
			if (a[1]==-1)
				printf("-x");
			else
				printf("%dx",a[1]);
		}
	}
	if (a[0]>0){
		if (flag==0){
			printf("%d",a[0]);
			flag=1;
		}
		else
			printf("+%d",a[0]);
	}
	if (a[0]<=0){
		printf("%d",a[0]);
	}
	printf("\n");
	return 0;
}
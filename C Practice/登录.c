#include <stdio.h>
#include <windows.h>
void UserReg(); //用户注册函数
void Login(); //用户登录函数
main()
{
	int selectNum;
	printf("\nRegistered and Login system\n\n");
	printf("1 UserReg\n");
		printf("2 Login\n");
	printf("3 Exit\n");
	scanf("%d",&selectNum);
	switch (selectNum)
{
	case 1:UserReg();
	break;
	case 2:Login();
	break;
	case 3:printf("Exit Program!\n");
	exit(1);
	break;
}
}
void UserReg()
{
	FILE *fp;
	char Linedata[50]={0},User[20],Pass[20];
	fp = fopen("data.dat","at");
	printf("Registered Account:\n");
	printf("Please input your name:\n");
	fflush(stdin);
	gets(User);
	printf("Please input your password:\n");
	fflush(stdin);
	gets(Pass);
	strcpy(Linedata,User);
	strcat(Linedata,",");
	strcat(Linedata,Pass);
	strcat(Linedata,"\n");
	fputs(Linedata,fp);
	fclose(fp);
	printf("Registered Success!\n");
}
void Login()
{
	FILE *fp;
	int find=0;
	char User[20],Pass[20],Userstrcat[50]={0};
	char Userdata[50]={0};
	fp = fopen("data.dat","r");
	printf("Login Account:\n");
	printf("Please input Username:\n");
	fflush(stdin);
	gets(User);
	printf("Please input Password:\n");
	fflush(stdin);
	gets(Pass);
	strcpy(Userstrcat,User);
	strcat(Userstrcat,",");
	strcat(Userstrcat,Pass);
	strcat(Userstrcat,"\n");
	while (!feof(fp))
{
	fgets(Userdata,19,fp);
	if (strcmp(Userdata,Userstrcat)==0 )
	{
		printf("OK!Login Success!\n");
		printf("Welcome back,%s!\n",User);
		find=1;
		break;
	}
}
	if (!find)
{
	printf("Username or Password incorrect!\n");
}
	fclose(fp);} 

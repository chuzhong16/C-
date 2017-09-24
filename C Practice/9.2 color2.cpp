#include <stdio.h>
#define MAXLINE 1000   /*maximum input line size*/

int getline1(char line[],int maxline);
int remove2(char s[]);

/*remove trailing blanks and tabs, and delete blank lines*/
int main()
{
	char line[MAXLINE];  /*current input line*/
	
	while(getline1(line,MAXLINE)>0)
		if(remove2(line)>0)
			printf("%s",line);
	return 0;
}
int remove2(char s[])
{
	int i;
	
	i=0;
	while(s[i]!='\n') /*fine newline character */
		++i;
	--i;
	while(i>= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;
	if(i>= 0 ){
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';		
	}
	return i;
}

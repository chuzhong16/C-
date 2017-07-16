#include<stdio.h>
void display(char cr,int lines,int width);
int main()
{
    int ch;//待打印字符
    int rows,cols;//行数和列数
    printf("enter a character and two integers;");
    while((ch=getchar())!='\n')
    {
        scanf("%d%d",&rows,&cols);
        display(ch,rows,cols);
        printf("enter another character and two integers;\n");
        printf("enter a newline to quit.\n");
    }
    printf("bye.\n");
    return 0;
}
void display(char cr,int lines,int width)
{
    int  row, col;
    for(int row＝1;row<=lines;row++)
    {
        for(col=1;col<=width;col++)
            putchar(cr);
        putchar('\n');
    }
}

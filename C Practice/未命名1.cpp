#include <stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int b=0;
    int i,j,k,q;
    int qipan[a][a];
    for(int i=0;i<=a-1;i++)
        for(int j=0;j<=a-1;j++)
            scanf("%d",&qipan[i][j]);
    int p=0;
    int m=0;
    for(i=0;i<=a-1;i++)
        for(j=0;j<=a-1;j++)
        {
            for(k=0;k<=a-1;k++)
            {
                if(p<=qipan[i][k])
                    p=qipan[i][k];
            }
            m=qipan[i][j];
            for(q=0;q<=a-1;q++)
            {
                if(m>=qipan[q][j])
                    m=qipan[q][j];
            }
            if(qipan[i][j]==p&&p==m)
            {
                printf("%d %d",i,j);
                b++;
            }
        }
    
    if(b==0)
        printf("no\n");
}

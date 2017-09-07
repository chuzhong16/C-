#include <stdio.h>
int main()
{
	int n,i,score,sum;
	float average;
	printf("请输入全班总人数%%d: \n");
	scanf("%d",&n);
	i=sum=0;
	do
	{
		i++;
		printf("请输入第%d同学的成绩：\n",i);
		scanf("%d",&score);
		sum+=score;
	}
	while(i<n);
	average=(float)sum/n;
	printf("全班同学的平均成绩为： %2f.\n",average);
}
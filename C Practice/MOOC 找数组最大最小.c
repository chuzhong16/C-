#include <stdio.h>
int a[105][105];
int main(){
	int n;
	while (~scanf("%d",&n)){
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
int k=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				int flag=0;
				for (int ii=0;ii<n;ii++){
	
					if (a[ii][j]<a[i][j]){
						flag=1;
						break;
					}
				}
				for (int jj=0;jj<n;jj++){
				
					if (a[i][jj]>a[i][j]){
						flag=1;
						break;
					}
				}
				if (flag==0){
					printf("%d %d\n",i,j);
k++;
				}
			}
		}
if (!k) printf("NO\n");
	}
	return 0;
}
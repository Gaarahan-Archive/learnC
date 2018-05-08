#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu{
        char name[8];
        int sex;
        };
int main(){
	struct stu s[50];
	int n,i,j=0,k=0,p=0,q=0,b[25],g[25];
	char name[50][8],**boy,**girl;
	scanf("%d",&n);
	if(n<=0) exit(0);
	boy=(char **)malloc(sizeof(char)*n/2);
	girl=(char **)malloc(sizeof(char)*n/2);

	for(i=0;i<n/2;i++){
		boy[i]=(char *)malloc(sizeof(char)*8);
		girl[i]=(char *)malloc(sizeof(char)*8);
	}
	for(i=0;i<n;i++){
		scanf("%d %s",&s[i].sex,s[i].name);
		if(s[i].sex==0){ 
			strcpy(girl[j],s[i].name);
			g[j++]=i;
			}
		else {
			strcpy(boy[k],s[i].name);
			b[k++]=i;
		}
	}
	for(j=0;j<n/2; j++)
		if(s[j].sex==0){
                if(g[p] > b[n/2-p-1])
                        printf("%s %s\n",boy[n/2-p-1],girl[p]);
                else
                        printf("%s %s\n",girl[p],boy[n/2-p-1]);
        		p++;
		}
		else 	{
				if(b[q] < g[n/2-p-1])
                        printf("%s %s\n",boy[q],girl[n/2-q-1]);
                else
                        printf("%s %s\n",girl[n/2-q-1],boy[q]);
            	q++;
            	}
}

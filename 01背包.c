#include<stdio.h>

int max(int a, int b){
	return (a > b)?a:b;
}

int main(){
	int dp[100]={0};
	int i;
	int n  = 5;
	int g,v;
  int w[5] = {1,2,5,7,3};//存储物品的重量
  int t[5] = {2,4,6,3,3};//存储物品的价值
	int c,d;
	
	
	printf("输入物品数量n:\n");
	scanf("%d",&n);
	
  printf("输入背包容量ｃ:\n");
  scanf("%d",&c);

	for(i = 0; i < n;i++){
		for(v = c;v > w[i];v--){
      if(v > w[i])
      dp[v] = max(dp[c],dp[v - w[i]] + t[i]);
    }
	}

  for(i = 0; i <= c; i++){
    printf("%d:%d\n",i,dp[i]);
  }

  printf("%d", dp[c]);
  	
}

#include <stdio.h>  
    #include <algorithm>  
    using namespace std;  
          
        int cmp(int a,int b)  
      {  
              return a<b;  
          }  
      
    int main()  
      {  
              int n;  
              while(~scanf("%d",&n),n)  
              {  
                          int i,price[2013]= {0},dp[2013] = {0};  
                          for(i = 1; i<=n; i++)  
                              scanf("%d",&price[i]);  
                          sort(price+1,price+1+n,cmp);  
                          int MAX=price[n];  
                          int j,m;  
                          scanf("%d",&m);  
                          if(m<5)//低于5元不能购买  
                          {  
                                          printf("%d\n",m);  
                                          continue;  
                                      }  
                          m-=5;//取出5元用于购买最贵的物品  
                          for(i = 1; i<n; i++)//01背包  
                          {  
                                          for(j = m;j>=price[i];j--)  
                                          {  
                                                              dp[j] = max(dp[j],dp[j-price[i]]+price[i]);  
                                                          }  
                                      }  
                          printf("%d\n",m+5-dp[m]-MAX);  
                      }  
            
              return 0;  
          }  

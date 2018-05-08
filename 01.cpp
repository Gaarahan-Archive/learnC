#include <iostream>
 using namespace std ; 
 const  int V = 1000 ;  //总成本b 
 const  int U = 1000 ;  //总成本a 
 const  int T = 5 ;    //物品的种类 
 
 int f[U+1][V+1] ;                                    //可以不装满 
 int w[T] = {8 , 10 , 4 , 5 , 5};                      //价值 
 int a[T] = {600 , 400 , 200 , 200 , 300};             //每一个的体积 
 int b[T] = {800 , 400 , 200 , 200 , 300};
 const int INF = -66536  ;
   
 int package()
 {
    for(int i = 1 ; i <= U ;i++) //条件编译，表示背包可以不存储满
      for(int j = 1 ; j <= V ;j++)
      f[i][j] = INF ;    
      
      f[0][0] = 0 ; //01
    
    for(int i = 0 ; i < T ; i++)
    {
      for(int u = U ; u >= a[i] ;u--) //必须全部从V递减到0
         {         
           for(int v = V ; v >= b[i] ;v--)                           
              f[u][v] = max(f[u-a[i]][v-b[i]] + w[i] , f[u][v])  ; //此f[v]实质上是表示的是i-1次之前的值。
         }                 
    }
    return f[U][V] ;        
 }
 
 int main()
 {
      
   int temp =package() ;   
   cout<<temp<<endl     ;   
   return 0 ;    
 } 

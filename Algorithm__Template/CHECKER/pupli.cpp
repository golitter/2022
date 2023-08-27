#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll dp[40][200]={1};

int main(){
   ll n,p,sum;
   dp[0][0]=1;
   cin>>n;
   p=1;
   for(int i=0;i<n;i++){
       p*=4;
   }
   for(int i=1;i<=n;i++){
       for(int j=1;j<=4*i;j++){
           for(int k=1;k<=4;k++){
               if(j-k>=0){
                   dp[i][j]+=dp[i-1][j-k];
               }
           }
       }
   }
   sum=0;
   for(int i=3*n;i<=4*n;i++){
       sum+=dp[n][i];
   }
   int q=__gcd(sum,p);
   cout<<sum/q<<"/"<<p/q<<endl;
   return 0;

}
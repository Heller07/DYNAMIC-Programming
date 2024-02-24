#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>&dp){
        if(n<=1)return n;

        if(dp[n]!=-1) return dp[n];

        dp[n] = fib(n-1, dp) + fib(n-2, dp);
        return dp[n];
}

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
                dp[i] = dp[i-2]+dp[i-1];
        }
        cout<<dp[n]<<endl;
        //return dp[n+1];
}



}

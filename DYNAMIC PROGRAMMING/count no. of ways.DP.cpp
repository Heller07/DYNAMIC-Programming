#include <bits/stdc++.h>
#define MOD 1000000007 
//BY recursion
int solve(long long nStairs,int i){
    if(i==nStairs){
        return 1;
    }
    if(i>nStairs){
        return 0;
    }
    return solve(nStairs,i+1)+solve(nStairs,i+2)%MOD;
}

int countDistinctWays(int nStairs) {
    //  Write your code here.
    int ans = solve(nStairs,0);
    return ans;
}

//BY DP BOTTOM UP+space optimisation
#include <bits/stdc++.h> 
#define MOD 1000000007
int countDistinctWays(int nStairs) {
    int prev1=1,prev2=1,curr;
    for(int i=2;i<=nStairs;i++)
        curr=(prev1+prev2)% MOD,prev2=prev1,prev1=curr;
    return prev1;
}
//without space optimisation
#include <bits/stdc++.h>
int countDistinctWays(int n) {
if (n <= 1) {
return 1;
}
vector<int> dp(n + 1, 0);
dp[0]=1;
dp[1]=1;
const int mod = 1e9 + 7;
for(int i=2;i<=n;++i){
dp[i]=(dp[i-1] + dp[i-2])%mod;
}
return dp[n];
}



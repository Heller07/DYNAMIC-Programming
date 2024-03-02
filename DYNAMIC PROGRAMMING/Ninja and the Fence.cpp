//RECURSION
//SC AND TC SAME aS PREVIOUS
#define MOD 1000000007 
#include <bits/stdc++.h> 
int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;

}
int mul(int a,int b){
    return ((a%MOD) * (b%MOD))%MOD;

}
int solve(int n,int k){
    //base case
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k,mul(k,k-1));
    }
    int ans = add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
    return ans;
}
int numberOfWays(int n, int k) {
    // Write your code here.
    return solve(n,k);
}
//RECURSION+MEMOIZATION OR TOP DOWN
#define MOD 1000000007 
#include <bits/stdc++.h> 
int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;

}
int mul(int a,int b){
    return (a%MOD * 1ll * b%MOD)%MOD;

}
int solvemem(int n,int k, vector<int> &dp){
    //base case
    if(n==1){
        return k;
    }
    if (n == 2) {
        return add(k, mul(k, k - 1));
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = add(mul(solvemem(n-2,k,dp),k-1),mul(solvemem(n-1,k,dp),k-1));
    return dp[n];
}
int numberOfWays(int n, int k) {
    // Write your code here.
    vector<int> dp(n+1,-1);
    return solvemem(n,k,dp);
}
//TABULATION OR BOTTOM UP
#define MOD 1000000007 
#include <bits/stdc++.h> 
int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;

}
int mul(int a,int b){
    return (a%MOD * 1ll * b%MOD)%MOD;

}
int solvetab(int n,int k){
    //base case
    vector<int> dp(n+1,0);
    dp[0] = 0;
    dp[1] = k;
    dp[2] = add(k,mul(k,k-1));
    for(int i = 3;i<=n;i++){
        dp[i] = add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];

}
int numberOfWays(int n, int k) {
    // Write your code here.
    return solvetab(n,k);
}
//SPACE OPTIMISATION
#define MOD 1000000007 
#include <bits/stdc++.h> 
int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;

}
int mul(int a,int b){
    return (a%MOD * 1ll * b%MOD)%MOD;

}
int solvetab(int n,int k){
    //base case
    
    int prev2 = k;
    int prev1 = add(k,mul(k,k-1));
    for(int i = 3;i<=n;i++){
        int ans = add(mul(prev2,k-1),mul(prev1,k-1));
        prev2 = prev1;
        prev1 = ans;
            }
    return prev1;

}


int numberOfWays(int n, int k) {
    // Write your code here.
    
    return solvetab(n,k);
}


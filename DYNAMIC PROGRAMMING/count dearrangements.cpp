//RECURSION
//SC AND TC IS SAME AS PREVIOUS PROBLEMS
#define MOD 1000000007

long long int countDerangements(int n) {
    // Write your code here.
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    int ans = (n-1)*((countDerangements(n-1)%MOD)+(countDerangements(n-2)%MOD))%MOD);
    return ans;
}
//RECURSION + MEMOIZATION
#define MOD 1000000007
#include <vector>
long long int solvemem(int n,vector<long long int> &dp){
    //base case
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = (n-1)*((solvemem(n-1,dp)%MOD)+(solvemem(n-2,dp)%MOD))%MOD;
    return dp[n];
}

long long int countDerangements(int n) {
    // Write your code here.
    vector<long long int> dp(n+1,-1);
    return solvemem(n,dp);

}
//tabulation
#define MOD 1000000007
#include <vector>
long long int solvetab(int n){
    
    vector<long long int> dp(n+1,0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3;i<=n;i++){
        long long int first = dp[i-1]%MOD;
        long long int second = dp[i-2]%MOD;
        long long int sum  = (first+second)%MOD;
        long long int ans = ((i-1)*sum)%MOD;
        dp[i] = ans;
    }
    return dp[n];
}
long long int countDerangements(int n) {
    // Write your code here.
    return solvetab(n);
}
//space optimisation
#define MOD 1000000007
#include <vector>
long long int solvetab(int n){
    
    
    long long int prev2 = 0;
    long long int prev1 = 1;
    for(int i = 3;i<=n;i++){
        long long int first = prev1%MOD;
        long long int second = prev2%MOD;
        long long int sum  = (first+second)%MOD;
        long long int ans = ((i-1)*sum)%MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int countDerangements(int n) {
    // Write your code here.
    
    return solvetab(n);

}

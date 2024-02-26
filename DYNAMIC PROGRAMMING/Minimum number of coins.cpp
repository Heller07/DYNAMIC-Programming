//RECURSION APPROACH OR TLE APPRAOACH
#include <bits/stdc++.h> 
int solverec(vector<int> &num, int x){
    //base case
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i = 0;i<num.size();i++){
        int ans = solverec(num,x-num[i]);
        if(ans != INT_MAX){
            mini = min(mini,1+ans);
        }
    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int ans = solverec(num,x);
    if(ans == INT_MAX){
        return -1;
            }
        return ans;

}

//RECURSION + MEMOIATION or TLE or TOP DOWN D
//TC == O(x*n) x = amount, n = no. of coins
//SC == O(x)
#include <bits/stdc++.h> 
int solvemem(vector<int> &num, int x,vector<int> &dp){
    //base case
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    if(dp[x] != -1){
        return dp[x];
    }
    int mini = INT_MAX;
    for(int i = 0;i<num.size();i++){
        int ans = solvemem(num,x-num[i],dp);
        if(ans != INT_MAX){
            mini = min(mini,1+ans);
        }
    }
    dp[x] = mini;
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int> dp(x+1,-1);
    int ans = solvemem(num,x,dp);
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}
//BOTTOM UP OR TABULATION
////TC == O(x*n) x = amount, n = no. of coins
//SC == O(x)
#include <bits/stdc++.h> 
int solvetab(vector<int> &num, int x){
    //base case
    vector<int> dp(x+1,INT_MAX);//dp array shown minimum no. of coins make sum i
    dp[0] = 0;
    for(int i = 1;i<=x;i++){
        for(int j = 0;j<num.size();j++){
          if (i - num[j] >= 0 && dp[i-num[j]] != INT_MAX) {
            dp[i] = min(dp[i],1+dp[i-num[j]]);
          }
        }
    }
    if(dp[x] == INT_MAX){
        return -1;
    }
    return dp[x];

}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
   return solvetab(num,x);
}

//SPACE OPTIMISATION NOT POSSIBLE

//TOP DOWN DP
class Solution {
public:
    int solve(vector<int> &cost, int n,vector<int> &dp){
        //base case
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        //step 3
        if(dp[n] != -1){
            return dp[n];
        }
        //step 2
        dp[n] = cost[n] + min(solve(cost,n-1,dp),solve(cost,n-2,dp));//memoization
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        //step 1
        vector<int> dp(n+1,-1);
        int ans = min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return ans;
    }
};
//BOTTOM UP TABULATION
//TC and SC = O(n)
class Solution {
public:
    int solve(vector<int> &cost, int n){
        // step 1:creation an dp array
        vector<int> dp(n+1);
        //step 2:base case analysis
        dp[0] = cost[0];
        dp[1] = cost[1];

        //step 3
        for(int i = 2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        return solve(cost,n);

    }
};

//SPACE OPTIMISATION
//O(n) = TC
//SC = O(1)
class Solution {
public:
    int solve(vector<int> &cost, int n){//TC = O(n)//SC = O(n)+O(n)
        int prev1,prev2;
        prev2 = cost[0];
        prev1 = cost[1];
        //step 3
        for(int i = 2;i<n;i++){
            int curr = cost[i] + min(prev1,prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost,n);
    }
};


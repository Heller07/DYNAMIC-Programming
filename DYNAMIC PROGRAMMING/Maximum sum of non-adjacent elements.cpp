#include <bits/stdc++.h> 
//RECURSION
int solve(vector<int> &nums,int n){
    //basse case
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    int incl = solve(nums,n-2) + nums[n];
    int excl = solve(nums,n-1) + 0;
    return max(incl,excl);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int ans = solve(nums,n-1);
    return ans;
}

//RECURSION + MEMOIZATION or TOP DOWN
#include <bits/stdc++.h> 
int solvemem(vector<int> &nums,int n,vector<int> &dp){
    //base case
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int incl = solvemem(nums,n-2,dp) + nums[n];
    int excl = solvemem(nums,n-1,dp) + 0;
    dp[n] = max(incl,excl);
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,-1);
    return solvemem(nums,n-1,dp);

}

//TABULATION OR BOTTOM UP
//TC SC == O(n)
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
int solvetab(vector<int> &nums){
    
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] = nums[0];
    for(int i = 1; i < n; i++) {
    if (i == 1) {
        dp[i] = max(nums[0], nums[1]); // Choose the maximum between the first two elements
    } else {
        int incl = dp[i-2] + nums[i]; // For subsequent elements, use i-2
        int excl = dp[i-1];
        dp[i] = max(incl, excl);
    }
}
    return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solvetab(nums);
}


//SPACE OPTIMISATION
//new SC = O(1)
#include <bits/stdc++.h> 
int solvetab(vector<int> &nums){
    
    int n = nums.size();
    
    int prev2 = 0;
    int prev1 = nums[0];
    for(int i = 1;i<n;i++){
        int incl = prev2+nums[i];
        int excl = prev1 + 0;
        int ans = max(incl,excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    
    return solvetab(nums);
}

    


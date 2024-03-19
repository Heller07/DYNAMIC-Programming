//Recursion
//TC is exponential
int solve(int n,vector<int> &days, vector<int> &cost,int index){
    //base case
    if(index>=n){
        return 0;
    }
    //1 day pass
    int option1 = cost[0]+solve(n,days,cost,index+1);
    int i;
    //7 day pass
    for(i = index;i<n && days[i]<days[index]+7;i++);//adding 7 in days after taking pass

    int option2 = cost[1]+solve(n,days,cost,i);

    //30 days pass
    for(i = index;i<n && days[i]<days[index]+30;i++);//adding 7 in days after taking pass

    int option3 = cost[2]+solve(n,days,cost,i);
    return min(option1,min(option2,option3));
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    return solve(n,days,cost,0);
}
//Top down
//TC O(1) as year as 365 days which is constant
int solvemem(int n,vector<int> &days, vector<int> &cost,int index,vector<int>&dp){
    //base case
    if(index>=n){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }
    //1 day pass
    int option1 = cost[0]+solve(n,days,cost,index+1);
    int i;
    //7 day pass
    for(i = index;i<n && days[i]<days[index]+7;i++);//adding 7 in days after taking pass

    int option2 = cost[1]+solve(n,days,cost,i);

    //30 days pass
    for(i = index;i<n && days[i]<days[index]+30;i++);//adding 7 in days after taking pass

    int option3 = cost[2]+solve(n,days,cost,i);
    dp[index] = min(option1,min(option2,option3));
    return dp[index];


}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    return solve(n,days,cost,0,dp);
}
//bottom up
//TC is O(n)
int solvetab(int n,vector<int> &days, vector<int> &cost){
    //base case
    vector<int> dp(n+1,INT_MAX);
    dp[n] = 0;
    
    for(int k = n-1;k>=0;k--){
        //1 day pass
    int option1 = cost[0]+dp[k+1];
    int i;
    //7 day pass
    for(i = k;i<n && days[i]<days[k]+7;i++);//adding 7 in days after taking pass

    int option2 = cost[1]+dp[i];

    //30 days pass
    for(i = k;i<n && days[i]<days[k]+30;i++);//adding 7 in days after taking pass

    int option3 = cost[2]+dp[i];
    dp[k] = min(option1,min(option2,option3));
    }
    return dp[0];
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    return solvetab(n,days,cost);
}

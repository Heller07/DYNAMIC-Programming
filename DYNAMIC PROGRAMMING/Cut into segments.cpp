#include <limits.h>
int solve(int n,int x,int y,int z){
	//base case
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}
	int a = solve(n-x,x,y,z)+1;// no. of segments
	int b = solve(n-y,x,y,z)+1;
	int c = solve(n-z,x,y,z)+1;

	int ans = max(a,max(b,c));
	return ans;
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	int ans = solve(n,x,y,z);
	if(ans<0){
		return 0;
	}
	return ans;
}

//RECURSION + MEMOIZATION OR TOP DOWN DP
//TC AND SC IS O(N)
#include <limits.h>
int solvemem(int n,int x,int y,int z,vector<int> &dp){
	//base case
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}
	if(dp[n] != -1){
		return dp[n];//pehle se store h to vo return kr dena 
	}
	int a = solvemem(n-x,x,y,z,dp)+1;// no. of segments
	int b = solvemem(n-y,x,y,z,dp)+1;
	int c = solvemem(n-z,x,y,z,dp)+1;

	dp[n] = max(a,max(b,c));
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	vector<int> dp(n+1,-1);//dp[i] represent ki i length ki rode ke max kitne segment ho skte h
	//n+1 isliye kyuki vector 0 base indexing hota h or hame n length ki rode bhi chaiye
	int ans = solvemem(n,x,y,z,dp);
	if(ans<0){
		return 0;
	}
	return ans;
}
//TABULATION OR BOTTOM UP
//TC AND SC IS O(N)
#include <limits.h>
int solvetab(int n,int x,int y,int z){
	vector<int> dp(n+1,INT_MIN);
	dp[0] = 0;
	for(int i = 1;i<=n;i++){
		if(i-x>=0){
			dp[i] = max(dp[i],dp[i-x]+1);
		}
		if(i-y>=0){
			dp[i] = max(dp[i],dp[i-y]+1);
		}
		if(i-z>=0){
			dp[i] = max(dp[i],dp[i-z]+1);
		}

	}
		if(dp[n]<0){
			return 0;
		}
		else{
			return dp[n];
					}
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	return solvetab(n,x,y,z);
}
//space optimisation not possible

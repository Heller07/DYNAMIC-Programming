#include<bits/stdc++.h>
using namespace std;
//BOTTOM UP approach
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


//TOP DOWN approach
#include<bits/stdc++.h>
using namespace std;
int fib(int n, vector<int> &dp){
//     base case
    if(n <= 1){
        return n;
    }
    
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> dp(n+1);
    for(int i = 0; i<=n; i++){
        dp[i] = -1;
    }
    cout<<fib(n, dp)<<endl;
}


//SPACE OPTIMISATION
#include<bits/stdc++.h>
using namespace std;



int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;
        int prev1 = 1;
        int prev2 = 0;
        
        if(n==0){
                return prev2;
        }
        for(int i=2;i<=n;i++){
                int curr = prev1 + prev2;
                prev2 = prev1;
                prev1 = curr;
        }  
        cout<<prev1<<endl;
        //return dp[n+1];
}

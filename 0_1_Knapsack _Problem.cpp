Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

Examples :

Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.



int dp[1005][1005];
  
  int solve(int i,int w,vector<int> &val,vector<int> &wt)
  {
      if(i==0||w==0)
      {
          return 0;
      }
      if(dp[i][w]!=-1)
      {
          return dp[i][w];
      }
      if(wt[i-1]<=w)
      {
          dp[i][w]= max(val[i-1]+solve(i-1,w-wt[i-1],val,wt),solve(i-1,w,val,wt));
      }
      else
      {
          dp[i][w]= solve(i-1,w,val,wt);
      }
      return dp[i][w];
      
  }
  
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        memset(dp,-1,sizeof(dp));
        int n=val.size();
        return solve(n,W,val,wt);
    }
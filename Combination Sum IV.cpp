class Solution {
public:
    int n;
    int solve(int ind, int target, vector<int>& nums, vector<vector<int>> &dp){

        if(ind>=n){
            if(target==0){
                return 1;
            }
            return 0;
        }

        if(dp[ind][target]!=-1) return dp[ind][target];

        int take = 0;
        if(target>=nums[ind]){
            take += solve(0, target-nums[ind], nums, dp);
        }

        int notTake = solve(ind+1, target, nums, dp);

        return dp[ind][target] = take + notTake;    
    }
    int combinationSum4(vector<int>& nums, int target){

        n = nums.size();
        
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(0, target, nums, dp);
        
    }
};

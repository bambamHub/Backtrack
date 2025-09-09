Approach 1 ->
class Solution {
public:
    int n;
    void solve(int ind, vector<int>& nums, vector<int> &ds, set<vector<int>> &ans){
        
        if(ind==n){
            if(ds.size()>=2){
                ans.insert(ds);
            }
            return;
        }  

        if(ds.empty() || nums[ind] >= ds.back()){
            ds.push_back(nums[ind]);
            solve(ind+1, nums, ds, ans);
            ds.pop_back();
        }

        solve(ind+1, nums, ds, ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums){

        n = nums.size();

        set<vector<int>> ans;
        vector<int> ds;

        solve(0, nums, ds, ans);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
        
    }


--- Approach -> 2
  class Solution {
public:
    int n;
    void solve(int ind, vector<int>& nums, vector<int> &ds, vector<vector<int>> &ans){
        
        if(ds.size()>=2){
            ans.push_back(ds);
        }
        
        unordered_set<int> st;
        for(int j=ind; j<n; j++){
            if((ds.empty() || nums[j] >= ds.back()) && (st.find(nums[j])==st.end()) ){
                ds.push_back(nums[j]);
                solve(j+1, nums, ds, ans);
                ds.pop_back();

                st.insert(nums[j]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums){

        n = nums.size();

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, nums, ds, ans);
        return ans;
    }
};
};

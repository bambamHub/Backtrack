class Solution {
public:
    int n;
    int res;
    void solve(int ind, vector<int>& nums, unordered_map<int,int> &mp, int k ){

        if(ind==n){
            res++;
            return;
        }

        if(!mp[nums[ind]-k] && !mp[nums[ind]+k]){
            mp[nums[ind]]++;
            solve(ind+1, nums, mp, k);
            mp[nums[ind]]--;
        }
        solve(ind+1,nums, mp, k);
    }
    int beautifulSubsets(vector<int>& nums, int k){

        n = nums.size();

        unordered_map<int,int> mp;
        res = 0;

        solve(0, nums, mp, k);
        return res-1;
    }
};

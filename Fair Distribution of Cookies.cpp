class Solution {
public:
    int n;
    int res = INT_MAX;
    void solve(int ind, int k, vector<int>& cookies, vector<int> &children){

        if(ind>=n){
            int unfairness = *max_element(children.begin(), children.end());
            res = min(res, unfairness);
            return;
        }
        
        int cookie = cookies[ind];
        for(int j=0; j<k; j++){
            children[j] += cookies[ind];
            solve(ind+1, k, cookies, children);
            children[j] -= cookies[ind];
        }
    }
    int distributeCookies(vector<int>& cookies, int k){

        n = cookies.size();

        vector<int> children(k, 0);
        solve(0, k, cookies, children);
        return res;
    }
};

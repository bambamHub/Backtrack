class Solution {
public:
    void solve(string &curr, vector<string> &ans, int n){

        // Base Case
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }

        for(char ch='a'; ch<='c'; ch++){
            if(curr.size()!=0 && curr.back()==ch) continue;
            curr.push_back(ch);
            solve(curr, ans, n);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {

        vector<string> ans;
        string curr = "";
        solve(curr, ans, n);
        if(k>ans.size()){
            return "";
        }
        return ans[k-1];
        
    }
};

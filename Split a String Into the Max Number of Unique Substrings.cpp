class Solution {
public:
    int n;
    void solve(int i, int &maxCnt, int currCnt, string &s, unordered_set<string> &st){

        if(currCnt + (n-i) <= maxCnt){
            return;
        }

        if(i==n){
            maxCnt = max(maxCnt, currCnt);
            return;
        }
        for(int j=i; j<n; j++){
            string sub = s.substr(i, j-i+1);
            if(st.find(sub)==st.end()){
                st.insert(sub);
                solve(j+1, maxCnt, currCnt+1, s, st);
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s){
        
        n = s.size();
        int maxCnt = 0;
        int currCnt = 0;
        unordered_set<string> st;
        solve(0, maxCnt, currCnt, s, st);
        return maxCnt;
        
    }
};

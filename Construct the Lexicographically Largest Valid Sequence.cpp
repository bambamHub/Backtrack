class Solution {
public:
    bool solve(int ind, int n, vector<int> &res, vector<bool> &used){

        if(ind>=res.size()){
            return true;
        }

        if(res[ind]!=-1){
            return solve(ind+1, n, res, used);
        }

        for(int num=n; num>=1; num--){

            if(used[num]){
                continue;
            }
            
            used[num] = true;
            res[ind] = num;

            if(num==1){
                if(solve(ind+1, n, res, used)==true){
                    return true;
                }
            }
            else{
                int j = ind + res[ind];

                if(j < res.size() && res[j]==-1){
                    res[j] = num;
                    if(solve(ind+1, n, res, used)==true){
                        return true;
                    }
                    res[j] = -1;
                }
            }
            used[num] = false;
            res[ind] = -1;
        }
        return false;
        
    }
    vector<int> constructDistancedSequence(int n){

        vector<int> res(2*n-1, -1);

        vector<bool> used(n+1, false);

        solve(0, n, res, used);
        return res;
        
    }
};

class Solution {
public:
    int n;
    int m;
    bool solve(int i, int j, int wordInd, string &word, vector<vector<char>>& board){

        // Base Case
        if(wordInd == word.size()) return true;

        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='$' || board[i][j]!=word[wordInd]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        int dr[] = {+1, 0, -1, 0};
        int dc[] = {0, -1, 0, +1};

        for(int ind=0; ind<4; ind++){
            int newi = i + dr[ind];
            int newj = j + dc[ind];

            if(solve(newi, newj, wordInd+1, word, board)){
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word){

        n = board.size();
        m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    if(solve(i, j, 0, word, board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

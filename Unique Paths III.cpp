class Solution {
public:
    int n;
    int m;
    int nonObstacles;
    int paths;
    void solve(int i, int j, int count, vector<vector<int>>& grid){

        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==-1) return;

        if(grid[i][j]==2){
            if(count == nonObstacles){
                paths++;
            }
            return;
        }

        int dr[] = {+1, 0, -1, 0};
        int dc[] = {0, -1, 0, +1};

        int temp = grid[i][j];
        grid[i][j] = -1;

        for(int ind=0; ind<4; ind++){
            int newi = i + dr[ind];
            int newj = j + dc[ind];

            solve(newi, newj, count+1, grid);
        }
        grid[i][j] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid){
        
        n = grid.size();
        m = grid[0].size();
        
        nonObstacles = 0;
        paths = 0;
        int start_x = 0;
        int start_y = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    nonObstacles++;
                }
                else if(grid[i][j]==1){
                    start_x = i;
                    start_y = j;
                }
                
            }
        }
        nonObstacles += 1;
        solve(start_x, start_y, 0, grid);
        return paths;
    }
};

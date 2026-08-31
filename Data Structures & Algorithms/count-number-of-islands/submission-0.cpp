class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()  ||  grid[0].empty())
        {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;

        auto dfs = [&](auto& self , int r ,  int c) -> void {
            if (r < 0 || c < 0 || r >= m || c  >= n ||  grid[r][c] == '0')
            {
                return;
            }

            grid [r][c] = '0';

            self(self, r - 1, c);
            self(self, r + 1, c);
            self(self, r , c - 1);
            self(self, r , c + 1);
        };

        for (int i =0; i<m ; i++){
            for (int j=0; j<n ; j++)
                {
                    if (grid[i][j] == '1')
                    {
                        islandCount++;
                        dfs(dfs, i ,j);
                    }
                }
        }

        return islandCount;
    }
};
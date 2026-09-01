#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};

        int rows = heights.size();
        int cols = heights[0].size();

        std::vector<std::vector<bool>> pacific(rows, std::vector<bool>(cols, false));
        std::vector<std::vector<bool>> atlantic(rows, std::vector<bool>(cols, false));

        // Helper DFS lambda function
        auto dfs = [&](auto& self, int r, int c, std::vector<std::vector<bool>>& visited) -> void {
            visited[r][c] = true;
            int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for (const auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                // Check bounds, unvisited status, and height condition (uphill/equal)
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    self(self, nr, nc, visited);
                }
            }
        };

        // Start DFS from horizontal borders: Pacific (top) & Atlantic (bottom)
        for (int c = 0; c < cols; ++c) {
            dfs(dfs, 0, c, pacific);
            dfs(dfs, rows - 1, c, atlantic);
        }

        // Start DFS from vertical borders: Pacific (left) & Atlantic (right)
        for (int r = 0; r < rows; ++r) {
            dfs(dfs, r, 0, pacific);
            dfs(dfs, r, cols - 1, atlantic);
        }

        // Collect all cells reachable from both oceans
        std::vector<std::vector<int>> result;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return grid[0][0];
    if (m < 0 || n < 0)
        return 1e5;

    if (dp[m][n] != -1)
        return dp[m][n];

    int up = solve(m - 1, n, grid, dp) + grid[m][n];
    int left = solve(m, n - 1, grid, dp) + grid[m][n];

    return dp[m][n] = min(up, left);
}
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solve(m - 1, n - 1, grid, dp);
}

// Tabulation
int solve(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[0][0];
            else
            {
                int right = 1e5, down = 1e5;
                if (i > 0)
                    down = dp[i - 1][j] + grid[i][j];
                if (j > 0)
                    right = dp[i][j - 1] + grid[i][j];
                dp[i][j] = min(down, right);
            }
        }
    }
    return dp[m - 1][n - 1];
}
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    return solve(m, n, grid, dp);
}

// Space Optimization
int solve(int m, int n, vector<vector<int>> &grid)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = grid[0][0];
            else
            {
                int right = 1e5, down = 1e5;
                if (i > 0)
                    down = prev[j] + grid[i][j];
                if (j > 0)
                    right = curr[j - 1] + grid[i][j];
                curr[j] = min(down, right);
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    return solve(m, n, grid);
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    return 0;
}
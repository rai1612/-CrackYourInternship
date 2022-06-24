#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    int up = solve(m - 1, n, dp);
    int left = solve(m, n - 1, dp);
    return dp[m][n] = up + left;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m - 1, n - 1, dp);
}

// Tabulation
int solve(int m, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int right = 0, down = 0;
                if (i > 0)
                    down = dp[i - 1][j];
                if (j > 0)
                    right = dp[i][j - 1];
                dp[i][j] = down + right;
            }
        }
    }
    return dp[m - 1][n - 1];
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m, n, dp);
}

// Space Optimization
int solve(int m, int n)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 1;
            else
            {
                int right = 0, down = 0;
                if (i > 0)
                    down = prev[j];
                if (j > 0)
                    right = curr[j - 1];
                curr[j] = down + right;
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}
int uniquePaths(int m, int n)
{

    return solve(m, n);
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    return 0;
}
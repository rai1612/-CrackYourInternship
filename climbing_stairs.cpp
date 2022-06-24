#include <bits/stdc++.h>
using namespace std;

// Memoization, Recursion space is used
int solve(int n, vector<int> &dp)
{
    if (n == 1 || n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

// Tabulation, No recursion space
int solve(int n, vector<int> &dp)
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

// Space Optimization, O(1) Space
int solve(int n)
{
    int prev = 1, prevprev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prevprev;
        prevprev = prev;
        prev = curr;
    }
    return prev;
}
int climbStairs(int n)
{
    return solve(n);
}
int main()
{
    std::ios_base::sync_with_stdio(false);

    return 0;
}
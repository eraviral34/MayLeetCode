class Solution {
    int min(int a,int b,int c)
    {
        if(a<=b && a<=c)
            return a;
        if(b<=a && b<=c)
            return b;
        return c;
    }
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j];
                else if (matrix[i][j])
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;

                res += dp[i][j];
            }
        }
        return res;
    }
};
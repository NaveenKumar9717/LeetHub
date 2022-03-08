class Solution
{
public:
    int numDecodingsH(string s, int i, int *dp)
    {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (i == s.size() - 1)
            return 1;
        if (dp[i] > 0)
            return dp[i];
        string b = s.substr(i, 2);

        int op1 = numDecodingsH(s, i + 1, dp);
        int op2 = 0;
        if (stoi(b) <= 26 && stoi(b) > 0)
        {
            op2 = numDecodingsH(s, i + 2, dp);
        }
        dp[i] = op1 + op2;
        return dp[i];
    }
    int numDecodings(string s)
    {
        int n = s.length();
        int dp[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = 0;
        return numDecodingsH(s, 0, dp);
    }
};
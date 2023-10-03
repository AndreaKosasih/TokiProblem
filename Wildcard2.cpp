#include <iostream>
using namespace std;

bool strmatch(string str, string pattern) {
    int m = str.length(), n = pattern.length();

    vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    for (int j = 1; j <= n; j++)
        if (pattern[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (pattern[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            else if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
        }
    }

    return dp[m][n];
}

int main() {
    string s, pattern;
    int n;
    cin >> pattern >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (strmatch(s, pattern))
            cout << s << endl;
    }
    return 0;
}

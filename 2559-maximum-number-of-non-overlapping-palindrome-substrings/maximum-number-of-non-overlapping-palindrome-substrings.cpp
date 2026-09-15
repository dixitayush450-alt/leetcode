class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] true hoga agar s[i...j] palindrome hai
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Har single character khud ek palindrome hota hai
        for (int i = 0; i < n; i++) {
            pal[i][i] = true;
        }

        // Length 2 se lekar length n tak ke substrings check karenge
        for (int len = 2; len <= n; len++) {

            // Substring ka starting index
            for (int i = 0; i + len <= n; i++) {

                // Substring ka ending index
                int j = i + len - 1;

                // Palindrome tabhi hoga jab:
                // 1. First aur last character same ho
                // 2. Beech ka substring palindrome ho
                if (s[i] == s[j] &&
                    (len == 2 || pal[i + 1][j - 1])) {

                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = first i characters mein maximum valid palindromes
        vector<int> dp(n + 1, 0);

        // i ko substring ke ending position ki tarah use karenge
        for (int i = 1; i <= n; i++) {

            // Option 1:
            // Current character ko kisi palindrome mein use nahi karna
            dp[i] = dp[i - 1];

            // Har possible starting point j check karo
            for (int j = 0; j < i; j++) {

                // s[j...i-1] ki length at least k honi chahiye
                int len = i - j;

                if (len >= k && pal[j][i - 1]) {

                    // Agar s[j...i-1] ek valid palindrome hai,
                    // toh isse pehle ke j characters ka answer
                    // dp[j] mein stored hai.
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // Puri string ke liye maximum answer
        return dp[n];
    }
};
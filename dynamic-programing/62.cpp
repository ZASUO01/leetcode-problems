// Matrix
// Unique Paths
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i + 1 < m) {
          dp[i + 1][j] += dp[i][j];
        }

        if (j + 1 < n) {
          dp[i][j + 1] += dp[i][j];
        }
      }
    }

    return dp[m - 1][n - 1];
  }
};

int main() {
  Solution s;

  int m1 = 3;
  int n1 = 7;

  cout << s.uniquePaths(m1, n1) << endl;

  return 0;
}

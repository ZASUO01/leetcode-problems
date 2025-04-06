// Matrix
// Minimum Falling Path Sum
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (a < b ? a : b)

class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    for (int i = 0; i < cols; i++) {
      dp[0][i] = matrix[0][i];
    }

    int min;
    for (int i = 1; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (j == 0) {
          dp[i][j] = MIN(dp[i - 1][j], dp[i - 1][j + 1]);
        }

        else if (j == cols - 1) {
          dp[i][j] = MIN(dp[i - 1][j - 1], dp[i - 1][j]);
        }

        else {
          min = MIN(dp[i - 1][j - 1], dp[i - 1][j]);
          dp[i][j] = MIN(min, dp[i - 1][j + 1]);
        }

        dp[i][j] += matrix[i][j];
      }
    }

    sort(dp[rows - 1].begin(), dp[rows - 1].end());

    return dp[rows - 1][0];
  }
};

int main() {
  Solution s;

  vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

  cout << s.minFallingPathSum(matrix) << endl;
  return 0;
}

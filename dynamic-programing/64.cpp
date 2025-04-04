// Matrix
// Minimum Path Sum
#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (a < b ? a : b)

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int i, j;
    int rows = grid.size();
    int columns = grid[0].size();

    vector<vector<int>> dp(rows, vector<int>(columns, 0));
    dp[0][0] = grid[0][0];

    for (j = 1; j < columns; j++) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (i = 1; i < rows; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    int top, left;
    for (i = 1; i < rows; i++) {
      for (j = 1; j < columns; j++) {
        top = dp[i - 1][j] + grid[i][j];
        left = dp[i][j - 1] + grid[i][j];

        dp[i][j] = MIN(top, left);
      }
    }

    return dp[rows - 1][columns - 1];
  }
};

int main() {
  Solution s;

  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

  cout << s.minPathSum(grid) << endl;
}

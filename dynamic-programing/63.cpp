// Matrix
// Unique Paths II
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid[0][0] == 1) {
      return 0;
    }

    int rows = obstacleGrid.size();
    int columns = obstacleGrid[0].size();
    vector<vector<int>> dp(rows, vector<int>(columns, 0));

    dp[0][0] = 1;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        if (i + 1 < rows && obstacleGrid[i + 1][j] != 1) {
          dp[i + 1][j] += dp[i][j];
        }

        if (j + 1 < columns && obstacleGrid[i][j + 1] != 1) {
          dp[i][j + 1] += dp[i][j];
        }
      }
    }

    return dp[rows - 1][columns - 1];
  }
};

int main() {
  Solution s;
  vector<vector<int>> grid1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  vector<vector<int>> grid2 = {{0, 1}, {0, 0}};
  vector<vector<int>> grid3 = {{0, 1}};

  cout << s.uniquePathsWithObstacles(grid1) << endl;
  cout << s.uniquePathsWithObstacles(grid2) << endl;
  cout << s.uniquePathsWithObstacles(grid3) << endl;

  return 0;
}

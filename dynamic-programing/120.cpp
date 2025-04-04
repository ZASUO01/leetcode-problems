// Matrix
// Triangle
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (a < b ? a : b)

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int height = triangle.size();
    int width = triangle[height - 1].size();

    vector<vector<int>> dp(height, vector<int>(width, 0));

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (j == 0) {
          dp[i][j] = triangle[i][j] + dp[i - 1][j];
        } else if (j < i) {
          dp[i][j] = triangle[i][j] + MIN(dp[i - 1][j - 1], dp[i - 1][j]);
        } else if (j == i) {
          dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
        }
      }
    }

    sort(dp[height - 1].begin(), dp[height - 1].end());

    return dp[height - 1][0];
  }
};

int main() {
  Solution s;

  vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  vector<vector<int>> triangle2 = {{-10}};

  cout << s.minimumTotal(triangle) << endl;
  cout << s.minimumTotal(triangle2) << endl;

  return 0;
}

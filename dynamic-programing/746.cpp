// Fibonacci style
// Min Cost Climbing Stairs
#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (a < b ? a : b)

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    int a, b;

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = cost[0];

    for (int i = 2; i <= n; i++) {
      dp[i] = MIN(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
    }
    a = dp[n];

    dp[1] = 0;
    dp[2] = cost[1];
    for (int i = 3; i <= n; i++) {
      dp[i] = MIN(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
    }
    b = dp[n];

    return MIN(a, b);
  }
};

int main() {
  Solution s;
  vector<int> cost = {10, 15, 20};
  vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

  cout << s.minCostClimbingStairs(cost) << endl;
  cout << s.minCostClimbingStairs(cost2) << endl;
  return 0;
}

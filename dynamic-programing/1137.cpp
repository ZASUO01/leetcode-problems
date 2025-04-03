// Fibonacci style
// N-th Tribonacci Number
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int tribonacci(int n) {
    if (n <= 0)
      return 0;
    if (n == 1 || n == 2)
      return 1;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
  }
};

int main() {
  Solution s;
  int n = 3;
  int n1 = 25;

  cout << s.tribonacci(n) << endl;
  cout << s.tribonacci(n1) << endl;

  return 0;
}

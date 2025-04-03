// Fibonacci style
// House Robber
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX(a, b) (a > b ? a : b)

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = nums[1];

    int max;
    for (int i = 2; i < n; i++) {
      max = 0;
      for (int j = i - 2; j >= 0; j--) {
        max = MAX(max, dp[j]);
      }
      dp[i] = nums[i] + max;
    }

    sort(dp.begin(), dp.end());

    return dp[n - 1];
  }
};

int main() {
  Solution s;
  vector<int> nums1 = {1, 2, 3, 1};
  vector<int> nums2 = {2, 7, 9, 3, 1};
  vector<int> nums3 = {2, 1, 1, 2};

  cout << s.rob(nums1) << endl;
  cout << s.rob(nums2) << endl;
  cout << s.rob(nums3) << endl;

  return 0;
}

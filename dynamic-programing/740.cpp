// Fibonacci style
// Delete and Earn
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX(a, b) (a > b ? a : b)

class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    int n = nums.size();
    vector<int> values;

    sort(nums.begin(), nums.end());

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
      sum += nums[i];

      if (nums[i] != nums[i + 1]) {
        values.push_back(sum);
        sum = 0;

        if (nums[i] != nums[i + 1] - 1) {
          values.push_back(0);
        }
      }
    }

    values.push_back(nums[n - 1] + sum);
    n = values.size();

    if (n == 1) {
      return values[0];
    }

    vector<int> dp(n, 0);
    dp[0] = values[0];
    dp[1] = values[1];

    int max;
    for (int i = 2; i < n; i++) {
      max = 0;

      for (int j = i - 2; j >= 0; j--) {
        max = MAX(max, dp[j]);
      }

      dp[i] = values[i] + max;
    }

    sort(dp.begin(), dp.end());

    return dp[n - 1];
  }
};

int main() {
  Solution s;

  vector<int> nums1 = {3, 4, 2};
  vector<int> nums2 = {2, 2, 3, 3, 3, 4};
  vector<int> nums3 = {8, 10, 4, 9, 1, 3, 5, 9, 4, 10};

  cout << s.deleteAndEarn(nums1) << endl;
  cout << s.deleteAndEarn(nums2) << endl;
  cout << s.deleteAndEarn(nums3) << endl;

  return 0;
}

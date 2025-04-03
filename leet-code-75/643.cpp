// Maximum Average Subarray I
#include <iostream>
#include <vector>

using namespace std;

#define MAX(a, b) (a > b ? a : b)

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    int i;
    int size = nums.size();
    int sum = 0;
    double maxAverage;

    for (i = 0; i < k; i++) {
      sum += nums[i];
    }

    maxAverage = sum / (double)k;

    for (i = k; i < size; i++) {
      sum += (nums[i] - nums[i - k]);
      maxAverage = MAX(maxAverage, (sum / (double)k));
    }
    return maxAverage;
  }
};

int main() {
  Solution s;
  vector<int> input1 = {1, 12, -5, -6, 50, 3};
  vector<int> input2 = {5};
  int k1 = 4;
  int k2 = 1;

  cout << s.findMaxAverage(input1, k1) << endl;
  cout << s.findMaxAverage(input2, k2) << endl;

  return 0;
}

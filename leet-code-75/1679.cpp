// Max Number of K-Sum Pairs
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    int i = 0;
    int j = nums.size() - 1;
    int count = 0;

    sort(nums.begin(), nums.end());

    int sum;
    while (i < j) {
      sum = nums[i] + nums[j];

      if (sum == k) {
        count++;
        i++;
        j--;
      } else if (sum < k) {
        i++;
      } else {
        j--;
      }
    }

    return count;
  }
};

int main() {
  Solution s;

  vector<int> input1 = {1, 2, 3, 4};
  vector<int> input2 = {3, 1, 3, 4, 3};
  int k1 = 5;
  int k2 = 6;

  cout << s.maxOperations(input1, k1) << endl;
  cout << s.maxOperations(input2, k2) << endl;

  return 0;
}

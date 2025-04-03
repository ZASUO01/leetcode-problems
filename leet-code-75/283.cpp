// Move Zeroes
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int i, j;
    int size = nums.size();

    for (i = 0; i < size - 1; i++) {
      if (nums[i] == 0) {
        for (j = i + 1; j < size; j++) {
          if (nums[j] != 0) {
            int tmp = nums[j];
            nums[j] = nums[i];
            nums[i] = tmp;

            j = size;
          }
        }
      }
    }
  }
};

int main() {
  Solution s;

  vector<int> input = {0, 1, 0, 3, 12};
  s.moveZeroes(input);

  cout << "[ ";
  for (int i = 0; i < 5; i++) {
    cout << input[i] << " ";
  }
  cout << "]" << endl;

  return 0;
}

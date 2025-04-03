// Array prefixes and sufixes
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int size = nums.size();
    vector<int> prefixes(size);
    vector<int> sufixes(size);
    vector<int> solution(size);

    prefixes[0] = 1;
    sufixes[size - 1] = 1;

    for (int i = 1; i < size; i++) {
      prefixes[i] = prefixes[i - 1] * nums[i - 1];
      sufixes[size - 1 - i] = sufixes[size - i] * nums[size - i];
    }

    for (int i = 0; i < size; i++) {
      solution[i] = sufixes[i] * prefixes[i];
    }

    return solution;
  }
};

int main() {
  Solution s;

  vector<int> input = {1, 2, 3, 4};
  vector<int> output = s.productExceptSelf(input);

  int size = output.size();
  cout << "output: [ ";
  for (int i = 0; i < size; i++) {
    cout << output[i] << " ";
  }
  cout << "]" << endl;

  return 0;
}

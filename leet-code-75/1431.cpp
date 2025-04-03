#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    int i;
    int max = 0;
    int size = candies.size();

    vector<bool> result(size, false);

    for (i = 0; i < size; i++) {
      if (candies[i] > max) {
        max = candies[i];
      }
    }

    for (i = 0; i < size; i++) {
      if (candies[i] + extraCandies >= max) {
        result[i] = true;
      }
    }

    return result;
  }
};

int main() {
  Solution s;

  vector<int> candies = {2, 3, 5, 1, 3};
  int extraCandies = 3;

  vector<bool> result = s.kidsWithCandies(candies, extraCandies);
  int size = result.size();

  cout << "[";
  for (int i = 0; i < size; i++) {
    cout << result[i] << ",";
  }
  cout << "]" << endl;

  return 0;
}

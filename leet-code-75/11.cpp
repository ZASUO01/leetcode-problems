// Container With Most Water
#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

class Solution {
public:
  int maxArea(vector<int> &height) {
    int max = 0;
    int i = 0;
    int j = height.size() - 1;

    while (i < j) {
      int area = (j - i) * MIN(height[i], height[j]);
      max = MAX(max, area);

      if (height[i] < height[j]) {
        i++;
      } else {
        j--;
      }
    }

    return max;
  }
};

int main() {
  Solution s;

  vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  vector<int> height2 = {1, 1};
  cout << s.maxArea(height1) << endl;
  cout << s.maxArea(height2) << endl;

  return 0;
}

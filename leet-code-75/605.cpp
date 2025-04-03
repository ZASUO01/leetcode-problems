#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int size = flowerbed.size();

    if (n <= 0)
      return true;
    else if (size == 1) {
      if (n == 1 && flowerbed[0] == 0)
        return true;
      else
        return false;
    } else {
      int i = 0;
      if (flowerbed[i] == 0 && flowerbed[i + 1] != 1) {
        n--;
        flowerbed[i] = 1;
        i++;
        if (n == 0)
          return true;
      }

      for (i = 1; i < size - 1; i++) {
        if (n == 0)
          break;

        if (flowerbed[i] == 0 && flowerbed[i - 1] != 1 &&
            flowerbed[i + 1] != 1) {
          flowerbed[i] = 1;
          n--;
        }
      }

      if (flowerbed[size - 1] == 0 && flowerbed[size - 2] != 1) {
        n--;
      }

      if (n <= 0)
        return true;
      else
        return false;
    }
  }
};

int main() {
  Solution s;
  vector<int> v1 = {1, 0, 0, 0, 1};
  int n1 = 1;

  cout << s.canPlaceFlowers(v1, n1) << endl;

  vector<int> v2 = {1, 0, 0, 0, 1};
  int n2 = 2;

  cout << s.canPlaceFlowers(v2, n2) << endl;
  return 0;
}

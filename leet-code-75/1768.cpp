#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int i = 0;
    int sz1 = word1.size();
    int sz2 = word2.size();
    string merged = "";

    if (sz1 >= sz2) {
      for (i = 0; i < sz1; i++) {
        merged += word1[i];
        if (i < sz2)
          merged += word2[i];
      }
    } else {
      for (i = 0; i < sz2; i++) {
        if (i < sz1)
          merged += word1[i];
        merged += word2[i];
      }
    }

    return merged;
  }
};

int main() {
  string w1, w2;
  cin >> w1;
  cin >> w2;

  Solution s;

  string merged = s.mergeAlternately(w1, w2);
  cout << merged << endl;

  return 0;
}

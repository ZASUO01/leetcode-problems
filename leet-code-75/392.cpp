// Is Subsequence
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int i, j;
    int size1 = s.size();
    int size2 = t.size();

    if (size1 == 0) {
      return true;
    }

    bool result = false;

    j = 0;
    for (i = 0; i < size2; i++) {
      if (t[i] == s[j]) {
        j++;
      }

      if (j == size1) {
        result = true;
        break;
      }
    }

    return result;
  }
};

int main() {
  Solution s;

  string s1 = "abc";
  string t1 = "ahbgdc";

  string s2 = "axc";
  string t2 = "ahbgdc";

  cout << s.isSubsequence(s1, t1) << endl;
  cout << s.isSubsequence(s2, t2) << endl;
  return 0;
}

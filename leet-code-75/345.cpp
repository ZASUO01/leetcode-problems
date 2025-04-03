#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string reverseVowels(string s) {
    int i;
    int size = s.size();

    vector<char> myVowels;
    vector<int> pos;

    for (i = 0; i < size; i++) {
      if (isVowel(s[i])) {
        myVowels.push_back(s[i]);
        pos.push_back(i);
      }
    }

    reverse(myVowels.begin(), myVowels.end());

    size = pos.size();
    for (i = 0; i < size; i++) {
      s[pos[i]] = myVowels[i];
    }

    return s;
  }

private:
  bool isVowel(char ch) {
    bool result = false;
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < 10; i++) {
      if (ch == vowels[i]) {
        result = true;
        break;
      }
    }
    return result;
  }
};

int main() {
  Solution s;

  string input = "IceCreAm";

  cout << ('I' < 'e') << endl;

  cout << s.reverseVowels(input) << endl;

  return 0;
}

// Maximum Number Of Vowels in a Substring of Given Length
#include <iostream>
#include <string>

using namespace std;

#define MAX(a, b) (a > b ? a : b)

class Solution {
public:
  int maxVowels(string s, int k) {
    int i;
    int size = s.size();
    int maxVowels = 0;

    for (i = 0; i < k; i++) {
      if (isVowel(s[i]))
        maxVowels++;
    }

    int currentVowels = maxVowels;

    for (i = k; i < size; i++) {
      if (isVowel(s[i]))
        currentVowels++;
      if (isVowel(s[i - k]))
        currentVowels--;

      maxVowels = MAX(maxVowels, currentVowels);
    }

    return maxVowels;
  }

private:
  bool isVowel(const char ch) {
    bool result = false;
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++) {
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
  string input1 = "abciiidef";
  string input2 = "aeiou";
  string input3 = "leetcode";
  int k1 = 3;
  int k2 = 2;
  int k3 = 3;

  cout << s.maxVowels(input1, k1) << endl;
  cout << s.maxVowels(input2, k2) << endl;
  cout << s.maxVowels(input3, k3) << endl;

  return 0;
}

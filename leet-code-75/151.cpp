#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    int i;
    int size = s.size();
    string curr = "";
    vector<string> words;

    int start = 0;
    int end = size - 1;
    while (s[start] == ' ') {
      start++;
    }
    while (s[end] == ' ') {
      end--;
    }

    for (int i = start; i <= end; i++) {
      if (s[i] == ' ') {
        words.push_back(curr);
        curr = "";

        while (s[i + 1] == ' ')
          i++;
      } else {
        curr += s[i];
      }
    }

    words.push_back(curr);

    reverse(words.begin(), words.end());

    string reversed = "";

    size = words.size();
    reversed += words[0];
    for (int i = 1; i < size; i++) {
      reversed += ' ';
      reversed += words[i];
    }

    return reversed;
  }
};

int main() {
  Solution s;

  string input1 = "the sky is blue";
  string input2 = "  hello world  ";

  cout << s.reverseWords(input1) << endl;
  cout << s.reverseWords(input2) << endl;

  return 0;
}

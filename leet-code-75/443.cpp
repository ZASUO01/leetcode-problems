#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int compress(vector<char> &chars) {
    int i, j;
    int size = chars.size();
    int count = 1;
    char prev = chars[0];
    string compressed = "";

    compressed += prev;
    j = 0;
    chars[j] = prev;

    for (i = 1; i < size; i++) {
      if (chars[i] == prev) {
        count++;

        if (i == size - 1) {
          string str = to_string(count);
          compressed += str;

          for (int i = 0; i < str.size(); i++) {
            j++;
            chars[j] = str[i];
          }
        }
      } else {
        if (count > 1) {
          string str = to_string(count);
          compressed += str;

          for (int i = 0; i < str.size(); i++) {
            j++;
            chars[j] = str[i];
          }
        }

        count = 1;

        prev = chars[i];
        compressed += prev;

        j++;
        chars[j] = prev;
      }
    }

    size = compressed.size();

    return size;
  }
};

int main() {
  Solution s;

  vector<char> input = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  int output = s.compress(input);

  cout << output << endl;

  return 0;
}

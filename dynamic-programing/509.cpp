// Fibonacci style
// Fibonacci Number
#include <iostream>

using namespace std;

class Solution {
public:
  int fib(int n) {
    if (n <= 0)
      return 0;
    if (n == 1)
      return 1;

    int first = 0;
    int second = 1;
    int fib;

    for (int i = 2; i <= n; i++) {
      fib = first + second;
      first = second;
      second = fib;
    }

    return fib;
  }
};
int main() {
  Solution s;

  cout << s.fib(5) << endl;

  return 0;
}

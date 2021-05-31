/**
6
5 4 2
5 3 2
5 5 2
10 5 3
17 2 4
10 1 3
YES
NO
NO
YES
YES
NO
 * 
*/

#include <iostream>
#include <string>

using string = std::string;

const string theBallEnterHole(int N, int x, int k)
{
  string ans = "NO";
  if (x == N || x == 0) {
    ans = "YES";
  } else {
    int backward = N % k;

    if (x % k == 0 || (x - backward) % k == 0) {
      ans = "YES";
    }
  }
  return ans;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  size_t T;

  std::cin >> T;

  while (T--)
  {
    int N, x, k;

    std::cin >> N >> x >> k;

    std::cout << theBallEnterHole(N + 1, x, k) << "\n";
  }

  return 0;
}
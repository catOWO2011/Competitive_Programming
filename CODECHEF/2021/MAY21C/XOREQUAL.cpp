#include <iostream>

using num = long int;

num MOD = 1000000007;

num exponentiation(num base, num exp)
{
  if (exp == 0)
    return 1;
  if (exp == 1)
    return base % MOD;

  num t = exponentiation(base, exp / 2);
  t = (t * t) % MOD;

  if (exp % 2 == 0)
    return t;
  else
    return ((base % MOD) * t) % MOD;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  num T,
    N;

  std::cin >> T;

  while (T--)
  {
    std::cin >> N;
    std::cout << exponentiation(2, N - 1) << "\n";
  }

  return 0;
}
#include <iostream>

#include <cmath>
#include <vector>

using num = long int;

num MOD = 1000000007;


void naive_combs(std::vector<int> v, int N, int M, num& tuples)
{
  if (v.size() == N) {

    int c = -1;
    for (auto a: v) {
      // std::cout << a << " ";
      if (c == -1) {
        c = a;
      } else {
        c = (c & a);
      }
    }

    if (c == 0) {
      tuples++;
    }
    // std::cout << "\n";

    return;
  }

  if (v.size() > N) return;

  // std::cout << v.size() << "\n";

  for (size_t i = 0; i < pow(2, M); i++)
  {
    // v.push_back(i);
    std::vector<int> nv = v;
    nv.push_back(i);
    naive_combs(nv, N, M, tuples);
  }
}

num naive_number_of_tuples(int N, int M) {
  std::vector<int> A;
  num tuples = 0;
  naive_combs(A, N, M, tuples);

  return tuples;
}

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

num number_of_tuples(int N, int M)
{
  num base_n = exponentiation(2, N) - 1;

  num ans = exponentiation(base_n, M);

  return ans;
}

int main()
{

  size_t T;
  std::cin >> T;

  int N,M;

  while (T--)
  {
    std::cin >> N >> M;

    // std::cout << naive_number_of_tuples(N, M) << "\n";
    std::cout << number_of_tuples(N, M) << "\n";
  }

  return 0;
}
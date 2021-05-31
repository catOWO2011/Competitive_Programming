/**
 * 
 * Build an map of remainders
 * Sum the remainders with each number and its multiple
*/
#include <iostream>
#include <unordered_map>
#include <vector>

// Added to test
// #include <fstream>
// #include <ctime>

using u_map = std::unordered_map<int, int>;
using vector = std::vector<int>;

const long long get_number_of_pairs(int N, int M)
{
  long long ans = N - 1;
  int max_mod = 0,
    rem;
  u_map rems;
  vector v(N + 1);

  for (int n = 2; n <= N; n++)
  {
    rem = M % n;
    v[n] = rem;
    max_mod = rem > max_mod ? rem : max_mod;

    if (rems.find(rem) != rems.end())
    {
      rems[rem]++;
    }
    else
    {
      rems[rem] = 1;
    }
  }

  for (int n = 2; n <= N; n++)
  {
    rems[v[n]]--;
    int np = 0;
    int mod = v[n] + np;

    if (mod > max_mod) break;

    while (mod <= max_mod)
    {
      if (rems.find(mod) != rems.end() && rems[mod] > 0)
      {
        ans += rems[mod];
      }
      mod += n;
    }
  }

  return ans;
}



const int brute_force(int N, int M)
{
  int ans = 0;

  for (int a = 1; a < N; a++)
  {
    for (int b = a + 1; b <= N; b++)
    {
      if (((M % a) % b) == ((M % b) % a))
      {
        // std::cout << "(" << a << ", " << b << ")\n";
        ans++;
      }
    }
  }
  

  return ans;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  // std::ofstream out("out.txt");

  int T, N, M;
  std::cin >> T;
  while (T--)
  {
    std::cin >> N >> M;
    // std::cout << brute_force(N, M) << "\n";

    // clock_t t0 = clock();
    // out << brute_force(N, M) << "\n";
    // auto t1 = clock();
    // out << "Brute force time " << (t1 - t0) << "\n";

    // t0 = clock();
    // out << get_number_of_pairs(N, M) << "\n";
    // t1 = clock();
    // out << "Improved solution time " << (((float)(t1 - t0)) / CLOCKS_PER_SEC) << " seconds\n";

    // std::cout << brute_force(N, M) << "\n";

    std::cout << get_number_of_pairs(N, M) << "\n";
  }

  // out.close();

  return 0;
}
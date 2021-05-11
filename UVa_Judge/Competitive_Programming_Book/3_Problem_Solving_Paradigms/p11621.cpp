#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using ll = long long;
using vector = std::vector<ll>;

ll pows[2][33];

void const generate_pows()
{
  ll num;
  int i, j;

  pows[0][0] = 1;
  pows[1][0] = 1;
  pows[0][1] = 2;
  pows[1][1] = 3;

  for (i = 0; i < 2; i++)
  {
    for (j = 2; j < 33; j++)
    {
      pows[i][j] = pows[i][j-1]*pows[i][1];
    }
  }
}

void generate_samples(vector& samples)
{
  ll sample;
  for (size_t i = 0; i < 33; i++)
  {
    for (size_t j = 0; j < 32; j++)
    {
      // std::cout << pows[0][i] << "...." << pows[1][j] << "...\n";
      sample = pows[0][i] * pows[1][j];
      if (sample > 0 && sample <= pows[0][32]) {
        samples.push_back(sample);
      }
    }
  }
}

int main()
{
  generate_pows();

  vector samples;
  generate_samples(samples);
  
  std::sort(samples.begin(), samples.end());

  // for (auto s: samples)
  // {
  //   std::cout << s << "\n";
  // }

  // auto idx = std::upper_bound(samples.begin(), samples.end(), 100);
  // std::cout << samples[idx - samples.begin()] << "\n";

  // std::ofstream output;
  // output.open("out.txt");

  ll m;
  // std::cin >> m;
  // while (m != 0)
  // {
  //   auto idx = std::lower_bound(samples.begin(), samples.end(), m);
  //   std::cout << samples[idx - samples.begin()] << "\n";
  //   // output << samples[idx - samples.begin()] << "\n";
  //   std::cin >> m;
  // }

  while(scanf("%lld", &m) == 1 && m) {
        printf("%lld\n", *std::lower_bound(samples.begin(), samples.end(), m));
  }

  // output.close();

  return 0;
}
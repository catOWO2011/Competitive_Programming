#include <iostream>
#include <vector>

// #include <fstream>

using vector = std::vector<int>;

bool can_reach_top_rug(int k, vector& rugs)
{
  bool reach = true;
  int gap;

  for (size_t i = 1; i < rugs.size() && reach; i++)
  {
    gap = rugs[i] - rugs[i - 1];
    if (gap > k)
    {
      reach = false;
    }
    else if (gap == k)
    {
      k--;
    }
  }

  return reach;
}

int find_minimum_strength_factor(vector& rugs)
{
  int lo = 1,
    mid,
    hi = 10000000;

  while (lo <= hi)
  {
    mid = lo + ( (hi - lo) / 2 );
    if (can_reach_top_rug(mid, rugs))
    {
      hi = mid - 1;
    }
    else
    {
      lo = mid + 1;
    }
  }

  return lo;
}

int main()
{
  int T,
    n,
    answer;
  scanf("%d", &T);

  // std::ofstream output;
  // output.open("out.txt");

  for (int i = 0; i < T; i++)
  {
    scanf("%d", &n);
    vector rugs(n + 1);
    rugs[0] = 0;

    for (int i = 0; i < n; i++)
    {
      scanf("%d", &rugs[i + 1]);
    }

    answer = find_minimum_strength_factor(rugs);

    // output << "Case " << (i+1) << ": " << answer << "\n";

    printf("Case %d: %d\n", (i+1), answer);
  }

  // output.close();

  return 0;
}
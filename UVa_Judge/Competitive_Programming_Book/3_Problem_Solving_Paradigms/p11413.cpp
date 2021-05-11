#include <iostream>
#include <vector>
#include <fstream>

using vector = std::vector<int>;

bool vessels_are_completely_poured(vector& vessels, int container_cap, int number_of_containers)
{
  bool flag = true;
  int cnt_containers = 1,
    vessel_milk,
    current_container_cap = container_cap;

  size_t vessel_idx = 0;

  while (vessel_idx < vessels.size() && flag)
  {
    vessel_milk = vessels[vessel_idx];
    if (vessel_milk > container_cap) {
      flag = false;
    }

    if (current_container_cap - vessel_milk < 0) {
      current_container_cap = container_cap;
      cnt_containers++;
    }

    if (cnt_containers > number_of_containers) {
      flag = false;
    }

    current_container_cap -= vessel_milk;

    vessel_idx++;
  }

  return flag;
}

int const find_minimal_possible_capacity(vector& vessels, int total_milk, int number_of_containers)
{
  int lo = 1,
    hi = total_milk,
    mid;

  while (lo <= hi)
  {
    mid = lo + ( (hi - lo) / 2 );

    if (vessels_are_completely_poured(vessels, mid, number_of_containers))
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
  // std::ios_base::sync_with_stdio(false);
  // std::cin.tie(null);
  int n,
    m,
    c,
    total_milk,
    ans;

  vector vessels;

  // std::ofstream output;
  // output.open("out.txt");

  while (scanf("%d%d", &n, &m) != EOF)
  {
    if (n == -1) break;
    vessels.clear();
    total_milk = 0;

    for (size_t i = 0; i < n; i++)
    {
      scanf("%d", &c);
      total_milk += c;
      vessels.push_back(c);
    }

    ans = find_minimal_possible_capacity(vessels, total_milk, m);

    // output << ans << "\n";

    printf("%d\n", ans);
  }

  // output.close();

  return 0;
}
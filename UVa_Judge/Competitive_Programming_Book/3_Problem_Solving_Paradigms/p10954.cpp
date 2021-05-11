#include <iostream>
#include <queue>

using priority_queue = std::priority_queue<int, std::vector<int>, std::greater<int>>;

int minimum_total_cost(priority_queue& q)
{
  int minimum = 0,
    a,
    b;

  while (!q.empty() && q.size() > 1)
  {
    a = q.top();
    q.pop();
    b = q.top();
    q.pop();

    // std::cout << a << "\n";
    // std::cout << b << "\n";

    q.push(a + b);
    minimum += (a + b);
  }

  // minimum += q.top();
  q.pop();

  return minimum;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  // auto cmp = [](inst a, int b) { return a < b; };

  int N,
    number,
    i;
  priority_queue q;
  do
  {
    std::cin >> N;

    if (N != 0)
    {
      i = 0;
      while (i < N)
      {
        std::cin >> number;
        q.push(number);
        i++;
      }

      std::cout << minimum_total_cost(q) << "\n";
    }
  } while (N != 0);
  

  return 0;
}
#include <iostream>

const size_t get_maximum_sugar_amount(size_t X, size_t A, size_t B)
{
  return ((100 - X) * B + A ) * 10;
}

int main()
{
  size_t T, X, A, B;

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::cin >> T;

  while (T)
  {
    T--;
    std::cin >> X >> A >> B;
    std::cout << get_maximum_sugar_amount(X, A, B) << "\n";
  }

  return 0;
}
#include <iostream>

const int get_number_of_coconut(size_t xa, size_t xb, size_t XA, size_t XB)
{
  return (XA / xa) + (XB / xb);
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  size_t T;

  size_t xa,
    xb,
    XA,
    XB;
  
  std::cin >> T;

  while (T--)
  {
    std::cin >> xa >> xb >> XA >> XB;

    std::cout << get_number_of_coconut(xa, xb, XA, XB) << "\n";
  }

  return 0;
}
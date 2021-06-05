
/**
 * 

XXX
OOO
XOX
XXO
OOO
XOX
XX_
OOO
XOX
 * 
*/
#include <iostream>
#include <vector>
#include <string>

using string = std::string;
using vector = std::vector<string>;

int dir[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

vector grid(3);

int wx,
  wo;

const bool is_inside(int r, int c)
{
  return r > -1 && r < 3 && c > -1 && c < 3;
}

const bool same_tokes(char token, int num_direction, int r, int c)
{
  bool same = true;

  while (same && is_inside(r, c))
  {
    same = grid[r][c] == token;
    r += dir[num_direction][0];
    c += dir[num_direction][1];
  }

  return same;
}

const int count_tokens(char token)
{
  int token_cnt = 0;

  for (size_t r = 0; r < 3; r++)
  {
    for (size_t c = 0; c < 3; c++)
    {
      if (grid[r][c] == token)
      {
        token_cnt++;
      }
    }
  }

  return token_cnt;
}

void count_wins()
{
  char token;
  wx = wo = 0;

  for (size_t i = 0; i < 3; i++)
  {
    token = grid[i][0];
    if (token != '_' && same_tokes(token, 0, i, 0))
    {
      token == 'X' ? wx++ : wo++;
    }
  }

  for (size_t i = 0; i < 3; i++)
  {
    token = grid[0][i];
    if (token != '_' && same_tokes(token, 1, 0, i))
    {
      token == 'X' ? wx++ : wo++;
    }
  }

  token = grid[0][0];
  if (token != '_' && same_tokes(token, 2, 0, 0))
  {
    token == 'X' ? wx++ : wo++;
  }

  token = grid[0][2];
  if (token != '_' && same_tokes(token, 3, 0, 2))
  {
    token == 'X' ? wx++ : wo++;
  }
}

int print()
{
  int option = 3;

  int o_token = count_tokens('O');
  int x_token = count_tokens('X');

  if (x_token == o_token || x_token - 1 == o_token)
  {
    count_wins();
    // std::cout << wx << "..." << wo << "\n";

    if ((wx && !wo && x_token - 1 == o_token ) ||
      (wo == 1 && !wx && x_token == o_token) ||
      (x_token + o_token == 9 && wx == wo && wx == 0))
    {
      option = 1;
    }
    else if(wx == 0 && wo == 0)
    {
      option = 2;
    }
  }

  return option;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie();

  size_t T;
  std::cin >> T;

  while (T--)
  {
    for (size_t i = 0; i < 3; i++)
    {
      std::cin >> grid[i];
    }

    std::cout << print() << "\n";
  }

  return 0;
}
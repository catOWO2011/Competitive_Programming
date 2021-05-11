/*
6 7
0 1 1 0 1 1 0
0 0 0 0 0 1 0
1 0 0 0 0 0 1
0 1 0 0 0 0 1
1 1 0 0 0 1 0
1 1 0 1 1 0 0
0 0
*/

#include <iostream>
#include <fstream>

int M,N;
int land[101][101];

void const fillLand()
{
  for (size_t i = 0; i < 101; i++)
  {
    for (size_t j = 0; j < 101; j++)
    {
      land[i][j] = 0;
    }
  }
}

const void printLand() {
  printf("########\n");
  for (size_t i = 1; i <= M; i++)
  {
    for (size_t j = 1; j <= N; j++)
    {
      printf("%d ", land[i][j]);
    }
    printf("\n");
  }
  
}

int getLargestPieceOfLand() {
  int largestPiece = 0;

  for (size_t r = 1; r <= M; r++)
  {
    for (size_t c = 1; c <= N; c++)
    {
      if (land[r][c] && land[r][c-1]) {
        land[r][c] += land[r][c-1];
      }
    }
  }

  // printLand();

  for (size_t left_col = 0; left_col <= N; left_col++)
  {
    for (size_t right_col = left_col + 1; right_col <= N; right_col++)
    {
      int subPiece = 0,
        row_diff = -1;
      for (size_t row = 1; row <= M; row++)
      {
        int land_row_diff = land[row][right_col] - land[row][left_col];
        if (row_diff == -1)
        {
          row_diff = land_row_diff > 0 ? land_row_diff : 0;
          subPiece += row_diff;
        }
        else
        {
          if (row_diff == land_row_diff)
          {
            subPiece += row_diff;
          }
          else
          {
            if (subPiece > largestPiece) {
              largestPiece = subPiece;
            }
            subPiece = 0;
            row_diff = land_row_diff > 0 ? land_row_diff : 0;
            subPiece += row_diff;
          }
        }
      }
      
      if (subPiece > largestPiece) {
        largestPiece = subPiece;
      }
    }
  }

  return largestPiece;
}

int main()
{

  // std::ofstream output;
  // output.open("out.txt");

  while (scanf("%d%d", &M, &N) && M)
  {
    fillLand();
    for (size_t r = 1; r <= M; r++)
    {
      for (size_t c = 1; c <= N; c++)
      {
        scanf("%d", &land[r][c]);
        land[r][c] = land[r][c] == 0 ? 1 : 0;
      }
    }

    int ans = getLargestPieceOfLand();

    // output << ans << "\n";

    printf("%d\n", ans);
  }

  // output.close();

  return 0;
}
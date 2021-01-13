/*
3

111
100
001

101
000
101

000
000
000
*/
#include <bits/stdc++.h>

using namespace std;

int g[3][3];
int dir[4][3] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isInfinite() {
  bool is = true;
  int i, j;
  i = 0;

  while (i < 3 && is) {
    j = 0;
    while (j < 3 && is) {
      if (g[i][j] == 1) {
        is = false;
      }
      j++;
    }
    i++;
  }

  return is; 
}


void f() {
  int ng[3][3];
  int i, j, idx, new_i, new_j;
  int ady_sum;
  i = 0;

  while (i < 3) {
    j = 0;
    while (j < 3) {
      ady_sum = 0;
      for (idx = 0; idx < 4; idx++) {
        new_i = i + dir[idx][0];
        new_j = j + dir[idx][1];
        if (new_i > -1 && new_i < 3 && new_j > -1 && new_j < 3) {
          ady_sum = (ady_sum + g[new_i][new_j]) % 2;
        }
        ng[i][j] = ady_sum;
      }
      j++;
    }
    i++;
  }

  i = 0;
  while (i < 3) {
    j = 0;
    while (j < 3) {
      g[i][j] = ng[i][j];
      j++;
    }
    i++;
  }
  
}

int get_greatest_index() {
  int i = -1;

  while (!isInfinite()) {
    // cout<<isInfinite()<<"...\n";
    f();
    i++;
  }

  return i;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  int i, j;

  scanf("%d", &T);

  while (T--) {
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        scanf("%1d", &g[i][j]);
      }
    }

    printf("%d\n", get_greatest_index());
  }

  return 0;
}
/*
5
X...X ....X
.X... ...X.
...X. .X...
..X.X ..X..
....X XX..X
6
....XX X....X
...X.. X.X...
XX..X. .X..X.
..X... ...X.X
...X.. ..X...
..X..X ..X...
2
X. X.
.X .X
4
..X. ...X
XX.. ....
.... XX..
...X ..X.
5
X.... .X...
.X... ..X..
.X... ..X..
...X. ....X
....X X....
4
.X.. ..X.
.X.X X...
.... ..XX
..X. ....
2
.. XX
XX ..

Pattern 1 was rotated 90 degrees.
Pattern 2 was rotated 270 degrees.
Pattern 3 was preserved.
Pattern 4 was reflected vertically.
Pattern 5 was improperly transformed.
Pattern 6 was reflected vertically and rotated 270 degrees.
Pattern 7 was rotated 180 degrees.
*/

#include <bits/stdc++.h>

using namespace std;

char original_square[11][11];
char transformed_square[11][11];
char new_square[11][11];
char current_square[11][11];

int N, i, j;

void print() {
  for (i = 0; i < N; i++) {
    printf("%s____\n", current_square[i]);
  }
}

void rotate_square() {
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      new_square[j][N - i - 1] = current_square[i][j];
    }
  }
}

void reflect_square() {
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      new_square[N-i-1][j] = original_square[i][j];
    }
  }
}

int get_rotated_degrees() {
  int dregrees = -1;
  
  memcpy(current_square, original_square, sizeof(original_square));
  // rotate degrees
  for (int d = 90; d < 360 && dregrees == -1; d += 90) {
    rotate_square();
    if (memcmp(new_square, transformed_square, sizeof(new_square)) == 0) {
      dregrees = d;
    }
    memcpy(current_square, new_square, sizeof new_square);
  }

  return dregrees;
}

string get_pattern(int order) {
  string pattern = "Pattern " + to_string(order) + " was ";

  bool is_same_pattern = false;

  if (memcmp(original_square, transformed_square, sizeof(original_square)) == 0) {
    pattern += "preserved.";
    is_same_pattern = true;
  }

  int dregrees = get_rotated_degrees();
  if (dregrees != -1 && !is_same_pattern) {
    is_same_pattern = true;
    pattern += "rotated " + to_string(dregrees) + " degrees.";
  }

  if (!is_same_pattern) {
    reflect_square();
    if (memcmp(new_square, transformed_square, sizeof(new_square)) == 0) {
      pattern += "reflected vertically.";
    } else {
      memset(current_square, 0, sizeof current_square);
      memcpy(original_square, new_square, sizeof(new_square));
      dregrees = get_rotated_degrees();
      if (dregrees != -1) {
        pattern += "reflected vertically and rotated " + to_string(dregrees) + " degrees.";
      } else {
        pattern += "improperly transformed.";
      }
    }
  }

  return pattern;
}

int main() {

  // ofstream myfile;
  // myfile.open("out.txt");

  int order = 1;

  while (scanf("%d", &N) != EOF) {
    // if (N == -1) break;
    memset(original_square, 0, sizeof original_square);
    memset(transformed_square, 0, sizeof transformed_square);
    memset(new_square, 0, sizeof new_square);
    memset(current_square, 0, sizeof current_square);

    i = 0;
    while (i < N) {
      scanf("%s %s", original_square[i], transformed_square[i]);
      i++;
    }
    
    // myfile<<get_pattern(order).c_str()<<"\n";
    printf("%s\n", get_pattern(order).c_str());
    order++;

  }
  // myfile.close();

  return 0;
}
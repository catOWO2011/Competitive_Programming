#include <bits/stdc++.h>

using namespace std;

int compute_score(string &problem) {
  int score = 0,
    parcial_score = 0;

  for (auto result: problem) {
    if (result == 'O') {
      parcial_score++;
      score += parcial_score;  
    } else {
      parcial_score = 0;
    }
  }

  return score;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  string problem;

  while (T--) {
    cin >> problem;
    cout<< compute_score(problem) <<"\n";
  }

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main () {
  int T, num_case = 1, N, speed;
  cin >> T;

  vector<int> speeds;

  while (T--) {
    speeds.clear();
    cin >> N;
    while (N--)
    {
      cin>>speed;
      speeds.push_back(speed);
    }

    int maxSpeed = 0;
    
    for (auto s: speeds)
    {
      if (s > maxSpeed) {
        maxSpeed = s;
      }
    }

    cout<<"Case "<<num_case++<<": "<<maxSpeed<<"\n";
  }

  return 0;
}
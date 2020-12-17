
#include <bits/stdc++.h>

using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T,
    N,
    case_cnt = 1,
    height,
    high_jumps,
    low_jumps;
  cin>>T;
  vector<int> wallHeights;

  while (T--)
  {
    cin>>N;
    wallHeights.clear();
    while (N--)
    {
      cin>>height;
      wallHeights.push_back(height);
    }
    high_jumps = low_jumps = 0;
    for(int i = 1; i < wallHeights.size(); i++) {
      if (wallHeights[i] > wallHeights[i-1]) {
        high_jumps++;
      }
      if (wallHeights[i] < wallHeights[i-1]) {
        low_jumps++;
      }
    }
    cout<<"Case "<<case_cnt<<": "<<high_jumps<<" "<<low_jumps<<"\n";
    case_cnt++;
  }
  

  return 0;
}
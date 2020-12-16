#include <bits/stdc++.h>

using namespace std;

long long number_of_rows(long long &n) {
  return (-1 + sqrt(1 + 8*n))/2;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  
  long long n;

  cin>>t;
  while (t--) {
    cin>>n;
    cout<<number_of_rows(n)<<endl;
  }
  

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

double compute_price(double p, double a, double b, double c, double d, double k) {
  return p*((sin(a*k + b) + cos(c*k + d)) + 2.0);
}

double compute_maximum_decline(int p, int a, int b, int c, int d, int n) {
  double maximum_decline = 0,
    pc = -1,
    pi;

  for (int k = 1; k <= n; k++) {
    pi = compute_price(p, a, b, c, d, k);
    if (pi > pc) {
      pc = pi;
    }

    if (pi < pc) {
      if ( pc - pi > maximum_decline ) {
        maximum_decline = pc - pi;
      }
    }
  }

  return maximum_decline;
}

/*
42 1 23 4 8 10
100 7 615 998 801 3
100 432 406 867 60 1000
*/
int main () {
  // ofstream myfile;
  // myfile.open ("out.txt");


  int a,b,c,d,n,p;
  while(cin>>p>>a>>b>>c>>d>>n) {
    // if (p == -1) break;
    cout.precision(6);
    cout<<fixed<<compute_maximum_decline(p, a, b, c, d, n)<<"\n";
    // myfile << fixed<<compute_maximum_decline(p, a, b, c, d, n) <<"\n";
  }

  // myfile.close();

  return 0;
}
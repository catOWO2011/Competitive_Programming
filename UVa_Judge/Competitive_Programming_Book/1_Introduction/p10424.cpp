/**
saima
shanto
Pakistan
India
USA
USSR
*/

#include <bits/stdc++.h>

using namespace std;

int alphabet_value(char c) {
  if (c >= 'A' && c <= 'Z') return c - 'A' + 1;
  if (c >= 'a' && c <= 'z') return c - 'a' + 1;
  return 0;
}

int transform_to_digit(string &nameA) {
  int digit = 0, digit_sum, pdigit;

  for(auto c: nameA) {
    digit += alphabet_value(c);
  }

  while (digit > 9) {
    pdigit = digit;
    digit_sum = 0;
    while (pdigit > 0) {
      digit_sum += pdigit % 10;
      pdigit /= 10;
    }
    digit = digit_sum;
  }

  return digit;
}

double love_calculation(string &nameA, string &nameB) {
  
  double digitA = transform_to_digit(nameA);
  double digitB = transform_to_digit(nameB);
  double temp;

  if (digitB > digitA) {
    temp = digitB;
    digitB = digitA;
    digitA = temp;
  }

  return digitA > 0 ? (digitB/digitA)*100.0 : 0;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string a,b;
  cout.precision(2);
  while (getline(cin, a)) {
    getline(cin, b);
    cout<<fixed<<love_calculation(a, b)<<" %\n";
  }
  // ofstream myfile;
  // myfile.open ("out.txt");
  // while (true) {
  //   getline(cin, a);
  //   getline(cin, b);
  //   if (a == "fernando") break;
  //   cout<<fixed<<love_calculation(a, b)<<" %\n";
  //   myfile <<fixed<<love_calculation(a, b)<<"\n";
  // }
  // myfile.close();

  return 0;
}
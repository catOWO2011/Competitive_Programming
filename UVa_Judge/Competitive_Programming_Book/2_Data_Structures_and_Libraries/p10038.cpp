#include <bits/stdc++.h>

using namespace std;

void print_binary_number(int num) {
  while (num > 0) {
    cout<<(num % 2);
    num /= 2;
  }
  cout<<num<<"\n";
}

string is_jolly_jumper (vector<int> &sequence) {
  string ans = "Not jolly";
  // I'll use bitmask
  int n = sequence.size();

  vector<bool> mark(n, false);

  // int set = pow(2, n);
  int cnt_numbers = 0;
  int i = 1;
  int diff_number = 0;
  bool number_is_on = false;

  while (i < n) {
    diff_number = abs(sequence[i] - sequence[i-1]);
    if (diff_number > 0 && diff_number < n && !mark[diff_number]) {
      mark[diff_number] = true;
      cnt_numbers++;
    }
    i++;
  }

  if (cnt_numbers == n - 1 || n == 1) {
    ans = "Jolly";
  }

  return ans;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int elem;

  vector<int> sequence;

  // ofstream myfile;
  // myfile.open ("out.txt");

  while (cin >> n) {
    if (n == -1)
     break;
    sequence.clear();
    while (n--) {
      cin >> elem;
      sequence.push_back(elem);
    }
    cout<<is_jolly_jumper(sequence)<<"\n";
    cin.ignore();

    // myfile<<is_jolly_jumper(sequence)<<"\n";
  }
  // myfile.close();

  return 0;
}
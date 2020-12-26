/**
 * 
 * Here the solution was so simple we just need to thinks on simple moves, for example after 2 o 3 decision
*/

#include <bits/stdc++.h>

using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int L, L_in;
  string dir, new_dir, decision;

  do {
    cin >> L_in;
    // if (L > 0) {
    //   getline(cin, str);
    //   cin.ignore();

    //   char *cstr = new char[str.length() + 1];
    //   strcpy(cstr, str.c_str());
    //   delete [] cstr;

    //   char *token = strtok(str.c_str(), " ");
    //   while (token != NULL) {
    //     cout<<token<<"\n";
    //     token = strtok(NULL, " ");
    //   }
    // }
    L = L_in;
    dir = "+x";
    while (L > 0 && --L) {
      cin >> decision;
      new_dir = "";
      // x DIRECTION
      if (dir == "+x") {
        if (decision == "+z") {
          new_dir = "+z";
        }
        if (decision == "-z") {
          new_dir = "-z";
        }
        if (decision == "+y") {
          new_dir = "+y";
        }
        if (decision == "-y") {
          new_dir = "-y";
        }
      }

      if (dir == "-x") {
        if (decision == "+z") {
          new_dir = "-z";
        }
        if (decision == "-z") {
          new_dir = "+z";
        }
        if (decision == "+y") {
          new_dir = "-y";
        }
        if (decision == "-y") {
          new_dir = "+y";
        }
      }
      // Y DIRECTION
      if (dir == "+y") {
        if (decision == "+z") {
          new_dir = "+y";
        }
        if (decision == "-z") {
          new_dir = "+y";
        }
        if (decision == "+y") {
          new_dir = "-x";
        }
        if (decision == "-y") {
          new_dir = "+x";
        }
      }

      if (dir == "-y") {
        if (decision == "+z") {
          new_dir = "-y";
        }
        if (decision == "-z") {
          new_dir = "-y";
        }
        if (decision == "+y") {
          new_dir = "+x";
        }
        if (decision == "-y") {
          new_dir = "-x";
        }
      }
      // Z DIRECTION
      if (dir == "+z") {
        if (decision == "+z") {
          new_dir = "-x";
        }
        if (decision == "-z") {
          new_dir = "+x";
        }
        if (decision == "+y") {
          new_dir = "+z";
        }
        if (decision == "-y") {
          new_dir = "+z";
        }
      }

      if (dir == "-z") {
        if (decision == "+z") {
          new_dir = "+x";
        }
        if (decision == "-z") {
          new_dir = "-x";
        }
        if (decision == "+y") {
          new_dir = "-z";
        }
        if (decision == "-y") {
          new_dir = "-z";
        }
      }

      if (new_dir != "") {
        dir = new_dir;
      }
    }

    if (L_in > 0) {
      cout<<dir<<"\n";
    }
    
  } while (L_in != 0);
  

  return 0;
}
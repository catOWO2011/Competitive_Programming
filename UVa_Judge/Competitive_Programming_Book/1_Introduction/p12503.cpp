#include <bits/stdc++.h>

using namespace std;

void procces_positions(vector<int> &instructions, int &robot_position) {
  for (auto instruccion: instructions) {
    robot_position += instruccion;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> instructions;

  int T,
    n,
    idx,
    robot_position;

  string instruction;

  cin >> T;
  cin.ignore();


  while (T--) {
    cin >> n;
    cin.ignore();
    instructions.clear();

    while (n--) {
      getline(cin, instruction);
      if (instruction == "LEFT") {
        instructions.push_back(-1);
      } else if (instruction == "RIGHT") {
        instructions.push_back(1);
      } else {
        instruction = instruction.substr(8);
        idx = stoi(instruction) - 1;
        instructions.push_back(instructions[idx]);
      }
    }

    robot_position = 0;

    procces_positions(instructions, robot_position);

    cout<<robot_position<<"\n";
    
  }
  

  return 0;
}
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Parser {
public:
  Parser(stringstream &ss) {
    ss >> _lRange;
    ss.ignore();
    ss >> _rRange >> _key;
    ss.ignore();
    ss >> _pass;
  };
  virtual ~Parser(){};
  int _lRange, _rRange;
  char _key;
  string _pass;
};

bool checkPassword(Parser par);
bool checkPasswordAgain(Parser par);

int main(int argc, char *argv[]) {

  /* ifstream ifile("dummy.txt"); */
  ifstream ifile("input.txt");
  string line;
  int count = 0;

  cout << "==Program Starts==" << endl;
  while (getline(ifile, line)) {
    stringstream ss(line);
    Parser par(ss);

    // part 1
    /* if (checkPassword(par)) { */
    /*   count++; */
    /* } */

    // part 2
    if (checkPasswordAgain(par)) {
        count++;
    }
    ss.clear();
  }
  cout << "==Program Ends (" << count << ")==" << endl;
  return count;
}

bool checkPassword(Parser par) {
  int count = 0;
  cout << "Checking: " << par._lRange << " " << par._rRange << " " << par._key <<
      " " << par._pass << endl;
  for (int i = 0; i < par._pass.size(); i++) {
    if (par._pass[i] == par._key) {
      count++;
    }
  }
  bool solution = count >= par._lRange && count <= par._rRange;
  cout << "Solution: " << solution << "(found " << count << ")" << endl;
  return solution;
}

bool checkPasswordAgain(Parser par) {
  cout << "Checking: " << par._lRange << " " << par._rRange << " " << par._key <<
      " " << par._pass << endl;
  bool pos1 = par._pass[par._lRange-1] == par._key;
  bool pos2 = par._pass[par._rRange-1] == par._key;
  bool solution = pos1 ^ pos2;
  cout << "Solution: " << solution << "( pos1: " << pos1 << " pos2: " << pos2 << " )" << endl;
  return solution;
}

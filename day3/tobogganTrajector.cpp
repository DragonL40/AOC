#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int findTrees(const string&, const int, const int);

int main(int argc, char *argv[]) {

  cout << "==Program Starts==" << endl;
  string fname = "input.txt";
  /* string fname = "dummy.txt"; */

  long int one = findTrees(fname, 1, 1);
  long int three = findTrees(fname, 3, 1);
  long int five = findTrees(fname, 5, 1);
  long int seven = findTrees(fname, 7, 1);
  long int onetwo = findTrees(fname, 1, 2);

  long int trees = three;
  long int TREES = one * three * five * seven * onetwo;
  cout << one << " " << three << " " << five << " " << seven << " " << onetwo << endl;

  cout << "==Program Ends (" << (TREES) << ")==" << endl;
}

int findTrees(const string& filename, const int cx, const int cy) {
  ifstream ifile(filename);
  string line;
  int trees = 0;
  int x = 0;
  int y = 0;
  while (getline(ifile, line)) {
    if (y++ % cy) {
      continue;
    }

    trees += line[x % line.size()] == '#';

    x += cx;
  }
  ifile.clear();
  return trees;
}

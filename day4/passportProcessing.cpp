#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Passport {
public:
  Passport(string data) {
    istringstream issp(data);
    string field;
    while (issp >> field) {
      istringstream issf(field);
      string index;
      string corres;
      getline(issf, index, ':');
      issf >> corres;

      if (index == "byr") {
        byr = corres;
      } else if (index == "iyr") {
        iyr = corres;
      } else if (index == "eyr") {
        eyr = corres;
      } else if (index == "hgt") {
        hgt = corres;
      } else if (index == "hcl") {
        hcl = corres;
      } else if (index == "ecl") {
        ecl = corres;
      } else if (index == "pid") {
        pid = corres;
      } else if (index == "cid") {
        cid = corres;
      } else {
        iyr = corres;
      }
    }
  };

  virtual ~Passport(){};

  string byr, iyr, eyr, hgt, hcl, ecl, pid, cid;

  bool isPresent() {
    return !(byr.empty() || iyr.empty() || eyr.empty() || hgt.empty() ||
             hcl.empty() || ecl.empty() || pid.empty());
  }

  void print() {
    cout << byr << iyr << eyr << hgt << hcl << ecl << pid << cid << endl;
  }

  bool isValid() {

    // Birth Year
    if (!(stoi(byr) >= 1920 && stoi(byr) <= 2002)) {
      return false;
    }

    // Issue Year
    if (!(stoi(iyr) >= 2010 && stoi(iyr) <= 2020)) {
      return false;
    }

    // Expiration Year
    if (!(stoi(eyr) >= 2020 && stoi(eyr) <= 2030)) {
      return false;
    }

    // Height
    istringstream ss(hgt);
    int height;
    string units;
    ss >> height >> units;
    if (units == "cm") {
      if (!(height >= 150 && height <= 193)) {
        return false;
      }
    } else if (units == "in") {
      if (!(height >= 59 && height <= 76)) {
        return false;
      }
    } else {
      return false;
    }

    // Hair Color
    if (hcl[0] != '#') {
      return false;
    }
    if (hcl.size() > 7) {
      return false;
    }
    for (int i = 1; i < hcl.size(); i++) {
      if (!((hcl[i] >= '0' && hcl[i] <= '9') ||
            (hcl[i] >= 'a' && hcl[i] <= 'f'))) {
        return false;
      }
    }

    // Eye Color
    vector<string> Expected = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    if (find(Expected.begin(), Expected.end(), ecl) == Expected.end()) {
      return false;
    }

    // Passport ID
    if (pid.size() != 9) {
      return false;
    }

    return true;
  }
};

int main(int argc, char *argv[]) {
  ifstream ifile("input.txt");
  /* ifstream ifile("dummy.txt"); */
  /* ifstream ifile("valid.txt"); */
  /* ifstream ifile("invalid.txt"); */

  vector<string> vec;
  string input = "";

  string line;
  while (getline(ifile, line)) {
    if (line.empty()) {
      vec.push_back(input);
      input.clear();
    } else {
      input += line;
      input += " ";
    }
  }

  vec.push_back(input);

  int result1 = 0;
  int result2 = 0;
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
    Passport passport(vec[i]);
    if (passport.isPresent()) {
      result1++;
      if (passport.isValid()) {
        result2++;
      }
    }
  }

  cout << "result 1:" << result1 << endl;
  cout << "result 2:" << result2 << endl;
  return result1;
}

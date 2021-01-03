#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int findTwoNumbers(int *arr, int target);
int findTwoNumbersUSet(vector<int> items, int target);
int findThreeNumbers(int *arr, int target);
int findThreeNumbersUSet(vector<int> items, int target);

int main(int argc, char *argv[]) {
  if (argc < 3) {
    cout << "Usage: ./reportRepair <numbers> <input file>";
    return -2;
  }
  string implementedNumbers = "23";
  if (implementedNumbers.find(argv[1]) == string::npos) {
    cout << "Only " + implementedNumbers + " are implemented" << endl;
    return -2;
  }

  vector<int> input;
  int num;
  ifstream ifile(argv[2]);
  while (ifile >> num) {
    input.push_back(num);
  }

  if (atoi(argv[1]) == 2) {
    cout << findTwoNumbersUSet(input, 2020) << endl;
  } else if (atoi(argv[1]) == 3) {
    cout << findThreeNumbersUSet(input, 2020) << endl;
  }

  return 0;
}

int findTwoNumbers(int *arr, int target) {
  for (int i = 1; i < target; i++) {
    int a;
    if (arr[i]) {
      a = i;
      if (arr[target - a]) {
        return a * (target - a);
      }
    }
  }
  return -1;
}

/******************************************************************************
 * Function:         int findThreeNumbers
 *                   Find the three entries that sums to target.
 * Where:
 * Return:           The multiple of the three entries
 * Error:
 *****************************************************************************/
int findThreeNumbers(int *arr, int target) {
  for (int i = 1; i < target; i++) {
    int a;
    if (arr[i]) {
      a = i;
      int multiply2 = findTwoNumbers(arr, target - a);
      if (multiply2 > 0) {
        return a * multiply2;
      }
    }
  }
  return -1;
}

/******************************************************************************
 * Function:         int findTwoNumbersUSet
 *                   Find two numbers that sum to tagert, using unordered sets
 * Where:
 *                   vector<int> items - TODO
 *                   int target - TODO
 * Return:           The multiple of the two numbers
 * Error:
 *****************************************************************************/
int findTwoNumbersUSet(vector<int> items, int target) {
  int result = -1;
  unordered_set<int> set;
  for (int i = 0; i < items.size(); i++) {
    int item = items[i];
    set.emplace(item);

    int goal = 2020 - item;

    auto it = set.find(goal);
    if (it != set.end()) {
      result = item * goal;
    }
  }
  return result;
}

/******************************************************************************
 * Function:         int findThreeNumbersUSet
 *                   Find three numbers that sums to target.
 * Where:
 *                   vector<int> items - TODO
 *                   int target - TODO
 * Return:           The multiple of the three entries;
 * Error:
 *****************************************************************************/
int findThreeNumbersUSet(vector<int> items, int target) { return -1; }

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int findTwoNumbers(int* arr, int traget);
int findThreeNumbers(int* arr, int target);

int main(int argc, char *argv[]) {
    int arr[2020] = {0};

    if (argc < 3) {
        cout << "Usage: ./reportRepair <numbers> <input file>";
        return -2;
    }

   string implementedNumbers = "23";
    if (implementedNumbers.find(argv[1]) == string::npos) {
        cout << "Only " + implementedNumbers + " are implemented" << endl;
        return -2;
    }

    int num;
    ifstream ifile(argv[2]);
    while (ifile >> num) {
        arr[num]++; 
    }
    
    if (atoi(argv[1]) == 2) {
        cout << findTwoNumbers(arr, 2020) << endl;
    } else if (atoi(argv[1]) == 3) {
        cout << findThreeNumbers(arr, 2020) << endl;
    }

    return 0;
}

int findTwoNumbers(int* arr, int target) {
    for (int i = 1; i < target; i++) {
        int a;
        if (arr[i]) {
            a = i;
            if (arr[target-a]) {
                return a * (target-a);
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
int findThreeNumbers(int* arr, int target){
    for (int i = 1; i < target; i++) {
        int a;
        if (arr[i]) {
            a = i;
            int multiply2 = findTwoNumbers(arr, target-a);
            if (multiply2 > 0) {
                return a * multiply2;
            }
        }
    }
    return -1;
}

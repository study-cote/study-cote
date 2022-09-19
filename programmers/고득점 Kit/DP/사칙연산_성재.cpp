#include <vector>
#include <string>

using namespace std;

int solution(vector<string> arr) {
    int answer = -1;
    
    vector<int> number;
    vector<char> op;
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2) {
            op.push_back(arr[i][0]);
        }
        else {
            number.push_back(stoi(arr[i]));
        }
    }

    int** max = new int* [number.size()];
    int** min = new int* [number.size()];
    for (int i = 0; i < number.size(); i++) {
        max[i] = new int[number.size()];
        min[i] = new int[number.size()];
        max[i][i] = number[i];
        min[i][i] = number[i];
    }
    for (int i = 1; i < number.size(); i++) {
        for (int j = 0; j < number.size() - i; j++) {
            int maxValue = -1000000, minValue = 1000000;
            for (int k = j; k < j + i; k++) {
                if (op[k] == '+') {
                    if (max[j][k] + max[k + 1][j + i] > maxValue) {
                        maxValue = max[j][k] + max[k + 1][j + i];
                    }
                    if (min[j][k] + min[k + 1][j + i] < minValue) {
                        minValue = min[j][k] + min[k + 1][j + i];
                    }
                }
                else {
                    if (max[j][k] - min[k + 1][j + i] > maxValue) {
                        maxValue = max[j][k] - min[k + 1][j + i];
                    }
                    if (min[j][k] - max[k + 1][j + i] < minValue) {
                        minValue = min[j][k] - max[k + 1][j + i];
                    }
                }
            }
            max[j][j + i] = maxValue;
            min[j][j + i] = minValue;
        }
    }
    answer = max[0][number.size() - 1];

    for (int i = 0; i < number.size(); i++) {
        delete[] max[i], min[i];
    }
    delete[] max, min;

    return answer;
}
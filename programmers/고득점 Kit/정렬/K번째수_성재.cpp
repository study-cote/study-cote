#include <string>
#include <vector>
#include <random>

using namespace std;

void swap(vector<int>&, int, int);
void quickSort(vector<int>&, int, int);

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> temp(array);
        quickSort(temp, commands[i][0] - 1, commands[i][1] - 1);
        answer.push_back(temp[commands[i][0] + commands[i][2] - 2]);
    }

    return answer;
}

void swap(vector<int>& arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void quickSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(l, r);

        int pivot = dis(gen);
        swap(arr, l, pivot);

        int i = l, j = r + 1;
        while (i < j) {
            for (i++; i <= r && arr[i] < arr[l]; i++);
            for (j--; j > l && arr[j] > arr[l]; j--);
            if (i < j) {
                swap(arr, i, j);
            }
        }
        swap(arr, l, j);
        quickSort(arr, l, j - 1);
        quickSort(arr, j + 1, r);
    }
}
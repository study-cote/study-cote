#include <string>
#include <vector>
#include <random>

using namespace std;

void swap(vector<string>&, int, int);
void quickSort(vector<string>&, int, int);

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> arr;
    for (int i = 0; i < numbers.size(); i++) {
        int size = 1000;
        int temp = numbers[i];
        string str = "";
        if (numbers[i] == 0) {
            str = "0";
        }
        else {
            for (; !(temp / size); size /= 10);
            for (; size; temp %= size, size /= 10) {
                str += (temp / size + '0');
            }
        }
        arr.push_back(str);
    }
    quickSort(arr, 0, arr.size() - 1);
    if (arr[0][0] == '0') {
        answer = "0";
    }
    else {
        for (int i = 0; i < arr.size(); i++) {
            answer += arr[i];
        }
    }

    return answer;
}

void swap(vector<string>& arr, int a, int b) {
    string temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void quickSort(vector<string>& arr, int l, int r) {
    if (l < r) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(l, r);

        int pivot = dis(gen);
        swap(arr, l, pivot);

        int i = l, j = r + 1;
        while (i < j) {
            bool iEnd = false, jEnd = false;
            for (i++; i <= r; i++) {
                string iBig = arr[i] + arr[l];
                string pivotBig = arr[l] + arr[i];
                int len = arr[i].length() + arr[l].length();
                for (int k = 0; k < len; k++) {
                    if (iBig[k] > pivotBig[k]) {
                        break;
                    }
                    if (iBig[k] < pivotBig[k]) {
                        iEnd = true;
                        break;
                    }
                }
                if (iEnd) {
                    break;
                }
            }
            for (j--; j > l; j--) {
                string jBig = arr[j] + arr[l];
                string pivotBig = arr[l] + arr[j];
                int len = arr[j].length() + arr[l].length();
                for (int k = 0; k < len; k++) {
                    if (jBig[k] < pivotBig[k]) {
                        break;
                    }
                    if (jBig[k] > pivotBig[k]) {
                        jEnd = true;
                        break;
                    }
                }
                if (jEnd) {
                    break;
                }
            }
            if (i < j) {
                swap(arr, i, j);
            }
        }
        swap(arr, l, j);
        quickSort(arr, l, j - 1);
        quickSort(arr, j + 1, r);
    }
}
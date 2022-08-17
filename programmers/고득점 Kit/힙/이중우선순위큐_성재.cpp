#include <string>
#include <vector>

using namespace std;

void insert(vector<int>&, int, int&);
void swap(int&, int&);
void deleteMin(vector<int>&, int&);
void deleteMax(vector<int>&, int&);

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    vector<int> arr(4);
    int last = 1;
    for (vector<string>::iterator i = operations.begin(); i != operations.end(); i++) {
        int num = stoi((*i).substr(2));
        if ((*i)[0] == 'I') {
            insert(arr, num, last);
        }
        else {
            if (last >= 2) {
                if (num == 1) {
                    deleteMax(arr, last);
                }
                else {
                    deleteMin(arr, last);
                }
            }
        }
    }

    if (last <= 1) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else if (last == 2) {
        answer.push_back(arr[2]);
        answer.push_back(arr[2]);
    }
    else {
        answer.push_back(arr[3]);
        answer.push_back(arr[2]);
    }

    return answer;
}

void insert(vector<int>& arr, int x, int& last) {
    int cur, gp, lcgp, rcgp;
    if (last == arr.size() - 1) {
        arr.push_back(0);
    }
    cur = ++last;
    if (last % 2 == 1 && x < arr[last - 1]) {
        arr[last] = arr[last - 1];
        cur--;
    }
    while (cur >= 4) {
        gp = cur / 4;
        lcgp = 2 * gp;
        rcgp = lcgp + 1;
        if (x < arr[lcgp]) {
            arr[cur] = arr[lcgp];
            cur = lcgp;
        }
        else if (x > arr[rcgp]) {
            arr[cur] = arr[rcgp];
            cur = rcgp;
        }
        else {
            break;
        }
    }
    arr[cur] = x;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void deleteMin(vector<int>& arr, int& last) {
    arr[2] = arr[last--];
    if (last >= 2) {
        int cur = 2;
        while (true) {
            if (cur + 1 <= last && arr[cur] > arr[cur + 1]) {
                swap(arr[cur + 1], arr[cur]);
            }
            int min = cur;
            if (cur * 2 <= last && arr[min] > arr[cur * 2]) {
                min = cur * 2;
            }
            if (cur * 2 + 2 <= last && arr[min] > arr[cur * 2 + 2]) {
                min = cur * 2 + 2;
            }
            if (min == cur) {
                break;
            }
            swap(arr[cur], arr[min]);
            cur = min;
        }
    }
}

void deleteMax(vector<int>& arr, int& last) {
    arr[3] = arr[last--];
    if (last >= 3) {
        int cur = 3;
        while (true) {
            if (arr[cur] < arr[cur - 1]) {
                swap(arr[cur - 1], arr[cur]);
            }
            int max = cur;
            if (cur * 2 - 1 <= last && arr[max] < arr[cur * 2 - 1]) {
                max = cur * 2 - 1;
            }
            if (cur * 2 + 1 <= last && arr[max] < arr[cur * 2 + 1]) {
                max = cur * 2 + 1;
            }
            if (max == cur) {
                break;
            }
            swap(arr[cur], arr[max]);
            cur = max;
        }
    }
}
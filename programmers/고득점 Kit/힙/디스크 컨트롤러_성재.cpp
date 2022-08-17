#include <string>
#include <vector>
#include <queue>
#include <random>

using namespace std;

struct Element {
    int start, time;

    bool operator<(const Element&) const;
};

void swap(vector<vector<int>>&, int, int);
void quickSort(vector<vector<int>>&, int, int);

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    quickSort(jobs, 0, jobs.size() - 1);
    int cur = 0, i = 0;
    priority_queue<Element> PQ;
    while (i < jobs.size() || !PQ.empty()) {
        Element temp;
        if (PQ.empty()) {
            cur = jobs[i][0] + jobs[i][1];
            answer += jobs[i][1];
            i++;
        }
        else {
            temp = PQ.top();
            PQ.pop();
            cur += temp.time;
            answer += (cur - temp.start);
        }
        for (; i < jobs.size(); i++) {
            if (jobs[i][0] > cur) {
                break;
            }
            temp = { jobs[i][0], jobs[i][1] };
            PQ.push(temp);
        }
    }
    answer /= jobs.size();

    return answer;
}

bool Element::operator<(const Element& e) const {
    return this->time > e.time;
}

void swap(vector<vector<int>>& arr, int a, int b) {
    vector<int> temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void quickSort(vector<vector<int>>& arr, int l, int r) {
    if (l < r) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(l, r);

        int pivot = dis(gen);
        swap(arr, l, pivot);

        int i = l, j = r + 1;
        while (i < j) {
            for (i++; i <= r; i++) {
                if (arr[i][0] > arr[l][0]) {
                    break;
                }
                if (arr[i][0] == arr[l][0] && arr[i][1] >= arr[l][1]) {
                    break;
                }
            }
            for (j--; j > l; j--) {
                if (arr[j][0] < arr[l][0]) {
                    break;
                }
                if (arr[j][0] == arr[l][0] && arr[j][1] <= arr[l][1]) {
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
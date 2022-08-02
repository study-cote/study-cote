#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int arr1[5] = { 1,2,3,4,5 };
    int arr2[8] = { 2,1,2,3,2,4,2,5 };
    int arr3[10] = { 3,3,1,1,2,2,4,4,5,5 };
    int size1 = 5, size2 = 8, size3 = 10;
    int count1 = 0, count2 = 0, count3 = 0;

    for (int i = 0, idx1 = 0, idx2 = 0, idx3 = 0; i < answers.size(); i++, idx1 = (idx1 + 1) % size1, idx2 = (idx2 + 1) % size2, idx3 = (idx3 + 1) % size3) {
        if (answers[i] == arr1[idx1]) {
            count1++;
        }
        if (answers[i] == arr2[idx2]) {
            count2++;
        }
        if (answers[i] == arr3[idx3]) {
            count3++;
        }
    }
    if (count1 > count2) {
        if (count1 > count3) {
            answer.push_back(1);
        }
        else if (count1 == count3) {
            answer.push_back(1);
            answer.push_back(3);
        }
        else {
            answer.push_back(3);
        }
    }
    else if (count1 == count2) {
        if (count1 > count3) {
            answer.push_back(1);
            answer.push_back(2);
        }
        else if (count1 == count3) {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else {
            answer.push_back(3);
        }
    }
    else {
        if (count2 > count3) {
            answer.push_back(2);
        }
        else if (count2 == count3) {
            answer.push_back(2);
            answer.push_back(3);
        }
        else {
            answer.push_back(3);
        }
    }

    return answer;
}
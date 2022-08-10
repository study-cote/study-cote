#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;

    for (int i = 0; i < name.length(); i++) {
        if (name[i] != 'A') {
            if (name[i] <= 'N') {
                answer += name[i] - 'A';
            }
            else {
                answer += ('A' - (name[i] - 26));
            }
        }
    }
    int min = 40;
    for (int i = 0; i < name.length(); i++) {
        int a = 0, b = 0;
        for (int j = 1; j <= i; j++) {
            if (name[j] != 'A') {
                a = j;
            }
        }
        for (int j = 1; j < name.length() - i; j++) {
            if (name[name.length() - j] != 'A') {
                b = j;
            }
        }
        if (a * 2 + b < min) {
            min = a * 2 + b;
        }
        if (a + b * 2 < min) {
            min = a + b * 2;
        }
    }
    answer += min;

    return answer;
}
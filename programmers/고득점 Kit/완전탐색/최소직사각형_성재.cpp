#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int aMax = -1, bMax = -1;
    for (int i = 0; i < sizes.size(); i++) {
        int a, b;
        a = sizes[i][0];
        b = sizes[i][1];
        if (b > a) {
            int temp = a;
            a = b;
            b = temp;
        }
        if (a > aMax) {
            aMax = a;
        }
        if (b > bMax) {
            bMax = b;
        }
    }

    answer = aMax * bMax;

    return answer;
}
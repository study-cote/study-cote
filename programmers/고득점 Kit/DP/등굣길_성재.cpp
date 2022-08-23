#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    bool** flood = new bool* [n];
    int** map = new int* [n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[m];
        flood[i] = new bool[m];
        for (int j = 0; j < m; j++) {
            flood[i][j] = false;
            map[i][j] = 0;
        }
    }
    for (int i = 0; i < puddles.size(); i++) {
        flood[puddles[i][1] - 1][puddles[i][0] - 1] = true;
    }
    for (int i = 0; i < m && !flood[0][i]; i++) {
        map[0][i] = 1;
    }
    for (int i = 1; i < n && !flood[i][0]; i++) {
        map[i][0] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (!flood[i][j]) {
                map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1000000007;
            }
        }
    }

    answer = map[n - 1][m - 1];

    for (int i = 0; i < n; i++) {
        delete[] flood[i], map[i];
    }
    delete[] flood, map;

    return answer;
}
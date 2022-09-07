#include <string>
#include <vector>

using namespace std;

struct List {
    int state;
    List* front, * back;

    List();
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    List*** pos = new List ** [51];
    for (int i = 1; i < 51; i++) {
        pos[i] = new List*[51];
        for (int j = 1; j < 51; j++) {
            pos[i][j] = new List();
        }
    }
    for (int i = 0; i < rectangle.size(); i++) {
        for (int j = rectangle[i][1] + 1; j < rectangle[i][3]; j++) {
            for (int k = rectangle[i][0] + 1; k < rectangle[i][2]; k++) {
                pos[j][k]->state = 1;
            }
        }
        int row = rectangle[i][1], col = rectangle[i][0];
        for (; col < rectangle[i][2]; col++) {
            if (pos[row][col]->state == 0 || (pos[row][col]->state != 1 && pos[row][col + 1]->state != 1) && (pos[row][col]->state != pos[row][col + 1]->state)) {
                pos[row][col]->state = i + 2;
                pos[row][col]->back = pos[row][col + 1];
                pos[row][col + 1]->front = pos[row][col];
            }
        }
        for (; row < rectangle[i][3]; row++) {
            if (pos[row][col]->state == 0 || (pos[row][col]->state != 1 && pos[row + 1][col]->state != 1) && (pos[row][col]->state != pos[row + 1][col]->state)) {
                pos[row][col]->state = i + 2;
                pos[row][col]->back = pos[row + 1][col];
                pos[row + 1][col]->front = pos[row][col];
            }
        }
        for (; col > rectangle[i][0]; col--) {
            if (pos[row][col]->state == 0 || (pos[row][col]->state != 1 && pos[row][col - 1]->state != 1) && (pos[row][col]->state != pos[row][col - 1]->state)) {
                pos[row][col]->state = i + 2;
                pos[row][col]->back = pos[row][col - 1];
                pos[row][col - 1]->front = pos[row][col];
            }
        }
        for (; row > rectangle[i][1]; row--) {
            if (pos[row][col]->state == 0 || (pos[row][col]->state != 1 && pos[row - 1][col]->state != 1) && (pos[row][col]->state != pos[row - 1][col]->state)) {
                pos[row][col]->state = i + 2;
                pos[row][col]->back = pos[row - 1][col];
                pos[row - 1][col]->front = pos[row][col];
            }
        }
    }
    for (List* search = pos[characterY][characterX]; search != pos[itemY][itemX]; answer++, search = search->back);
    int count = 0;
    for (List* search = pos[characterY][characterX]; search != pos[itemY][itemX]; count++, search = search->front);
    if (count < answer) {
        answer = count;
    }

    for (int i = 1; i < 51; i++) {
        for (int j = 1; j < 51; j++) {
            delete pos[i][j];
        }
        delete[] pos[i];
    }
    delete[] pos;

    return answer;
}

List::List() : state(0), front(NULL), back(NULL) {

}
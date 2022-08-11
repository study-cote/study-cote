#include<vector>

using namespace std;

struct List {
    int x, y;
    List* next;

    List(int, int);
};

class Queue {
    List* front = NULL, * rear;

public:
    void addQ(int x, int y);
    void deleteQ(int& x, int& y);
    bool isEmpty();
};

int search(vector<vector<int>>);

int solution(vector<vector<int> > maps) {
    int answer = 0;

    answer = search(maps);

    return answer;
}

List::List(int a, int b) : x(a), y(b), next(NULL) {

}

void Queue::addQ(int x, int y) {
    List* temp = new List(x, y);

    if (!front) {
        front = temp;
    }
    else {
        rear->next = temp;
    }
    rear = temp;
}

void Queue::deleteQ(int& x, int& y) {
    x = front->x, y = front->y;

    List* temp = front;
    front = front->next;
    delete temp;
}

bool Queue::isEmpty() {
    if (!front) {
        return true;
    }
    else {
        return false;
    }
}

int search(vector<vector<int>> maps) {
    int** count = new int* [maps.size()];
    for (int i = 0; i < maps.size(); i++) {
        count[i] = new int[maps[i].size()];
        for (int j = 0; j < maps[i].size(); j++) {
            count[i][j] = 0;
        }
    }
    count[0][0] = 1;

    Queue Q;
    Q.addQ(0, 0);
    while (!Q.isEmpty()) {
        int x, y;
        Q.deleteQ(x, y);
        if (x + 1 < maps.size() && maps[x + 1][y] && !count[x + 1][y]) {
            count[x + 1][y] = count[x][y] + 1;
            Q.addQ(x + 1, y);
        }
        if (y + 1 < maps[0].size() && maps[x][y + 1] && !count[x][y + 1]) {
            count[x][y + 1] = count[x][y] + 1;
            Q.addQ(x, y + 1);
        }
        if (x - 1 >= 0 && maps[x - 1][y] && !count[x - 1][y]) {
            count[x - 1][y] = count[x][y] + 1;
            Q.addQ(x - 1, y);
        }
        if (y - 1 >= 0 && maps[x][y - 1] && !count[x][y - 1]) {
            count[x][y - 1] = count[x][y] + 1;
            Q.addQ(x, y - 1);
        }
    }

    int retVal;
    if (!count[maps.size() - 1][maps[0].size() - 1]) {
        retVal = -1;
    }
    else {
        retVal = count[maps.size() - 1][maps[0].size() - 1];
    }

    for (int i = 0; i < maps.size(); i++) {
        delete[] count[i];
    }
    delete[] count;

    return retVal;
}
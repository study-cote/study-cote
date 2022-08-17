#include <string>
#include <vector>

using namespace std;

struct List {
    int data;
    List* next;

    List(int, List*);
    ~List();
};

void insert(List*&, int);

int solution(int N, int number) {
    int answer = -1;

    List** list = new List * [9];
    for (int i = 1; i <= 8; i++) {
        list[i] = NULL;
    }
    int temp = N;
    for (int i = 1; i <= 7; i++) {
        if (number == temp) {
            answer = i;
        }
        list[i] = new List(temp, list[i]);
        temp = temp * 10 + N;
    }

    if (answer < 0) {
        bool find = false;
        for (int i = 2; !find && i <= 8; i++) {
            for (int j = i - 1; !find && j >= 1; j--) {
                for (List* a = list[j]; !find && a; a = a->next) {
                    for (List* b = list[i - j]; b; b = b->next) {
                        if (a->data + b->data == number) {
                            answer = i;
                            find = true;
                            break;
                        }
                        insert(list[i], a->data + b->data);
                        if (a->data - b->data == number) {
                            answer = i;
                            find = true;
                            break;
                        }
                        insert(list[i], a->data - b->data);
                        if (a->data * b->data == number) {
                            answer = i;
                            find = true;
                            break;
                        }
                        insert(list[i], a->data * b->data);
                        if (b->data != 0) {
                            if (a->data / b->data == number) {
                                answer = i;
                                find = true;
                                break;
                            }
                            insert(list[i], a->data / b->data);
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 8; i++) {
        if (list[i]) {
            delete list[i];
        }
    }
    delete[] list;

    return answer;
}

List::List(int d, List* ptr) : data(d), next(ptr) {

}

List::~List() {
    if (next) {
        delete next;
    }
}

void insert(List*& ptr, int num) {
    List* search = ptr;
    for (; search; search = search->next) {
        if (search->data == num) {
            break;
        }
    }
    if (!search) {
        ptr = new List(num, ptr);
    }
}
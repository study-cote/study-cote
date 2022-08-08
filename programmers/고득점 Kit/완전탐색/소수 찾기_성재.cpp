#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct List {
    int data;
    List* next;

    List(int, List*);
    ~List();
};

List* ptr = NULL;

void func(int&, string, int);

int solution(string numbers) {
    int answer = 0;

    func(answer, numbers, 0);

    if (ptr) {
        delete ptr;
    }

    return answer;
}

List::List(int d, List* ptr) : data(d), next(ptr) {

}

List::~List() {
    if (next) {
        delete next;
    }
}

void func(int& answer, string str, int sum) {
    if (str.length() == 0) {
        List* search = ptr;
        for (; search; search = search->next) {
            if (search->data == sum) {
                break;
            }
        }
        if (!search) {
            ptr = new List(sum, ptr);
            int max = (int)sqrt(sum), i = 2;
            for (; i <= max; i++) {
                if (sum % i == 0) {
                    break;
                }
            }
            if (sum > 1 && i > max) {
                answer++;
            }
        }
    }
    else {
        for (int i = 0; i < str.length(); i++) {
            func(answer, str.substr(0, i) + str.substr(i + 1, str.length() - i - 1), sum * 10 + str[i] - '0');
            func(answer, str.substr(0, i) + str.substr(i + 1, str.length() - i - 1), sum);
        }
    }
}
#include <string>
#include <vector>

using namespace std;

struct List {
    string data;
    List* next;
    bool visit;

    List(string, List*);
    ~List();
};

struct Element {
    string start;
    List* end;

    Element(string);
    ~Element();
};

struct Stack {
    List* data;
    Stack* next;

    Stack(List*, Stack*);
};

List* pop(Stack*&);
void dfs(vector<Element*>&, int, vector<string>&);

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    vector<Element*> arr;
    for (int i = 0; i < tickets.size(); i++) {
        int j = 0;
        for (; j < arr.size(); j++) {
            if (arr[j]->start.compare(tickets[i][0]) == 0) {
                break;
            }
        }
        if (j == arr.size()) {
            Element* temp = new Element(tickets[i][0]);
            arr.push_back(temp);
        }
        List* before = NULL;
        for (List* search = arr[j]->end; search; before = search, search = search->next) {
            if (tickets[i][1].compare(search->data) < 0) {
                break;
            }
        }
        if (!before) {
            arr[j]->end = new List(tickets[i][1], arr[j]->end);
        }
        else {
            before->next = new List(tickets[i][1], before->next);
        }
    }

    dfs(arr, tickets.size(), answer);

    for (int i = arr.size() - 1; i >= 0; i--) {
        delete arr[i];
    }

    return answer;
}

List::List(string str, List* ptr) : data(str), next(ptr), visit(false) {

}

List::~List() {
    if (next) {
        delete next;
    }
}

Element::Element(string str) : start(str), end(NULL) {

}

Element::~Element() {
    if (end) {
        delete end;
    }
}

Stack::Stack(List* lptr, Stack* sptr) : data(lptr), next(sptr) {

}

List* pop(Stack*& ptr) {
    List* retVal = ptr->data;
    Stack* temp = ptr;
    ptr = ptr->next;
    delete temp;

    return retVal;
}

void dfs(vector<Element*>& arr, int count, vector<string>& answer) {
    List* search = NULL;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]->start.compare("ICN") == 0) {
            search = arr[i]->end;
            break;
        }
    }
    Stack* top = NULL;
    answer.push_back("ICN");
    while (count) {
        for (; search; search = search->next) {
            if (!search->visit) {
                count--;
                answer.push_back(search->data);
                if (count) {
                    search->visit = true;
                    top = new Stack(search, top);
                    bool find = false;
                    for (int i = 0; i < arr.size(); i++) {
                        if (arr[i]->start.compare(search->data) == 0) {
                            search = arr[i]->end;
                            find = true;
                            break;
                        }
                    }
                    if (!find) {
                        search = NULL;
                    }
                }
                break;
            }
        }
        if (!search) {
            count++;
            answer.pop_back();
            search = pop(top);
            search->visit = false;
            search = search->next;
        }
    }

    while (top) {
        pop(top);
    }
}
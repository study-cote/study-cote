#include <string>
#include <vector>

using namespace std;

struct List {
    string data;
    List* next;

    List(string, List*);
};

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    int bucketSize = 10000;
    List** hash = new List * [bucketSize];
    for (int i = 0; i < bucketSize; i++) {
        hash[i] = NULL;
    }
    for (int i = 0; i < participant.size(); i++) {
        int bucket = 0;
        for (int j = 1; j <= participant[i].length(); j++) {
            bucket += (j * j * participant[i][j]);
        }
        bucket %= bucketSize;
        hash[bucket] = new List(participant[i], hash[bucket]);
    }
    for (int i = 0; i < completion.size(); i++) {
        int bucket = 0;
        for (int j = 1; j <= completion[i].length(); j++) {
            bucket += (j * j * completion[i][j]);
        }
        bucket %= bucketSize;
        List* before = NULL;
        for (List* search = hash[bucket]; search; before = search, search = search->next) {
            if (search->data.compare(completion[i]) == 0) {
                if (!before) {
                    hash[bucket] = search->next;
                }
                else {
                    before->next = search->next;
                }
                delete search;
                break;
            }
        }
    }
    for (int i = 0; i < bucketSize; i++) {
        if (hash[i]) {
            answer = hash[i]->data;
            delete hash[i];
            break;
        }
    }

    return answer;
}

List::List(string d, List* ptr) : data(d), next(ptr) {

}
#include <vector>
using namespace std;

struct List {
    int data;
    List* next;

    List(int, List*);
    ~List();
};

int solution(vector<int> nums)
{
    int answer = 0;

    List** hash = new List * [10000];
    for (int i = 0; i < 10000; i++) {
        hash[i] = NULL;
    }
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        List* search = hash[nums[i] % 10000];
        for (; search; search = search->next) {
            if (search->data == nums[i]) {
                break;
            }
        }
        if (!search) {
            hash[nums[i] % 10000] = new List(nums[i], hash[nums[i] % 10000]);
            count++;
        }
    }

    if (count > nums.size() / 2) {
        answer = nums.size() / 2;
    }
    else {
        answer = count;
    }

    for (int i = 0; i < 10000; i++) {
        if (hash[i]) {
            delete hash[i];
        }
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
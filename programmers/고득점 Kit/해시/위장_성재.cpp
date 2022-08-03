#include <string>
#include <vector>

using namespace std;

struct Element {
    string type;
    vector<string> data;

    Element(string);
};

void func(const vector<Element>&, int, int, int&);

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    vector<Element> input;
    for (int i = 0; i < clothes.size(); i++) {
        int index = 0;
        for (; index < input.size(); index++) {
            if (input[index].type == clothes[i][1]) {
                break;
            }
        }
        if (index == input.size()) {
            Element temp(clothes[i][1]);
            input.push_back(temp);
        }
        input[index].data.push_back(clothes[i][0]);
    }

    func(input, 0, 1, answer);

    return answer;
}

Element::Element(string t) : type(t) {

}

void func(const vector<Element>& input, int cur, int sum, int& answer) {
    if (cur < input.size()) {
        answer += (sum * input[cur].data.size());
        func(input, cur + 1, sum * input[cur].data.size(), answer);
        func(input, cur + 1, sum, answer);
    }
}
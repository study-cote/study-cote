#include <string>
#include <vector>

using namespace std;

struct Element {
    string type;
    vector<string> data;

    Element(string);
};
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

    answer = 1;
    for (int i = 0; i < input.size(); i++) {
        answer *= (input[i].data.size() + 1);
    }
    answer -= 1;

    return answer;
}

Element::Element(string t) : type(t) {

}
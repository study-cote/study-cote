#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for (int i = 0; i < number.length(); i++) {
        while (answer.length() && (int)answer.length() - i > -k) {
            if (number[i] <= answer.back()) {
                break;
            }
            answer.pop_back();
        }
        if (answer.length() < number.length() - k) {
            answer.push_back(number[i]);
        }
        if ((int)answer.length() - i - 1 == -k) {
            for (int j = i + 1; j < number.length(); j++) {
                answer.push_back(number[j]);
            }
            break;
        }
    }

    return answer;
}
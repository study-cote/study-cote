#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;

    int count = 781;
    for (int i = 0; i < word.length(); i++) {
        switch (word[i]) {
        case 'A':
            answer += 1;
            break;
        case 'E':
            answer += (1 + count);
            break;
        case 'I':
            answer += (1 + count * 2);
            break;
        case 'O':
            answer += (1 + count * 3);
            break;
        case 'U':
            answer += (1 + count * 4);
            break;
        }
        count /= 5;
    }

    return answer;
}
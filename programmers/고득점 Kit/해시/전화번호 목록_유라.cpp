#include <string>
#include <vector>
#include <algorithm> // substr

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    // 정렬 - 비슷한 문자끼리 순서 연속되도록
    sort(phone_book.begin(), phone_book.end());
    
    for (int i=0; i<phone_book.size()-1; i++) {
        if (phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size()))
            return answer = false;
    }
    
    return answer;
}
/* 효율성 통과한 코드 -> 이전 코드와 차이점
- 최종 결과 리턴 전에 if(!st.empty()) 추가
- '('가 오면 페어 검사 안하고 일단 다 스택에 넣음
*/

#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack <int> st;

    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(') { 
            st.push(s[i]);
        }
        
        else { // s[i] == ')'
            if (!st.empty()) {
                st.pop();
                answer = true;
            }
            else { // ( 가 없어서 짝 안 맞는 경우
                return answer = false;
            }
        }
   }
    
    if (!st.empty()) // ( 가 남아있어서 짝 안 맞는 경우
        return answer = false;

    return answer;
}
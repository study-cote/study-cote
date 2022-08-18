/* 효율성 2번만 실패한 코드*/

#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack <int> st;

    if (s.size() % 2)
        return answer = false;

    if (s[0] == ')')
        return answer = false;
    
    for (int i=0; i<s.size()-1; i++) {
        if (s[i] == '(') { 
            if (s[i] != s[i+1]) { // case: ()
                i += 1;
            }
            else { // case: ((
                st.push(s[i]);
                answer = false;
            }
        }

        else { // case : )
            if (!st.empty()) {
                answer = true;
                st.pop();
            }
            else
                return answer = false;
        }
   }

    return answer;
}
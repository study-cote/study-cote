#include <iostream>
#include <stdlib.h>
#include <stack>
#include <map>

using namespace std;

map <char, char> pr; // pair map

int check_end(char tmp) {
    if (tmp == ')' || tmp == ']'
    || tmp == '}' || tmp == '>') { // is end char
    }
    
    return 0; // is not
}

int main(void) {
    int length;
    char *arr;

    pr[')'] = '(';
    pr['>'] = '<';
    pr['}'] = '{';
    pr[']'] = '[';

    for (int t=1; t<=10; t++) {
        cin >> length;

        // get char array
        arr = (char *)malloc(sizeof(char) * length);
        for (int i=0; i<length; i++) {        
            scanf("%1s", &arr[i]);
        }

        // check pair
        stack <char> st;
        int ans = 0;
        for (int i=0; i<length; i++) {
            char tmp = arr[i];
            
            if(!check_end(tmp)) { // end char
                st.push(tmp);
            }

            else { // start char
                if (pr[tmp] == st.top()) { // pair
                    st.pop();
                    ans = 1;
                }
                else {
                    ans = 0;
                    break;
                }      
            }
        }
        
        // print answer
        cout << "#" << t << " " << ans << endl; 

        free(arr);
    }

    return 0;
}
/*
==> 메모리 초과 런타임 에러,, 도저히 모르겠음,,
==> 비트 플래그 사용해서 완전 탐색하려고 했는데 경우의 수가 너무 커져서
==> 마지막으로 계산된 경우의 수 = 7469289
==> 숫자 작을 때는 괜찮은데 숫자 커지면 메모리 초과남 ㅠㅠ

4명의 N일 간 활동 일정
- 각 부원은 활동 참여 여부 결정
- 어떤 부원이 참여하는 지 경우의 수 = 16가지
- 아무도 참여하지 않는 것 X -> 실제로는 15가지

- 열쇠는 하나 밖에 없음 -> 열쇠 가진 사람 필참
- 오늘 활동 참여한 사람 중에 내일도 하는 사람 있으면 열쇠 넘겨줄 수 있음
- 첫 날 열쇠 A한테 있음 / 모든 활동 끝난 후 누가 가지든 상관 X
- 각 날의 활동 책임자 필참
*/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// return binary of alphabet
long long get_binary(char alphabet) {
    long long bin = 0b0000;

    switch (alphabet) {
        case 'A':
            return (bin |= (1 << 3));
        case 'B':
            return (bin |= (1 << 2));
        case 'C':
            return (bin |= (1 << 1));
        case 'D':
            return (bin |= (1 << 0));
        default:
            return 0;
    }
}

// get all subset of set
//vector <int> get_subset(int set) {
long long get_subset(int set) {
    // vector <int> subset;
    long long subset = 0b0000;
    for (int i=1; i < (1 << 4); i++) { // 공집합을 제외한 모든 부분 집합 순회
        if ((set & i) == 0) {
            subset = subset << 4;
            subset |= i;
            //subset.push_back(i);
        }
    }
    return subset;
}

// check set includes element
bool check_included(int set, int element) {
    if ((set & element) != 0)
        return true;
    else return false;
}

// remove elements not included in prev
//vector <int> remove_subset(vector <int> set, int prev) {
long long remove_subset(long long set, int prev) {    
    long long ret_set = 0;
    /* for (int i=0; i<set.size(); i++) {
    if ((set[i] & prev) == 0) { // only set with one element
        set.erase(set.begin() + i);
        i--;
    } */
    while (set > 0) {
        int check = 0b0000;
        check = set & ~(~0U << 4);
        set = set >> 4; //remove

        // set[i] = check | set
        if ((check & prev) != 0) {
            ret_set = ret_set << 4;
            ret_set |= check;
        }     
    }

    return ret_set;
}

long long add_element(long long set, int curr) {
    long long ret_set = 0;
    while (set > 0) {
        int check = 0b0000;
        check = set & ~(~0U << 4); // set[i] = check | set
        set = set >> 4;
        check |= curr; // add element
        ret_set = ret_set << 4;
        ret_set |= check;
    }
    return ret_set;
}

long long concat_set(long long s1, long long s2) {
    while (s2 > 0) {
        int check = 0b0000;
        check = s2 & ~(~0U << 4);
        s2 = s2 >> 4;

        s1 = s1 << 4;
        s1 |= check;
    }

    return s1;
}

int return_numsize(long long set) {
    int cnt = 0;
    while (set > 0) {
        int check = set & ~(~0U << 4);
        if (check != 0)
            cnt++;
        set = set >> 4;
    }
    return cnt;
}

int main(void) {
    int test_case;
    cin >> test_case;

    for (int t=1; t<=test_case; t++) {
        string s;
        cin >> s;
        vector <unsigned long long> curr_set, prev_set;
        int curr = 0, cnt = 0;
        unsigned long long cases;

        // check each element
        for (int i=0; i<s.size(); i++) {
            // init var
            cases = 0;
            prev_set = curr_set;
            curr_set.clear(); 

            curr = get_binary(s[i]); // Responsible student of today

            // At first, student 'A' has the key (= student 'A' should attend)
            if (i==0) {
                prev_set.push_back(get_binary('A'));
            }

            cout << prev_set.size() << endl;
            for(int j=0; j<prev_set.size(); j++) {
                unsigned long long prev_set2 = prev_set[j];

                unsigned long long tmp_set = get_subset(curr); // get all subset excluding current student

                int prev = prev_set2 & ~(~0U << 4);
                prev_set2 = prev_set2 >> 4;

                if (check_included(prev, curr)) { // include empty set
                    tmp_set = tmp_set << 4;
                    tmp_set |= 0b0000;
                    tmp_set |= curr;
                }   

                else {// remove 
                    tmp_set = remove_subset(tmp_set, prev);
                }

                tmp_set = add_element(tmp_set, curr);
            
                cases += return_numsize(tmp_set);
                
                while(tmp_set > 0) {
                    curr_set.push_back((tmp_set & ~(~0U << 4)));
                    tmp_set = tmp_set >> 4;
                }
            }
        }

        cases %= 1000000007;
    
        cout << "#" << t << " " << cases << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector <int> parent;
vector <int> left_child;
vector <int> right_child;
int ans_size;

// find ancestor
vector<int> findAnc(int idx) {
    int tmp = parent[idx];
    vector <int> anc;
    while (tmp != 0) {
        anc.emplace_back(tmp);
        tmp = parent[tmp];
    }
    return anc;
}

// find same and closest ancestor
int LSA(vector<int> v1_vec, vector<int> v2_vec) {
    int lsa;
    int loop_size = (v1_vec.size() >= v2_vec.size()) ? v2_vec.size() : v1_vec.size();
    for (int i=0; i<loop_size; i++) {
        if (v1_vec.back() != v2_vec.back())
            break;
        
        lsa = v1_vec.back();
        v1_vec.pop_back();
        v2_vec.pop_back();
    }
    return lsa;
}

void findMax(int v) {
    if (v == 0)
        return;
    
    ans_size += 1;

    if (left_child[v] != 0)
        findMax(left_child[v]);
    if (right_child[v] != 0)
        findMax(right_child[v]);
}

int main(void) {
    int test_case, v, e, v1, v2, ans_v;
    cin >> test_case;

    for (int t=1; t<=test_case; t++) {
        cin >> v >> e >> v1 >> v2;
    
        parent.clear(); // init
        left_child.clear();
        right_child.clear();

        parent.resize(v+1, 0); // resizing
        left_child.resize(v+1, 0);
        right_child.resize(v+1, 0);
        
        parent[0] = 0;
        parent[1] = 0;

        int e1, e2;
        for (int i=1; i<=e; i++) {
            cin >> e1 >> e2;

            parent[e2] = e1;
            if (left_child[e1] == 0)
                left_child[e1] = e2;
            else if (right_child[e1] == 0)
                right_child[e1] = e2;
        }

        vector <int> v1_anc = findAnc(v1);
        vector <int> v2_anc = findAnc(v2);
        ans_v = LSA(v1_anc, v2_anc);

        ans_size = 0;
        findMax(ans_v);

        cout << "#" << t << " " << ans_v << " " << ans_size << endl;
    }

    return 0;
}
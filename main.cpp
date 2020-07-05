#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> query(n);
    for (int i = 0; i < n; i++) {
        cin >> query[i].first >> query[i].second;
    }
    unordered_map<int, int> m1;
    unordered_map<int,set<int>> m2;
    for(int i=0;i<query.size();i++) {
        if (query[i].first == 1) {
            m2[m1[query[i].second]].erase(query[i].second);
            m1[query[i].second]++;
            m2[m1[query[i].second]].insert(query[i].second);
        } else if (query[i].first == 2) {
            m2[m1[query[i].second]].erase(query[i].second);
            m1[query[i].second]--;
            if (m1[query[i].second] <= 0)m1.erase(query[i].second);
            else m2[m1[query[i].second]].insert(query[i].second);
        } else if (query[i].first == 3) {
            if (m2[query[i].second].size() > 0) {
                cout << 1 << endl;

            } else {
                cout << 0 << endl;
            }
        }
    }
}
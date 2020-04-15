#include <bits/stdc++.h>

#define ii pair <int, int>
#define fi first
#define se second

using namespace std;

const int MAXN = 100005;

struct DATA {
    int par;
    int cnt;
    int stop;
    int child[27];
};

int N, root, id,fk=0;
DATA Trie[MAXN * 10];

int AddNode() {
    ++id;
    Trie[id].stop = Trie[id].cnt = Trie[id].par = 0;
    //for (int k = 0; k <= 26; ++k)
        //Trie[id].child[k] = 0;
    return id;
}
void AddWord(string tmp) {
    tmp = " " + tmp;
    int r = root;


    for (int i = 1; i < tmp.size(); ++i) {
        int k = tmp[i] - 'a', l;
        if (Trie[r].child[k] == 0) {
            l = AddNode();
            Trie[r].child[k] = l;
            Trie[l].par = r;
        }
        r = Trie[r].child[k];
    }
    Trie[r].stop++;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("Cost of Data.INP", "r", stdin);
    freopen("Cost of Data.OUT", "w", stdout);
#endif

    cin >> N;
    while (N--) {
        string S;
        cin >> S;
        AddWord(S);
    }
    cout << id + 1;
	return 0;
}

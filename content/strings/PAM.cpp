#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct PAM {
    const static int N = (int)3e5 + 50;

    struct node {
        int len;
        int nxt[26], fail;
        node(int len = 0): len(len), fail(0) {
            memset(nxt, 0, sizeof(nxt));
        }
    } nd[N];

    int len, cnt;
    int cur;
    char s[N];
    int dp[N];

    int getfail(int x) {
        while(s[len - nd[x].len - 1] != s[len]) x = nd[x].fail;
        return x;
    }

    void init() {
        len = cnt = cur = 0;
        nd[cnt] = node(0);
        nd[cnt].fail = 1;
        nd[++cnt] = node(-1);
        nd[cnt].fail = 0;
        s[0] = '$';
    }

    void extend(char c) {
        s[++len] = c;
        int now = getfail(cur);
        if(!nd[now].nxt[c - 'a']) {
            int tmp = ++cnt;
            nd[tmp] = node(nd[now].len + 2);
            nd[tmp].fail = nd[getfail(nd[now].fail)].nxt[c - 'a'];
            nd[now].nxt[c - 'a'] = tmp;
        }
        cur = nd[now].nxt[c - 'a'];
        dp[cur]++;
    }

} pam;

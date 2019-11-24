/**
 * Author: 
 * Date: 
 * License: 
 * Source: 
 * Description: DSU with rollbacks, $O(\log n)$ both to find root and to unite two nodes
 */
struct DSU {
    P S[N*2];
    int f[N];
    int sz = 0;

    void init(int n) {
        fill(f, f + n, -1);
    }

    int getroot(int i) {
        while(f[i] >= 0) i = f[i];
        return i;
    }

    bool unite(int i, int j) {
        int ri = getroot(i);
        int rj = getroot(j);
        if(ri == rj) return false;

        if(ri < rj) swap(ri, rj);
        S[sz++] = {ri, f[ri]};
        S[sz++] = {rj, f[rj]};
        f[rj] += f[ri];
        f[ri] = rj;

        return true;
    }

    void roll_back(int la_sz) {
        while(sz > la_sz) {
            sz--;
            f[S[sz].first] = S[sz].second;
        }
    }

} dsu;
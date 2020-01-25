/**
 * Author: 
 * Date: 
 * License: 
 * Source: 
 * Description: Find Euler Circuit in $O(n)$
 */
multiset<int> G[N];

void dfs(int v){
    while(G[v].size()){
        int nxt = *G[v].begin();
        G[nxt].erase(G[nxt].find(v));
        G[v].erase(G[v].begin());
        dfs(nxt);
    }
    res.push_back(v);
}

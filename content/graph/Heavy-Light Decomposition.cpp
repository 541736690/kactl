/**
 * Author: 
 * Date: 
 * License: 
 * Source: 
 * Description: 
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 100050;

int n,m,q;
vector<int> G[N];
int chainNo, chainHead[N], chainInd[N], totPos[N], totsize, veridx[N];
int subsize[N], par[N];

void dfs(int v, int p, int d){
    par[v] = parent[0][v] = p;
    subsize[v] = 1;
    for(int &nxt : G[v]){
        if(nxt == p) continue;
        dfs(nxt, v, d+1);
        subsize[v] += subsize[nxt];
        if(subsize[nxt] > subsize[G[v][0]])
            swap(nxt, G[v][0]);
    }
}

void hld(int v, int p){
    if(chainHead[chainNo] == -1) chainHead[chainNo] = v;
    chainInd[v] = chainNo;
    in[v] = totPos[v] = totsize;
    veridx[totsize++] = v;
//    v_cost[totsize ++] = cost;

    for(auto nxt : G[v]){
        if(nxt == p) continue;
        if(nxt != G[v][0]) chainNo ++;
        hld(nxt, v);
    }
    out[v] = totsize;
}

void init_hld(int V){
    chainNo = totsize = 0;
    fill(chainHead, chainHead + n, -1);
    dfs(0, -1, 0);
    hld(0, -1);
    fill(sum, sum + 4 * n, 0);
    fill(add, add + 4 * n, 0);
}

int query(int pos, int x, int l, int r) {
    // Segment Tree Query
}

void update(int a, int b, int x, int l, int r, int val) {
    // Segment Tree Update
}

void update_to_root(int v, int val) {
    while(chainInd[v] != chainInd[0]){
        update(totPos[chainHead[chainInd[v]]], totPos[v], 0, 0, n-1, val);
        v = par[chainHead[chainInd[v]]];
    }
    update(totPos[0], totPos[v], 0, 0, n-1, val);
}
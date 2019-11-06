/**
 * Author: 
 * Date: 
 * License: 
 * Source: 
 * Description: 
 */
#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50, B = 31;

int n;
int a[N];

struct Basis {
    int sz = 0;
    int bas[B];

    bool add(int x) {
        if(x == 0) return false;
        for(int i = 0; i < sz; i++) {
            if((x ^ bas[i]) < x) x ^= bas[i];
            if(x == 0) return false;
        }
        bas[sz++] = x;
        for(int i = sz - 2; i >= 0; i--) {
            if(bas[i] < bas[i+1]) swap(bas[i], bas[i+1]);
        }
        return true;
    }
}basis;
/**
 * Author: 
 * Date: 
 * License: 
 * Source: 
 * Description: 
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + (int)1e5, mod = (int)1e9 + 7, inv2 = (int)5e8 + 4, M = (int)1e5 + 50, INF = (int)1e9;

int add(int a, int b) {
    a = (a + b) % mod;
    if(a < 0) a += mod;
    return a;
}

int mul(int a, int b) {
    return (int)(1LL * a * b % mod);
}

int p[N];

int n, m;
string str[20];
int freq[N], cnt[N], res[N];

struct FWT {
    // Please set N!!!
    int N;
    // Sum over Subsets
    void FWTor(int *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++)
                    if(opt == 1) a[j + k + mid] = add(a[j + k], a[j + k + mid]);
                    else a[j + k + mid] = add(a[j + k + mid], -a[j + k]);
    }
    // Sum over supersets
    void FWTand(int *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++)
                    if(opt == 1) a[j + k] = add(a[j + k], a[j + k + mid]);
                    else a[j + k] = add(a[j + k], -a[j + k + mid]);
    }
    void FWTxor(int *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++) {
                    int x = a[j + k], y = a[j + k + mid];
                    if(opt == 1) a[j + k] = add(x, y), a[j + k + mid] = add(x, -y);
                    else a[j + k] = mul(add(x, y), inv2), a[j + k + mid] = mul(add(x, -y), inv2);
                }

    }
} fwt;
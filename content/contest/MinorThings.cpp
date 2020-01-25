/**
 * Author: 
 * Date: 
 * License: 
 * Source: 
 * Description: 
 */
#include <bits/stdc++.h>
using namespace std;

// Define Hash Function for hash map
struct HASH{
    size_t operator()(const P &x)const{
        return hash<ll>()((x.first)^((x.second)<<32));
    }
};
// multiply numbers up to 1e18 under some modulo
ll big_mul(ll a, ll b)
{
    ll q = (ll)((ld) a * (ld) b / (ld) mod);
    ll r = a * b - q * mod;

    return (r + mod) % mod;
}


int main(){
	//random number
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cout << rng() % 5 << endl;
    	std::shuffle(v.begin(), v.end(), rng);

    //calculating sum of floor(n/i) in O(sqrt(n))
    for (int i = 1, j = 0; i <= n; i = j + 1)  j = n/(n/i), ans += 1ll*(j-i+1)*(n/i);
        
    // Iterate every submask
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int sub = mask; ; sub = (sub - 1) & mask) {
            //...
            if(sub == 0) break;
        }
    }

    //Better hash map
    unordered_map<int, int> mp;
    mp.reserve(32768);
    mp.max_load_factor(0.25);
}

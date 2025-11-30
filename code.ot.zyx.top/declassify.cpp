#define debug(...) nullptr
#define stdlib(...) nullptr
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef __int128 i128;
typedef unsigned __int128 u128;
constexpr int m99 = 998244353;
constexpr int m17 = 1e9 + 7;
constexpr int mod = 65537;
mt19937 mrand(random_device{}());
inline int rnd(int l,int r){return uniform_int_distribution<int>(l,r)(mrand);}
#define rndshuffle(bg,en) shuffle(bg,en,mrand)
inline int quickpow(int x,int y){
    int ret = 1,pw = x;
    for (;y;y >>= 1){
        if (y & 1) ret = ret * 1LL * pw % mod;
        pw = pw * 1LL * pw % mod;
    }
    return ret;
}
inline void getv(int &id){
	unsigned x,y;
	cin >> x >> y;
	for (;x--;){
		unsigned v = y;
		for (unsigned i = 1;i;i <<= 1){
			v ^= (v & i) << 3;
		}
		for (unsigned i = 1U << 31;i;i >>= 1){
			v ^= (v & i) >> 17;
		}
		for (unsigned i = 1;i;i <<= 1){
			v ^= (v & i) << 15;
		}
		y = v;
	}
	id = y;
}
inline int qinv(int x){return quickpow(x,mod - 2);}
int main (){
	freopen("密文.txt", "r", stdin);
	freopen("原文.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> a,c,s;
	for (int i = 1;i <= n;i++) a.push_back(0),getv(a.back());
	for (int i = 1;i <= n;i++) c.push_back(0),getv(c.back());
	for (int i = 1;i <= n;i++) s.push_back(0),getv(s.back());
	for (int i = 0;i < n;i++)
		wcout << (wchar_t)((a[i] - s[i] + mod) % mod * 1LL * qinv(c[i]) % mod);
}
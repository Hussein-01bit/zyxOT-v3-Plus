#include <bits/stdc++.h>
using namespace std;
wstring s;
inline random_device *getdevice(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#ifndef __GNUC__
	cout << "warning:Compiler is not GCC,you will never get warning of although use Pseudo-random (possibly insecure) to make random number,press any key to confirm\n";
#else
	random_device *pnt = allocator<random_device>().allocate(1);
	try{
		try{
			return new (pnt) random_device ("rdrand");
		}catch(...){
			return new (pnt) random_device ("rdseed");
		}
	}catch(...){
		cout << "warning:rdrand failed,will use Pseudo-random (possibly insecure) to make random number,press any key to confirm\n";
		return new (pnt) random_device ();
	}
#endif
}
random_device &rdv = *getdevice();
inline void xorshift(unsigned x){
	random_device &rdrand = rdv;
	int rd = uniform_int_distribution<int>(1,10)(rdrand);
	cout << rd << ' ';
	for (;rd--;){
		x ^= x << 15;
		x ^= x >> 17;
		x ^= x << 3;
	}
	cout << x << ' ';
}
int main (){
	wifstream strm("原文.txt");
	for (;strm;s += strm.get());
	s.pop_back();
	freopen("密文.txt", "w", stdout);
	random_device &rd = rdv;
	vector<int> a,c;
	cout << s.size() << '\n';
	for (int i:s){
		uniform_int_distribution<int> unif(0,65536);
		long long v = uniform_int_distribution<int>(1,65536)(rd);
		a.push_back(v);
		long long v2 = unif(rd);
		c.push_back(v2);
		i = (i * v + v2) % 65537;
		xorshift(i);
	}
	cout << '\n';
	for (auto i:a)
		xorshift(i);
	cout << '\n';
	for (auto i:c)
		xorshift(i);
}
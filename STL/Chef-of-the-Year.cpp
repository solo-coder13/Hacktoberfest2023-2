#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int maxCount (auto Map){
	int Max = -1e9;
	for (auto i:Map)
		Max = max (Max, i.second);
	return Max;
}
void dbg (auto X){
	#ifndef VarunDebug
	return;
	#endif
	cout << "{\n";
	for (auto i:X)
		cout << "\t" << i.first << " : " << i.second << '\n';
	cout << "}\n";
}
void debug (auto X){
	#ifndef VarunDebug
	return;
	#endif
	cout << "[ ";
	for (auto i:X)
		cout << i << " ";
	cout << "]\n";
}
void Onigiri () {
	int N, M; cin >> N >> M;
	map <string, string> dp;
	for (int i=0;i<N;++i){
		string s1, s2; cin >> s1 >> s2;
		dp[s1] = s2;
	}
	string A[M];
	for (int i=0;i<M;++i)
		cin >> A[i];
	//for (auto i:A) cout << i << ", "; cout << '\n';
	map <string, int> chef, country;
	for (int i=0;i<M;++i){
		chef[A[i]]++;
		country[dp[A[i]]]++;
	}
	dbg (dp);
	dbg (chef);
	dbg (country);
	multiset <string> chefCandidates, countryCandidates;
	int maxChef = maxCount (chef);
	int maxCountry = maxCount (country);
	for (auto i:chef)
		if (i.second == maxChef)
			chefCandidates.insert (i.first);
	for (auto i:country)
		if (i.second == maxCountry)
			countryCandidates.insert (i.first);
	debug (chefCandidates);
	debug (countryCandidates);
	cout << *countryCandidates.begin() << '\n';
	cout << *chefCandidates.begin() << '\n';
}
int32_t main (){
	#ifndef VarunDebug
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#endif

	int t = 1; 
	//cin >> t;

	for (int i=0;i<t;++i)
		Onigiri();
}

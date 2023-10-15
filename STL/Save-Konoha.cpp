#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void dbg (auto S){
	#ifndef VarunDebug
	return;
	#endif
	cout << "Set : ";
	for (int i:S)
		cout << i << ' ';
	cout << '\n';
}
void Onigiri () {
	int N, Z; cin >> N >> Z;
	int A[N];
	for (int i=0;i<N;++i)
		cin >> A[i];
	int cntr = 0;
	multiset <int, greater<int>> dp;
	for (int i=0;i<N;++i)
		dp.insert (A[i]);
	dbg (dp);
	while (Z > 0 && dp.size() > 0){
		int Largest = *dp.begin();
		dp.erase(dp.begin());
		Z -= Largest;
		Largest /= 2;
		if (Largest > 0)
			dp.insert (Largest);
		cntr++;
	}
	if (Z > 0)
		cout << "Evacuate" << '\n';
	else
		cout << cntr << '\n';

}
int32_t main (){
	#ifndef VarunDebug
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#endif

	int t = 1;
	cin >> t;

	for (int i=0;i<t;++i)
		Onigiri();
}

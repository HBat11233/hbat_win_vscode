#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

/*
	Codeforces Round : 521
	Div : 3
	Problem : D
*/

int freq[200005];

int main(){
	int n, k; cin >> n >> k;

	for(int i = 0; i < n; i++){
		int a; cin >> a;
		freq[a]++;
	}

	priority_queue<pii> pq;
	for(int i = 0; i < 200005; i++){
		if(freq[i] != 0){
			pq.push({freq[i], i});
		}
	}

	vi ans;

	map<int,int> m;

	while(k--){
		pii top = pq.top(); pq.pop();
		ans.push_back(top.second);
		m[top.second]++;
		pq.push({ freq[top.second] / (m[top.second] + 1), top.second });
	}

	for(int i : ans)
		cout << i << ' ';
	cout << '\n';

	return 0;
}
//学习到了，
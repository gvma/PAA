#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vlli;
lli n, input;
vlli levels, seg_tree;

void build(int node = 1, int start = 1, int end = n){
	if(start == end) seg_tree[node] = levels[start];
	else {
		int mid = (start + end) >> 1;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		seg_tree[node] = max(seg_tree[2*node], seg_tree[2*node+1]);
	}
}

int query(int l, int r, int node = 1, int start = 1, int end = n){
	if(start > r or end < l) return 0;
	if(start >= l and end <= r) return seg_tree[node];

	int mid = (start + end) >> 1;
	int p1 = query(l ,r, 2*node, start, mid);
	int p2 = query(l, r, 2*node+1, mid+1, end);
	return max(p1, p2);
}

int main(){
	lli count = 0;
	cin >> n;
	levels.resize(n+1);
	seg_tree.resize(n*4+1);
	for(int i = 1; i <= n; i++){
		cin >> input;
		levels[i] = input;
	}
	lli resp = 0;
	build(1, 1, n);
	for(int i = 2; i <= n-1; i++){
		if(levels[i] < query(1, i-1) 
			&& levels[i] < query(i+1, n)){
			resp++;
		}
	}
	cout << resp << endl;
	return 0;
}
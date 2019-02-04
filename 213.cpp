#include <bits/stdc++.h>

using namespace std;

char adj_matrix[1000][1000];
int n, m;

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> adj_matrix[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << adj_matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}
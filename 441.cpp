#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<lli> vlli;
typedef vector<vlli> vvlli;

lli dx[] = {1 , 1 , 1 , 0 , 0 , -1 , -1 , -1};
lli dy[] = {1 , 0 , -1 , 1 , -1 , 1 , 0 , -1};

char adj_matrix[25][25];
lli sz, input;

void search(lli x, lli y){
	for(int i = 0; i < 8; i++){
		if(adj_matrix[x + dx[i]][y + dy[i]] == '1'){
			// if(adj_matrix[x + dx[i]][y + dy[i]] >= sz) continue;
			adj_matrix[x + dx[i]][y + dy[i]] = '0'; //atualizando para não considerar mais
			//esse espaço da matriz como válido, já que ele já foi explorado, evitando, então
			//recursão infinita		
			search(x + dx[i],y + dy[i]);
		}
	}
}

int main(){
	int count = 1;
	while(scanf("%lld",&sz) != EOF){
		for(int i = 0; i < sz; i++){
			for(int j = 0; j < sz; j++){
				cin >> adj_matrix[i][j];
			}
		}
		for(int i = 0; i < sz; i++){
			for(int j = 0; j < sz; j++){
				cout << adj_matrix[i][j] << " ";
			}
			cout << endl;
		}
		lli ans = 0;
		for(int i = 0; i < sz; i++){
			for(int j = 0; j < sz; j++){
				if(adj_matrix[i][j] == '1'){
					search(i,j);
					ans++;
				}
			}
		}
		cout << "Image number " << count << " contains " << ans << " war eagles." << endl;
		count++;
	}
	return 0;
}
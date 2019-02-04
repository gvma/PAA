#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int GLOBAL;
lli n_of_tests;
char a;

void printing_matrix(vvb matrix){
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++){
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void generating_b_matrix(vvb &matrix, string input, int x, int y, int xx, int yy){
	GLOBAL += 1;
	if(GLOBAL >= input.size()){
		return;
	}
	int mid_x = (x + xx) / 2, mid_y = (y + yy) / 2; 
	if(x == xx || y == yy){
		GLOBAL -= 1;
		return;
	}
	if(input[GLOBAL] == 'D'){
		if((xx - x) % 2 != 0){
			mid_x++;
		}
		if((yy - y) % 2 != 0){
			mid_y++;
		} 
		generating_b_matrix(matrix, input, x, y, mid_x, mid_y);
		generating_b_matrix(matrix, input, x, mid_y, mid_x, yy);
		generating_b_matrix(matrix, input, mid_x, y, xx, mid_y);
		generating_b_matrix(matrix, input, mid_x, mid_y, xx, yy);

	} else {
		for(int i = x; i < xx; i++){
			for(int j = y; j < yy; j++){
				if(input[GLOBAL] == '1'){
					matrix[i][j] = true;
				} else {
					matrix[i][j] = false;
				}
			}
		}
	}
	return;
}

int main(){
	GLOBAL = -1;
	vvb matrix;
	lli n_of_lines, n_of_columns;
	cin >> n_of_tests;
	for(int i = 0; i < n_of_tests; i++){
		cin >> n_of_lines >> n_of_columns;
		matrix.resize(n_of_lines);
		for(int j = 0; j < n_of_lines; j++){
			matrix[j].resize(n_of_columns);
		}
		string in;
		cin >> in;
		generating_b_matrix(matrix, in, 0, 0, n_of_lines, n_of_columns);
		printing_matrix(matrix);
		for(int j = 0; j < n_of_lines; j++){
			for(int k = 0; k < n_of_columns; k++){
				matrix[j].clear();
			}
		}
		GLOBAL = -1;
		cout << endl;
	}

	// cout << matrix[0][0] << endl;
	return 0;
}
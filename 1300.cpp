#include <bits/stdc++.h>

using namespace std;

typedef vector<long long int> vi;
typedef vector<vi> vvi;
int x;

vvi copying_matrix(vvi matrix, int chosen_line, int chosen_column, int x, int total_lines){
	vvi new_matrix;
	new_matrix.resize(matrix.size()-1);
	int ii = 0, jj = 0;
	for(int i = chosen_line; i < matrix.size(); i++){
		for(int j = 0; j < matrix.size(); j++){
			if(i == chosen_line || j == chosen_column){
				continue;
			} else {
				if(jj == total_lines - 2){
					new_matrix[ii].push_back(matrix[i][j]);
					ii++;
					jj = 0;
				} else {
					new_matrix[ii].push_back(matrix[i][j]);
					jj++;
				}
			}
		}
	}
	return new_matrix;
}

long long int determinant(vvi matrix){
	if(matrix.size() == 2){
		return matrix[0][0] * matrix[1][1] - (matrix[0][1] * matrix[1][0]);
	} else if(matrix.size() == 1){
		return matrix[0][0];
	} else {
		vvi new_matrix;
		new_matrix.resize(matrix.size()-1);
		long long int sum = 0;
		for(int i = 0; i < matrix.size(); i++){
			new_matrix = copying_matrix(matrix,0,i,matrix.size(),matrix.size());
			if(i % 2 == 0){
				sum += matrix[0][i] * determinant(new_matrix);
			} else {
				sum += matrix[0][i] * determinant(new_matrix) * -1;
			}
		}
		return sum;
	}
}

int main(){
	vvi matrix;
	int input;
	cin >> x;
	int det = 0;
	matrix.resize(x);
	for(int i = 0; i < x; i++){
		for(int j = 0; j < x; j++){
			cin >> input;
			matrix[i].push_back(input);
		}
	}
	cout << determinant(matrix) << endl;
	// cout << answer << endl;
	return 0;
}
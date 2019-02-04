#include <bits/stdc++.h>

using namespace std;

int main(){
	char a;
	long double aux_min = INT_MAX, aux_max = INT_MIN;
	long long int input, count = 0;
	long double sum = 0;
	cin >> a;
	while(cin >> input){
		cout << "INPUT = " << input << endl;
		if(input > aux_max){
			aux_max = input;
		}
		if(input < aux_min){
			aux_min = input;
		}
		sum += input;
		cin >> a;
		count += 1;
		if(a == ']'){
			break;
		}
	}
	cout << "Maior: " << aux_max << endl;
	cout << "Menor: " << aux_min << endl;
	printf("Media: %.2Lf\n", (long double)sum/(long double)count);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

// typedef pow(10,9) MAX;
typedef long double ld;
typedef vector<ld> vld;
ld n_of_planets, rocket_weight, fuel_left, ans;
bool flag = false;

ld checking_fuel(vld landing, vld take_off, ld fuel_test){
	int ii = 0, jj = 0;
	ld aux;
	fuel_left = fuel_test;
	for(int i = 0; i < n_of_planets * 2; i++){
		if(i % 2 == 0){
			aux = (rocket_weight + fuel_left) / take_off[ii];
			fuel_left -= aux;
			ii++; 
		} else {
			aux = (rocket_weight + fuel_left) / landing[jj];
			fuel_left -= aux;
			jj++;
		}
	}
	if(fuel_left < 0){
		return -1;
	} else {
		return fuel_test;
	}
}

ld binary_search(vld landing, vld take_off){
	ld begin = 0;
	ld end = pow(10,9);
	ld resp, aux = INT_MAX;
	ld middle = (end + begin) / 2;
	while(begin <= end && abs(end - begin) > 0.000001){
		resp = checking_fuel(landing, take_off, middle);
		if(resp == -1){
			begin = middle;
		} else {
			if(resp < aux){
				aux = resp;
			}
			end = middle;
		}
		middle = (end + begin) / 2;
	}
	return aux;
}

void scanning(vld &vec){
	for(int i = 0; i < n_of_planets; i++){
		cin >> vec[i];
	}
}

int main(){
	cin >> n_of_planets >> rocket_weight;
	vld landing, take_off;
	landing.resize(n_of_planets);
	take_off.resize(n_of_planets);
	scanning(take_off);
	scanning(landing);
	ans = binary_search(landing, take_off);
	if(ans == INT_MAX){
		cout << "-1" << endl;
	} else {
		printf("%.2Lf\n", ans);
	}
	return 0;
}
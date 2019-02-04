#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

struct count_struct{
	lli type_of_food = 0;
	lli frequency = 0;
	lli cache = 0;
};

lli quantity_of_travelers, total, input;

int max_days(struct count_struct *count_struct_vec, lli quantity_of_days){
	lli aux = -1;
	for(int i = 0; i < total; i++){
		count_struct_vec[i].cache = count_struct_vec[i].frequency;
	}
	for(int i = 0; i < quantity_of_travelers; i++){
		for(int j = 0; j < total; j++){
			if(count_struct_vec[j].cache >= quantity_of_days){
				count_struct_vec[j].cache -= quantity_of_days;
				aux = 0;
				break;
			}
		}
		if(aux == -1){
			return -1;
		}
		aux = -1;
	}
	return 1;
}

lli binary_search(lli begin, lli end, struct count_struct *count_struct_vec){
	lli aux = 0;
	while(begin <= end){
		lli middle = (end + begin) / 2;
		if(max_days(count_struct_vec, middle) < 0){
			end = middle;
		} else {
			if(middle > aux){
				aux = middle;
			}
			begin = middle + 1;
		}
	}
	if(max_days(count_struct_vec, end) == 1){
		aux = begin;
	}
	return aux;
}

int main(){
	lli aux = -999;
	lli quantity_of_food;
	vector<lli> inputs;
	cin >> quantity_of_travelers >> quantity_of_food;
	total = quantity_of_food;
	struct count_struct count_struct_vec[quantity_of_food];
	for(int i = 0; i < quantity_of_food; i++){
		cin >> input;
		inputs.push_back(input);
	}
	for(int i = 0; i < quantity_of_food; i++){
		for(int j = 0; j <= i; j++){
			if(count_struct_vec[j].type_of_food == 0){
				count_struct_vec[j].type_of_food = inputs[i];
				count_struct_vec[j].frequency = 1;
				break;
			}
			if(count_struct_vec[j].type_of_food == inputs[i]){
				count_struct_vec[j].frequency++;
				break;
			}
		}	
	}
	cout << binary_search(0, quantity_of_food / quantity_of_travelers, count_struct_vec) << endl;
	return 0;
}
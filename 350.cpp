#include <stdio.h>
#include <stdlib.h>

void search(long long int middle){
	long long int begin = 0;
	long long int end = 100;
	long long int guess;
	while(end - begin != 2){
		scanf("%lld",&guess);
		if(guess < middle){
			if(end - guess == 2){
				printf("Ambrosio bebe!\n");
				return;
			}
		} else if(guess > middle){
			if(guess - begin == 2){
				printf("Ambrosio bebe!\n");
				return;
			}
		}
		if(guess - begin == 2){
			printf("Ambrosio bebe!\n");			
			return;
		}
		if(guess == middle){
			printf("Voce bebe!\n");
			return;
		} else {
			if(guess < middle){
				if(guess > begin){
					begin = guess;
				}
				printf("Escolha um numero entre %lld e %lld!\n", begin, end);
			} else {
				if(guess < end){
					end = guess;
				}
				printf("Escolha um numero entre %lld e %lld!\n", begin, end);
			}
		}
	}
	printf("Ambrosio bebe!\n");
}

int main(){
	long long int input, chosenNumber;
	scanf("%lld",&chosenNumber);
	search(chosenNumber);
	return 0;
}
#include <iostream>
#include <stdio.h>
using namespace std;
 
int main(){
	int T, N;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		N = N/2+1;
		printf("%d\n", N);
	}
	return 0;
}

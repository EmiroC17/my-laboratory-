#include <iostream>
#include <math.h>
//Эмиро Кордоба
using namespace std;

long double fact(int N)
{
    if(N < 0) 
        return 0; 
    if (N == 0) 
        return 1; 
    else 
        return N * fact(N - 1); 
}

int main(int argc, char** argv) {
	int n, x, k = 1;
	int op1 = pow(-1, k) * (pow(x, (2*k)+1));
	int op2 = ((2*k)+4)*((2*k)+4)* fact(k);
	float total = 0;
	cout<<"Enter n, x: ";
	cin>>n>>x;
	
	while (k != n){
		total += (op1)/ (op2);
		k++;
	}
	
	cout<<"Result: "<<total;
	
	return 0;
}

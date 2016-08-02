#include<iostream>
#define min(a,b) (a)<(b) ? (a):(b)
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	char *dna = new char[n];
	cin >> dna;
	int *toA = new int[n];
	int *toB = new int[n];

	int i = 0;
	if(dna[0] == 'A'){
    	while(dna[i] == 'A'){
    	    toA[i] = 0;
    	    toB[i] = 1;
    	   	i++;
    	}
    } 
    else{
    	while(dna[i] == 'B'){
        	toA[i] = 1;
        	toB[i] = 0;
        	i++;
    	}   
    }   

    for(; i<n; i++){
        if(dna[i] == 'A'){
            toA[i] = min(toA[i-1], toB[i-1]+1);
            toB[i] = min(toA[i-1]+1, toB[i-1]+1);
        }   
        else{
            toA[i] = min(toA[i-1]+1, toB[i-1]+1);
            toB[i] = min(toA[i-1]+1, toB[i-1]);
        }   
    }   

	int min = min(toA[n - 1], toB[n - 1] + 1);

    cout<<min<<endl;
}
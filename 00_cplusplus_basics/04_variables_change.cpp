#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << ++counter; // 1: increments before evaluating
	cout << counter;   // 1: has NOT changed.
	cout << counter++; // 1: increments after evaluating
	cout << counter;   // 2: evidence of change.
return 0;
}
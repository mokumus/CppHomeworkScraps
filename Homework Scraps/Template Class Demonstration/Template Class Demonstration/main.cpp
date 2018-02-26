#include <iostream>
#include <ctime>
#include "mySort.h"

using namespace std;

int main(int argc, const char * argv[]) {
	srand(static_cast<int>(time(NULL)));
	char arr[7] = {'R','E','K','T','B','O','I'};
	//mySort<char>::fillArrayWithRandoms(arr, 7);
	mySort<char>::printArray(arr, 7);
	cout << "Sorting..." << endl;
	mySort<char>::linearSort(arr, 7);
	mySort<char>::printArray(arr, 7);
	
	
    return 0;
}





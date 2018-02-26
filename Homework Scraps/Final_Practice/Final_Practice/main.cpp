#include <iostream>
#include "GTUVectorDynamic.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
	GTUVectorDynamic<double> d1(3);
	cout << "Size: " <<d1.size() << endl;
	d1.push_back(1.1);
	d1.push_back(0.2);
	d1.push_back(0.3);
	d1.push_back(0.4);
	d1.push_back(0.5);
	d1.push_back(0.6);
	cout << "Size: " <<d1.size() << endl;
	for(int i = 0; i < d1.size(); i++)
		cout << d1.a[i] << " ";
	
	
	
	
	
	
	cout << endl;
	
}

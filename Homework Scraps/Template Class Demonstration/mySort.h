#ifndef mySort_h
#define mySort_h
#include<iostream>
#include<ctime>

using namespace std;

template <class T>
class mySort{
public:
	static void linearSort(T a[], int size);
	static void fillArrayWithRandoms(T a[], int size);
	static void printArray(const T a[], int size);
private:
	static void swapValues(T& val1, T& val2);
	static int indexOfTheSmallest(const T a[],int index,int size);
};

template <class T>
void mySort<T>::swapValues(T& val1, T& val2){
	T temp = val1;
	val1 = val2;
	val2 = temp;
}

template <class T>
void mySort<T>::linearSort(T a[], int size){
	int nextIndex;
	for(int i = 0; i < size - 1; ++i){
		nextIndex = indexOfTheSmallest(a, i, size);
		swapValues(a[i], a[nextIndex]);
	}
}

template <class T>
int mySort<T>::indexOfTheSmallest(const T a[],int startIndex,int size){
	int min = a[startIndex];
	int indexOfMin = startIndex;
	
	for(int index = startIndex + 1; index < size; ++index){
		if(a[index] < min){
			min = a[index];
			indexOfMin = index;
		}
		
	}
	return indexOfMin;
}

template <class T>
void mySort<T>::fillArrayWithRandoms(T a[], int size){
	for(int i = 0; i < size; ++i)
		a[i] = static_cast<T>(rand()%100);
}

template <class T>
void mySort<T>::printArray(const T a[], int size){
	cout << "[";
	for(int i = 0; i < size - 1; ++i)
		cout << a[i] << ", ";
	
	cout << a[size-1] << "]" << endl;
}



#endif /* mySort_h */

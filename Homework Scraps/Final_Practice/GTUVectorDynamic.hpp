#ifndef GTUVectorDynamic_hpp
#define GTUVectorDynamic_hpp
#include "GTUVector.hpp"
#include <iostream>
using namespace std;

template <class T>
class GTUVectorDynamic : public GTUVector<T>{
public:
	GTUVectorDynamic();
	GTUVectorDynamic(int size);
	GTUVectorDynamic(GTUVectorDynamic<T>& obj);
	~GTUVectorDynamic();
	
	
	int size() const;
	bool equal(GTUVector<T>& obj);
	void push_back(const T& item);
	

	T* a;
private:
	
	int capacity;
	int used;
};

template <class T>
GTUVectorDynamic<T>::GTUVectorDynamic() : GTUVectorDynamic(50){
	//Blank
}

template <class T>
GTUVectorDynamic<T>::GTUVectorDynamic(int size){
	a = new T[size];
	capacity = size;
	used = 0;
}

template <class T>
GTUVectorDynamic<T>::GTUVectorDynamic(GTUVectorDynamic<T>& obj){
	capacity = obj.capacity;
	used = obj.used;
	
	for(int i = 0; i < used; ++i)//array copy
		a[i] = obj.a[i];
}

template <class T>
GTUVectorDynamic<T>::~GTUVectorDynamic(){
	if(a)
		delete [] a;
}


template <class T>
int GTUVectorDynamic<T>::size() const{
	return used;
}


template <class T>
bool GTUVectorDynamic<T>::equal(GTUVector<T>& obj){
	
	auto tempObj = static_cast<GTUVectorDynamic<T>*>(&obj);
	if(used == tempObj->used){
		for(int i = 0; i < used; ++i){
			if(a[i] != tempObj->a[i])
				return false;
		}
		return true;
	}
	
	return false;
}

template <class T>
void GTUVectorDynamic<T>::push_back(const T& item){
	if(used < capacity)
		a[used++] = item;
	
	else{
		T* temp = new T[capacity+50];
		copy(a,a+used,temp);
		delete[] a;
		
		a = temp;
		
		a[used++] = item;
		capacity += 50;
		delete []temp;
	}
}







#endif /* GTUVectorDynamic_hpp */

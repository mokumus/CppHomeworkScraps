#include "GTUVectorDynamic.hpp"
#include <iostream>
using namespace std;

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
int GTUVectorDynamic<T>::size(){
	return used;
}


template <class T>
bool GTUVectorDynamic<T>::equal(GTUVector<T>& obj){
	if(used == obj.used){
		for(int i = 0; i < used; ++i){
			if(a[i] != obj.a[i])
				return false;
		}
		return true;
	}
	
	return false;
}

template <class T>
void GTUVectorDynamic<T>::push_back(const T& item){
	if(capacity > used)
		a[used++] = item;
	
	else{
		T* temp = new T[capacity+50];
		std::copy(a,a+capacity,temp);
		a[used++] = item;
		capacity += 50;
	}
}

template <class T>
GTUVector<T>& GTUVectorDynamic<T>::operator=(const GTUVector<T>& rightSide){
	if(capacity != rightSide.capacity){
		delete [] a;
		a = new double[rightSide.capacity];
	}
	
	capacity = rightSide.capacity;
	used = rightSide.used;
	for(int i = 0; i < capacity; ++i)//array copy
		a[i] = rightSide.a[i];
	
	return *this;
}



template <class T>
ostream& operator << (std::ostream& outs , const GTUVectorDynamic<T>& vector){
	outs << "[";
	for(int i = 0; i < vector[i]; i++){
		outs << vector[i];
		if(i != vector.getCapacity() - 1)
			outs << ", ";
	}
	outs << "]";
	return outs;
}























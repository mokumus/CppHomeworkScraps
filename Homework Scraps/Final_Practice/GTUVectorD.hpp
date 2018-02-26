#ifndef GTUVectorD_h
#define GTUVectorD_h
#include "GTUVector.hpp"
#include <vector>
template <class T>
class GTUVectorD : public GTUVector<T>{
public:
	
	GTUVectorD() : GTUVectorD(20){};
	GTUVectorD(int size);
	GTUVectorD(vector<T> &vec);
	GTUVectorD(GTUVectorD &obj);
	
	~GTUVectorD(){delete[] vectorD;}
	int size(){return current_size;}
	int maxsize(){return max_size;}
	T at(int index){return vectorD[index];}
	//bool equal(T object);
	void push_back(T item);
	
	GTUVectorD& operator=(const GTUVectorD<T> &rtSide){
		if(this == &rtSide)
			return *this;
		else{
			
			current_size = rtSide.current_size;
			max_size = rtSide.max_size;
			
			delete [] vectorD;
			
			vectorD = new T[max_size];
			
			return *this;
		}
		cout << "Assignment called" << endl;
	}
	
private:
	T* vectorD;
	int current_size;
	int max_size;
};

template <class T>
GTUVectorD<T>::GTUVectorD(GTUVectorD &obj){
	*this = obj;
	cout << "Cpy Constr called..." << endl;
}


template <class T>
GTUVectorD<T>::GTUVectorD(int size){
	current_size = 0;
	max_size = size;
	vectorD = new T[size];
}

template <class T>
GTUVectorD<T>::GTUVectorD(vector<T> &vec){
	current_size = static_cast<int>(vec.size());
	max_size = current_size + 20;
	vectorD = new T[max_size];
	
	for(auto i = vec.begin(); i != vec.end(); i++)
		vectorD = &*i;
	
}


template <class T>
void GTUVectorD<T>::push_back(T item){
	if(current_size < max_size)
		vectorD[current_size++] = item;
	else{
		/*
		T* temp = new T[max_size+20];
		std::copy(vectorD, vectorD + current_size, temp);
		vectorD = temp;
		vectorD[current_size++] = item;
		max_size +=20;
		*/
		
		GTUVectorD<T> temp(max_size+20);
		std::copy(vectorD, vectorD + current_size, temp.vectorD);
		*this = temp;
		vectorD[current_size++] = item;
		
	}
}

#endif /* GTUVectorD_h */

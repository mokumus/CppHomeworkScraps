#ifndef GTUVectorD_h
#define GTUVectorD_h
#include "GTUVector.hpp"

template <class T>
class GTUVectorD : public GTUVector{
public:
	
	virtual ~GTUVector(){cout << "Base constr call." << endl;}
	virtual int size() = 0;
	virtual T at(int index) = 0;
	virtual bool equal(T object) = 0;
	virtual void push_back(T item) = 0;
	
private:
	T* vectorD;
	
};



#endif /* GTUVectorD_h */

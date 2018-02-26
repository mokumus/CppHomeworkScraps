#ifndef GTUVector_hpp
#define GTUVector_hpp
template<class T>
class GTUVector{
public:
	virtual ~GTUVector<T>(){};
	
	virtual int size() const  = 0;
	virtual bool equal(GTUVector<T>& obj) = 0;
	virtual void push_back(const T& item) = 0;

	
};

#endif /* GTUVector_hpp */

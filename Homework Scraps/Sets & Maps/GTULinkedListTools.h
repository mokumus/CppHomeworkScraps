#ifndef GTULinkedListTools_h
#define GTULinkedListTools_h
#include <cstddef>
namespace tools{
	
	template<class T>
	class Node
	{
	public:
		//CONSTRUCTOR
		Node(const T& theData, Node<T>* theLink) : data(theData), link(theLink){}
		//GETTERS
		Node<T>* getLink( ) const { return link; }
		const T& getData( ) const { return data; }
		//SETTERS
		void setData(const T& theData) { data = theData; }
		void setLink(Node<T>* pointer) { link = pointer; }
	protected:
		T data;
		Node<T> *link;
	};
	
	template <class T>
	class GTUIterator{
	public:
		//CONSTRUCTORS
		GTUIterator() : current(nullptr) {}
		GTUIterator(Node<T>* initial) : current(initial) {}
		//DEREFERENCE OPT.
		const T& operator *() const {return current->getData();}
		const Node<T>* operator ->() const {return current;}
		//++PREFIX
		GTUIterator& operator++(){
			current = current->getLink();
			return *this;
		}
		//Node<T> * getCurrent() {return current;}
		//POSTFIX++
		GTUIterator& operator++(int ignoreMe){
			static GTUIterator temp(current); //To allocate space on heap
			current = current->getLink();
			return temp;
		}
		//--PREFIX
		GTUIterator& operator--(){
			current = (current - 1)->getLink();
			return *this;
		}
		//COMPARASION ==
		bool operator ==(const GTUIterator& rightSide) const{
			return(current == rightSide.current);
		}
		//COMPARASION !=
		bool operator !=(const GTUIterator& rightSide) const{
			return(current != rightSide.current);
		}
		//The default assignment operator and copy constructor should work for this class.
	private:
		Node<T> *current;
	};
	
	
	
	
	template<class T>
	void headInsert(Node<T>*& head, const T& theData)
	{
		head = new Node<T>(theData, head);
	}
	
	template<class T>
	void insert(Node<T>* afterMe, const T& theData)
	{
		afterMe->setLink(new Node<T>(theData, afterMe->getLink( )));
	}
	
	template<class T>
	void deleteNode(Node<T>* before)
	{
		Node<T> *discard;
		discard = before->getLink( );
		before->setLink(discard->getLink( ));
		delete discard;
	}
	
	template<class T>
	void deleteFirstNode(Node<T>*& head)
	{
		Node<T> *discard;
		discard = head;
		head = head->getLink( );
		delete discard;
	}
	
	template<class T>
	Node<T>* search(Node<T>* head, const T& target)
	{
		Node<T>* here = head;
		
		if (here == nullptr) //if empty list
		{
			return nullptr;
		}
		else
		{
			while (here->getData( ) != target && here->getLink( ) != nullptr)
				here = here->getLink( );
			
			if (here->getData( ) == target)
				return here;
			else
				return nullptr;
		}
	}
	
	
	template<class T>
	Node<T>* seekAndDestroy(Node<T>* head, const T& target)
	{
		Node<T>* here = head;
		Node<T>* next = head->getLink();
		
		if (here == nullptr) //if empty list
		{
			return nullptr;
		}
		else
		{
			while (next->getData( ) != target && next->getLink( ) != nullptr){
				here = here->getLink( );
				if(here != nullptr)
					next = here->getLink();
			}
			
			
			if (next->getData( ) == target)
				return here;
			else
				return nullptr;
		}
	}
	
}

#endif /* GTULinkedListTools_h */

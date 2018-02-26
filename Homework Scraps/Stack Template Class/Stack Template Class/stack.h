//
//  stack.h
//  Stack Template Class
//
//  Created by Muhammed Okumuş on 09/12/17.
//  Copyright © 2017 Muhammed Okumuş. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include<iostream>
using std::cout;

template <class T>
class Node{
	T data;
	Node<T> *link;
	
public:
	//CONSTRUCTOR
	Node(T theData, Node<T>* theLink) : data(theData), link(theLink) {}
	//GETTERS
	Node<T>* getLink() const {return link;}
	const T getData() const {return data;}
	//SETTERS
	void setData(const T& theData){data = theData;}
	void setLink(Node<T>* pointer){link = pointer;}
};

template <class T>
class Stack {
	Node<T> *top;
public:
	//CONSTRUCOTORS
	Stack(); //Init to empty stack
	Stack(const Stack<T>& aStack); //Copy c'tor.
	//OPERATORS
	Stack<T>& operator=(const Stack<T>& rightSide);
	//DESTRUCTOR
	virtual ~Stack();
	//MISC
	void push(T stackFrame);
	T pop();
	bool isEmpty() const;
};


template <class T>
Stack<T>::Stack() : top(nullptr) {}

template <class T>
Stack<T>::Stack(const Stack<T>& aStack){
	if(aStack.isEmpty())
		top = nullptr;
	else
	{
		Node<T> *temp = aStack.top;//temp moves
		//through the nodes from top to bottom of aStack.
		Node<T> *end;//Points to end of the new stack.
		
		end = new Node<T>(temp->getData( ), nullptr);
		top = end;
		//First node created and filled with data.
		//New nodes are now added AFTER this first node.
		
		temp = temp->getLink( );//move temp to second node
		//or nullptr if there is no second node.
		while (temp != nullptr)
		{
			end->setLink(new Node<T>(temp->getData( ), nullptr));
			temp = temp->getLink( );
			end = end->getLink( );
		}
		//end->link == nullptr;
	}
}

template<class T>
Stack<T>& Stack<T>::operator =(const Stack<T>& rightSide)
{
	if (top == rightSide.top) //if two stacks are the same
		return *this;
	else //send left side back to freestore
	{
		T next;
		while (! isEmpty( ))
			next = pop( );//remove calls delete.
	}
	
	if (rightSide.isEmpty())
	{
		top = nullptr;
		return *this;
	}
	else
	{
		Node<T> *temp = rightSide.top;//temp moves
		//through the nodes from front top to bottom of rightSide.
		
		Node<T> *end;//Points to end of the left side stack.
		end = new Node<T>(temp->getData( ), nullptr);
		top = end;;
		//First node created and filled with data.
		//New nodes are now added AFTER this first node.
		
		temp = temp->getLink();//Move temp to second node
		//or set to nullptr if there is no second node.
		
		while (temp != nullptr)
		{
			end->setLink(new Node<T>(temp->getData(), nullptr));
			temp = temp->getLink();
			end = end->getLink();
		}
		//back->link == nullptr;
		
		return *this;
	}
}



template<class T>
Stack<T>::~Stack( )
{
	T next;
	while (! isEmpty( ))
		next = pop( );//pop calls delete.
}


template<class T>
bool Stack<T>::isEmpty( ) const
{
	return (top == nullptr);
}

template<class T>
void Stack<T>::push(T stackFrame)
{
	top = new Node<T>(stackFrame, top);
}



template<class T>
T Stack<T>::pop( )
{
	if (isEmpty( ))
	{
		cout << "Error: popping an empty stack.\n";
		exit(1);
	}
	
	T result = top->getData( );
	
	Node<T> *discard;
	discard = top;
	top = top->getLink( );
	
	delete discard;
	
	return result;
}


#endif /* stack_h */

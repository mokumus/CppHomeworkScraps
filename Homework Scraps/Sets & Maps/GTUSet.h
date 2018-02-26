#ifndef GTUSet_h
#define GTUSet_h
#include<iostream>
#include<string>
#include "GTULinkedListTools.h"

using namespace std;
using tools::Node;
using tools::search;
using tools::headInsert;
using tools::deleteNode;
using tools::deleteFirstNode;
using tools::GTUIterator;


class GTUSet{
public:
	typedef GTUIterator<string> Iterator;
	
	
	GTUSet() : head(nullptr){};
	//GTUSet(GTUSet aSet);
	virtual ~GTUSet();
	
	
	bool contains(string target) const;
	
	void add(string item);
	void output();
	
	
	int count (const string& wanted) const;
	size_t max_size() const{return 10*size();};
	size_t size() const;
	void clear();
	void erase(const string& data);
	
	
	
	GTUSet* setUnion(const GTUSet& otherSet);
	shared_ptr<GTUSet> setIntersection(const GTUSet& otherSet);
	
	
	Iterator find (const string& data) const;
	Iterator begin() const{return Iterator(head);}
	Iterator end() const{return Iterator();}
	
private:
	Node<string>* head;
};

GTUSet::~GTUSet(){
	Node<string> *toDelete = head;
	while(head != nullptr){
		head = head->getLink();
		delete toDelete;
		toDelete = head;
	}
}

bool GTUSet::contains(string target) const{
	Node<string>* result = search(head,target);
	if(result == nullptr)
		return false;
	else
		return true;
}

void GTUSet::output(){
	Node<string>* iterator = head;
	while(iterator != nullptr){
		cout << iterator->getData() << " ";
		iterator = iterator->getLink();
	}
	cout << endl;
}

void GTUSet::add(string item){
	if(search(head, item) == nullptr)
		headInsert(head, item);
	else
		throw 1;
	
}

void GTUSet::clear(){
	GTUSet::Iterator i;
	for(i = this->begin(); i != this->end(); i++){
		if(i != nullptr){
			output();
			deleteFirstNode(head);
		}
	}
}

void GTUSet::erase(const string& data){
	auto temp = seekAndDestroy(head,data);
	
	
	if(head->getData() == data)
		deleteFirstNode(head);
	
	else if(temp != nullptr)
		deleteNode(temp);
	
	else
		cout << "Not found" << endl;
}


GTUIterator<string> GTUSet::find(const string& data) const{
	return search(head,data);
}

size_t GTUSet::size() const{
	auto size = sizeof(string&);
	for(auto i = this->begin(); i != this->end(); ++i)
		size++;
	
	return size;
}

int GTUSet::count (const string& wanted) const{
	int matches = 0;
	
	for(auto i = this->begin(); i != this->end(); i++){
	
		if(i->getData() == wanted){
			
			cout << "Found >> " << wanted << endl;
			matches++;
		}
		
	}
	return matches;
	
}

GTUSet* GTUSet::setUnion(const GTUSet& otherSet){
	GTUSet *unionSet = new GTUSet();
	Node<string> *iterator = head;
	while(iterator != nullptr){
		unionSet->add(iterator->getData());
		iterator = iterator->getLink();
	}
	iterator = otherSet.head;
	while(iterator != nullptr){
		unionSet->add(iterator->getData());
		iterator = iterator->getLink();
	}
	return unionSet;
}

shared_ptr<GTUSet> GTUSet::setIntersection(const GTUSet& otherSet){
	shared_ptr<GTUSet> interSet = shared_ptr<GTUSet>(new GTUSet());
	Node<string> *iterator = head;
	
	while(iterator != nullptr){
		if(otherSet.contains(iterator->getData()))
		   interSet->add(iterator->getData());
	
		iterator = iterator->getLink();
	}
	return interSet;
}


#endif /* GTUSet_h */

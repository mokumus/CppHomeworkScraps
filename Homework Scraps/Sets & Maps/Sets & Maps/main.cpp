#include <iostream>
#include "GTUSet.h"

shared_ptr<GTUSet> setIntersection(const GTUSet& first, const GTUSet& second){
	shared_ptr<GTUSet> interSet = shared_ptr<GTUSet>(new GTUSet());
	for(auto i = first.begin(); i != first.end(); i++){
		if(second.contains(i->getData()))
		   interSet->add(i->getData());
	}
	return interSet;
}



using namespace std;
int main(int argc, const char * argv[]) {
	GTUSet round;
	GTUSet green;
	
	green.add("money");
	green.add("aliens");
	green.add("leaves");
	green.add("grass");


	
	
	round.add("coins");
	round.add("aliens");
	round.add("leaves");
	round.add("butts");
	

	auto inter = setIntersection(round,green);
	
	inter->output();
	
    return 0;
}

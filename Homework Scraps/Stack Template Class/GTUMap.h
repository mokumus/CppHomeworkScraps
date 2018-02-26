#ifndef GTUMap_h
#define GTUMap_h
#include "GTUSet.h"
#include "GTULinkedListTools.h"
namespace GTUContainers{
	template <class K, class V>
	class GTUMap : public GTUSet<pair<K,V>>{
		
	public:
		GTUMap(K theFirst, V theSecond) : pair<K,V>(theFirst,theSecond) {}
		virtual ~GTUMap() {}
		
		K& getFirst() const {return get<0>(data);}
		V& getSecond() const {return get<1>(data);}
		
		
	
		

		
	private:
		pair<K, V> data;
	};
}


#endif /* GTUMap_h */

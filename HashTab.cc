#include <cmath>
#include "HashTab.h"

using std::cout;
using std::endl;

long HashTab::hashFunction(long key) {
	long position = hashFunction1(key);
	long count = 0;
	
	while(hashD[position].key != key) {
		if(!hashD[position].valid) return size;
		position += hashFunction2(key);
		position %= size;
		if(count++ > size) return size;
	}
	
	return position;
}

long HashTab::search(long key) {
	
	long position = hashFunction(key);
	
	if(position < size) {
		return hashD[position].data;
	}

	cout << "Have Not found " << key << endl;
	return 0;
}

bool HashTab::insert(long key, long data) {

	long position = hashFunction1(key);
	long count = 0;
		
	while(hashD[position].key != key && hashD[position].valid) {
		position += hashFunction2(key);
		position %= size;
		if(count++ > size) {
			cout << "Insert Error: Full" << endl;
			return false;
		}
	}

	hashD[position].key = key;
   	hashD[position].valid = true;
	hashD[position].data = data;
	return true;
}


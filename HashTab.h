#ifndef _HASHTAB_H
#define _HASHTAB_H

#include <iostream>
#include <cmath>

typedef struct HashData{
	long key;
	long data;
	bool valid;
} HashD;

class HashTab {

private:
	long size;
	long r;
	HashD *hashD;	
	long hashFunction(long key);
	long hashFunction1(long key);
	long hashFunction2(long key);

public:
	HashTab(long _r) :r(_r) {
		size = pow(2, r);
		hashD = new HashD[size];
	}

	~HashTab() {
		delete []hashD;
	}

	long search(long key);
	bool insert(long key, long data);
};

inline long HashTab::hashFunction1(long key) {
	static const long W = 32;
	static const long A = 0x9E3579B9;//2^32 * 0.61803398
	static const long F = 0x100000000;//2^32
	//cout << (key * A % (F) >> (W - r)) << endl;;
	return key * A % (F) >> (W - r);
}

inline long HashTab::hashFunction2(long key) {
	return 1;	
}

#endif

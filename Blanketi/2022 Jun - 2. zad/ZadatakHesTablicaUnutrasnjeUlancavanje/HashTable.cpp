 #include"HashTable.h"

unsigned int HashTable::h(char* key)
{
	return g(f(key));
}

unsigned int HashTable::f(char* key)
{
	//TODO:Implementirati funkciju koja prevodi char u unsigned int
	/*AAFFFKKTTBBB  
	AA - zadnje dve cifre godine akreditacije predmeta,
	FFF - slovna oznaka fakulteta,
	KK - slovna oznaka katedre koja drzi predmet,
	TT - slovna tipa predmeta,
	BBB - brojcana oznaka predmeta.*/
	//za racunanje hash-a -> KKTTBBB

	unsigned int hash = 0;
	for (int i = 4; i < strlen(key); i++)
		hash += key[i];
	return hash;
}

unsigned int HashTable::g(unsigned int key)
{
	//TODO:Implementirati funkciju koja prevodi unsigned int u [0...M-1]
	return key % m;
}


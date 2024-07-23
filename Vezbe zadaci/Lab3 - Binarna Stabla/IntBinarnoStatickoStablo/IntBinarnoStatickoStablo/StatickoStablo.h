#pragma once
#include<iostream>
using namespace std;
class StatickoStablo
{
private:
	int** cvorovi;
	int m;//maksimalni broj cvorova
	int t;//trenutni broj cvorova
public:
	StatickoStablo(int brojNivoa);
	~StatickoStablo();
	void ubaci(int);
	void preorder() { preorder(0); cout << endl; }
	void preorder(int);
	void inorder() { inorder(0); cout << endl; }
	void inorder(int);
	void postorder() { postorder(0); cout << endl; }
	void postorder(int);

	int distinct() { return distinct(0); }//2. zadatak
	int distinct(int);
	void insertDistinct(int, int*, int&);
	int visina() { return visina(0); };//4. zadatak
	int visina(int);
	int max(int, int);
	int moment() { return moment(0); }//6. zadatak
	int moment(int);
	int tezina() { return tezina(0); }//8. zadatak
	int tezina(int);
	void brisanjeListova() { brisanjeListova(0); }//10.zadatak
	void brisanjeListova(int);
	void mirrorKopija();//12.zadatak
	void dupliraj(StatickoStablo* result) { return dupliraj(0, result); }
	void dupliraj(int, StatickoStablo*);
	void spajanjeStabala(StatickoStablo&);//14. zadatak
	int nivoSaNajviseCvorova();//16.zadatak
};

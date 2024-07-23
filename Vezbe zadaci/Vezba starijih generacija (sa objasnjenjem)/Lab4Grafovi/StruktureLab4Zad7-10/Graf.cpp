#include"Graf.h"

Graf::Graf()
{
	matSusedstva = NULL;
	brEl = 0;
}
Graf::Graf(int n)
{
	//inicijalizovali smo matricu i niz
	maxDim = n;
	brEl = 0;
	matSusedstva = new int*[n];
	nizCvorova = new int[n];
	for (int i = 0;i < n;i++)
	{	
		matSusedstva[i] = new int[n];
     	nizCvorova[i] = 0;
    }
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			matSusedstva[i][j] = 0;
		}
	}
}
void Graf::dodajCvor(int p)
{
	nizCvorova[brEl] = p;
	brEl++;
}
void Graf::dodajVezu(int p, int k)
{
	int i = nadjiCvor(p);
	int j = nadjiCvor(k);
	if(i!=-1 && j!=-1)//vidi nadjiCvor();
	     matSusedstva[i][j] = 1;
}
int Graf::nadjiCvor(int p)
{
	for (int i = 0;i < brEl;i++)
		if (nizCvorova[i] == p)
			return i;
		
	return -1;//-1 je samo oznaka da nije naso indeks
	//jer ako stavim da vrati NULL, a gore u fji dodajVezu()
	//smestim to NULL u i, j, on ce u i, j da stavi broj 0 umesto NULL
	//pa zato nece da upise prvu vrstu i prvu kolonu zbog
	//uslova if(i!=0 && j!=0)
}
void Graf::stampajGraf()
{
	cout << "Cvorovi: ";
	for (int i = 0;i < brEl;i++)
		cout << nizCvorova[i] << " ";
	
	cout <<endl<< "Matrica susedstva: " << endl;
	for (int i = 0;i < brEl;i++)
	{
		for (int j = 0;j < brEl;j++)
		{
			cout << matSusedstva[i][j] << " ";

		}
 	  cout << endl;
     }
}
void Graf::maxIzlazni() //trazim poklapanja po vrstama
{
	int max = 0,povratnik;
	int brojac;
	for (int i = 0;i < brEl;i++)
	{
		brojac = 0;
		for (int j = 0;j < brEl;j++)
		{
			if (matSusedstva[i][j] == 1)
				brojac++;
		}
		if (max < brojac)
		{
			max = brojac;
			povratnik = nizCvorova[i];
		}
	}
	cout << "Cvor sa najvecim izlaznim stepenom je: " << povratnik << "."<<endl;
	cout << "Njegov izlazni stepen je: " << max << "."<< endl;
}
void Graf::maxUlazni()  //trazim poklapanja po kolonama
{
	int max = 0, povratnik;
	int brojac;
	for (int j = 0;j < brEl;j++)
	{
		brojac = 0;
		for (int i = 0;i < brEl;i++)
		{
			if (matSusedstva[i][j] == 1)
				brojac++;
		}
		if (max < brojac)
		{
			max = brojac;
			povratnik = nizCvorova[j];
		}
	}
	cout << "Cvor sa najvecim ulazni stepenom je: " << povratnik << "." << endl;
	cout << "Njegov ulazni stepen je: " << max << "." << endl;
}

void Graf::nulaIzlazni()
{
	int* povratnik = new int[brEl];
	int brojac;
	int indeks = 0;
	for (int i = 0;i < brEl;i++)
	{
		brojac = 0;
		for (int j = 0;j < brEl;j++)
		{
			if (matSusedstva[i][j] == 1)
				brojac++;
		}
		if (!brojac)
		{
			povratnik[indeks] = nizCvorova[i];
			indeks++;
		}
	}
	cout << "Cvor sa izlaznim stepenom 0 je: " << endl;
	for (int i = 0;i < indeks;i++)
	{
		cout << povratnik[i] << " ";
	}
	cout << endl;
	delete[] povratnik;
}
void Graf::nulaUlazni()
{
	int* povratnik = new int[brEl];
	int brojac;
	int indeks = 0;
	for (int j = 0;j < brEl;j++)
	{
		brojac = 0;
		for (int i = 0;i < brEl;i++)
		{
			if (matSusedstva[i][j] == 1)
				brojac++;
		}
		if (!brojac)
		{
			povratnik[indeks] = nizCvorova[j];
			indeks++;
		}
	}
	cout << "Cvor sa ulaznim stepenom 0 je: " << endl;
	for (int i = 0;i < indeks;i++)
	{
		cout << povratnik[i] << " ";
	}
	cout << endl; 
	delete[] povratnik;
}

bool Graf::isStronglyConnected()
{
	int br = 0;
	for (int i = 0; i < maxDim; i++)
	{
		for (int j = 0; i < maxDim; i++)
		{
			if (matSusedstva[i][j] == 1 && matSusedstva[i][j] == matSusedstva[j][i])
				br++;
		}
	}
	if (br == brEl*brEl)
		return true;
	return false;
	
}
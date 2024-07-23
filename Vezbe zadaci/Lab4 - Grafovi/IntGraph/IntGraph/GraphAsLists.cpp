#include "GraphAsLists.h"
#include "Edge.h"
#include "LinkedNode.h"
#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"
#include <iostream>
#include <queue> // For priority_queue
#include <vector> //za vektor
#include <functional> //za vece (min-heap comparator)

using namespace std;

struct LinkedNodeComparator //potrebno za priority queue za Dijkstru
{
	bool operator()(const LinkedNode* a, const LinkedNode* b) const
	{
		return a->distance > b->distance; // '>' operator za min-heap
	}
};

GraphAsLists::GraphAsLists()
{
	start = NULL;
	nodeNum = 0;
}
GraphAsLists::~GraphAsLists()
{

}

void GraphAsLists::insertNode(int pod)
{
	LinkedNode* newNode = new LinkedNode(pod, NULL, start);
	start = newNode;
	nodeNum++;
}
bool GraphAsLists::insertEdge(int a, int b, double w)
{
	LinkedNode* pa = findNode(a);
	LinkedNode* pb = findNode(b);
	if (pa == NULL || pb == NULL)
		return false;
	Edge* newEdge = new Edge(pb, pa->adj, w);
	if (newEdge == NULL)
		return false;
	pa->adj = newEdge;
	return true;
}

LinkedNode* GraphAsLists::findNode(int pod)
{
	LinkedNode* curr = start;
	while (curr != NULL && curr->node != pod)
	{
		curr = curr->next;
	}
	return curr;
}

Edge* GraphAsLists::findEdge(int a, int b)
{
	LinkedNode* pa = findNode(a);
	LinkedNode* pb = findNode(b);
	if (pa == NULL || pb == NULL)
		return NULL;
	Edge* curr = pa->adj;
	while (curr != NULL && curr->dest != pb)
		curr = curr->link;
	return curr;
}

bool GraphAsLists::deleteNode(int pod)
{

	return false;
}

bool GraphAsLists::deleteEdge(int a, int b)
{
	Edge* edge = findEdge(a, b);
	LinkedNode* node = findNode(a);
	if (node->adj == edge) //granicni slucaj
	{
		node->adj = edge->link;
		delete edge;
		return true;
	}
	Edge* prevEdge = node->adj;
	while (prevEdge->link != edge)
		prevEdge = prevEdge->link;
	prevEdge->link = edge->link;
	delete edge;
	return true;
}

void GraphAsLists::print()
{
	LinkedNode* ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->node << "->";
		Edge* pa = ptr->adj;
		while (pa != NULL)
		{
			cout << pa->dest->node << "|";
			pa = pa->link;
		}
		cout << "\n";//endl;
		ptr = ptr->next;
	}
	cout << endl;
}

void GraphAsLists::SetStatusForAllNodes(int status)
{
	if (start == NULL)
		return;
	LinkedNode* curr = start;
	while (curr != NULL)
	{
		curr->status = status;
		curr = curr->next;
	}
}

long GraphAsLists::breadthFirstTraversal(int data)
{
	long count = 0;

	LinkedNode* node = findNode(data);
	SetStatusForAllNodes(1); // 1 - neobradjen
	QueueAsArrayLinkedNodeInt queue(nodeNum);
	queue.enqueue(node);
	node->status = 2; // 2 - smesten
	while (!queue.isEmpty())
	{
		LinkedNode* ptr = queue.dequeue();
		ptr->status = 3; // 3 - obradjen
		ptr->visit();
		count++;
		Edge* edge = ptr->adj;
		while (edge != NULL)
		{
			if (edge->dest->status == 1)
			{
				queue.enqueue(edge->dest);
				edge->dest->status = 2;
			}
			edge = edge->link;
		}
	}
	cout << endl;
	return count;
}

long GraphAsLists::depthFirstTraversalIterative(int data)
{
	long count = 0;

	SetStatusForAllNodes(1); // 1 - neobradjen
	LinkedNode* node = findNode(data);
	StackAsArrayLinkedNodeInt stack(nodeNum);
	stack.push(node);
	node->status = 2; // 2 - smesten
	while (!stack.isEmpty())
	{
		LinkedNode* ptr = stack.pop();
		ptr->visit();
		ptr->status = 3; // 3 - obradjen
		count++;
		Edge* edge = ptr->adj;
		while (edge != NULL)
		{
			if (edge->dest->status == 1)
			{
				stack.push(edge->dest);
				edge->dest->status = 2;
			}
			edge = edge->link;
		}
	}
	cout << endl;
	return count;
}

long GraphAsLists::dfs(int first)
{
	LinkedNode* pFirst = nullptr;
	LinkedNode* ptr = start;
	while (ptr != nullptr)
	{
		ptr->status = 0;
		if (ptr->node == first)
			pFirst = ptr;

		ptr = ptr->next;
	}
	if (pFirst == nullptr)
		return 0;

	return dfs(pFirst);
}
long GraphAsLists::dfs(LinkedNode* ptr)
{
	long count = 0;
	if (ptr->status != 1)
	{
		ptr->status = 1;
		ptr->visit();
		count++;
		Edge* edge = ptr->adj;
		while (edge != nullptr)
		{
			count += dfs(edge->dest);
			edge = edge->link;
		}
	}

	return count;
}

long GraphAsLists::topologicalOrderTravrsal()
{
	long count = 0;
	SetStatusForAllNodes(0);
	//odredjivanje ulaznog stepena za svaki cvor
	LinkedNode* curr = start;
	while (curr != NULL)
	{
		Edge* edge = curr->adj;
		while (edge != NULL)
		{
			edge->dest->status++;
			edge = edge->link;
		}
		curr = curr->next;
	}

	QueueAsArrayLinkedNodeInt queue(nodeNum);
	curr = start;
	while (curr != NULL)
	{
		if (curr->status == 0)
			queue.enqueue(curr);
		curr = curr->next;
	}

	while (!queue.isEmpty())
	{
		curr = queue.dequeue();
		curr->visit();
		count++;
		Edge* edge = curr->adj;
		while (edge != NULL)
		{
			edge->dest->status--;
			if (edge->dest->status == 0)
				queue.enqueue(edge->dest);
			edge = edge->link;
		}
	}
	cout << endl;
	return count;
}

// ---------------------------------------------------------------------------
// -------------------------- priprema za lab vezbu --------------------------
// ---------------------------------------------------------------------------
long GraphAsLists::findPath(int first, int last, int* arPath, int* lPath)
{
	LinkedNode* pFirst = nullptr, * pLast = nullptr;
	LinkedNode* ptr = start;
	while (ptr != nullptr)
	{
		ptr->status = 0;

		if (ptr->node == first)
			pFirst = ptr;
		if (ptr->node == last)
			pLast = ptr;

		ptr = ptr->next;
	}

	if (pFirst == nullptr || pLast == nullptr)
		return 0;
	return findPath(pFirst, pLast, arPath, lPath);
}
long GraphAsLists::findPath(LinkedNode* ptr, LinkedNode* pEnd, int* arPath, int* lPath)
{
	if (ptr->node == pEnd->node)
	{
		if (arPath != nullptr)
			arPath[(*lPath)++] = ptr->node;
		return 1;
	}

	long count = 0;
	if (ptr->status != 1)
	{
		ptr->status = 1;
		count++;
		Edge* edge = ptr->adj;
		while (lPath != nullptr && *lPath == 0 && edge != nullptr)
		{
			count += findPath(edge->dest, pEnd, arPath, lPath);
			edge = edge->link;
		}
		if (lPath != nullptr && *lPath != 0 && arPath != nullptr)
			arPath[(*lPath)++] = ptr->node;
	}

	return count;
}

//detekcija ciklusa - topolosko (za orjentisane grafove), bfs (radi samo za neorjentisane), dfs (mora rekurzivno)
bool GraphAsLists::isCycleTopological()
{
	//za orjentisane grafove
	//obilazi se graf topoloski, ukoliko se ne obidju svi cvorovi znaci da postoji ciklus

	int count = 0;
	SetStatusForAllNodes(0);
	//odredjuje se ulazni stepen svih cvorova
	LinkedNode* ptr = start;
	while (ptr != nullptr)
	{
		Edge* edge = ptr->adj;
		while (edge != nullptr)
		{
			edge->dest->status++;
			edge = edge->link;
		}
		ptr = ptr->next;
	}

	//svi cvorovi sta ulaznim stepenom 0 se smestaju u red
	QueueAsArrayLinkedNodeInt queue(nodeNum);
	ptr = start;
	while (ptr != nullptr)
	{
		if (ptr->status == 0)
			queue.enqueue(ptr);
		ptr = ptr->next;
	}

	while (!queue.isEmpty())
	{
		ptr = queue.dequeue();
		count++;
		Edge* edge = ptr->adj;
		while (edge != nullptr)
		{
			edge->dest->status--;
			if (edge->dest->status == 0)
				queue.enqueue(edge->dest);

			edge = edge->link;
		}
	}

	return nodeNum != count; //count i broj cvorova moraju biti isti sto znaci da
							 //su se svi cvorovi obisli, ako nisu onda postoji ciklus
}

bool GraphAsLists::isCycleBfs()
{
	//RADI SAMO ZA NEORJENTISANE GRAFOVE
	//proverava da li graf sadrzi ciklus
	//klasican bfs samo ukoliko prilikom posecivanja suseda
	//taj sused se vec nalazi u redu to znaci da graf sadrzi ciklus

	LinkedNode* ptr = start;
	while (ptr != nullptr)
	{
		ptr->status = -1; //neobradjen
		ptr = ptr->next;
	}

	QueueAsArrayLinkedNodeInt queue(nodeNum);
	ptr = start;
	if (ptr != nullptr)
	{
		queue.enqueue(ptr);
		ptr->status = 0; //smesten
		while (!queue.isEmpty())
		{
			ptr = queue.dequeue();
			ptr->status = 1;//obradjen
			Edge* edge = ptr->adj;
			while (edge != nullptr)
			{
				if (edge->dest->status == 0) //uslov za detekciju ciklusa u grafu
					return true;
				else if (edge->dest->status == -1)
				{
					queue.enqueue(edge->dest);
					edge->dest->status = 0;
				}

				edge = edge->link;
			}
		}
	}

	return false;
}
bool GraphAsLists::isCycleDfs()
{
	//mora rekurzivno da obilazi ne moze sa stack-om
	LinkedNode* ptr = start;
	while (ptr != nullptr)
	{
		ptr->status = -1; //neobradjen
		ptr = ptr->next;
	}

	ptr = start;
	while (ptr != nullptr)
	{
		if (ptr->status == -1) //ako nije obradjen
		{
			if (isCycleDfs(ptr))
				return true;

		}
		ptr = ptr->next;
	}

	return false;
}
bool GraphAsLists::isCycleDfs(LinkedNode* ptr)
{
	ptr->status = 0;

	Edge* edge = ptr->adj;
	while (edge != nullptr)
	{
		if (edge->dest->status == 0) //detektovan ciklus
			return true;
		else if (edge->dest->status == -1 && isCycleDfs(edge->dest)) //ako nije obradjen i ako nije u ciklusu
			return true;

		edge = edge->link;
	}

	ptr->status = 1; //obradjen
	return false;
}

//prikaz jednog ciklusa - ne radi kako treba :D
bool GraphAsLists::printCycle() // ne stampa lepo :D
{
	//isto trazenje ciklusa sa dfs samo kada detektujemo ciklus upisujemo cvorove u nis i posle ih stampamo
	SetStatusForAllNodes(-1);

	LinkedNode* ptr = start;
	while (ptr != nullptr)
	{
		if (ptr->status == -1)
		{
			vector<LinkedNode*> cycle; //niz koji pamti cvorove koji su u ciklusu
			if (printCycle(ptr, cycle))
			{
				for (LinkedNode* node : cycle)
				{
					node->visit();
				}
				cout << endl;
				return true;
			}
		}

		ptr = ptr->next;
	}
	return false;
} 
bool GraphAsLists::printCycle(LinkedNode* ptr, vector<LinkedNode*>& cycle)
{
	ptr->status = 0;

	Edge* edge = ptr->adj;
	while (edge != nullptr)
	{
		if (edge->dest->status == 0) //detektovan ciklus
		{
			cycle.push_back(edge->dest);
			cycle.push_back(ptr);
			return true;
		}
		else if (edge->dest->status == -1 && printCycle(edge->dest, cycle))
		{
			cycle.push_back(ptr);
			return true;
		}

		edge = edge->link;
	}

	ptr->status = 1;
	return false;
}


//najkraci put Dijkstra
long GraphAsLists::shortestPathDijkstra(int data)
{
	long count = 0;
	LinkedNode* curr = start, *ptr = nullptr;
	while (curr != NULL)
	{
		curr->status = 1; //neobradjen
		curr->prev = NULL;
		curr->distance = numeric_limits<double>::max(); //postavlja max vrednost za double jer tako kaze algoritam
		if (curr->node == data)
			ptr = curr;
		curr = curr->next;
	}

	if (ptr == nullptr)
		return 0;

	//pravi se priority queue koji je organizovan kao min heap jer u algoritmu
	//se stalno trazi cvor sa najmanjim distance-om, pa zbog efikasnosti algoritma
	//koristi se min heap za brzo pristupanje prvom elementu (koji je uvak najmanji) O(1)
	//na kolokvijumu nam najverovatnije ne daju min heap strukturu pa moze da se 
	//koristi ona iz c++ standard library
	//ako 2013 vs ne podrzava ovo usrali smo motku
	priority_queue<LinkedNode*, vector<LinkedNode*>, LinkedNodeComparator> pq;

	ptr->distance = 0; //pocetni cvor je duzine 0 logicno
	pq.push(ptr);
	ptr->status = 2; //posecen
	while (!pq.empty())
	{
		ptr = pq.top(); //u min-heap-u prvi element je najmanji
		pq.pop(); //pop samo brise prvi element pa zato mora top pa pop, glupost
		ptr->status = 3; //obradjen
		count++;

		Edge* edge = ptr->adj;
		while (edge != NULL)
		{
			if (edge->dest->status == 1) //prvi slucaj je da sledeci cvor nije obradjen
										 //pa samo treba izracunati njego distance, distance = distance trenutnog cvora + weight
			{
				edge->dest->distance = ptr->distance + edge->weight;
				edge->dest->status = 2;
				edge->dest->prev = ptr;
				pq.push(edge->dest);
			}
			else if (edge->dest->status == 2) //drugi slucaj je da je posecen cvor i da mu je distance izracnunat
											 //ako mu je novi distance manji postaviti taj novi distance i update prev pokazivac
			{
				if (edge->dest->distance > ptr->distance + edge->weight)
				{
					double newDistance = ptr->distance + edge->weight;
					edge->dest->prev = ptr;
					edge->dest->distance = newDistance; //nema potrebe menjati distance cvora u pq jer se sve radi sa pokazivacima

					// Rebuild the priority queue, jer se mozda redosled izgubio prilikom menjanja distance-a
					// nije efikasno jer heap bi trebao da ima funkciju da se sam sortira sto je mnogo efikasnije
					// od ponovnog gradjenja celog min-heap-a
					vector<LinkedNode*> nodes;
					while (!pq.empty()) {
						nodes.push_back(pq.top());
						pq.pop();
					}

					for (LinkedNode* node : nodes) {
						pq.push(node);
					}
					
				}//treci slucaj kada je distace manji onda se nista ne radi
				//cetvrti slucaj kada je cvor obradjen onda se isto nista ne radi
			}

			edge = edge->link;
		}
	}

	//Dijkstra nadje najkrace puteve za sve cvorove od prosledjenog cvora
	//ako ti treba sad neki cvor nadjes ga i ides kroz njegov prev i naso si najkraci put do pocetnog cvora ez

	return count;
	//sve u svemu bilo bi bolje kad bi na kol dali minHeap strukturu jer bi onda sadrzala f-ju za sortiranje
	//i laksa je za koriscenje
	//ili umesto da se jebavas stavi sve u niz pa min element trazi rucno :D
}

//najkraci put izmedju 2 cvora (pada se dosta na ispitu)
long GraphAsLists::shortestPath(int a, int b)
{
	//isto dijkstra samo taj put prikazujemo na kraju i kada pronadjemo cvor do koga se trazi putanja njegove susede ne obradjujemo
	//ako graf nije tezinski onda se distance izracunava distance = distance prethodnog + 1 (1 umesto weight grane)
	//ako nije tezinski graf mislim i da ne mora sa priority queue da se radi moze sa obicnim redom

	long count = 0;
	LinkedNode* curr = start, * ptr = nullptr, * end = nullptr;
	while (curr != nullptr)
	{
		curr->status = 1; //neobradjen
		curr->prev = nullptr;
		curr->distance = numeric_limits<double>::max();
		if (curr->node == a)
			ptr = curr;
		if (curr->node == b)
			end = curr;

		curr = curr->next;
	}

	if (ptr == nullptr || end == nullptr)
		return 0;

	priority_queue<LinkedNode*, vector<LinkedNode*>, LinkedNodeComparator> pq;
	ptr->distance = 0;
	pq.push(ptr);
	ptr->status = 2; //posecen

	while (!pq.empty())
	{
		ptr = pq.top(); //uzima se cvor sa najmanjom duzinom -> O(1)
		pq.pop();
		ptr->status = 3; //obradjen
		count++;
		Edge* edge = ptr->adj;
		if (ptr != end) //ne obradjujemo susede cvora koji se trazi kao kraj putanje
		{
			while (edge != nullptr)
			{
				if (edge->dest->status == 1) //ako nije obradjen
				{
					edge->dest->distance = ptr->distance + 1;
					edge->dest->prev = ptr;
					edge->dest->status = 2;
					pq.push(edge->dest);
				}
				else if (edge->dest->status == 2) //ako je posecen/smesten u pq
				{
					if (edge->dest->distance > ptr->distance + 1) //ako je nov put do tog cvora kraci
					{
						edge->dest->distance = ptr->distance + 1;
						edge->dest->prev = ptr;
						//sada treba priority queue da se uredi jer se promenio atribut na osnovu koga se sortira
						//trebala bi funkcija da postoji za to ali posto nema 
						//brisemo stari pq i pravimo novi i on ce sam da se sortira (nije efikasno)
						vector<LinkedNode*> nodes;
						while (!pq.empty())
						{
							nodes.push_back(pq.top());
							pq.pop();
						}
						for (LinkedNode* node : nodes)
							pq.push(node);
					}
				}

				edge = edge->link;
			}
		}
	}

	//stack se koristi da bi prikazao od pocetnog cvora putanju a ne od krajnjeg
	ptr = end;
	StackAsArrayLinkedNodeInt stack(nodeNum);
	while (ptr != nullptr)
	{
		stack.push(ptr);
		ptr = ptr->prev;
	}
	while (!stack.isEmpty())
	{
		ptr = stack.pop();
		ptr->visit();
	}
	cout << endl;

	return count;
}

//1. zad
LinkedNode* GraphAsLists::maxInDeg()
{
	SetStatusForAllNodes(0);
	//odredjivanje ulaznog stepena za svaki cvor
	LinkedNode* curr = start;
	while (curr != NULL)
	{
		Edge* edge = curr->adj;
		while (edge != NULL)
		{
			edge->dest->status++;
			edge = edge->link;
		}
		curr = curr->next;
	}

	LinkedNode* maxNode = start;
	curr = start;
	while (curr != NULL)
	{
		if (curr->status > maxNode->status)
			maxNode = curr;
		curr = curr->next;
	}
	
	if (maxNode->status > 0)
	{
		cout << "Cvor sa maksimalnim brojem ulaznih cvorova je: " << maxNode->node << "." << endl;
		cout << "Ulazni stepen je: " << maxNode->status << "." << endl;
		return maxNode;
	}
	else
	{
		cout << "Ni jedan cvor nema ulaznih potega." << endl;
		return nullptr;
	}
}
LinkedNode* GraphAsLists::maxInDeg2()
{
	LinkedNode* trazeni = start;
	LinkedNode* maxNode = NULL;
	int maxUlazni = 0;
	while (trazeni != NULL)
	{
		LinkedNode* ptr = start;
		int countUlaznih = 0;
		while (ptr != NULL)
		{
			Edge* edge = ptr->adj;
			while (edge != NULL)
			{
				if (edge->dest == trazeni)
					countUlaznih++;

				edge = edge->link;
			}
			ptr = ptr->next;
		}
		if (countUlaznih > maxUlazni)
		{
			maxNode = trazeni;
			maxUlazni = countUlaznih;
		}
		trazeni = trazeni->next;
	}

	if (maxNode != NULL)
	{
		cout << "Cvor sa maksimalnim brojem ulaznih cvorova je: " << maxNode->node << "." << endl;
		cout << "Ulazni stepen je: " << maxUlazni << "." << endl;
	}
	else
		cout << "Ni jedan cvor nema ulaznih potega." << endl;

	return maxNode;
}

//2. zad
LinkedNode* GraphAsLists::maxOutDeg()
{
	SetStatusForAllNodes(0);

	//odredjivanje izlaznog stepena za svaki cvor
	LinkedNode* curr = start;
	while (curr != NULL)
	{
		Edge* edge = curr->adj;
		while (edge != NULL)
		{
			curr->status++;
			edge = edge->link;
		}
		curr = curr->next;
	}

	LinkedNode* maxNode = start;
	curr = start;
	while (curr != NULL)
	{
		if (curr->status > maxNode->status)
			maxNode = curr;
		curr = curr->next;
	}

	if (maxNode->status > 0)
	{
		cout << "Cvor sa maksimalnim brojem izlaznih cvorova je: " << maxNode->node << "." << endl;
		cout << "Izlazni stepen je: " << maxNode->status << "." << endl;
		return maxNode;
	}
	else
	{
		cout << "Ni jedan cvor nema izlaznih potega." << endl;
		return nullptr;
	}
}
LinkedNode* GraphAsLists::maxOutDeg2()
{
	LinkedNode* curr = start;
	LinkedNode* maxNode = NULL;
	int maxIzlazni = 0;
	while (curr != NULL)
	{
		int countIzlaznih = 0;
		Edge* edge = curr->adj;
		while (edge != NULL)
		{
			countIzlaznih++;
			edge = edge->link;
		}
		if (countIzlaznih > maxIzlazni)
		{
			maxIzlazni = countIzlaznih;
			maxNode = curr;
		}
		curr = curr->next;
	}

	if (maxNode != NULL)
	{
		cout << "Cvor sa maksimalnim brojem izlaznih cvorova je: " << maxNode->node << "." << endl;
		cout << "Izlazni stepen je: " << maxIzlazni << "." << endl;
	}
	else
		cout << "Ni jedan cvor nema izlaznih potega." << endl;

	return maxNode;
}

//3. zad
int GraphAsLists::countZeroIn()
{
	SetStatusForAllNodes(0);

	//odredjivanje ulaznog stepena za svaki cvor
	LinkedNode* curr = start;
	while (curr != NULL)
	{
		Edge* edge = curr->adj;
		while (edge != NULL)
		{
			edge->dest->status++;
			edge = edge->link;
		}
		curr = curr->next;
	}

	curr = start;
	int count = 0;
	while (curr != NULL)
	{
		if (curr->status == 0)
		{
			cout << "Cvor sa ulaznim stepenom 0: " << curr->node << endl;
			count++;
		}
		curr = curr->next;
	}

	return count;
}
int GraphAsLists::countZeroIn2()
{
	cout << "Cvorovi za 0 ulaznim stepenom: " << endl;
	LinkedNode* trazeni = start;
	int count = 0;
	while (trazeni != NULL)
	{
		int countUlaznih = 0;
		LinkedNode* ptr = start;
		while (ptr != NULL)
		{
			Edge* e = ptr->adj;
			while (e != NULL)
			{
				if (e->dest == trazeni)
					countUlaznih++;
				e = e->link;
			}
			ptr = ptr->next;
		}
		if (countUlaznih == 0)
		{
			count++;
			cout << trazeni->node << " ";
		}

		trazeni = trazeni->next;
	}
	cout << endl;
	return count;
}

//4. zad
int GraphAsLists::countZeroOut()
{
	SetStatusForAllNodes(0);

	//odredjivanje izlaznog stepena za svaki cvor
	LinkedNode* curr = start;
	while (curr != NULL)
	{
		Edge* edge = curr->adj;
		while (edge != NULL)
		{
			curr->status++;
			edge = edge->link;
		}
		curr = curr->next;
	}

	curr = start;
	int count = 0;
	while (curr != NULL)
	{
		if (curr->status == 0)
		{
			cout << "Cvor sa izlaznim stepenom 0: " << curr->node << endl;
			count++;
		}
		curr = curr->next;
	}

	return count;
}
int GraphAsLists::countZeroOut2()
{
	cout << "Cvorovi za 0 izlaznim stepenom: " << endl;
	int count = 0;
	LinkedNode* ptr = start;
	while (ptr != NULL)
	{
		if (ptr->adj == NULL)
		{
			cout << ptr->node << " ";
			count++;
		}
		ptr = ptr->next;
	}

	cout << endl;
	return count;
}

//5. zad
bool GraphAsLists::stronglyConnected()
{
	LinkedNode* ptr = start;
	while (ptr != NULL)
	{
		breadthFirstTraversal(ptr->node);
		LinkedNode* pom = start;
		while (pom != NULL)
		{
			if (pom->status == 1)
			{
				cout << "Graf nije jako povezan";
				return false;
			}
			pom = pom->next;
		}

		ptr = ptr->next;
	}
	cout << "Graf jeste jako povezan";
	return true;
}

//6. zad
int** GraphAsLists::adjescentMatrix()
{
	//dodeli indekse svim cvorovima
	int count = nodeNum - 1;
	LinkedNode* ptr = start;
	while (ptr != NULL)
	{
		ptr->status = count;
		count--;
		ptr = ptr->next;
	}

	int** mat = new int* [nodeNum];
	for (int i = 0; i < nodeNum; i++)
		mat[i] = new int[nodeNum];
	for (int i = 0; i < nodeNum; i++)
		for (int j = 0; j < nodeNum; j++)
		{
			mat[i][j] = 0;
		}

	ptr = start;
	while (ptr != NULL)
	{
		Edge* e = ptr->adj;
		while (e != NULL)
		{
			mat[ptr->status][e->dest->status] = 1;
			e = e->link;
		}

		ptr = ptr->next;
	}

	for (int i = 0; i < nodeNum; i++)
	{
		for (int j = 0; j < nodeNum; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}

	return mat;
}

// ----------------------------------------------------------------------------
// --------------------------------- blanketi ---------------------------------
// ----------------------------------------------------------------------------

//oktobar2 2022
bool GraphAsLists::pathExists(LinkedNode* a, LinkedNode* b, LinkedNode* c, LinkedNode* d)
{
	//proverava da li postoji put izmedju cvora a i b koj ukljucuje podeg izmedju cvorova c i d
	
	LinkedNode* curr = start, * ptr = a, * end = b;
	while (curr != NULL)
	{
		curr->status = 1;//neobradjen
		curr->prev = nullptr;
		curr = curr->next;
	}

	Edge* pot = c->adj;
	while (pot != NULL && pot->dest != d)
		pot = pot->link;

	if (pot == NULL || a == NULL || b == NULL || c == NULL || d == NULL)
		return false;

	QueueAsArrayLinkedNodeInt queue(nodeNum);
	bool endFound = false;
	bool edgeFound = false;
	if (ptr != nullptr)
	{
		queue.enqueue(ptr);
		ptr->status = 2; //smesten
		while (!queue.isEmpty())
		{
			ptr = queue.dequeue();
			if(ptr != end) //end cvor ne sme imati status obradjen
				ptr->status = 3; //obradjen
			Edge* edge = ptr->adj;
			if (ptr != end)
			{
				while (edge != nullptr)
				{
					if (edge->dest->status != 3) //ako nije smesten
					{
						queue.enqueue(edge->dest);
						edge->dest->prev = ptr;
						edge->dest->status = 2;
						if (edge->dest == end)
							endFound = true;
					}

					if (endFound)
					{
						curr = end;
						while (curr != nullptr)
						{
							if (curr->prev != nullptr)
							{
								Edge* pom = curr->prev->adj;
								while (pom != nullptr)
								{
									if (pom == pot && pom->dest == curr)
										edgeFound = true;
									pom = pom->link;
								}
							}

							curr = curr->prev;
						}

						if (edgeFound)
						{
							curr = end;
							while (curr != nullptr)
							{
								curr->visit();
								curr = curr->prev;
							}
							cout << endl;
							return true;
						}
					}

					endFound = false;
					edge = edge->link;
				}
			}
		}
	}

	return false;
}

//jun2 2022
int GraphAsLists::reachableInNHoops(LinkedNode* a, int n)
{
	//vraca broj cvorova do kojih je moguce doci za tacno n skokova (prolaska kroz potege)
	//koristimo pomocni atribut, ako nije to dozvoljeno onda jbg
	//dodatak: svaki put se prikazuje

	int count = 0;
	LinkedNode* ptr = start;
	while (ptr != nullptr)
	{
		ptr->status = 1; //neobradjen
		ptr->prev = nullptr;
		ptr->distance = 0; //pomocni atribut koji pamti broj skokova od pocetnog cvora
		
		ptr = ptr->next;
	}

	ptr = a;

	StackAsArrayLinkedNodeInt stack(nodeNum);
	if (ptr != nullptr)
	{
		stack.push(ptr);
		ptr->status = 2; //smesten
		while (!stack.isEmpty())
		{
			ptr = stack.pop();
			ptr->status = 3;//obradjen
			Edge* edge = ptr->adj;
			while (edge != nullptr)
			{
				if (ptr->distance == n - 1) //slucaj kada sledeci cvor mora da poveca counter
										    //moramo da povecamo counter, prikazemo taj put ali taj cvor da ne obradimo
										    //takodje susede tog cvora ne obradjujemo, tkd status tog cvora nam je nebitan
				{
					count++;
					edge->dest->prev = ptr;
					LinkedNode* curr = edge->dest;
					while (curr != NULL)
					{
						curr->visit();
						curr = curr->prev;
					}
					cout << endl;
				}
				else if (edge->dest->status == 1)
				{
					stack.push(edge->dest);
					edge->dest->status = 2;
					edge->dest->prev = ptr;
					edge->dest->distance = ptr->distance + 1;
				}

				edge = edge->link;
			}
		}
	}

	return count;
}

//septembar 2020
void GraphAsLists::makeUndirected()
{
	//pretvara graf u neorjentisan
	//dodaje samo neophodne cvorove

	LinkedNode* ptr = start;
	while (ptr != nullptr)
	{
		Edge* edge = ptr->adj;
		while (edge != nullptr)
		{
			//za svaki poteg u cvoru:
			//nalazi cvor na koga taj poteg pokazuje
			LinkedNode* ptr2 = start;
			while (ptr2 != nullptr && ptr2 != edge->dest)
				ptr2 = ptr2->next;

			//proverava da li taj poteg vec postoji
			Edge* edge2 = ptr2->adj;
			bool postojiPoteg = false;
			while (edge2 != nullptr)
			{
				if (edge2->dest == ptr)
				{
					postojiPoteg = true;
					break;
				}
				edge2 = edge2->link;
			}

			//dodaje poteg koji pokazuje nazad na pocetan cvor ako on vec ne postoji
			if (!postojiPoteg)
			{
				Edge* newEdge = new Edge(ptr, ptr2->adj);
				ptr2->adj = newEdge;
			}

			edge = edge->link;
		}

		ptr = ptr->next;
	}
}
bool GraphAsLists::isWeaklyConnected()
{
	//proverava da li je slabo povezan graf
	//bilo bi pozeljno da se radi sa pomocnim grafom da se trenutni ne bi modifikao al jbg

	makeUndirected();
	LinkedNode* ptr = start;
	while (ptr != nullptr)
	{
		breadthFirstTraversal(ptr->node);
		LinkedNode* pom = start;
		while (pom != nullptr)
		{
			if (pom->status == 1)
			{
				cout << "Graf nije slabo povezan";
				return false;
			}
			pom = pom->next;
		}
		ptr = ptr->next;
	}

	cout << "Graf jeste slabo povezan";
	return true;
}

//oktobar 2021
bool GraphAsLists::canReachMoreWithUndirected(LinkedNode* a)
{
	//proverava da li se moze vise cvorova obici od zadatog ako je graf neorjentisan
	int countDirected = breadthFirstTraversal(a->node);
	makeUndirected();
	int countUndirected = breadthFirstTraversal(a->node);

	return countUndirected > countDirected;
}
#include <iostream>     //cin cout
#include <stdio.h>      // printf fopen fclose fputs 
#include <stdlib.h>     //
#include <string>       //to_string
#include <vector>
#include <algorithm>    // std::sort

using namespace std;

bool yaEsta(int i, int j, vector<pair<pair<int, int>, int> > aristas) {
	int h = 0;
	bool loEncontre = false;
	while(h < aristas.size() && !loEncontre) {
		if ( (aristas[h].first.first == i && aristas[h].first.second == j) || (aristas[h].first.first == j && aristas[h].first.second == i) ) {
			loEncontre = true;
		}
		h++;
	}
	return loEncontre;
}

int randombis() {
	return rand() % 1000 + (rand() % 1000) * 1000 + (rand() % 1000) * 1000000;
}


int main() {
	FILE * doc;
	
	int n, m, min_peso, max_peso;
	cin >> n >> m >> min_peso >> max_peso; 
	
	vector<bool> loUse;
	vector<pair<pair<int,int>, int> > aristas;


	char filename[64];
	sprintf(filename, "grafoConexo-n%d-m%d.txt", n, m);
	

	doc = fopen(filename,"w");

	if (doc!=NULL) {
  	
		fprintf(doc, "%d %d\n", n, m);
		time_t seconds;
		time(&seconds);
		srand((unsigned int) seconds);
	
		int i;
		int j;
		int peso;

		for (int h = 0; h < n; h++) {
			loUse.push_back(false);
		}

		i = randombis() % n;
		j = randombis() % n;

		while (i == j) {
			j = randombis() % n;
		}

		loUse[j] = true;
		loUse[i] = true;
		peso = randombis() %  (max_peso - min_peso + 1) + min_peso;  
		pair<pair<int, int>, int> aristaConPeso;
		aristaConPeso.first.first = i;
		aristaConPeso.first.second = j;
		aristaConPeso.second = peso;
		aristas.push_back(aristaConPeso);		

		for (int h = 1; h < n -1; h++) {

			i = randombis() % n;    //(n - 1 - 0 + 1) + 0   
			j = randombis() % n;    //(n - 1 - 0 + 1) + 0   

			while (loUse[i] == false) {
				i = randombis() % n;    //(n - 1 - 0 + 1) + 0   
			}
		
			cerr << "ya tengo un i= " << i << endl; 

			while (loUse[j] == true) {
				j = randombis() % n;    //(n - 1 - 0 + 1) + 0   
			}

			cerr << "ya tengo un j= " << j << endl; 

			loUse[j] = true;

			peso = randombis() %  (max_peso - min_peso + 1) + min_peso;  

			pair<pair<int, int>, int> aristaConPeso;
			aristaConPeso.first.first = i;
			aristaConPeso.first.second = j;
			aristaConPeso.second = peso;

			aristas.push_back(aristaConPeso);		

		}

		while (aristas.size() < m) {
			cerr << "estoy buscando una nueva arista, ya tengo: " << aristas.size() << endl;
			i = randombis() % n;    //(n - 1 - 0 + 1) + 0   
			j = randombis() % n;    //(n - 1 - 0 + 1) + 0   
			while (yaEsta(i, j, aristas) || (i == j) ) {
				i = randombis() % n;    //(n - 1 - 0 + 1) + 0   
				j = randombis() % n;    //(n - 1 - 0 + 1) + 0   
			} 
			peso = randombis() %  (max_peso - min_peso + 1) + min_peso;  

			pair<pair<int, int>, int> aristaConPeso;
			aristaConPeso.first.first = i;
			aristaConPeso.first.second = j;
			aristaConPeso.second = peso;
			aristas.push_back(aristaConPeso);		

		}

		cerr << "estoy por imprimir" << endl;

		for (int i = 0; i < m ; i++) {
			fprintf(doc, "%d %d %d\n", aristas[i].first.first, aristas[i].first.second, aristas[i].second);
		}
    	
		cerr << "ya imprimi todo " << endl;

    	fclose(doc);
	}
	return 0;
}
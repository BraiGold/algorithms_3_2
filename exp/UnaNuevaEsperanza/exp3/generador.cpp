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
	
	int n, m, e;
	cin >> n >> m >> e; 
	
	vector<bool> loUse;
	vector<pair<pair<int,int>, int> > aristas;
	vector<int> tipo;

	char filename[64];
	sprintf(filename, "grafoConexo-%d.txt", e);
	

	doc = fopen(filename,"w");

	if (doc!=NULL) {
  	
		fprintf(doc, "%d %d\n", n, m);
		time_t seconds;
		time(&seconds);
		srand((unsigned int) seconds);
	
		int i;
		int j;

		for (int h = 0; h < n; h++) {
			loUse.push_back(false);
		}
		for (int h = 0; h < n; h++) {
			tipo.push_back(0);
		}

		i = randombis() % n;
		j = randombis() % n;

		while (i == j) {
			j = randombis() % n;
		}

		loUse[j] = true;
		loUse[i] = true;
		
		int r;
		for(int h = 0; h < e; h++){
				r = randombis() % n;
				tipo[r] = 1;  
		}


		pair<pair<int, int>, int> arista;
		arista.first.first = i;
		arista.first.second = j;
		arista.second = tipo[aristas.size()];
		aristas.push_back(arista);		

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

			pair<pair<int, int>, int> arista;
			arista.first.first = i;
			arista.first.second = j;
			arista.second = tipo[aristas.size()];

			aristas.push_back(arista);		

		}

		while (aristas.size() < m) {
			cerr << "estoy buscando una nueva arista, ya tengo: " << aristas.size() << endl;
			i = randombis() % n;    //(n - 1 - 0 + 1) + 0   
			j = randombis() % n;    //(n - 1 - 0 + 1) + 0   
			while (yaEsta(i, j, aristas) || (i == j) ) {
				i = randombis() % n;    //(n - 1 - 0 + 1) + 0   
				j = randombis() % n;    //(n - 1 - 0 + 1) + 0   
			} 

			arista.first.first = i;
			arista.first.second = j;
			arista.second = tipo[aristas.size()];
			aristas.push_back(arista);		

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
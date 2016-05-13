#include <iostream>     //cin cout
#include <stdio.h>      // printf fopen fclose fputs 
#include <stdlib.h>     //
#include <string>       //to_string
#include <vector>
#include <algorithm>    // std::sort

using namespace std;

int randombis() {
	return rand() % 1000 + (rand() % 1000) * 1000 + (rand() % 1000) * 1000000;
}


int main() {
	FILE * doc;
	
	int n, m, h, min, max;
	cin >> n >> m >> h >> min >> max; 

	
	char filename[64];
	sprintf(filename, "matriz-n%d-m%d.txt", n, m);

	vector<vector<int> > matriz;
	vector<int> fila;

	for (int i = 0; i < m; i++) {
		fila.push_back(0);
	}
	for (int i = 0; i < n; i++) {
		matriz.push_back(fila);
	}	

	doc = fopen(filename,"w");

	if (doc!=NULL) {
  	
		time_t seconds;
		time(&seconds);
		srand((unsigned int) seconds);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matriz[i][j] = randombis() % (max - min + 1) + min; 

			}
		}

		fprintf(doc, "%d %d %d\n", n, m, h);

		for (int i = 0; i < n ; i++) {
			for (int j = 0; j < m; j++) {
				fprintf(doc, "%d ", matriz[i][j]);
			}
			fprintf(doc, "\n");
		}
    	

    	fclose(doc);
	}
	return 0;
}
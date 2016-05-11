#include <stdio.h>      /* printf */
#include <math.h>       /* log */
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

void mergeImperio(vector<pair<pair<int, int>, int> > &a ,vector<pair<pair<int, int>, int> > &b, int low, int pivot, int high);

void mergesortImperio(vector<pair<pair<int, int>, int> > &a, vector<pair<pair<int, int>, int> > &b, int low, int high);

void init(int n, vector<int> &padre, vector<int> &altura){
	for (int i = 0; i < n; i++) {
		altura.push_back(1);
		padre.push_back(i);
	}
}

int find(vector<int>& padre, int x){
		if (padre[x] != x) {
			padre[x] = find(padre, padre[x]);
		}
	return padre[x];
}

void unionImperio(int x, int y, vector<int>& padre, vector<int>& altura){
	x = find(padre, x);
	y = find(padre, y);
	if(altura[x] < altura[y]){
		padre[x] = y;
	}else{
		if(altura[x] = altura[y]){
			altura[x] = altura[x] + 1;
		}
		padre[y] = x;
	}
}


vector<pair<pair<int, int>, int> > kruskal(vector<pair<pair<int, int>, int> > aristas, int n) {
	vector<pair<pair<int, int>, int> > solucion;
	vector<int> padre;
	vector<int> altura;
	init(n, padre, altura);
	mergesortImperio(aristas, aristas, 0, aristas.size() - 1);
	for(int i = 0; i < aristas.size(); i++){
		cout << aristas[i].first.first << "," << aristas[i].first.second<< "," << aristas[i].second << endl; 
	}
	for(int i = 0; i < aristas.size(); i++) {
		pair<pair<int, int>, int> arista = aristas[i];
		if((find(padre, (arista.first.first))) != find(padre, (arista.first).second)) {
			solucion.push_back(arista);
			unionImperio((arista.first).first, (arista.first).second, padre, altura);
		}

	 }
	
	return solucion;
}


void mergesortImperio(vector<pair<pair<int, int>, int> > &a, vector<pair<pair<int, int>, int> > &b, int low, int high){
    int pivot;
    if(low<high){
        pivot=(low+high)/2;
        mergesortImperio(a,b,low,pivot);
        mergesortImperio(a,b,pivot+1,high);
        mergeImperio(a,b,low,pivot,high);
    }
}

void mergeImperio(vector<pair<pair<int, int>, int> > &a, vector<pair<pair<int, int>, int> > &b, int low, int pivot, int high) {
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;
 
    while((h<=pivot)&&(j<=high)) {
        if(a[h].second<=a[j].second) {
            b[i].second=a[h].second;
            b[i].first.first=a[h].first.first;
            b[i].first.second=a[h].first.second;
            h++;
        }else{
            b[i].second=a[j].second;
            b[i].first.first=a[j].first.first;
            b[i].first.second=a[j].first.second;
            j++;
        }
        i++;
    }
    
    if(h>pivot){
        for(k=j; k<=high; k++){
            b[i].second=a[k].second;
            b[i].first.first=a[k].first.first;
            b[i].first.second=a[k].first.second;
            i++;
        }
    }else{
        for(k=h; k<=pivot; k++){
            b[i].second=a[k].second;
            b[i].first.first=a[k].first.first;
            b[i].first.second=a[k].first.second;
            i++;
        }
    }
    for(k=low; k<=high; k++){
    	a[k].second=b[k].second;
    	a[k].first.first=b[k].first.first;
        a[k].first.second=b[k].first.second;
	}
}


int main(int argc, char* argv[]) {

	int n;
	int m;
	cin >> n >> m;
	vector<pair<pair<int, int>, int> > aristas;
	for(int i = 0; i < m; i++){
		int x;
		int y;
		int p;
		cin >> x >> y >> p;
		pair<pair<int, int>, int> arista;
		arista.first.first = x;
		arista.first.second = y;
		arista.second = p;
		aristas.push_back(arista);
	}
	vector<pair<pair<int, int>, int> > solucion;

	solucion = kruskal(aristas, n);
	int l = 0;
	vector<int> ordenados;
	for (int i = 0; i < n; i++){
		ordenados.push_back(0);
	}
	for (int i = 0; i < solucion.size(); i++){
		l = l + solucion[i].second;
		ordenados[(solucion[i].first).second] = (solucion[i].first).first;

	}
	cout << l << endl;
	for (int i = 0; i < n; i++){
		cout << ordenados[i] << endl;
	}





	vector<int> padre;
	vector<int> altura;
	init(5, padre, altura);
	for(int i = 0; i < 5; i++){
	}
	for(int i = 0; i < 5; i++){
	}

	unionImperio(3, 4, padre, altura);
	//cout << endl;

	for(int i = 0; i < 5; i++){
		//cout << altura[i]; 

	}
	//cout << endl;
	//cout << endl;
	for(int i = 0; i < 5; i++){
		//cout << padre[i];
	}
	//cout << endl;
	int a = find(padre, 4);
	//cout  << a << endl;
	return 0;

}
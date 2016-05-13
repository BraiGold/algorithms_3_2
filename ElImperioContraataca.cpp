#include <stdio.h>      /* printf */
#include <math.h>       /* log */
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <sys/time.h>

using namespace std;

timeval timeStart, timeEnd;

void init_time()
{
    gettimeofday(&timeStart,NULL);
}

double get_time()
{
    gettimeofday(&timeEnd,NULL);
    return (1000000*(timeEnd.tv_sec-timeStart.tv_sec)+(timeEnd.tv_usec-timeStart.tv_usec))/1000000.0;
}

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

	pair<pair<int, int>, int> elemento;
	elemento.first.first = 0;
	elemento.first.second = 0;
	elemento.second = 0;
	vector<pair<pair<int, int>, int> > aristasordenadas;
	for (int i = 0; i < aristas.size(); i++) {
		aristasordenadas.push_back(elemento);
	}

	mergesortImperio(aristas, aristasordenadas, 0, aristas.size() - 1);

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

vector<vector<int> > listaDeAdy(vector<pair<pair<int, int>, int> > solucion, int n){
	vector<vector<int> >  listaAdy;
	pair<int, int> arista;
	vector<int> vacio;
	for (int i = 0; i < n; i++) { 
		listaAdy.push_back(vacio);
	}

	for (int i = 0; i < solucion.size(); i++){
		arista.first = solucion[i].first.first;
		arista.second = solucion[i].first.second;
		listaAdy[arista.first].push_back(arista.second);
		listaAdy[arista.second].push_back(arista.first);
	}	
	return listaAdy;
}


vector<int> DFS(vector<vector<int> > adyacencias) { 
	vector<int> pila;
	vector <int> orden;
	//inicializo el vector orden con 0
	for (int i = 0; i < adyacencias.size(); i++) {
		orden.push_back(-1);
	}

	pila.push_back(0);
	int w;
	int ord = 0;

	while (pila.size() > 0) {
		w = pila.back();
		pila.pop_back();
		ord++;
		orden[w]= ord;
		//apilo todos los vecinos de w
		for (int j = 0; j < adyacencias[w].size(); j++) {
			if (orden[adyacencias[w][j]] < 0) {
				pila.push_back(adyacencias[w][j]);
			}
		}
	}

	return orden; 
}


int main(int argc, char* argv[]) {
  bool pidieronTiempo = false; 
  double tiempo;
  if (argc > 1) {
    if (argv[1] == string("-t")) {
      pidieronTiempo = true;
    }
  }
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

  	init_time();

	solucion = kruskal(aristas, n);
	int l = 0;
	vector<int> ordenados;
	ordenados.push_back(0);

	for (int i = 1; i < n; i++){
		ordenados.push_back(0);
	}

	vector<vector<int> > adyacencias; 
	adyacencias = listaDeAdy(solucion, n);
	vector<int> orden;
	orden = DFS(adyacencias);

	for (int i = 0; i < solucion.size(); i++) {
		l = l + solucion[i].second;
		if ( (orden[solucion[i].first.first]) < (orden[solucion[i].first.second]) ) { 
			//el primero es menor que el segundo entonces el primero es padre
			ordenados[(solucion[i].first).second] = (solucion[i].first).first; //en ordenados[hijo] pongo el padre
		} else { 
			//el segundo es menor que el primero entonces el segundo es padre
			ordenados[(solucion[i].first).first] = (solucion[i].first).second; 
		}
	}

	tiempo = get_time();

  	if (!pidieronTiempo) { 
		cerr << l << endl;
		for (int i = 0; i < n; i++){
			cout << ordenados[i] << endl;
		}
	}
	if (pidieronTiempo) {
    	 printf("%.10f ", tiempo);
  	}




	return 0;


}
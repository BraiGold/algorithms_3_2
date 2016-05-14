#include <stdio.h>      /* printf */
#include <math.h>       /* log */
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
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

int minimo(int a, int b) { 
	if (a < b) { 
		return a;
	} else {
		return b;
	}
}
int costo(int xAnterior, int yAnterior, int xSiguiente, int ySiguiente, int h, vector<vector<int> > matriz){
	int res;
	if(abs(matriz[xAnterior][yAnterior] - matriz[xSiguiente][ySiguiente]) <= h){
		return 0;
	}else{
		return abs(matriz[xAnterior][yAnterior] - matriz[xSiguiente][ySiguiente]) - h;
	}
}

int main(int argc, char* argv[]) {
	bool pidieronTiempo = false; 
  	double tiempo;
  	if (argc > 1) {
    	if (argv[1] == string("-t")) {
      		pidieronTiempo = true;
    	}
  	}
	int n, m, h;
	cin >> n >> m >> h;
	vector<vector<int> > matriz;
	vector<int> vacio;
	int e;

	for (int i = 0; i < n; i ++) {
		matriz.push_back(vacio);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> e;
			matriz[i].push_back(e);
		}
	}
	//inicializo todos en 0. Tengo una matriz de nxm en 0.
	//s es la matriz tal que llegar de (1,1) a (i,j) en m es s[i,j]. 
	init_time();

	vector<vector<int> > s;

	for (int i = 0; i < n; i ++) {
		s.push_back(vacio);
	}
	for(int i = 0; i < n; i++){
		for ( int j = 0; j < m; j++){
			s[i].push_back(0);
		}
	}
	int deArriba;
	int deIzq;
	for( int i = 0; i < n; i ++){
		for(int j = 0; j < m; j++){
			if (i == 0 && j > 0){ //estoy en la primer fila
				s[i][j] = costo(i, j-1, i, j, h, matriz) + s[i][j-1];
				/*if(abs(matriz[i][j] - matriz[i][j-1]) <= h){
					s[i][j] = s[i][j-1];
				}else{
					s[i][j] = abs(matriz[i][j] - matriz[i][j-1]) - h + s[i][j-1];

				}*/
			}
			
			if(i > 0 && j == 0){// estoy en primer columna
				s[i][j] = costo(i-1, j, i, j, h, matriz) + s[i-1][j];
				/*if(abs(matriz[i][j] - matriz[i-1][j]) <= h){
					s[i][j] = s[i-1][j];

				} else{
					s[i][j] = abs(matriz[i][j] - matriz[i-1][j]) - h + s[i-1][j];

				}*/
			}
			
			if(i > 0 && j > 0){
				deArriba = costo(i-1, j, i, j, h, matriz);
				/*if(abs(matriz[i][j] - matriz[i-1][j]) <= h){
					deArriba = 0;

				}else{
					deArriba = abs(matriz[i][j] - matriz[i-1][j]) - h;

				}*/
				deIzq = costo(i, j-1, i, j, h, matriz);
				/*if(abs(matriz[i][j] - matriz[i][j-1]) <= h){
					deIzq = 0;

				}else{
					deIzq = abs(matriz[i][j] - matriz[i][j-1]) - h;

				}*/
				s[i][j] = minimo(deArriba + s[i-1][j], deIzq + s[i][j-1]);

			}
		}
	}

	/*cerr << "Matriz s:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cerr << s[i][j] << " ";
		}
		cerr << endl;
	}*/
	
	vector<char> respuesta;
	int x = n - 1;
	int y = m - 1;
	while(x != 0 || y != 0){
		if(x == 0 && y > 0){
			y = y - 1;
			respuesta.push_back('Y');
		}
		if(x > 0 && y == 0){
			x = x - 1;
			respuesta.push_back('X');
		}
		if(x > 0 && y > 0){
			if(s[x-1][y] + costo(x-1, y, x, y, h, matriz) < s[x][y-1] + costo(x , y-1, x, y, h, matriz)){
				x = x - 1;
				respuesta.push_back('X');
			}else{
				y = y - 1;
				respuesta.push_back('Y');
			}
		}
	}
	tiempo = get_time();
	//cerr << n << " " << m << endl;
  	if (!pidieronTiempo) { 
	

	cout << s[n-1][m-1] << endl;
	char a;
	int ys = 0;
	int bx = 0;
	int by = 0; 
	int prueba = 0;
	while (respuesta.size() > 0) {
		a = respuesta.back();
		cout << a << endl;
		/*if (a == 'Y') {
			if(abs(matriz[bx][by] - matriz[bx][by+1]) > h) {
				prueba = prueba + abs(matriz[bx][by] - matriz[bx][by+1]) - h;
				//cerr << "Y: " << abs(matriz[bx][by] - matriz[bx][by+1]) - h << endl;
			} //si no, es 0
			by++;
		} else {
			if(abs(matriz[bx][by] - matriz[bx+1][by]) > h) {
				prueba = prueba + abs(matriz[bx][by] - matriz[bx+1][by]) - h;
				//cerr << "X: " << abs(matriz[bx][by] - matriz[bx+1][by]) - h << endl;

			} //si no, es 0
			bx++;
		}*/
		respuesta.pop_back();
	}
	
	}
	if (pidieronTiempo) {
    	 printf("%.10f ", tiempo);
	}

	//cerr << "S: " << s[n-1][m-1] << endl;
	//cerr << "prueba: " << prueba << endl;
	return 0;

}
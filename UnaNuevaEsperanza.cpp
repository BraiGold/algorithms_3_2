#include <stdio.h>      /* printf */
#include <math.h>       /* log */
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <sys/time.h>
#include <queue>
#include <climits>
#include <list>
#include <stdlib.h>

using namespace std;

void BFS(vector<vector<int> >& g,vector<int>& distancia,int inicial);
vector<int> elegirUnOptimo(vector<vector<int> >& g,vector<int>& distancia);

int main(int argc, char* argv[]) {
  int n,m;
  cin >> n >> m;
  vector<int> l;
  vector<vector<int> >  g(3*n,l);//grafo de 3n nodos
  for (int i = 0; i < m; i++) { //genero el grafo con sus 3 copias y saltos en las aristas especiales
    int a,b,e;
    cin >>a >> b >> e;
    //creo 3 grafos iguales de 0 a n-1 , de n a 2n-1 y de 2n a 3n-1  todos copias del original
    g[a].push_back(b);
    g[b].push_back(a);

    g[a+n].push_back(b+n);
    g[b+n].push_back(a+n);

    g[a+2*n].push_back(b+2*n);
    g[b+2*n].push_back(a+2*n);
    if(e==1){//si la arista es especial le meto un salto a la dimension siguiente
      g[a].push_back(b+n);
      g[b].push_back(a+n);
      g[a+n].push_back(b);
      g[b+n].push_back(a);

      g[a+n].push_back(b+2*n);
      g[b+n].push_back(a+2*n);
      g[a+2*n].push_back(b+n);
      g[b+2*n].push_back(a+n);
    }
  }
  vector<int> distancia(3*n,INT_MAX);
  BFS(g,distancia,3*n-1);
  vector<int> caminoMin=elegirUnOptimo(g,distancia);//devolvera un camino optimo de 0 a 3n-1
  //respuesta:
  cout << caminoMin.size()+1 << endl;
  for (size_t i = 0; i < caminoMin.size()-1; i++) {
    cout <<caminoMin[i] <<" ";
  }
  cout << caminoMin.back() << endl;
}

void BFS(vector<vector<int> >& g,vector<int>& distancia,int inicial){
 int n = g.size(),t;
 queue<int> cola;
 cola.push(inicial);
 distancia[inicial] = 0;
 while(!cola.empty()){
   t = cola.front();cola.pop();

   for(int i=0; i < g[t].size() ; i++){
     if(distancia[g[t][i]]==INT_MAX) {
       distancia[g[t][i]] = distancia[t]+1;
       cola.push(g[t][i]);
     }
   }
 }
}

vector<int> elegirUnOptimo(vector<vector<int> >& g,vector<int>& distancia){
  vector<int> caminoMin;
  int N=g.size();//el tamaño de ToDo el grafo(los 3 subgrafos)
  int n=div(N,3).quot;
  int actual=0;
  int proximo=0;
  while(actual != N-1){

    for (int i = 0; i < g[actual].size(); i++) {
      if(distancia[g[actual][i]] < distancia[proximo])
        proximo=g[actual][i];
    }
    //meto en el camino minimo elegido el proximo mod n (el mod es pues como para "aplanar" los 3 grafos iguales en 1 y hacer indistingubles los movimientos sobre uno u otro)
    caminoMin.push_back(proximo % n);//notar que el 0 no esta incluido en la respuesta, como pide el enunciado el ultimo si lo estara pero luego lo borro
    int temp=proximo;
    actual=proximo;
    proximo=temp;
  }
  caminoMin.pop_back();//borro en n-1
  return caminoMin;
}

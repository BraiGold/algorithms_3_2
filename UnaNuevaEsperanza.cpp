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

using namespace std;


int main(int argc, char* argv[]) {
  int n,m;
cin >> n >> m;
list<pair<int,bool> > listaVacia;
vector<list<pair<int,bool> > > g(n,listaVacia);
for (int i = 0; i < m; i++) {
  bool esEspecial=false;
  cin >>a >> b >> e;
  if(e==1)
    esEspecial=true;
  pair<int,bool> p1(b,esEspecial);
  g[a].push_back(p1);
  pair<int,bool> p2(a,esEspecial);
  g[b].push_back(p2);
}

  vector<int> mejorCaminoCon2Distintos= BFSpa2Distintos(g);
  vector<int> mejorCaminoCon1Solo=BFSpa1Solo(g);

  vector<int> elMejor;
  if(mejorCaminoCon1Solo.size()<mejorCaminoCon2Distintos.size())
    elMejor=mejorCaminoCon1Solo;
  else
    elMejor=mejorCaminoCon2Distintos;

  //en el mejor esta la respuesta
}

BFSpa2Distintos(g){
  queue<int> cola;
  std::vector<int> distancias0E(g.size(),INT_MAX);
  std::vector<int> distancias1E(g.size(),INT_MAX);
  std::vector<int> distancias2E(g.size(),INT_MAX);
  distanciasCon0[g.size()-1]=0;
  cola.push(g.size()-1);

  while(!cola.empty()){
    int tope=cola.front();cola.pop();

    for (list<int>::iterator it=g[tope].begin(); it != g[tope].end(); ++it) {//para cada vecino de tope
      int vecino=it->first;
      bool esEspecial=it->second;

      if(distancias0E[vecino]==INT_MAX){//si no esta marcado
        distancias0E[vecino]=distancias0E[tope]+1;
        if(esEspecial){//si es especial
          if(distancias1E[tope]!=INT_MAX)//si el tope tiene algun camino con 1
            distancias2E[vecino]=distancias1E[tope]+1;//la distancia pasando por 2 al vecino es la distancia pasando por 1 al tope mas la arista especial en cuestion
          distancias1E[vecino]=distancias0E[tope]+1;//la distancia pasando por 1 es la distancia comun al tope +1

        }else{//no especial Y no marcado
          if(distancias1E[tope]!=INT_MAX)
            distancias1E[vecino]=distancias1E[tope]+1;
          if(distancias2E[tope]!=INT_MAX)
            distancias2E[vecino]=distancias2E[tope]+1;
        }
        cola.push(vecino);//encolo si no esta marcado
      }else{//si ya esta marcado
          if(esEspecial){
            distancias2E[vecino]=minimo(distancias2E[vecino],distancias1E[tope]+1);
            distancias1E[vecino]=minimo(distancias1E[vecino],distancias0E[tope]+1);
          }else{//no es especial y ya esta marcado
            distancias2E[vecino]=minimo(distancia2E[vecino],distancias2E[tope]+1);
            distancias1E[vecino]=minimo(distancias1E[vecino],distancias1E[tope]+1);
          }
        }


    }
  }//aca ya tengo todas las distancias echas
  //tomare la mejor distancia que pase por 2 especiales dese 0
   return generarCaminoPor2E(g,distancias0E,distancias1E,distancias2E);
  }

}

vector<int> generarCaminoPor2E(vector<list<pair<int,bool> > >g,vector<int> distancias0E,vector<int> distancias1E,vector<int>distancias2E){
  vector<int> CaminoMinPor2E;
  int CantEspecialesRestantes=2;
  int actual=0;
  while(actual!=g.size()-1){
    int VecMinimo=-1;
    int minimo=INT_MAX;
    bool esEspecial=false;
    for(list<int>::iterator it=g[actual].begin(); it != g[actual].end(); ++it){//itero vecinos de 0
      int vecino=it->first;
      if(CantEspecialesRestantes=2){
        if(distancias2E[vecino] < minimo){
          VecMinimo=vecino;
          minimo=distancias2E[vecino];
          if(it->second)
            esEspecial=true;
        }
      }
      if(CantEspecialesRestantes=1){
        if(distancias1E[vecino] < minimo){
          VecMinimo=vecino;
          minimo=distancias1E[vecino];
          if(it->second)
            esEspecial=true;
        }
      }
      if(CantEspecialesRestantes=0){
        if(distancias0E[vecino] < minimo){
          VecMinimo=vecino;
          minimo=distancias0E[vecino];
        }
      }
    }//fin del for
    if(esEspecial)
      CantEspecialesRestantes--;

    actual=VecMinimo;
    CaminoMinPor2E.push_back(actual);
      if(VecMinimo=-1){
        vector<int> vectLongitudAbsurda(2*g.size(),0);
        return vectLongitudAbsurda;
      }

  }
  return CaminoMinPor2E;
}

BFSpa1Solo(g){
  vector<int> distA0(g.size(),INT_MAX);
  vector<int> distAN_1(g.size(),INT_MAX);
  BFScomun(g,distA0,0);
  BFScomun(g,distAN_1,g.size()-1);

  //si e=(u,w) minimizo la suma s de  dist(u,0)+dist(w,n-1)+k donde k es 2 si d(u,0)=d(w,n-1) y k=3 si d(u,0)!=d(w,n-1)
  pair<int,int> aristaGanadora;
  int minimaSuma=INT_MAX;
  int elK;
  for (int i = 0; i < g.size(); i++) {
    for (list<int>::iterator it=g[i].begin(); it != g[i].end(); ++it) {
      if(it->second){//si es especial
        int k=3;
          if(distA0[i]==distAN_1[it->first])
            k=2;
          if(distA0[i]+distAN_1[it->first]+k<minimaSuma){
            minimaSuma=distA0[i]+distAN_1[it->first]+k;
            aristaGanadora.first=i;aristaGanadora.second=it->first;
            elK=k;
          }
      }
    }
  }

  vector<int> distHastaE(g.size(),INT_MAX);
  BFScomun(g,distHastaE,aristaGanadora.first);
  vector<int> caminoHasta=generarCamino(g,distHastaE,0,aristaGanadora.first);
  if(elK==2){
    vector<int> distDesdeE(g.size(),INT_MAX);
    BFScomun(g,distDesdeE,aristaGanadora.second);
    vector<int> caminoDesde=generarCamino(g,distDesdeE,aristaGanadora.second,g.size()-1);
    int arista[]={aristaGanadora.first,aristaGanadora.second,aristaGanadora.first};
    vector<int> e(arista);
    caminoDesde= concantenar(caminoDesde,e);
  }else{//si el k es 2
    vector<int> distDesdeE(g.size(),INT_MAX);
    BFScomun(g,distDesdeE,aristaGanadora.first);
    vector<int> caminoDesde=generarCamino(g,distDesdeE,aristaGanadora.first,g.size()-1);
    int arista[]={aristaGanadora.first,aristaGanadora.second,aristaGanadora.first};
    vector<int> e(arista);
    caminoDesde= concantenar(caminoDesde,e);
  }
}

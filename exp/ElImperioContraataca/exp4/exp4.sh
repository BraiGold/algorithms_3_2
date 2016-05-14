#!/bin/bash 

LC_NUMERIC="en_US.UTF-8"

iteraciones=1
# Para que el arbol sea completo nx(n-1)/2 = m
n="100"
m="4950" 
pesomin="1"
pesomax="100"

while getopts 'ha:' opt; do
  case $opt in
    a) iteraciones=$OPTARG ;;
    h) echo ""
       echo "    Experimento 4 - Tiempo de ejecución caso borde con el grafo de entrada es completo"
       echo ""
       echo "    Opciones disponibles:"
       echo "        -h        Imprime este texto de ayuda."
       echo "        -a <núm>  Cantidad de iteraciones - por defecto 1"
       echo ""
       exit 0 ;;
  esac
done

#genero archivos de entrada
printf "%d %d %d \n" $n $m $pesomin $pesomax | $(dirname $0)/generador #parametros del programa generador de archivos de entrada (n, m, pesomin, pesomax) 

printf "%d \n" $iteraciones >> $(dirname $0)/tiempos-exp4.txt

  printf "%d " 1 >> $(dirname $0)/tiempos-exp4.txt
  for h in $(seq 1 $iteraciones); do
    echo "iteracion numero"
    printf "%d\n " $h
    $(dirname $0)/../../../ElImperioContraataca < $(dirname $0)/grafoConexo-n$n-m$m.txt -t >> $(dirname $0)/tiempos-exp4.txt
  done
  printf "\n" >> $(dirname $0)/tiempos-exp4.txt
#octave -q $(dirname $0)/exp1.m
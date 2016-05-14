#!/bin/bash 

LC_NUMERIC="en_US.UTF-8"

iteraciones=1
# Para que el arbol sea AGM n-1 = m
n="10001"
m="10000" 
pesomin="1"
pesomax="100"

while getopts 'ha:' opt; do
  case $opt in
    a) iteraciones=$OPTARG ;;
    h) echo ""
       echo "    Experimento 3 - Tiempo de ejecución caso borde con el grafo de entrada AGM"
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

printf "%d \n" $iteraciones >> $(dirname $0)/tiempos-exp3.txt

  printf "%d " 1 >> $(dirname $0)/tiempos-exp3.txt
  for h in $(seq 1 $iteraciones); do
    echo "iteracion numero"
    printf "%d\n " $h
    $(dirname $0)/../../../ElImperioContraataca < $(dirname $0)/grafoConexo-n$n-m$m.txt -t >> $(dirname $0)/tiempos-exp3.txt
  done
  printf "\n" >> $(dirname $0)/tiempos-exp3.txt
#octave -q $(dirname $0)/exp1.m
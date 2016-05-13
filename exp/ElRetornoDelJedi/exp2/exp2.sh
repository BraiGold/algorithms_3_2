#!/bin/bash 

LC_NUMERIC="en_US.UTF-8"

iteraciones=1
m="$(seq 1000 50 2000)"
n="1000" 
h="20"
min="1"
max="100"

while getopts 'ha:' opt; do
  case $opt in
    a) iteraciones=$OPTARG ;;
    h) echo ""
       echo "    Experimento 1 - Tiempo de ejecución variando m"
       echo ""
       echo "    Opciones disponibles:"
       echo "        -h        Imprime este texto de ayuda."
       echo "        -a <núm>  Cantidad de iteraciones - por defecto 1"
       echo ""
       exit 0 ;;
  esac
done

#genero archivos de entrada
for i in $m; do
  echo "Esta creando el archivo numero"
  printf "%d\n " $i
  printf "%d %d %d \n" $n $i $h $min $max | $(dirname $0)/generador 
done 

printf "%d \n" $iteraciones >> $(dirname $0)/tiempos-exp2.txt

for k in $m; do
  printf "%d " $k >> $(dirname $0)/tiempos-exp2.txt
  echo "Esta corriendo la instancia numero"
  printf "%d\n " $k
  for h in $(seq 1 $iteraciones); do
    echo "iteracion numero"
    printf "%d\n " $h
    $(dirname $0)/../../../ElRetornoDelJedi < $(dirname $0)/matriz-n$n-m$k.txt -t >> $(dirname $0)/tiempos-exp2.txt
  done
  printf "\n" >> $(dirname $0)/tiempos-exp2.txt
done

#octave -q $(dirname $0)/exp1.m
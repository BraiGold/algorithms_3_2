#!/bin/bash 

LC_NUMERIC="en_US.UTF-8"

iteraciones=1
n="100"
m="$(seq 99 500 4950)" 
# el minimo m que puedo tener dado n es: m = n-1 
# el maximo m que puedo tener dado n es: m = n * (n - 1) /2 
pesomin="1"
pesomax="100"

while getopts 'ha:' opt; do
  case $opt in
    a) iteraciones=$OPTARG ;;
    h) echo ""
       echo "    Experimento 2 - Tiempo de ejecución variando cantidad de rutas entre planetas"
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
  printf "%d %d %d \n" $n $i $pesomin $pesomax | $(dirname $0)/generador #parametros del programa generador de archivos de entrada (n, m, pesomin, pesomax) 
done 

printf "%d \n" $iteraciones >> $(dirname $0)/tiempos-exp2.txt

for k in $m; do
  printf "%d " $k >> $(dirname $0)/tiempos-exp2.txt
  echo "Esta corriendo la instancia numero"
  printf "%d\n " $k
  for h in $(seq 1 $iteraciones); do
    echo "iteracion numero"
    printf "%d\n " $h
    $(dirname $0)/../../../ElImperioContraataca < $(dirname $0)/grafoConexo-$k.txt -t >> $(dirname $0)/tiempos-exp2.txt
  done
  printf "\n" >> $(dirname $0)/tiempos-exp2.txt
done

#octave -q $(dirname $0)/exp1.m
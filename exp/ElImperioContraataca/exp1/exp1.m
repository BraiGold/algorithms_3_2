% Procesado de los datos
[enemigos_x, tiempo_y, e, cant] = leer_datos_float('tiempos-exp1.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;

n = size(enemigos_x);
ult = enemigos_x(n);
ultimo = ult(1);
primero = enemigos_x(1);

eje_x = primero:ultimo;
eje_y = (eje_x/57000000);


hold on;
x = gca;
xlim([primero ultimo]);
plot(eje_x,eje_y,'r'); %O(n)
errorbar( enemigos_x, tiempo_y, e);
xlabel('Cantidad de Enemigos','FontSize',12);
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
legend('Complejidad O(n)','Tiempo de ejecucion del algoritmo','Location','northwest')
%set(get(h, 'Parent'), 'YScale', 'log');
hold off;
print('exp1', filetype);
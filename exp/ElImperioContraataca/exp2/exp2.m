% Procesado de los datos
[rutas_x, tiempo_y, e, cant] = leer_datos_float('tiempos-exp2.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;

n = 40; %CANTIDAD DE ARISTAS CONSTANTE	

m = size(rutas_x);
ult = rutas_x(m);
ultimo = ult(1);
primero = rutas_x(1);

%disp(primero);
%disp(ultimo);


eje_x = (primero:ult);
aux=log2(eje_x);
%disp(eje_x);
%disp(aux);
auxx= times(aux, eje_x);
eje_y = times(auxx,(1/15000000));
%disp('y');
%disp(eje_y);

%disp('x');
%disp(eje_x);


hold on;
x = gca;
%xlim([0 dim]);
plot(eje_x,eje_y,'r'); 
errorbar(rutas_x, tiempo_y, e, 'b');
xlabel('Cantidad de Rutas','FontSize',12); %CAMBIAR M
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
legend('Complejidad O(m (log m))','Tiempo de ejecucion del algoritmo','Location','northwest')
%set(get(h, 'Parent'), 'YScale', 'log');
hold off;
print('exp2', filetype);
% Procesado de los datos
[n_x, tiempo_y, e, cant] = leer_datos_float('tiempos-exp1.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;

m = 300; %CANTIDAD DE ARISTAS CONSTANTE	

n = size(n_x);
ult = n_x(n);
ultimo = ult(1);
primero = n_x(1);

%disp(primero);
%disp(ultimo);

% COMPLEJIDAD O(m * n)


dim = ultimo-primero+1; %+1 porque matlab no me cuenta el cero -.-
%disp(dim);
disp(dim);

eje_x = (primero:ult);
%disp('x');
%disp(eje_x);

aux_y = eje_x * m; 
eje_y = times(aux_y, 1/1600);

%eje_y(1:dim) = (log2(m) * m) *(1/5000000);
disp('y');

hold on;
x = gca;
xlim([90 610]);
%ylim([0.0005 0.0022]);
plot(eje_x,eje_y,'r'); 
errorbar(n_x, tiempo_y, e, 'b');
xlabel('Valor de N','FontSize',12); %CAMBIAR M
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
legend('Complejidad O(n * m)','Tiempo de ejecucion del algoritmo','Location','northwest')
%set(get(h, 'Parent'), 'YScale', 'log');
hold off;
print('exp1', filetype);
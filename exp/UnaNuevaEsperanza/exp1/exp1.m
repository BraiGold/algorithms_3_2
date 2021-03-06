% Procesado de los datos
[cuevas_x, tiempo_y, e, cant] = leer_datos_float('tiempos-exp1.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;

m = 10000; %CANTIDAD DE ARISTAS CONSTANTE	

n = size(cuevas_x);
ult = cuevas_x(n);
ultimo = ult(1);
primero = cuevas_x(1);

%disp(primero);
%disp(ultimo);

% COMPLEJIDAD O(m + n + n log m)


dim = ultimo-primero+1; %+1 porque matlab no me cuenta el cero -.-
disp(dim);


eje_x = (primero:ult);
%disp('x');
%disp(eje_x);

auxm(1:dim) = m;
disp('M:');
disp(auxm);

aux_y = eje_x + auxm;

eje_y = times(aux_y, 1/500000);
%disp('y');

hold on;
x = gca;
xlim([0 dim]);
%ylim([0.0005 0.0022]);
plot(eje_x,eje_y,'r'); 
errorbar(cuevas_x, tiempo_y, e, 'b');
xlabel('Cantidad de Cuevas','FontSize',12); %CAMBIAR M
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
legend('Complejidad O(n + m)','Tiempo de ejecucion del algoritmo','Location','northwest')
%set(get(h, 'Parent'), 'YScale', 'log');
hold off;
print('exp1', filetype);
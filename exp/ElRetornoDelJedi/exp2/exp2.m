% Procesado de los datos
[m_x, tiempo_y, e, cant] = leer_datos_float('tiempos-exp2.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;

n = 300; %CANTIDAD DE ARISTAS CONSTANTE	

tam = size(m_x);
ult = m_x(tam);
ultimo = ult(1);
primero = m_x(1);

%disp(primero);
%disp(ultimo);

% COMPLEJIDAD O(m * n)


dim = ultimo-primero+1; %+1 porque matlab no cuenta el cero -.-
%disp(dim);


eje_x = (primero:ult);
%disp('x');
%disp(eje_x);

aux_y = eje_x * n; 
eje_y = times(aux_y, 1/2000);

%eje_y(1:dim) = (log2(m) * m) *(1/5000000);
disp('y');

hold on;
x = gca;
xlim([primero dim]);
%ylim([0.0005 0.0022]);
plot(eje_x,eje_y,'r'); 
errorbar(m_x, tiempo_y, e, 'b');
xlabel('Valor de m','FontSize',12); %CAMBIAR M
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
legend('Complejidad O(n * m)','Tiempo de ejecucion del algoritmo','Location','northwest')
%set(get(h, 'Parent'), 'YScale', 'log');
hold off;
print('exp2', filetype);
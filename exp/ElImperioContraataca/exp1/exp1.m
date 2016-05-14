% Procesado de los datos
[planetas_x, tiempo_y, e, cant] = leer_datos_float('tiempos-exp1.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;

m = 40; %CANTIDAD DE ARISTAS CONSTANTE	

n = size(planetas_x);
ult = planetas_x(n);
ultimo = ult(1);
primero = planetas_x(1);

%disp(primero);
%disp(ultimo);

dim = ultimo-primero+1; %+1 porque matlab no me cuenta el cero -.-
%disp(dim);

eje_y(1:dim) = (log2(m) * m) *(1/500000);
%disp('y');
%disp(eje_y);

eje_x = (primero:ult);
%disp('x');
%disp(eje_x);


hold on;
x = gca;
%xlim([0 dim]);
plot(eje_x,eje_y,'r'); 
errorbar(planetas_x, tiempo_y, e, 'b');
xlabel('Cantidad de Planetas (m = 40 )','FontSize',12); %CAMBIAR M
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
legend('Complejidad O(m (log m))','Tiempo de ejecucion del algoritmo','Location','northwest')
%set(get(h, 'Parent'), 'YScale', 'log');
hold off;
print('exp1', filetype);
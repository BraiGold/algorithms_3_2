% Procesado de los datos
[pasadizos_x, tiempo_y, e, cant] = leer_datos_float('tiempos-exp2.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;

n = 1000; %CANTIDAD DE ARISTAS CONSTANTE	

nn = size(pasadizos_x);
ult = pasadizos_x(nn);
ultimo = ult(1);
primero = pasadizos_x(1);

%disp(primero);
%disp(ultimo);

% COMPLEJIDAD O(m + n + n log m)


dim = ultimo-primero+1; %+1 porque matlab no me cuenta el cero -.-
%disp(dim);


eje_x = (primero:ult);
%disp('x');
%disp(eje_x);

auxn(1:dim) = n;


aux_y = (auxn + eje_x);
eje_y = times(aux_y, 1/900000); 


hold on;
x = gca;
xlim([0 dim+1000]);
%ylim([0.0005 0.0022]);
plot(eje_x,eje_y,'r'); 
errorbar(pasadizos_x, tiempo_y, e, 'b');
xlabel('Cantidad de pasadizos','FontSize',12); %CAMBIAR M
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
legend('Complejidad O(n + m)','Tiempo de ejecucion del algoritmo','Location','northwest')
hold off;
print('exp2', filetype);
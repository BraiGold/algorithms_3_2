% Procesado de los datos
[especiales_x, tiempo_y, e, cant] = leer_datos_float('tiempos-exp3.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;



hold on;
x = gca;
%xlim([0 dim+1000]);
ylim([0.02 0.03]);
%plot(eje_x,eje_y,'r'); 
errorbar(especiales_x, tiempo_y, e, 'b');
xlabel('Cantidad de pasadizos especiales','FontSize',12); %CAMBIAR M
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
%legend('Complejidad O(n + m)','Tiempo de ejecucion del algoritmo','Location','northwest')
hold off;
print('exp3', filetype);
% Datos
x = [1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 10000000];
y = [0.1878911018, 0.3264364958, 0.5171173811, 0.6984700799, 0.8521822929, 1.005517328, 1.193224823, 1.392010105, 1.714698637, 1.974507928];

% Ajuste de una función polinomial
p = polyfit(x, y, 3); % Polinomio de grado 3 (ajusta según sea necesario)
y_poly = polyval(p, x);

% Ajuste de una función logarítmica
p_log = polyfit(log(x), y, 1);
y_log = polyval(p_log, log(x));

% Gráfica
figure;
scatter(x, y, 'o', 'DisplayName', 'Datos');
hold on;
plot(x, y_poly, '-r', 'DisplayName', 'Polinomial');
plot(x, y_log, '-g', 'DisplayName', 'Logarítmica');
hold off;

title('Gráfico de Puntos y Funciones');
xlabel('Tamaño del Problema (n)');
ylabel('Tiempo de ejecución');
legend('Location', 'Northwest');
grid on;

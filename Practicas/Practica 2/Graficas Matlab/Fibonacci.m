% Datos
x = [1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 10000000];
y_data = [0.000776434, 0.000767338, 0.000786662, 0.000755215, 0.000774324, 0.000772548, 0.000919342, 0.000804424, 0.000904667, 0.00098803];

% Ajuste de una función polinomial
grado_polinomio = 3; % Puedes ajustar el grado según sea necesario
p = polyfit(x, y_data, grado_polinomio);
y_polinomio = polyval(p, x);

% Ajuste de una función logarítmica
p_log = polyfit(log(x), y_data, 1);
y_logaritmica = polyval(p_log, log(x));

% Ajuste de una función exponencial
p_exp = polyfit(x, log(y_data), 1);
y_exponencial = exp(polyval(p_exp, x));

% Graficar
figure;

scatter(x, y_data, 'o', 'DisplayName', 'Datos');
hold on;

plot(x, y_polinomio, '-r', 'LineWidth', 2, 'DisplayName', 'Polinomial');
plot(x, y_logaritmica, '-g', 'LineWidth', 2, 'DisplayName', 'Logarítmica');
plot(x, y_exponencial, '-b', 'LineWidth', 2, 'DisplayName', 'Exponencial');

hold off;

title('Gráfico de Puntos con Funciones Ajustadas');
xlabel('n');
ylabel('Valor');
legend('Location', 'Northwest');
grid on;

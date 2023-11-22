% Datos
x = [1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 10000000];
y_data = [0.1840609312, 0.3688258052, 0.5296885967, 0.6760047793, 0.9811458945, 1.087353945, 1.261013937, 1.457639515, 1.699121702, 1.807818246];

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

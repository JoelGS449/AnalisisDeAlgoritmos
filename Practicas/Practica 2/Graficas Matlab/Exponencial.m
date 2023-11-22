% Datos
x = [1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 10000000];
y_data = [0.1737502337, 0.3247193217, 0.4846215725, 0.7096844077, 0.8829488516, 1.063800991, 1.236817396, 1.398847616, 1.604394138, 1.742619991];

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

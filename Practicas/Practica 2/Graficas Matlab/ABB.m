% Datos
x = [1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 10000000];
y_data = [0.2075582266, 0.4304417253, 0.6336193323, 0.9931870937, 1.237547743, 1.418361235, 1.64032315, 1.80688585, 2.125991535, 2.496997654];

% Ajuste de una función polinomial
grado_polinomio = 3; % Puedes ajustar el grado según sea necesario
p = polyfit(x, y_data, grado_polinomio);
y_polinomio = polyval(p, x);

% Ajuste de una función logarítmica
p_log = polyfit(log(x), y_data, 1);
y_logaritmica = polyval(p_log, log(x));

% Graficar
figure;

scatter(x, y_data, 'o', 'DisplayName', 'Datos');
hold on;

plot(x, y_polinomio, '-r', 'LineWidth', 2, 'DisplayName', 'Polinomial');
plot(x, y_logaritmica, '-g', 'LineWidth', 2, 'DisplayName', 'Logarítmica');

hold off;

title('Gráfico de Puntos con Funciones Ajustadas');
xlabel('n');
ylabel('Valor');
legend('Location', 'Northwest');
grid on;

% Definir el rango de valores para n
n = linspace(1, 100, 100); % Puedes ajustar el rango según tus necesidades

% Definir las funciones
f_lineal = n./2 + (1 - (2./(2*(n+1))));
f_ABB = (2*n.*n + n + 5*n - 1) ./ (n + 1);
f_binaria = 2*n + 2;
f_exponencial = 3*n + 2;
f_fibonacci = (1/3) * (28 * ((log(log(n)) + (1/2) * log(log(5))) / (log(log(phi())))));

% Graficar
figure;

plot(n, f_lineal, '-r', 'LineWidth', 2, 'DisplayName', 'Lineal');
hold on;

plot(n, f_ABB, '-g', 'LineWidth', 2, 'DisplayName', 'ABB');
plot(n, f_binaria, '-b', 'LineWidth', 2, 'DisplayName', 'Binaria');
plot(n, f_exponencial, '-m', 'LineWidth', 2, 'DisplayName', 'Exponencial');
plot(n, f_fibonacci, '-c', 'LineWidth', 2, 'DisplayName', 'Fibonacci');

hold off;

title('Gráficas de Funciones');
xlabel('n');
ylabel('f(n)');
legend('Location', 'Northwest');
grid on;

% Función auxiliar para obtener el valor de phi
function val = phi()
    val = (1 + sqrt(5)) / 2;
end

clear all;
global w;
T = 100;
w = 10;
X0=[0,0];
options=odeset('AbsTol',[1e-8,1e-8],'RelTol',1e-8);
[t,x]=ode45('model1',[0,T],X0,options);
Ax=max(x(round(length(x)/2):length(x),1)); % нормирующий коэффициент
 
% Определение АЧХ по максимальному установившемуся значению x(t)
figure
plot(t,x(:,1),'b-','LineWidth',2);
hold on;
y=sin(w*t);
plot(t,y,'g-','LineWidth',2);
legend('x(t)','y(t)');
grid on;
xlabel('t, c');
ylabel('x_i(t)');
title(strcat('\omega=', num2str(w), ' Гц, A_x='));
annotation('arrow',[0.13 0.13],[0.13 0.95], 'HeadStyle', 'plain');
annotation('arrow',[0.11 0.92],[0.11 0.11], 'HeadStyle', 'plain');
 
% Выделение максимальных значений на графике для определения фазы
x1 = x(:, 1);
%
DT = 2 * pi / w;
steps = ceil(3 * DT / mean(diff(t)));
idx_2 = length(t);
idx_1 = length(t) - steps + 1;
X1 = x1(idx_1 : idx_2);
Y = y(idx_1 : idx_2);
Xt = t(idx_1 : idx_2);
X1_src = X1;
Y_src = Y;
%
X1_MAX_IDX = [];
Y_MAX_IDX = [];
for k = 1 : 3
    [~, X1_max_idx] = max(X1);
    dt = ceil(0.1 * DT / mean(diff(t))); % отступ 10%
    tidx_1_x = max(X1_max_idx - dt, 1);
    tidx_2_x = X1_max_idx + dt;
    X1(tidx_1_x : tidx_2_x) = 0;
    
    [~, Y_max_idx] = max(Y);
    tidx_1_y = max(Y_max_idx - dt, 1);
    tidx_2_y = Y_max_idx + dt;
    Y(tidx_1_y : tidx_2_y) = 0;
    
    X1_MAX_IDX = [X1_MAX_IDX, X1_max_idx];
    Y_MAX_IDX = [Y_MAX_IDX, Y_max_idx];
end
 
% Определение ФЧХ (разности dt между максимумами y(t) и x(t))
figure
plot(Xt, X1_src / Ax, 'b-', 'LineWidth', 2);
hold on;
plot(Xt, Y_src, 'g-', 'LineWidth', 2);
plot(Xt(X1_MAX_IDX), X1_src(X1_MAX_IDX) / Ax, 'bo');
plot(Xt(Y_MAX_IDX), Y_src(Y_MAX_IDX), 'go');
grid on
legend('x(t) / A_x', 'y(t)');
title(strcat('\omega=', num2str(w), ' Гц, \phi='));
xlabel('t, c');
ylabel('x_i(t) / A_x');
annotation('arrow',[0.13 0.13],[0.13 0.95], 'HeadStyle', 'plain');
annotation('arrow',[0.11 0.92],[0.11 0.11], 'HeadStyle', 'plain');

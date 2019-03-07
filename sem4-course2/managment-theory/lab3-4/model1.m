function dx=model1(t,x)
global w;
k = 2.5;
T = 2.5;
xi = 0.35;
dx=zeros(2,1);
y=sin(w*t);
a2 = T^2;
a1 = 2 * xi * T;
a0 = 1;
b0 = k;
dx(1)=x(2);
dx(2)= 1 / (a2) * (b0 * y - (a1 * x(2) + a0 * x(1)));

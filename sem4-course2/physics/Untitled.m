a = 10;
m = 9.1 * 10^(-31);
U = 10;
h = 4.135667662*10^(-15);

E0 = U:0.01:10000;
x0=sqrt(2*m*E0/h^2);
x0=[x0 -x0];
y0=sqrt(2*m*(E0-U)/h^2);
y0=[y0 -y0];
L0=cos(x0.*a/2).*cos(y0.*a/2)-0.5.*(x0./y0+y0./x0).*sin(x0.*a/2).*sin(y0.*a/2);

E1 = 0:0.01:U;
x1=sqrt(2*m*E1/h^2);
x1=[x1 -x1];
y1=sqrt(2*m*(U-E1)/h^2);
y1=[y1 -y1];
L1=cos(x1.*a/2).*cosh(y1.*a/2)-0.5.*(x1./y1-y1./x1).*sin(x1.*a/2).*sinh(y1.*a/2);

E2 = -1000:0.01:0;
x2=sqrt(-2*m*E2/h^2);
x2=[x2 -x2];
y2=sqrt(2*m*(U-E2)/h^2);
y2=[y2 -y2];
L2=cosh(x2.*a./2).*cosh(y2.*a./2)+0.5.*(x2./y2+y2./x2).*sinh(x2.*a./2).*sinh(y2.*a./2);

plot([E0 E0], L0, [E1 E1], L1, [E2 E2], L2, 'Linewidth', 2);
grid on;
axis([-20, 100, -32, 5]);
title('L(E) при a = 10 А, U = 10 В');
xlabel('E');
ylabel('L');

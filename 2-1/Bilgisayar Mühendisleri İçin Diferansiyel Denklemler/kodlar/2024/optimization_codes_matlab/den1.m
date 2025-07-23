syms x1;
syms x2;
syms expr;
% diff(expr,n,v) differentiate expr n times with respect to v .
expr=x1^2+3*x2^2+4*x1*x2+3*x2+2;
ddx=diff(expr,2,x1);
dx=diff(expr,1,x1);
dy=diff(expr,1,x2);
dxdy=diff(dx,1,x2);
ddy=diff(expr,2,x2);

q=[ddx dxdy; dxdy ddy]

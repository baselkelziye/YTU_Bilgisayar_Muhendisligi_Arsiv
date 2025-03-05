m0 = [0;0;0];
S0 = [0.1 0 0;0 0.1 0;0 0 100];
r=2;
theta=0;
g=[
r*cos(theta);
r*sin(theta);
0];

G_x = [
1 0 -r*sin(theta);
0 1 r*cos(theta);
0 0 1];  

R=[
0.1 0 0;
0 0.1 0;
0 0 0.1];


m1=m0+g;
S1=G_x*S0*transpose(G_x)+ R ;

z=[2.5];
C=[1 0 0];
Q=[0.05];

K1=S1*C'*inv(C*S1*C'+Q);
m2=m1+K1*(z-C*m1);
S2=(eye(3)-K1*C)*S1;
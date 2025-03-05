clear all
pkg load statistics
kappa=1; #kappa>=0
alpha=0.5; #0<alpha<=1
beta=2; #2 for normal dist
n=2;
lambda=alpha^2*(n+kappa)-n;
gamma=sqrt(n+lambda);
wm(1)=lambda/(lambda+n);
wc(1)=wm(1)+(1-alpha^2+beta);
for i=2:n+1
	wm(i)=1/(2*(n+lambda));
	wc(i)=1/(2*(n+lambda));
endfor
for i=n+2:2*n+1
	wm(i)=1/(2*(n+lambda));
	wc(i)=1/(2*(n+lambda));
endfor

if n==1
	x=5;
	s=1;
elseif n==2
	x=[5;5];
	s=[4 1.2;1.2 2];
endif
sigma_points=x;
sigma_points = [sigma_points,x+gamma*sqrt(s)];
sigma_points = [sigma_points,x-gamma*sqrt(s)];

if n==1
  scatter(sigma_points,zeros(size(sigma_points)),'r');
  XX=[x-4*s:8*s/100:x+4*s];
  hold on;
  plot (XX,normpdf(XX,x,s));
  axis("auto");
elseif n==2
  scatter(sigma_points(1,:),sigma_points(2,:),'r');
  hold on
  [XX, YY] = meshgrid (linspace (0, 10, 25));
  XY = [XX(:), YY(:)];
  Z = mvnpdf (XY, x, s);
  mesh (XX, YY, reshape (Z, size (XX)));
  colormap jet
  axis("auto");
endif


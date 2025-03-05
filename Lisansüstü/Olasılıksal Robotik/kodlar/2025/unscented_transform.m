# univarite gaussian distribution
clear all;
pkg load statistics
samples_mu = 0;
samples_sigma = 1;
samples = normrnd(samples_mu,samples_sigma,1,1000000);
x_sample=[samples_mu-4*samples_sigma:8*samples_sigma/100:samples_mu+4*samples_sigma];


transform = 1./e.^(samples/2);
transform_mu = mean(transform);
transform_sigma = var(transform, 1);
x_transform=[transform_mu-4*transform_sigma:8*transform_sigma/100:transform_mu+4*transform_sigma];


#kappa>=0
#0<alpha<=1
#betaa=2 for normal dist
#wm sample weight
#wc sample variance weight
n = length(samples_mu);
kappa=0;
alpha=0.2;
beta=2;
lambda = alpha^2*(n+kappa)-n;
gamma = sqrt(n+lambda);
wm(1) = lambda/(lambda+n);
wc(1) = wm(1)+(1-alpha^2+beta);
sigma_points(1) = samples_mu;

for i=2:n+1
  wm(i)=1/(2*(n+lambda));
  wc(i)=1/(2*(n+lambda));
  sigma_points(i) = samples_mu + gamma*sqrt(samples_sigma);
endfor

for i=n+2:2*n+1
  wm(i)=1/(2*(n+lambda));
  wc(i)=1/(2*(n+lambda));
  sigma_points(i) = samples_mu - gamma*sqrt(samples_sigma);
endfor


figure;
hist(samples,100,10);
hold on;
plot (x_sample,normpdf(x_sample,samples_mu,samples_sigma));
plot(sigma_points, zeros(1,3),'or')
axis ("auto");


g_points = 1./e.^(sigma_points/2);
g_mu = sum(wm.*g_points);
g_sigma = sum(wc.*((g_points-g_mu)*(g_points-g_mu)'));
x_g=[g_mu-4*g_sigma:8*g_sigma/100:g_mu+4*g_sigma];

figure;
hist(transform,100,10);
hold on;
plot (x_transform,normpdf(x_transform,transform_mu,transform_sigma));
plot(g_points, zeros(size(g_points)),'*g')
plot (x_g,normpdf(x_g,g_mu,g_sigma));
axis ("auto");


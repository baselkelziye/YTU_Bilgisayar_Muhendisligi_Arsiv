##########################################
#
#		x'(t) = sin(x(t))
#		z(t) = e^(x'(t))
#
#
##########################################

function [wm, wc, gammaa, nn] = gen_weights(kappa=0, alpha=0.2, betaa=2, n=1)
	#kappa>=0
	#0<alpha<=1
	#betaa=2 for normal dist
	#wm sample weight
	#wc sample variance weight
	lambda=alpha^2*(n+kappa)-n;
	gammaa=sqrt(n+lambda);
	wm(1)=lambda/(lambda+n);
	wc(1)=wm(1)+(1-alpha^2+betaa);
	for i=2:n+1
	  wm(i)=1/(2*(n+lambda));
	  wc(i)=1/(2*(n+lambda));
	endfor
  for i=n+2:2*n+1
	  wm(i)=1/(2*(n+lambda));
	  wc(i)=1/(2*(n+lambda));
	endfor
  nn=n;
  %wc=wc./(sum(wc));
endfunction

function  a = g (x)
  a = sin(x);
endfunction

function b = h (x)
  b = e^(x);
endfunction

function [xx, ss] = predict (x, s, n, wm, wc ,gammaa, r)
  sigma_points=x;
  sigma_points = [sigma_points,x+gammaa*sqrt(s)];
  sigma_points = [sigma_points,x-gammaa*sqrt(s)];
  for i=1:2*n+1
    sigma_points_(i) = g(sigma_points(i));
  endfor
  xx = sum(sigma_points_.*wm);
  ss = sum(wc.*(sigma_points_-xx).*(sigma_points_-xx))+r;
endfunction

function [x, s] = correct (z, xx, ss, n, wm, wc ,gammaa, q)
  sigma_points=xx;
  sigma_points = [sigma_points,xx+gammaa*sqrt(ss)];
  sigma_points = [sigma_points,xx-gammaa*sqrt(ss)];
  for i=1:2*n+1
    sigma_points_(i) = h(sigma_points(i));
  endfor
  z_av= sum(sigma_points_.*wm);
  sz =  sum(wc.*(sigma_points_-z_av).*(sigma_points_-z_av))+q;
  sxz=  sum(wc.*(sigma_points-xx).*(sigma_points_-z_av));
  k = sxz/sz;
  x = xx + k*(z-z_av);
  s = ss-k*sz*k;
endfunction

function [x_org, z_org, z_err] = gen_data(n=20, err_var=1)
  x_org(1)=1.5;
  z_org(1)=h(x_org(1));
  z_err(1)=err_var*randn/5+z_org(1);
  for i=2:n
    x_org(i)=g(x_org(i-1));
    z_org(i)=h(x_org(i));
    z_err(i)=err_var*randn/5+z_org(i);
  endfor
endfunction

  clear all;
  [x_org, z_org, z_err] = gen_data();
  #z_err=[ 4.5633   2.5527   2.7708   1.9718   2.2742   1.7286   1.7123   1.8354   1.8957   1.5772   1.7487   1.5052   1.2458   1.2036   1.6289   1.4300   1.4017   1.7458   1.4683   1.2826];
  [wm, wc, gammaa, nn] = gen_weights(2.5, 0.9, 2, 1);
  x=2;
  s=2;
  for i=1:20
    [xx,ss]=predict(x,s,nn, wm, wc ,gammaa, 0.1);
    pred(i)=xx;
    [x, s] = correct (z_err(i), xx, ss, nn, wm, wc ,gammaa, 0.1);
    est(i)=x;
  endfor
  figure;
  plot(x_org,'r',pred,'g',est,'b')
  hold on;
  plot(z_org,'b',z_err,'r')

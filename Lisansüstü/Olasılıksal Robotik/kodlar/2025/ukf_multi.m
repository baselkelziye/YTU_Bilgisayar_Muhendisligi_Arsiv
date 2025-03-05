##########################################
#
#		x(t) = x(t-1) + r * cos( theta(t-1) )
#   y(t) = y(t-1) + r * sin( theta(t-1) )
#		theta(t) = theta(t-1)
#
#   z(t) = sqrt( x(t) * x(t) + y(t) * y(t) )
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

function  a = g (x,u)
  a = x + [u*cos(x(3)); u*sin(x(3)); 0];
endfunction

function b = h (x)
  b = sqrt(x(1)*x(1) + x(2)*x(2));
endfunction

function [xx, ss] = predict (x, s, u, n, wm, wc ,gammaa, r)
  sigma_points=x;
  #sigma_points = [sigma_points,x+gammaa*sqrt(s)];
  sigma_points = [sigma_points,x+gammaa*chol(s)'];
  #sigma_points = [sigma_points,x-gammaa*sqrt(s)];
  sigma_points = [sigma_points,x-gammaa*chol(s)'];
  for i=1:2*n+1
    sigma_points_(:,i) = g(sigma_points(:,i), u);
  endfor
  xx = sigma_points_*wm';
  ss = wc.*(sigma_points_-xx)*(sigma_points_-xx)'+r;
endfunction

function [x, s] = correct (z, xx, ss, n, wm, wc ,gammaa, q)
  sigma_points=xx;
  #sigma_points = [sigma_points,xx+gammaa*sqrt(ss)];
  sigma_points = [sigma_points,xx+gammaa*chol(ss)'];
  #sigma_points = [sigma_points,xx-gammaa*sqrt(ss)];
  sigma_points = [sigma_points,xx-gammaa*chol(ss)'];
  for i=1:2*n+1
    sigma_points_(i) = h(sigma_points(:,i));
  endfor
  z_av= sigma_points_*wm';
  sz =  wc.*(sigma_points_-z_av)*(sigma_points_-z_av)'+q;
  sxz=  wc.*(sigma_points-xx)*(sigma_points_-z_av)';
  k = sxz*inv(sz);
  x = xx + k*(z-z_av);
  s = ss-k*sz*k';
endfunction

function [x_org, z_org, z_err] = gen_data(n=20, err_var=1)
  x_org=[2;1;pi/3];
  z_org=h(x_org);
  z_err=err_var*randn/5+z_org;
  for i=2:n
    x_org(:,i)=g(x_org(:,i-1),2);
    z_org(i)=h(x_org(:,i));
    z_err(i)=err_var*randn/5+z_org(i);
  endfor
endfunction

  clear all;
  [x_org, z_org, z_err] = gen_data();
  #z_err=[ 4.5633   2.5527   2.7708   1.9718   2.2742   1.7286   1.7123   1.8354   1.8957   1.5772   1.7487   1.5052   1.2458   1.2036   1.6289   1.4300   1.4017   1.7458   1.4683   1.2826];
  [wm, wc, gammaa, nn] = gen_weights(2.5, 0.91, 2, 3);
  x=[1;1;pi/4];
  s=[2 0 0; 0 2 0; 0 0 pi/4];
  u=2;
  for i=1:20
    [xx,ss]=predict(x,s,u, nn, wm, wc ,gammaa, [0.2 0 0; 0 0.2 0; 0 0 0.5]);
    pred(:,i)=xx;
    [x, s] = correct (z_err(i), xx, ss, nn, wm, wc ,gammaa, 0.2);
    est(:,i)=x;
  endfor

  figure;
  scatter(x_org(1,:),x_org(2,:),'r');
  hold on;
  quiver(x_org(1,:),x_org(2,:),cos(x_org(3,:)),sin(x_org(3,:)),0.1,'r');
  hold on;
  scatter(pred(1,:),pred(2,:),'b');
  hold on;
  quiver(pred(1,:),pred(2,:),cos(pred(3,:)),sin(pred(3,:)),0.1,'b');
  hold on;
  scatter(est(1,:),est(2,:),'g');
  hold on;
  quiver(est(1,:),est(2,:),cos(est(3,:)),sin(est(3,:)),0.1,'g');
  
  


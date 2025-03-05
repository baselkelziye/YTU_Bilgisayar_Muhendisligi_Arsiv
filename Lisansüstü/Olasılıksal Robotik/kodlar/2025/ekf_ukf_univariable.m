##########################################
#
#		x'(t) = sin(x(t))
#		z(t) = e^(x'(t))
#
#
##########################################

function  a = g_jac (x)
  a = cos(x);
endfunction

function b = h_jac (x)
  b = e^(x);
endfunction

function [xx, ss] = predict (x, s, r)
  xx = sin(x);
  ss = g_jac(x)*g_jac(x)*s + r;
endfunction

function [x, s] = correct (z, xx, ss, q)
  k = (ss*h_jac(xx))/(h_jac(xx)*ss*h_jac(xx)+q);
  x = xx + k*(z-e^(xx));
  s = (1-k*h_jac(xx))*ss;
endfunction

function [x_org, z_org, z_err] = gen_data(n=20, err_var=1)
  x_org(1)=1.5;
  z_org(1)=e^(x_org(1));
  z_err(1)=err_var*randn/5+z_org(1);
  for i=2:n
    x_org(i)=sin(x_org(i-1));
    z_org(i)=e^(x_org(i));
    z_err(i)=err_var*randn/5+z_org(i);
  endfor
endfunction


  clear all;
  [x_org, z_org, z_err] = gen_data();
  #z_err=[ 4.5633   2.5527   2.7708   1.9718   2.2742   1.7286   1.7123   1.8354   1.8957   1.5772   1.7487   1.5052   1.2458   1.2036   1.6289   1.4300   1.4017   1.7458   1.4683   1.2826];
  x=2;
  s=2;
  for i=1:20
    [xx,ss]=predict(x,s,0.1);
    [x, s] = correct (z_err(i), xx, ss, 0.1);
    est(i)=x;
  endfor
  figure;
  plot(x_org,'b',est,'r')
  hold on;
  plot(z_org,'b',z_err,'r')

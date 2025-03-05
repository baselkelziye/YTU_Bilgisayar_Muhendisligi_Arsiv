##########################################
#
#		x'(t) = x(t)^1.2
#		z(t) = arctan(x'(t))
#
#
##########################################

function  a = g_jac (x)
  a = 1.2*x^0.2;
endfunction

function b = h_jac (x)
  b = 1/(1+x^2);
endfunction

function [xx, ss] = predict (x, s, r)
  xx = x^1.2;
  ss = g_jac(x)*g_jac(x)*s + r;
endfunction

function [x, s] = correct (z, xx, ss, q)
  k = (ss*h_jac(xx))/(h_jac(xx)*ss*h_jac(xx)+q);
  x = xx + k*(z-atan(xx));
  s = (1-k*h_jac(xx))*ss;
endfunction

function [x_org, z_org, z_err] = gen_data(n=20, err_var=1)
  x_org(1)=1.1;
  z_org(1)=atan(x_org(1));
  z_err(1)=err_var*randn/10+z_org(1);
  for i=2:n
    x_org(i)=(x_org(i-1))^1.2;
    z_org(i)=atan(x_org(i));
    z_err(i)=err_var*randn/10+z_org(i);
  endfor
  #plot(x_org);
  #drawnow;
  #figure,
  #plot(z_org);
  #drawnow;
  #figure,
  #plot(z_org);
  #drawnow;
endfunction


  clear all;
  [x_org, z_org, z_err] = gen_data();
  #z_err=[0.73690   0.90162   1.06450   0.82941   0.85031   0.77043   0.76732   1.00957   1.18037   1.10605   1.09124   0.88138   0.99588   1.18426   1.31232   1.22655   1.36629   1.68047   1.60503   1.53051]
  x=0;
  s=5;
  for i=1:20
    [xx,ss]=predict(x,s,1);
    est_pred(i)=xx;
    est_pred_ss(i)=ss;
    [x, s] = correct (z_err(i), xx, ss, 1.5);
    est_corr(i)=x;
    est_corr_s(i)=s;
  endfor
  plot(x_org,'b',est_corr,'r',est_pred,'g');
  plot(est_pred_ss,'b',est_corr_s,'r');

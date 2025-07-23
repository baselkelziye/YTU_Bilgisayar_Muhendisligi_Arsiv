% ADAM moving average 
clear all;
close all;
b1=0.9; % kuculdukce m daha cok salýnýyor
b2=0.99;
alfa=0.005;
eps=0.00000001;
T=500;
m=zeros(1,T); % 1. derece moment
v = m; % 2. derece moment
tm= m; % bias corrected m
tv= m; % bias corrected v
w_adam = m; % parametre adam
w_sgd =m;
w_adagrad =m;
adagrad= m;
adam_up=m;
adagrad_up=m;
%gr = 2*rand(1,T)+1; % gurultulu gradyan (1,3) arasi 
gr = randn(1,T)/2+0; % gurultulu gradyan (1,3) arasi 
%gr = randn(1,T/2)/2+2; % gurultulu gradyan (1,3) arasi ort yarisinda 2 sonrasýnda 1
%gr = [gr randn(1,T/2)/2+1];
gr=gr+6*exp(-0.02*[1:T]);
plot(gr);
%sifir_ind=randperm(T,9*T/10);
%gr(sifir_ind)=0;
for t=2:T
    m(t)=b1*m(t-1)+(1-b1)*gr(t); % b1 kuculdukce oncesinin etkisi azalýyor, simdinin etkisi artiyor, dolayýsýyla m daha cok saliniyor
    v(t)=b2*v(t-1)+(1-b2)*gr(t)*gr(t);
    adagrad(t)=adagrad(t-1)+gr(t)*gr(t);
    tm(t)=m(t)/(1-power(b1,t)); % t arttikca power(b1,t) 0 a, 1-power(b1,t) 1 e, tm(t) m(t) ye yaklaþýr.
    tv(t)=v(t)/(1-power(b2,t));
    w_adam(t)   = w_adam(t-1)-alfa*tm(t)/(sqrt(tv(t))+eps); % adam update
    adam_up(t)   = tm(t)/(sqrt(tv(t))+eps);
    w_sgd(t) = w_sgd(t-1)-alfa*gr(t); % sgd update
    w_adagrad(t) = w_adagrad(t-1)-alfa*gr(t)/(sqrt(adagrad(t))); % adagrad update
    adagrad_up(t) = gr(t)/(sqrt(adagrad(t))+eps);
end
plot(gr);
hold on;
%plot(m);
%plot(v);
%plot(tm);
%plot(tv);
plot(w_adam);
plot(w_sgd);
plot(w_adagrad);
plot(adam_up);
plot(adagrad_up);
%legend('gr','m','v','tm','tv','w_{adam}','w_{sgd}','w_{adaGrad}','adam-up','adagrad-up');
%legend('g_t','m','tm');
%legend('g_t','v','tv');
%legend('gr','m','v','tm','tv','adam-up');
legend('gr','w_{adam}','w_{sgd}','w_{adaGrad}','adam-up','adagrad-up');


%

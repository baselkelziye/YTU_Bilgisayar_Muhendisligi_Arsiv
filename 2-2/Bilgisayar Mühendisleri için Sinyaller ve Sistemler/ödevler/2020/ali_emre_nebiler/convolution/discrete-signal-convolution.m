clc
clear all
close all

disp('- CONVOLUTION CALCULATION -');
disp('(!) Enter the starting points as integers.');
disp('(!) Enter the signals in the form [. . .].');
x_str = input('Starting point of t for x[t]: ');
x = input('x[t] = '); % x[t]
h_str = input('Starting point of t for h[t]: ');
h = input('h[t] = '); % h[t]

m = length(x); % number of values in x[t]
n = length(h); % number of values in h[t]
l = m+n-1; % number of values in y[t]
y_str = x_str + h_str; % starting point of y[t]

% my convolution code
y1 = zeros(1,l); % my y[t] signal
for i = 1:m % value of x[t]
    for j = 1:n % iteration of h[t]
        %{
        In each iteration, part of a y[t] value is calculated.
        For example, for y[1]:
        when x[2] and h[1], one part of y[1] ...
        when x[1] and h[2], another part of y[1] ...
        and the sum of all of them together.
        %}
        y1(i+j-1) = y1(i+j-1) + h(j)*x(i);
    end
end

% built-in convolution function
y2 = conv(x,h); % function's y[t] signal

% print the results
arr_all = [x h y1 y2];
max = max(abs(arr_all)); % maximum for graph y values

subplot(221) % x[t] signal
stem(x_str:x_str+m-1, x, 'filled'),
set(gca,'xlim',[x_str x_str+l-1]), % x-axis range
set(gca,'ylim',[-max max]), % y-axis range
ylabel('x[t]'), xlabel('t'), grid on,
title('1st Signal');

subplot(222) % h[t] signal
stem(h_str:h_str+n-1, h, 'filled'),
set(gca,'xlim',[h_str h_str+l-1]),
set(gca,'ylim',[-max max]),
ylabel('h[t]'), xlabel('t'), grid on,
title('2nd Signal');

subplot(223) % my calculated y[t] signal
stem(y_str:y_str+l-1, y1, 'filled'),
set(gca,'xlim',[y_str y_str+l-1]),
set(gca,'ylim',[-max max]),
ylabel('y[t]'), xlabel('t'), grid on,
title('My Convolution');

subplot(224) % function's y[t] signal
stem(y_str:y_str+l-1, y2, 'filled'),
set(gca,'xlim',[y_str y_str+l-1]),
set(gca,'ylim',[-max max]),
ylabel('y[t]'), xlabel('t'), grid on,
title('Function Convolution');
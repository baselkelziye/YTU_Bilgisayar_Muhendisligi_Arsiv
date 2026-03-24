f1=697;
f2=1477;
fs=4000;

for n=0:255
    a(n+1)=sin(2*pi*f1/fs*n)+sin(2*pi*f2/fs*n);
end    

fid = fopen('941_1633_fs4kHz.data','w+'); 
for t=1:255
fprintf(fid,'%1.2f,',a(t));
end
t=256;
fprintf(fid,'%1.2f',a(t));
fclose(fid);
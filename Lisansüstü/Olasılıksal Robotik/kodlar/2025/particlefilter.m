clear all
pkg load statistics
nSamples=1000;
initPose=[0;0;0];
initCov=[16 0 0; 0 0.01 0; 0 0 0.16];
particles=randn(3,nSamples);
particles=sqrt(initCov)*particles+initPose;
particles(3,:)=mod(particles(3,:),2*pi);
figure
scatter(particles(1,:),particles(2,:),[],particles(3,:),'filled');

t = linspace(0,2*pi,250)'; 
circsx = 1.*cos(t); 
circsy = 1.*sin(t); 
figure
scatter(circsx,circsy,64,t,'filled'); 

L=2;
u=[L.*cos(particles(3,:)); L.*sin(particles(3,:));zeros(1,nSamples)];
r=randn(3,nSamples);
rCov=[0.09 0 0; 0 0.09 0; 0 0 0.16];
r=sqrt(rCov)*r;
particles=particles + u + r;
particles(3,:)=mod(particles(3,:),2*pi);
figure
scatter(particles(1,:),particles(2,:),[],particles(3,:),'filled');

z=1.5;
qCov=0.4;
weights=normpdf (z, particles(1,:), sqrt(qCov));
weights=weights./sum(weights);
figure
scatter(particles(1,:),particles(2,:),[],weights./max(weights),'filled');

weightSum= cumsum(weights);
resampleIndex = rand(1,nSamples);
resampleIndex =  sort (resampleIndex);

j=1;
for i=1:nSamples
  while(resampleIndex(i)>weightSum(j) && j<=nSamples)
    j=j+1;
  endwhile
  resample(:,j)=particles(:,j);
endfor
figure
scatter(resample(1,:),resample(2,:),[],resample(3,:),'filled');
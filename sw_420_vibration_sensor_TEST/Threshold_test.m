clc
clear all
close all

filename = 'TEST_Threshold_1.dat';
threshold_1 = csvread(filename);

x = 1:length(threshold_1);

figure
plot(x,threshold_1)
ylim([-0.5 1.5])
title('Sensor output when threshold = 1')
xlabel('n')
ylabel('Sensor digital output')

filename = 'TEST_Threshold_2.dat';
threshold_2 = csvread(filename);

x = 1:length(threshold_2);

figure
plot(x,threshold_2)
ylim([-0.5 1.5])
title('Sensor output when threshold = 2')
xlabel('n')
ylabel('Sensor digital output')


filename = 'TEST_Threshold_3.dat';
threshold_3 = csvread(filename);

x = 1:length(threshold_3);

figure
plot(x,threshold_3)
ylim([-0.5 1.5])
title('Sensor output when threshold = 3')
xlabel('n')
ylabel('Sensor digital output')

filename = 'TEST_Threshold_5.dat';
threshold_5 = csvread(filename);

x = 1:length(threshold_5);

figure
plot(x,threshold_5)
ylim([-0.5 1.5])
title('Sensor output when threshold = 5')
xlabel('n')
ylabel('Sensor digital output')

filename = 'TEST_Threshold_10.dat';
threshold_10 = csvread(filename);

x = 1:length(threshold_10);

figure
plot(x,threshold_10)
ylim([-0.5 1.5])
title('Sensor output when threshold = 10')
xlabel('n')
ylabel('Sensor digital output')

filename = 'TEST_Threshold_20.dat';
threshold_20 = csvread(filename);

x = 1:length(threshold_20);

figure
plot(x,threshold_20)
ylim([-0.5 1.5])
title('Sensor output when threshold = 20')
xlabel('n')
ylabel('Sensor digital output')

filename = 'TEST_Threshold_30.dat';
threshold_30 = csvread(filename);

x = 1:length(threshold_30);

figure
plot(x,threshold_30)
ylim([-0.5 1.5])
title('Sensor output when threshold = 30')
xlabel('n')
ylabel('Sensor digital output')

filename = 'TEST_Threshold_50.dat';
threshold_50 = csvread(filename);

x = 1:length(threshold_50);

figure
plot(x,threshold_50)
ylim([-0.5 1.5])
title('Sensor output when threshold = 50')
xlabel('n')
ylabel('Sensor digital output')

filename = 'TEST_Threshold_100.dat';
threshold_100 = csvread(filename);

x = 1:length(threshold_100);

figure
plot(x,threshold_100)
ylim([-0.5 1.5])
title('Sensor output when threshold = 100')
xlabel('n')
ylabel('Sensor digital output')

filename = 'TEST_Threshold_200.dat';
threshold_200 = csvread(filename);

x = 1:length(threshold_200);

figure
plot(x,threshold_200)
ylim([-0.5 1.5])
title('Sensor output when threshold = 200')
xlabel('n')
ylabel('Sensor digital output')

filename = 'TEST_Threshold_500.dat';
threshold_500 = csvread(filename);

x = 1:length(threshold_500);

figure
plot(x,threshold_500)
ylim([-0.5 1.5])
title('Sensor output when threshold = 500')
xlabel('n')
ylabel('Sensor digital output')
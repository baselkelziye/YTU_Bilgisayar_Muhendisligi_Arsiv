close all
clearvars

%% PART 1 -  Synthesis (audiowrite)

fprintf('\n1. SYNTHESIS\n\n');

phoneNumber = input('Enter your phone number: ', 's');

numberAmount = length(phoneNumber);

numberFreqs = zeros(numberAmount, 2);

for i = 1:numberAmount
    switch phoneNumber(i)
        case '1'
            numberFreqs(i, 1) = 697;
            numberFreqs(i, 2) = 1209;
        case '2'
            numberFreqs(i, 1) = 697;
            numberFreqs(i, 2) = 1336;
        case '3'
            numberFreqs(i, 1) = 697;
            numberFreqs(i, 2) = 1477;
        case '4'
            numberFreqs(i, 1) = 770;
            numberFreqs(i, 2) = 1209;
        case '5'
            numberFreqs(i, 1) = 770;
            numberFreqs(i, 2) = 1336;
        case '6'
            numberFreqs(i, 1) = 770;
            numberFreqs(i, 2) = 1477;
        case '7'
            numberFreqs(i, 1) = 852;
            numberFreqs(i, 2) = 1209;
        case '8'
            numberFreqs(i, 1) = 852;
            numberFreqs(i, 2) = 1336;
        case '9'
            numberFreqs(i, 1) = 852;
            numberFreqs(i, 2) = 1477;
        case '*'
            numberFreqs(i, 1) = 941;
            numberFreqs(i, 2) = 1209;
        case '0'
            numberFreqs(i, 1) = 941;
            numberFreqs(i, 2) = 1336;
        case '#'
            numberFreqs(i, 1) = 941;
            numberFreqs(i, 2) = 1477;
    end
end

amplitude = 0.1;
duration = 0.15;
fs = 8000;
t = 0:1/fs:duration;

time = length(t);

numSamples = zeros(1, time * numberAmount);

j = 1;

for i = 1:2:(2 * numberAmount - 1)
    output = amplitude * (sin(2 * pi * numberFreqs(j, 1) * t) + sin(2 * pi * numberFreqs(j, 2) * t));
    numSamples((i - 1) * time + 1 : i * time) = output;
    numSamples(i * time + 1 : (i + 1) * time) = sin(0);
    j = j + 1;
end

T = 100000 / fs;
x_axis = 1 : T : 100000 * length(numSamples) / fs;
x_axis = x_axis / 100000;

audiowrite('UserPhoneNumber.wav', numSamples, fs);

pause(1);
fprintf('\nYour audio file (UserPhoneNumber.wav) has been created.\n\n');
pause(1);
fprintf('The audio file is currently being played...\n\n');
sound(numSamples);
pause(3);
input('Press ''Enter'' to continue...\n', 's');

%% PART 2 - Analysis (audioread)

fprintf('2. ANALYSIS\n\n');

audioFile(1) = "UserPhoneNumber.wav";
audioFile(2) = "Example.wav";

amount(1) = numberAmount;
amount(2) = input('Please enter the length of the phone number in the audio file (Example.wav) you have: ');

fprintf("\n-> Length of the phone number in UserPhoneNumber.wav File : %d", amount(1));
fprintf("\n-> Length of the phone number in Example.wav File         : %d\n\n", amount(2));

for i = 1:2
    [phoneData, fs] = audioread(audioFile(i));
    interval = floor(length(phoneData) / amount(i));
    f = fs * (0 : (interval / 2)) / interval;
    
    T = 100000 / fs;
    x_axis = 1 : T : 100000 * length(phoneData) / fs;
    x_axis = x_axis / 100000;
    
    figure;
    
    if i == 1
        subplot(2, 1, 1);
        plot(x_axis, phoneData);
        title("Continuous Graph of UserPhoneNumber.wav");
        xlabel('Time');
        ylabel('Amplitude');
        
        subplot(2, 1, 2);
        stem(x_axis, phoneData);
        title("Discrete Graph of UserPhoneNumber.wav");
        xlabel('Time');
        ylabel('Amplitude');
    else
        subplot(2, 1, 1);
        plot(x_axis, phoneData);
        title("Continuous Graph of Example.wav");
        xlabel('Time');
        ylabel('Amplitude');
        
        subplot(2, 1, 2);
        stem(x_axis, phoneData);
        title("Discrete Graph of Example.wav");
        xlabel('Time');
        ylabel('Amplitude');
    end
    
    foundNumber = "";
    
    if(i == 1)
        fprintf("Audio File %d (UserPhoneNumber.wav)\n", i);
    else
        fprintf("Audio File %d (Example.wav)\n", i);
    end
    
    for j = 1:amount(i)
        fourier = fft(phoneData(1 + ((j - 1) * interval) : j * interval), fs);
        fourier_abs = abs(fourier);
        result = (fourier_abs(1 : floor(length(fourier_abs) / 2) + 1));
        
        [max_values, freqs] = maxk(result, 3);
        
        % selected_freq(1) = low frequency group  (697, 770, 852 or 941)
        % selected_freq(2) = high frequency group (1209, 1336 or 1477)
        
        if(abs(freqs(1) - freqs(2)) <= 10)
            if(freqs(1) > freqs(3))
                selected_freq(1) = freqs(3);
                selected_freq(2) = freqs(1);
            else
                selected_freq(1) = freqs(1);
                selected_freq(2) = freqs(3);
            end
        else
            if(freqs(1) < freqs(2) && abs(freqs(2) - freqs(3)) <= 10)
                selected_freq(1) = freqs(1);
                selected_freq(2) = freqs(2);
            elseif(freqs(1) < freqs(2) && abs(freqs(2) - freqs(3)) >= 10)
                selected_freq(1) = freqs(3);
                selected_freq(2) = freqs(2);
            elseif(freqs(1) > freqs(2) && abs(freqs(2) - freqs(3)) <= 10)
                selected_freq(1) = freqs(3);
                selected_freq(2) = freqs(1);
            elseif(freqs(1) > freqs(2) && abs(freqs(2) - freqs(3)) >= 10)
                selected_freq(1) = freqs(2);
                selected_freq(2) = freqs(1);
            end
        end
        
        if(abs(selected_freq(1) - 697) <= 10)
            if(abs(selected_freq(2) - 1209) <= 10)
                foundNumber = strcat(foundNumber, "1");
                temp = "'1'";
            elseif(abs(selected_freq(2) - 1336) <= 10)
                foundNumber = strcat(foundNumber, "2");
                temp = "'2'";
            elseif(abs(selected_freq(2) - 1477) <= 10)
                foundNumber = strcat(foundNumber, "3");
                temp = "'3'";
            end
        elseif(abs(selected_freq(1) - 770) <= 10)
            if(abs(selected_freq(2) - 1209) <= 10)
                foundNumber = strcat(foundNumber, "4");
                temp = "'4'";
            elseif(abs(selected_freq(2) - 1336) <= 10)
                foundNumber = strcat(foundNumber, "5");
                temp = "'5'";            
            elseif(abs(selected_freq(2) - 1477) <= 10)
                foundNumber = strcat(foundNumber, "6");
                temp = "'6'";
            end 
        elseif(abs(selected_freq(1) - 852) <= 10)
            if(abs(selected_freq(2) - 1209) <= 10)
                foundNumber = strcat(foundNumber, "7");
                temp = "'7'";          
            elseif(abs(selected_freq(2) - 1336) <= 10)
                foundNumber = strcat(foundNumber, "8");
                temp = "'8'";            
            elseif(abs(selected_freq(2) - 1477) <= 10)
                foundNumber = strcat(foundNumber, "9");
                temp = "'9'";
            end
        elseif(abs(selected_freq(1) - 942) <= 10)
            if(abs(selected_freq(2) - 1209) <= 10)
                foundNumber = strcat(foundNumber, "*");
                temp = "'*'";            
            elseif(abs(selected_freq(2) - 1336) <= 10)
                foundNumber = strcat(foundNumber, "0");
                temp = "'0'";            
            elseif(abs(selected_freq(2) - 1477) <= 10)
                foundNumber = strcat(foundNumber, "#");
                temp = "'3'";
            end
        end
        
        figure;
        plot(result);

        if(i == 1)
            title("Graph of Key " + temp + " (UserPhoneNumber)");
        else
            title("Graph of Key " + temp + " (Example)");
        end

        xlabel("Frequency");
        ylabel("Amplitude");
    end
    
    if(foundNumber == " ")
        fprintf("There is no phone number in this audio file.\n");
    else
        fprintf("-> Phone Number: %s\n", foundNumber);
    end

    if(i == 1)
        fprintf("These new graphics were created for UserPhoneNumber.wav.\n\n");
        input('Press ''Enter'' to continue...\n', 's');
        phone1 = foundNumber; % to see first phone number in Workspace
    else
        fprintf("These new graphics were created for Example.wav.\n\n");
        phone2 = foundNumber; % to see second phone number in Workspace
    end
end

fprintf("--- END ---\n\n");

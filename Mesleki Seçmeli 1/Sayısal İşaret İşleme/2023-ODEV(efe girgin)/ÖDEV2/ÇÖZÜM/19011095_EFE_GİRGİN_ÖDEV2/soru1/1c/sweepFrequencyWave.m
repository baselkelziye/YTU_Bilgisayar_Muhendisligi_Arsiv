function sweepFrequencyWave()
    % Image size configuration
    imageSize = 256;
    [X, Y] = meshgrid(1:imageSize, 1:imageSize);
    
    % Adjust grid to center at (0,0)
    X = X - imageSize / 2;
    Y = Y - imageSize / 2;

    % Parameters
    angles = [0, pi/4, pi/2];  % Angles in radians
    phases = [0, pi/2, pi];    % Phases in radians
    freqRanges = [0.1 0.2; 0.2 0.4; 0.3 0.5]; % Min-Max frequency ranges

    figure; % Open a new figure window
    count = 1; % Initialize subplot count
    
    % Loop through all parameter combinations
    for angle = angles
        for phase = phases
            for fr = 1:size(freqRanges, 1)
                f_min = freqRanges(fr, 1);
                f_max = freqRanges(fr, 2);
                
                % Calculate distance 'd' in the direction of the angle
                d = X * cos(angle) + Y * sin(angle);
                
                % Normalize distance 'd' by maximum distance 'L'
                L = max(abs(d(:)));
                normalized_d = d / L;
                
                % Wave computation
                Z = cos(2 * pi * (f_min + (f_max - f_min) * normalized_d) .* d + phase);
                subplot(9, 3, count);
                imagesc(Z);  % Display the wave
                colormap(gray);  % Set the color map to gray
                axis image off;  % Hide axes for clarity
                title(sprintf('Angle: %.2f, Phase: %.2f, Freq: %.2f-%.2f', angle, phase, f_min, f_max));
                count = count + 1;
            end
        end
    end
end



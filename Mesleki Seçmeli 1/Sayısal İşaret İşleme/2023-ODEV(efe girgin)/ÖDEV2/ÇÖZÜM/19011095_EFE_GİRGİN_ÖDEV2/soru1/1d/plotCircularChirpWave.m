function plotCircularChirpWave()
    % Image size configuration
    imageSize = 256;
    [X, Y] = meshgrid(1:imageSize, 1:imageSize);

    % Parameters
    phases = [0, pi/2, pi];            % Phase values in radians
    origins = [64, 128, 192];          % Origin values in x and y (symmetric for simplicity)
    freqRanges = [0.05 0.1; 0.1 0.2; 0.15 0.3]; % Min-Max frequency ranges

    figure; % Open a new figure window
    count = 1; % Initialize subplot count
    
    % Loop through all parameter combinations
    for origin = origins
        for phase = phases
            for fr = 1:size(freqRanges, 1)
                f_min = freqRanges(fr, 1);
                f_max = freqRanges(fr, 2);
                
                % Compute the radial distance from the specified origin
                d = sqrt((X - origin).^2 + (Y - origin).^2);
                L = max(d(:)); % Maximum radial distance for normalization
                
                % Wave computation
                Z = cos(2 * pi * (f_min + (f_max - f_min) * (d / L)) .* d + phase);
                subplot(9, 3, count);
                imagesc(Z); % Display the wave
                colormap(gray); % Set the color map to gray
                axis image off; % Hide axes for clarity
                title(sprintf('Origin: (%d,%d), Phase: %.2f rad, Freq: %.2f-%.2f', origin, origin, phase, f_min, f_max));
                count = count + 1;
            end
        end
    end
end

% Call the function to display the waveforms
%%plotCircularChirpWave();

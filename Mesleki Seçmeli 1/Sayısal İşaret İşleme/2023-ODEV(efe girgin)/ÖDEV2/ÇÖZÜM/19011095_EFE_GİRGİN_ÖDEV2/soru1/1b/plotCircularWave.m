function plotCircularWave()
    % Image size configuration
    imageSize = 256;
    [X, Y] = meshgrid(1:imageSize, 1:imageSize);

    % Parameters
    phases = [0, pi/2, pi];    % Phase values in radians
    freqs = [0.1, 0.25, 0.4];  % Normalized frequencies
    origins = [64, 128, 192];  % Origin x and y values (symmetric)

    figure; % Open a new figure window
    count = 1; % Initialize subplot count

    % Correcting the number of subplots: 3 origins, 3 phases, 3 frequencies -> 27 plots
    % Need a 9x3 grid to fit all plots
    for origin = origins
        for phase = phases
            for freq = freqs
                subplot(9, 3, count);
                % Compute the distance from the origin
                d = sqrt((X - origin).^2 + (Y - origin).^2);
                
                % Wave computation
                Z = cos(2 * pi * freq * d + phase);
                imagesc(Z); % Display the wave
                colormap(gray); % Set the color map to gray
                axis image off; % Hide axes for clarity
                title(sprintf('Origin: (%d,%d), Phase: %.2f rad, Freq: %.2f c/p', origin, origin, phase, freq));
                count = count + 1;
            end
        end
    end
end

% Call the function to display the waveforms
%%plotCircularWave();

function wave2D()
    % Image size configuration
    imageSize = 256; % Size of the square image
    [X, Y] = meshgrid(-imageSize/2:imageSize/2-1, -imageSize/2:imageSize/2-1);

    % Parameters
    angles = [0, pi/4, pi/2]; % Angles in radians
    phases = [0, pi/2, pi];   % Phases in radians
    freqs = [0.1, 0.25, 0.4]; % Normalized frequencies

    figure; % Open a new figure window
    count = 1; % Initialize subplot count

    % 27 subplots require 9x3 grid
    for i = 1:length(angles)
        for j = 1:length(phases)
            for k = 1:length(freqs)
                subplot(length(angles) * length(phases), length(freqs), count);
                angle = angles(i);
                phase = phases(j);
                freq = freqs(k);
                
                % Wave computation
                Z = cos(2 * pi * freq * (X * cos(angle) + Y * sin(angle)) + phase);
                imagesc(Z); % Display the wave
                colormap(gray); % Set the color map to gray
                axis image off; % Hide axes for clarity
                title(sprintf('Angle: %.2f rad, Phase: %.2f rad, Freq: %.2f c/p', angle, phase, freq));
                count = count + 1;
            end
        end
    end
end



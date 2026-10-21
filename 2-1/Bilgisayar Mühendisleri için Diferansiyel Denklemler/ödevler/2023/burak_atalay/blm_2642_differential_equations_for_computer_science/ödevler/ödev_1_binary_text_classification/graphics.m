fileID = fopen("file1.txt", "r");
fileID2 = fopen("file2.txt", "r");
fileID3 = fopen("file3.txt", "r");
if fileID == -1 || fileID2 == -1 || fileID3 == -1
    error('Error opening file');
end
j=1;
while j<6
    gd = [];
    sgd = [];
    adam = [];
    i = 1;
    while ~feof(fileID)
        line = fgets(fileID);
        if contains(line, "stop")
            break;
        end
        gd(i)= str2double(line);
        i= i+1;
    end
    time1 = linspace(0, str2double(fgets(fileID)), length(gd));
    i=1;
    while ~feof(fileID2)
        line = fgets(fileID2);
        if contains(line, "stop")
            break;
        end
        sgd(i)= str2double(line);
        i= i+1;
    end
    time2 = linspace(0, str2double(fgets(fileID2)), length(sgd));
    i=1;
    while ~feof(fileID3)
        line = fgets(fileID3);
        if contains(line, "stop")
            break;
        end
        adam(i)= str2double(line);
        i= i+1;
    end
    time3 = linspace(0, str2double(fgets(fileID3)), length(adam));
    
    figure;
    
    plot(gd, '-o', 'Color', 'b', 'LineWidth', 2);
    hold on;

    plot(sgd, '-o', 'Color', 'r', 'LineWidth', 2);
    hold on;

    plot(adam, '-o', 'Color', 'g', 'LineWidth', 2);
    hold off;

    xlabel("epoch");
    ylabel("loss");

    legend("gd", "sgd", "adam", "GD", "SGD", "ADAM");
    title(['epoch vs loss ' num2str(j)]);
    figure;
    
    plot(time1, gd, 'o-', "Color", "b",'LineWidth', 2);
    hold on;
    
    plot(time2, sgd, 'o-', "Color", "r", 'LineWidth', 2);
    hold on;
    
    plot(time3, adam, 'o-', "Color", "g", 'LineWidth', 2);
    hold off;
    
    xlabel("time");
    ylabel("loss");
    legend("gd", "sgd", "adam", "GD", "SGD", "ADAM");
    title(['time vs loss ' num2str(j)]);
    j = j+1;
end
fclose(fileID);
fclose(fileID2);
fclose(fileID3);
import matplotlib.pyplot as plt

def plot_confussion_matrix(cm, color_map = plt.cm.Blues):
        
    plt.imshow(cm, interpolation = 'nearest', cmap = color_map)
    plt.title("deneme")
    plt.colorbar()
    tick_marks = range(2) ## we have got only 2 classes
    plt.xticks(tick_marks, ['team_1', 'team_2'], rotation = 45)
    plt.yticks(tick_marks, ['team_1', 'team_2'])
        
    for i in range(2):
        for j in range(2):
            plt.text(j, i, format(cm[i][j], 'd'), 
                 horizontalalignment = "center", color= "white")
        
    plt.ylabel('True label')
    plt.xlabel('Predicted label')
    plt.tight_layout()
    
    plt.show()
    
    return    
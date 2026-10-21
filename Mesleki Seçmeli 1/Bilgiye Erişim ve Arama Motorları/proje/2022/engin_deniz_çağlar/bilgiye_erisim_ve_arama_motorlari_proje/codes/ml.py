import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay
from sklearn.metrics import accuracy_score, precision_score, recall_score, cohen_kappa_score, f1_score

from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.neighbors import KNeighborsClassifier
from xgboost import XGBClassifier

X = np.load("X.npy")
y = np.load("y.npy")

def classify(test_ratio, classifier):

    test_ratio = 1 - (int(test_ratio)/100)
    classifier = classifier - 1

    # Train test split
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=test_ratio, random_state=42)


    # ML Algorithms
    if classifier==0: # SVC
        svc_clf = SVC(C=0.1, gamma= 1, kernel='linear')
        svc_clf.fit(X_train, y_train)
        y_predicted = svc_clf.predict(X_test)

    elif classifier == 1: # Decision Tree
        dtree_clf = DecisionTreeClassifier(criterion='entropy', splitter='best', max_depth=15)
        dtree_clf.fit(X_train, y_train)
        y_predicted = dtree_clf.predict(X_test)

    elif classifier == 2: # Random Forest
        ran_forest = RandomForestClassifier(n_estimators=100, criterion='entropy')
        ran_forest.fit(X_train, y_train)
        y_predicted = ran_forest.predict(X_test)

    elif classifier == 3: # KNN
        knn = KNeighborsClassifier(n_neighbors=10)
        knn.fit(X_train, y_train)
        y_predicted = knn.predict(X_test)

    elif classifier == 4: # XGB
        xgb_clf = XGBClassifier(max_depth=20, min_child_weight=5, gamma=0.5, use_label_encoder=False)
        xgb_clf.fit(X_train, y_train)
        y_predicted = xgb_clf.predict(X_test)


    cm = confusion_matrix(y_test, y_predicted)
    disp_cm = ConfusionMatrixDisplay(confusion_matrix=cm)
    disp_cm.plot()
    plt.savefig("conf.png", dpi=70)

    a = ("Accuracy: ",str(accuracy_score(y_test, y_predicted)))
    b = ("Recall: ",recall_score(y_test, y_predicted, average = 'macro'))
    c = ("Precision: ",precision_score(y_test, y_predicted, average ='macro'))
    d = ("F1 Score : ",f1_score(y_test, y_predicted, average='macro'))
    e = ("Cohens Kappa : ",cohen_kappa_score(y_test, y_predicted))


    return (str(a)+"\n"+str(b)+"\n"+str(c)+"\n"+str(d)+"\n"+str(e))

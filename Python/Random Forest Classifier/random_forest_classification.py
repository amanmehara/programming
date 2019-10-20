# Classification Template

# Importing the Libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

#importing the dataset
dataset = pd.read_csv('Social_Network_Ads.csv')
X = dataset.iloc[:,[2,3]].values
y = dataset.iloc[:, 4].values

#splitting data set into test set and training set
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.25, random_state = 0)

#feature scaling
#we dont always need to do this
from sklearn.preprocessing import StandardScaler
sc_X = StandardScaler()
X_train = sc_X.fit_transform(X_train)
X_test = sc_X.transform(X_test)

# Fitting the Classifier to the training set
from sklearn.ensemble import RandomForestClassifier
classifier = RandomForestClassifier(n_estimators = 10, criterion='entropy', random_state = 0)
classifier.fit(X_train,y_train)

# Predicting the Test set Results
y_pred = classifier.predict(X_test)

# Making the confusion Matrix. This is to check if the classification model is doing a good job or not.
from sklearn.metrics import confusion_matrix
cm = confusion_matrix(y_test,y_pred)

# Visualising the Trainnig set results
from matplotlib.colors import ListedColormap
X_set,y_set = X_train,y_train
X1, X2 = np.meshgrid(np.arange(start = X_set[:, 0].min()-1, stop = X_set[:, 0].max() + 1, step = 0.01), 
                     np.arange(start = X_set[:, 1].min()-1, stop = X_set[:, 1].max() + 1, step = 0.01)) #Look it up on GeeksforGeeks
#plt.grid(True,color = 'K')
plt.contourf(X1,X2, classifier.predict(np.array([X1.ravel(),X2.ravel()]).T).reshape(X1.shape), alpha = 0.75, 
             cmap = ListedColormap(('orange','green')))

plt.xlim(X1.min(),X1.max())
plt.ylim(X2.min(),X2.max())
 
for i,j in enumerate(np.unique(y_set)): #Look enumerate on geeks and unique on tutorialspoint
    plt.scatter(X_set[y_set == j, 0], X_set[y_set == j, 1], c = ListedColormap(('red','green'))(i),label = j)
        
plt.title('Random Forest Classification (Training Set)')
plt.xlabel('Age')
plt.ylabel('Estimated Salary')
plt.legend() #This is to make the Label Visible on the top right corner of the Graph
plt.show()


# Visualising the test set results
from matplotlib.colors import ListedColormap
X_set,y_set = X_test,y_test
X1, X2 = np.meshgrid(np.arange(start = X_set[:, 0].min()-1, stop = X_set[:, 0].max() + 1, step = 0.01), 
                     np.arange(start = X_set[:, 1].min()-1, stop = X_set[:, 1].max() + 1, step = 0.01)) #Look it up on GeeksforGeeks
#plt.grid(True,color = 'K')
plt.contourf(X1,X2, classifier.predict(np.array([X1.ravel(),X2.ravel()]).T).reshape(X1.shape), alpha = 0.75, 
             cmap = ListedColormap(('orange','green')))

plt.xlim(X1.min(),X1.max())
plt.ylim(X2.min(),X2.max())
 
for i,j in enumerate(np.unique(y_set)): #Look enumerate on geeks and unique on tutorialspoint
    plt.scatter(X_set[y_set == j, 0], X_set[y_set == j, 1], c = ListedColormap(('red','green'))(i),label = j)
        
plt.title('Random Forest Classification (Test Set)')
plt.xlabel('Age')
plt.ylabel('Estimated Salary')
plt.legend() #This is to make the Label Visible on the top right corner of the Graph
plt.show()
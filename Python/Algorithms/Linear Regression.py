#!/usr/bin/env python
# coding: utf-8

# In[ ]:


'''
Copyright [2020] [Satyajeet Narayan]
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
'''

#importing the necessary libraries
import numpy as np
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

#creating the object of linearRegression
reg= LinearRegression()

#loading the dataset
dataset= pd.read_excel("Regression.xlsx", sheet_name="Linear Regression")

    
#getting some insigts about the data
dataset.head()
dataset.isnull().sum()
dataset.describe()
dataset.corr()

#defining a function to which the independent variable will be passed
def reg(col_name):

#dividing the data in to x and y
    x=dataset[[col_name]]
    y=dataset[['price']]
    
#dividing the dataset into traing set(70% of the whole dataset) and testing set(30% of the whole dataset)   
    x_train,x_test,y_train,y_test= train_test_split(x,y,test_size=0.3,random_state=10)
    

#fitting the model
    reg.fit(x_train,y_train)

#predicting on the unseen data (x_test)
    prediction= reg.predict(x_test)
    
#getting the RMSE value and r2 score
    RMSE=np.sqrt(mean_squared_error(y_test,prediction))
    r2=r2_score(y_test, prediction)
    
#printing the RMSE value and r2 score 
    print("R Sqaure value is", r2)
    print("Root mean square is ", RMSE)
    
#getting the estimated salary and printing it
    unseen_pred=reg.predict(np.array([[2]]))
    print("The estiamted salary is",unseen_pred)


#calling the reg function and passing 'bedrooms' as the independent variable
reg('bedrooms')


'''Note:
Most of the EDA part is not shown as the purpose is only to get the essence of Linear Regression '''


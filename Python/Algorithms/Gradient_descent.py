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

import sklearn
from sklearn.datasets import make_regression
import numpy as np
import matplotlib.pyplot as plt

#Creating the  dataset
X,y = make_regression(n_samples=60,n_features=1,noise=7)

#Visualizing the data
plt.scatter(X,y)
plt.show()

def gradientDescent(x, y, theta, alpha, m, Iterations):
    X = x.transpose()
    for i in range(0, Iterations):
        hypothesis = np.dot(x, theta)
        loss = (hypothesis) - y
        # avg cost per example (the 2 in 2*m doesn't really matter here.
        # But to be consistent with the gradient, I include it)
        cost = np.sum(loss ** 2) / (2 * m)
        print("After Iteration %d | Cost: %f" % (i, cost))
        # avg gradient per example
        gradient = np.dot(X, loss) / m
        # update
        theta = theta - alpha * gradient
    return theta
theta = gradientDescent(X,y,np.random.rand(1),0.4,60,30)

#Visualizing the results
plt.scatter(X,y)
x = np.linspace(-3,3,60)
y = theta[0]*x + 1
plt.plot(x,y)
plt.show



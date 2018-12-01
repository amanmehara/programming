"""
    Neural network from scratch
"""

import numpy as np


def sigmoid(x, derivative=False):
    """
        Sigmoid function
    """
    if(derivative):
        return x * (1 - x)

    return 1 / (1 + np.exp(-x))


def relu(x, derivative=False):
    if (derivative):
        return 1. * (x > 0)
    return x * (x > 0)


def tanh(x, derivative=False):
    if derivative:
        return 1. - x * x
    return np.tanh(x)

X = np.array([[1, 0, 1, 1, 1, 0, 1, 1, 1, 0], [1, 0, 0, 1, 1, 1, 0, 0, 0, 0],
             [0, 1, 1, 0, 1, 1, 0, 1, 1, 0]])

Y = np.array([[1], [0], [1]])

epochs = 15000
w0 = 2 * np.random.random((10, 5)) - 2
w1 = 2 * np.random.random((5, 3)) - 2
w2 = 2 * np.random.random((3, 1)) - 2

bias_layer1 = np.random.random((1, 5))
bias_layer2 = np.random.random((1, 3))
bias_layer3 = np.random.random((1, 1))

print bias_layer1
print bias_layer2
print bias_layer3

for j in xrange(epochs):

    layer0 = X
    layer1 = sigmoid(np.dot(layer0, w0) + bias_layer1)
    layer2 = relu(np.dot(layer1, w1) + bias_layer2)
    layer3 = sigmoid(np.dot(layer2, w2) + bias_layer3)

    layer3_error = Y - layer3

    if j % 1000 == 0:
        print 'Error', np.mean(np.abs(layer3_error))

    layer3_delta = layer3_error * sigmoid(layer3, derivative=True)

    layer2_error = layer3_delta.dot(w2.T)
    layer2_delta = layer2_error * sigmoid(layer2, derivative=True)

    layer1_error = layer2_delta.dot(w1.T)
    layer1_delta = layer1_error * sigmoid(layer1, derivative=True)

    w2 += layer2.T.dot(layer3_delta)
    w1 += layer1.T.dot(layer2_delta)
    w0 += layer0.T.dot(layer1_delta)

    bias_layer3 += np.sum(layer3_delta)
    bias_layer2 += np.sum(layer2_delta)
    bias_layer1 += np.sum(layer1_delta)
print 'Final output:'
print layer3
print 'Final Weights'
print w2
print w1
print w0
print 'Final Biases'
print bias_layer1
print bias_layer2
print bias_layer3

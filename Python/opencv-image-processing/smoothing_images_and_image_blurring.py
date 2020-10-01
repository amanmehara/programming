import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread('lena.jpg')
img = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)


kernel = np.ones((5,5),np.float32)/25

dst = cv2.filter2D(img,-1,kernel)

blur = cv2.blur(img,(5,5))

guassian_blur = cv2.GaussianBlur(img,(5,5),0)

median_blur = cv2.medianBlur(img,5)#to remove salt_and_pepper_noise

bilateralFilter = cv2.bilateralFilter(img,9, 75,75)

titles = ['images','2D Convolution','blur','Gaussian Blur','median','bilateralFilter']
images= [ img,dst,blur,guassian_blur, median_blur,bilateralFilter]





for i in range(len(images)):
    plt.subplot(2,3,i+1)
    plt.imshow(images[i],cmap='gray')
    plt.title(titles[i])
    plt.xticks([]),plt.yticks([])

plt.show()

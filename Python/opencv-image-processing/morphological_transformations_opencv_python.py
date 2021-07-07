import cv2
import numpy as np
from matplotlib import pyplot as plt


img = cv2.imread('images\smarties.png', cv2.IMREAD_GRAYSCALE)
_,mask = cv2.threshold(img,220,255,cv2.THRESH_BINARY_INV)

kernel = np.ones((5,5),np.uint8)

dilation = cv2.dilate(mask,kernel = kernel, iterations = 2)

erosion = cv2.erode(mask,kernel,iterations= 1)

opening = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)

closing = cv2.morphologyEx(mask,cv2.MORPH_CLOSE,kernel)

morphological_gradient = cv2.morphologyEx(mask,cv2.MORPH_GRADIENT,kernel)

top_Hat = cv2.morphologyEx(mask,cv2.MORPH_TOPHAT,kernel)
                                          

                                          
titles = ['image','mask','Dilation','erosion','opening','closing','morphological_gradient','top_Hat']
images = [img,mask,dilation,erosion,opening,closing,morphological_gradient,top_Hat]

for i in range(8):
    plt.subplot(2,4,i+1)
    plt.imshow(images[i],cmap='gray')
    plt.title(titles[i])
    plt.xticks([]),plt.yticks([])

plt.show()

import cv2,numpy as np
img=cv2.imread('traf.jpg')

low=np.array([0,0,0])
high=np.array([50,50,255])
mask=cv2.inRange(img,low,high)

h,w,c=img.shape

roi=img[0:50,0:150]

mask=cv2.inRange(roi,low,high)
print(h,w,c)

res=cv2.bitwise_and(roi,roi,mask=mask)

cv2.imshow('mas',mask)
cv2.imshow('result',res)
#cv2.imshow('img')

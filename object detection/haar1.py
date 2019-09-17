import cv2,pygame,numpy as np
fcas=cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
ecas=cv2.CascadeClassifier('haarcascade_eye.xml')

img=cv2.imread('face.jpg')
gray=cv2.imread('face.jpg',0)

faces=fcas.detectMultiScale(gray,1.3,5)
print(faces)
for x,y,w,h in faces:
    cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,255),2)
    roi=img[y:y+h,x:x+w]
    roig=gray[y:y+h,x:x+w]
    eyes=ecas.detectMultiScale(roig,2,5)
    for ex,ey,ew,eh in eyes:
        cv2.rectangle(roi,(ex,ey),(ex+ew,ey+eh),(0,255,0),2)
        
        cv2.imshow('face',img)
        print(eyes)

print(len(faces))

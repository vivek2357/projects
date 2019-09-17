import cv2,numpy as np
a=cv2.VideoCapture(0)
while True:
    _,f=a.read()
    hsv=cv2.cvtColor(f,cv2.COLOR_BGR2HSV)
    l=np.array([0,0,0])
    h=np.array([180,255,150])
    m=cv2.inRange(hsv,l,h)
    mi=cv2.bitwise_not(m)
    r=cv2.bitwise_and(hsv,hsv,mask=mi)

    k=np.ones((5,5),np.float32)
    blur=cv2.filter2D(r,-1,k)
    e=cv2.erode(m,k,iterations=1)
    cv2.imshow('e',blur)
    cv2.imshow('mask',mi)
    #cv2.imshow('hsv',hsv)
    cv2.imshow('r',r)
    if cv2.waitKey(1) & 0xFF==ord('q'):
        break


a.release()
cv2.destroyAllWindows()


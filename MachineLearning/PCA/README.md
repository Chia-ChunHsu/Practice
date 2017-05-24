# PCA

## Brief
A PCA Application Using and Testing Based On OPENCV PCA Tutorial Created a simple using PCA Class. You can only using _mypca.h_ and _mypca.cpp_ to implement the function shown on OPENCV. __Class similarPCA__ is written for comparison the similarity between two Principle Component. __Class PCAAxis__ is written as a container to storage the vector released form PC1 and PC2

## Lib
OpenCV 3.2.0

## File
class myPCA

class PCAAxis

class SimilarPCA   

### myPCA
is a class which is reviesd from OpenCV

### PCAAxis
a container to storage the vector of Principle Component.

### similarPCA
this class is using to compare the difference between each PCs.
The goal of this class is to find the similar Objects in the image.
The interesting point is the similar PCs. In other words, we delete those PCs which is quite different to other.


## Reference:
[OPENCV Tutorial][1]


[1]: http://docs.opencv.org/3.2.0/d1/dee/tutorial_introduction_to_pca.html  "OPENCV PCA Tutorial"

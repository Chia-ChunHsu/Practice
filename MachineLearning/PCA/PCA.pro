#-------------------------------------------------
#
# Project created by QtCreator 2017-05-23T13:17:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PCA
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    mypca.cpp \
    similarpca.cpp \
    pcaaxis.cpp \
    limitpoint.cpp

HEADERS  += mainwindow.h \
    mypca.h \
    similarpca.h \
    pcaaxis.h \
    limitpoint.h

FORMS    += mainwindow.ui
#INCLUDEPATH += $$quote(D:\Lib\OpenCVBinaries-master\opencv\include)\
#               $$quote(D:\Lib\OpenCVBinaries-master\opencv\include\opencv2)

INCLUDEPATH += $$quote(D:\opencv320_x64_vs2015\include)\
               $$quote(D:\opencv320_x64_vs2015\include\opencv2)
#OPENCVLIB += $$quote(D:\Lib\OpenCVBinaries-master\opencv\x64\vc14\lib)
OPENCVLIB += $$quote(D:\opencv320_x64_vs2015\x64\vc14\lib)
CONFIG(debug, debug|release){
LIBS+= $$OPENCVLIB/opencv_core320d.lib\
       $$OPENCVLIB/opencv_calib3d320d.lib\
       $$OPENCVLIB/opencv_highgui320d.lib\
       $$OPENCVLIB/opencv_imgcodecs320d.lib\
       $$OPENCVLIB/opencv_imgproc320d.lib\
       $$OPENCVLIB/opencv_videoio320d.lib\
       $$OPENCVLIB/opencv_objdetect320d.lib\
}

CONFIG(release, debug|release){
LIBS+= $$OPENCVLIB/opencv_core320.lib\
       $$OPENCVLIB/opencv_calib3d320.lib\
       $$OPENCVLIB/opencv_highgui320.lib\
       $$OPENCVLIB/opencv_imgcodecs320.lib\
       $$OPENCVLIB/opencv_imgproc320.lib\
       $$OPENCVLIB/opencv_videoio320.lib\
       $$OPENCVLIB/opencv_objdetect320.lib\
}

DEFINES += HAVE_OPENCV

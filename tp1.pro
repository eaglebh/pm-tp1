# Add more folders to ship with the application, here
folder_01.source = qml/tp1
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    BibtexBook.cpp \
    BibtexFormat.cpp \
    BibtexArticle.cpp \
    BibtexInproceedings.cpp \
    pages.cpp \
    authors.cpp \
    BibTexHasPages.cpp \
    util.cpp \
    bibfile.cpp \
    authorreader.cpp \
    pagesreader.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    BibtexBook.h \
    BibtexFormat.h \
    BibtexArticle.h \
    BibtexInproceedings.h \
    pages.h \
    authors.h \
    BibTexHasPages.h \
    util.h \
    bibfile.h \
    authorreader.h \
    pagesreader.h

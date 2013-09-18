#include <iostream>
#include <sstream>
#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "util.h"
#include "authorreader.h"
#include "pagesreader.h"
#include "bibfile.h"
#include "BibtexArticle.h"
#include "BibtexBook.h"
#include "BibtexInproceedings.h"
#include "bibfileio.h"
#include "mainwindow.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{

    BibfileIO fileio("file.bib");
    cout << "fileio=\n" << fileio.getBibFile()->toText() << endl;


    QApplication app(argc, argv);
    app.setOrganizationName("QtProject");
    app.setApplicationName("Application Example");
    MainWindow mainWin;
    mainWin.show();
    return app.exec();

    //    QGuiApplication app(argc, argv);
    //    QtQuick2ApplicationViewer viewer;
    //    viewer.setMainQmlFile(QStringLiteral("qml/tp1/main.qml"));
    //    viewer.showExpanded();
    //    return app.exec();
}

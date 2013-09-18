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

using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    BibfileIO fileio("file.bib");
    cout << "fileio=\n" << fileio.getBibFile()->toText() << endl;

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/tp1/main.qml"));
    viewer.showExpanded();

    return app.exec();
}

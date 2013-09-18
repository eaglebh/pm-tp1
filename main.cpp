#include <iostream>
#include <sstream>
#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "util.h"
#include "authorreader.h"
#include "pagesreader.h"

using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    cout << Util::parseInt("{123}") << endl;
    cout << Util::parseString("{456}") << endl;
    cout << Util::parseString("abcd") << endl;
    cout << Util::parseString("{efgh}") << endl;
    cout << Util::parseField("Title","Title = \"Something Great\",") << endl;
    cout << Util::parseField("Title","Title = {Something Great2},") << endl;
    AuthorReader::parseAuthors("author = \"Joe Torre and Tom Verducci\",");
    PagesReader::parsePages("author = \"Joe Torre and Tom Verducci\",pages = {1,2,3}");
    PagesReader::parsePages("pages = {1-5,8,9,20-22}");

    //Util::test();

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/tp1/main.qml"));
    viewer.showExpanded();

    return app.exec();
}

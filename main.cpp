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

    BibtexArticle* book = new BibtexArticle();
    book->setReference("myref");
    book->setTitle("mytitle");
    book->setYear(2013);
    Authors authors;
    authors.addAuthor("autor1");
    authors.addAuthor("autor2");
    book->setAuthors(authors);
    book->setJournal("jornal1");
    book->setNumber(1);
    book->setVolume(2);
    Pages pages;
    pages.addPage(12);
    pages.addPage(13);
    book->setPages(pages);
    BibFile bibFile;
    bibFile.createBibtex(book);
    cout << bibFile.toText() << endl;

    Util::test();

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/tp1/main.qml"));
    viewer.showExpanded();

    return app.exec();
}

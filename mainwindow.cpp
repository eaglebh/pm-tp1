#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bibfileio.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lwAllBibtex->setModel(&model);
    QItemSelectionModel *selectionModel= ui->lwAllBibtex->selectionModel();
    connect(selectionModel, SIGNAL(selectionChanged (const QItemSelection &, const QItemSelection &)),
            this, SLOT(selectionChangedSlot(const QItemSelection &, const QItemSelection &)));

    connect(ui->cbSearch, SIGNAL(currentIndexChanged (int)),
            this, SLOT(filterSelectionChanged(int)));
    connect(ui->pbSearch, SIGNAL(clicked ()),
            this, SLOT(searchButtonClicked()));

    fileio = new BibfileIO("file.bib");
}

void MainWindow::selectionChangedSlot(const QItemSelection &, const QItemSelection &)
{
    //get the text of the selected item
    const QModelIndex index = ui->lwAllBibtex->selectionModel()->currentIndex();
    QString selectedText = index.data(Qt::DisplayRole).toString();
    qDebug() << selectedText;


    try {
    BibtexFormat *bib = fileio->getBibFile()->retrieveBibtex(BibFile::SearchCriteria::REFERENCE, selectedText.toUtf8().constData());
    if(bib)
        qDebug() << bib->getRequiredFieldsText().c_str();
    } catch(char const* msg) {
        qDebug() << "ERRO: " << msg;
    }
}

void MainWindow::filterSelectionChanged(int index)
{
    qDebug() << "mudou para" << index;
}

void MainWindow::showAllBibtex(QStandardItem *rootNode)
{
    list<BibtexFormat*> bibs = fileio->getBibFile()->getBibs();
    list<BibtexFormat*>::const_iterator findIter = bibs.begin();
    for(;findIter != bibs.end(); findIter++) {
        BibtexFormat* bib = *findIter;
        QStandardItem *item = new QStandardItem(bib->getReference().c_str());
        rootNode->appendRow(item);
    }
}

void MainWindow::showOneBibtex(QStandardItem *rootNode)
{
    QStandardItem *item = new QStandardItem(fileio->getBibFile()->retrieveBibtex(static_cast<BibFile::SearchCriteria>(ui->cbSearch->currentIndex()), ui->leQuery->text().toUtf8().constData())->getReference().c_str());
    rootNode->appendRow(item);
}

void MainWindow::searchButtonClicked()
{
    model.clear();
    QStandardItem *rootNode = model.invisibleRootItem();
    switch (static_cast<BibFile::SearchCriteria>(ui->cbSearch->currentIndex())) {
    case BibFile::SearchCriteria::ALL:
        showAllBibtex(rootNode);
        break;
    case BibFile::SearchCriteria::AUTHOR:
        showOneBibtex(rootNode);
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

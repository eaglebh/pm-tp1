#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bibfileio.h"
#include <QMessageBox>
#include "pagesreader.h"
#include "authorreader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lwAllBibtex->setModel(&model);
    QItemSelectionModel *selectionModel= ui->lwAllBibtex->selectionModel();
    connect(selectionModel, SIGNAL(selectionChanged (const QItemSelection &, const QItemSelection &)),
            this, SLOT(selectionChangedSlot(const QItemSelection &, const QItemSelection &)));

    connect(ui->cbSearch, SIGNAL(currentIndexChanged (int)), this, SLOT(filterSelectionChanged(int)));
    connect(ui->pbSearch, SIGNAL(clicked ()), this, SLOT(searchButtonClicked()));
    connect(ui->pbSave, SIGNAL(clicked ()), this, SLOT(saveButtonClicked()));
    connect(ui->pbRemove, SIGNAL(clicked ()), this, SLOT(removeButtonClicked()));

    fileio = new BibfileIO("file.bib");
}

void MainWindow::selectionChangedSlot(const QItemSelection &, const QItemSelection &)
{
    //get the text of the selected item
    const QModelIndex index = ui->lwAllBibtex->selectionModel()->currentIndex();
    QString selectedText = index.data(Qt::DisplayRole).toString();
    qDebug() << selectedText;

    hideAllInputs();

    try {
        BibtexFormat *bib = fileio->getBibFile()->retrieveBibtex(BibFile::SearchCriteria::REFERENCE, selectedText.toUtf8().constData());
        if(bib) {
            qDebug() << bib->getRequiredFieldsText().c_str();
        }
        if(BibtexArticle::TYPE.compare(bib->getType()) == 0){
            showArticleInputs();
            ui->leJournal->setText(((BibtexArticle*)bib)->getJournal().c_str());
            ui->leVolume->setText(QString::number(((BibtexArticle*)bib)->getVolume()));
            ui->leNumber->setText(QString::number(((BibtexArticle*)bib)->getNumber()));
            ui->lePages->setText(Pages::getPagesText(((BibtexArticle*)bib)->getPages()).c_str());
        } else {
            if(BibtexBook::TYPE.compare(bib->getType()) == 0){
                showBookInputs();
                ui->lePublisher->setText(((BibtexBook*)bib)->getPublisher().c_str());
            } else {
                if(BibtexInproceedings::TYPE.compare(bib->getType()) == 0){
                    showInproceedingsInputs();
                    ui->leBookTitle->setText(((BibtexInproceedings*)bib)->getBooktitle().c_str());
                    ui->lePages->setText(Pages::getPagesText(((BibtexInproceedings*)bib)->getPages()).c_str());
                }
            }
        }
        ui->leAuthor->setText(bib->getAuthors().getAuthorsText().c_str());
        ui->leTitle->setText(bib->getTitle().c_str());
        ui->leYear->setText(QString::number(bib->getYear()));
        ui->leReference->setText(bib->getReference().c_str());
    } catch(char const* msg) {
        qDebug() << "ERRO: " << msg;
    }
}

void MainWindow::hideAllInputs(){
    ui->leJournal->setVisible(false);
    ui->leVolume->setVisible(false);
    ui->leNumber->setVisible(false);
    ui->lePages->setVisible(false);
    ui->lePublisher->setVisible(false);
    ui->leBookTitle->setVisible(false);
    ui->lePages->setVisible(false);
    ui->lbJournal->setVisible(false);
    ui->lbVolume->setVisible(false);
    ui->lbNumber->setVisible(false);
    ui->lbPages->setVisible(false);
    ui->lbPublisher->setVisible(false);
    ui->lbBookTitle->setVisible(false);
    ui->lbPages->setVisible(false);
}

void MainWindow::showArticleInputs(){
    ui->leJournal->setVisible(true);
    ui->leVolume->setVisible(true);
    ui->leNumber->setVisible(true);
    ui->lePages->setVisible(true);
    ui->lbJournal->setVisible(true);
    ui->lbVolume->setVisible(true);
    ui->lbNumber->setVisible(true);
    ui->lbPages->setVisible(true);
    showBasicInputs();
}


void MainWindow::showBookInputs(){
    ui->lePublisher->setVisible(true);
    ui->lbPublisher->setVisible(true);
    showBasicInputs();
}

void MainWindow::showBasicInputs(){
    ui->leAuthor->setVisible(true);
    ui->leTitle->setVisible(true);
    ui->leYear->setVisible(true);
    ui->leReference->setVisible(true);
    ui->lbAuthor->setVisible(true);
    ui->lbTitle->setVisible(true);
    ui->lbYear->setVisible(true);
    ui->lbReference->setVisible(true);
}

void MainWindow::showInproceedingsInputs(){
    ui->leBookTitle->setVisible(false);
    ui->lePages->setVisible(false);
    ui->lbBookTitle->setVisible(false);
    ui->lbPages->setVisible(false);
    showBasicInputs();
}


void MainWindow::filterSelectionChanged(int index)
{
    qDebug() << "mudou para" << index;
}

void MainWindow::filterAllBibtex(QStandardItem *rootNode)
{
    list<BibtexFormat*> bibs = fileio->getBibFile()->getBibs();
    list<BibtexFormat*>::const_iterator findIter = bibs.begin();
    for(;findIter != bibs.end(); findIter++) {
        BibtexFormat* bib = *findIter;
        QStandardItem *item = new QStandardItem(bib->getReference().c_str());
        rootNode->appendRow(item);
    }
}

void MainWindow::filterOneBibtex(QStandardItem *rootNode)
{
    try {
        QStandardItem *item = new QStandardItem(fileio->getBibFile()->retrieveBibtex(static_cast<BibFile::SearchCriteria>(ui->cbSearch->currentIndex()), ui->leQuery->text().toUtf8().constData())->getReference().c_str());
        rootNode->appendRow(item);
    } catch(char const* msg) {
        qDebug() << "ERRO: " << msg;
        QMessageBox::information(NULL, "PMCC-TP1", "Não encontrou BibTex");
    }
}

void MainWindow::searchButtonClicked()
{
    model.clear();
    QStandardItem *rootNode = model.invisibleRootItem();
    switch (static_cast<BibFile::SearchCriteria>(ui->cbSearch->currentIndex())) {
    case BibFile::SearchCriteria::ALL:
        filterAllBibtex(rootNode);
        break;
    default:
        filterOneBibtex(rootNode);
        break;
    }
}

void MainWindow::saveButtonClicked()
{
    fileio->persist();
    try {
        BibtexFormat *bib = fileio->getBibFile()->retrieveBibtex(BibFile::SearchCriteria::REFERENCE, ui->leReference->text().toUtf8().constData());
        if(bib) {
            qDebug() << bib->getRequiredFieldsText().c_str();
        }
        if(BibtexArticle::TYPE.compare(bib->getType()) == 0){
            ((BibtexArticle*)bib)->setJournal(ui->leJournal->text().toUtf8().constData());
            ((BibtexArticle*)bib)->setVolume(ui->leVolume->text().toInt());
            ((BibtexArticle*)bib)->setNumber(ui->leNumber->text().toInt());
            ((BibtexArticle*)bib)->setPages(*PagesReader::parsePagesFromValue(ui->lePages->text().toUtf8().constData()));
        } else {
            if(BibtexBook::TYPE.compare(bib->getType()) == 0){
                ((BibtexBook*)bib)->setPublisher(ui->lePublisher->text().toUtf8().constData());
            } else {
                if(BibtexInproceedings::TYPE.compare(bib->getType()) == 0){
                    ((BibtexInproceedings*)bib)->setBooktitle(ui->leBookTitle->text().toUtf8().constData());
                    ((BibtexInproceedings*)bib)->setPages(*PagesReader::parsePagesFromValue(ui->lePages->text().toUtf8().constData()));
                }
            }
        }
        bib->setAuthors(*AuthorReader::parseAuthorsFromValue(ui->leAuthor->text().toUtf8().constData()));
        bib->setTitle(ui->leTitle->text().toUtf8().constData());
        bib->setYear(ui->leYear->text().toInt());
        bib->setReference(ui->leReference->text().toUtf8().constData());
    } catch(char const* msg) {
        qDebug() << "ERRO: " << msg;
        QMessageBox::information(NULL, "PMCC-TP1", "Não encontrou BibTex modificado para salvar");
    }
}

void MainWindow::removeButtonClicked()
{
    try {
        BibtexFormat *bib = fileio->getBibFile()->retrieveBibtex(BibFile::SearchCriteria::REFERENCE, ui->leReference->text().toUtf8().constData());
        if(bib) {
            qDebug() << bib->getRequiredFieldsText().c_str();
        }

        fileio->getBibFile()->deleteBibtex(bib);
    } catch(char const* msg) {
        qDebug() << "ERRO: " << msg;
        QMessageBox::information(NULL, "PMCC-TP1", "Não encontrou BibTex modificado para remover");
    }
    qDebug() << fileio->getBibFile()->toText().c_str();
}

MainWindow::~MainWindow()
{
    delete ui;
    //fileio->persist();
}

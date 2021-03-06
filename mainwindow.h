#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "bibfileio.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void filterAllBibtex(QStandardItem *rootNode);
    void filterOneBibtex(QStandardItem *rootNode);
    void saveBibtex(BibtexFormat *bib);
private slots:
    void selectionChangedSlot(const QItemSelection &, const QItemSelection &);
    void saveButtonClicked();
    void removeButtonClicked();
    void createButtonClicked();
    void newButtonClicked();
public slots:
    void filterSelectionChanged(int index = 0);
    void searchButtonClicked();
private:
    Ui::MainWindow *ui;
    QStandardItemModel model;
    BibfileIO *fileio;
    void hideAllInputs();
    void showArticleInputs();
    void showBookInputs();
    void showInproceedingsInputs();
    void showBasicInputs();
    void clearAllInputs();
};

#endif // MAINWINDOW_H

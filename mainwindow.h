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

    void showAllBibtex(QStandardItem *rootNode);
    void showOneBibtex(QStandardItem *rootNode);
private slots:
    void selectionChangedSlot(const QItemSelection &, const QItemSelection &);
public slots:
    void filterSelectionChanged(int index = 0);
    void searchButtonClicked();
private:
    Ui::MainWindow *ui;
    QStandardItemModel model;
    BibfileIO *fileio;
};

#endif // MAINWINDOW_H

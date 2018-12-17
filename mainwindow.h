#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_treeWidget_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
    void loadSubWindow(QWidget *widget);
    bool serialdialogopened;
};

#endif // MAINWINDOW_H

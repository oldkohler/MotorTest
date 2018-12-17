#include "mainwindow.h"
#include <QApplication>
#include "startdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    StartDialog dlg;
    if(dlg.exec() == QDialog::Accepted)
    {
        w.showMaximized();
        return a.exec();
    }
    return 0;

}

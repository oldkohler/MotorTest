#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = nullptr);
    ~StartDialog();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::StartDialog *ui;
};

#endif // STARTDIALOG_H

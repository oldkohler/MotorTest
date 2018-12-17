#ifndef SERIALPORTDIALOG_H
#define SERIALPORTDIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
extern QString name,baud;
extern int bit,jiaoyan,stopbit;

namespace Ui {
class SerialPortDialog;
}

class SerialPortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SerialPortDialog(QWidget *parent = nullptr);
    ~SerialPortDialog();

    void find_port();
private slots:
    void on_SendDataButton_clicked();

private:
    Ui::SerialPortDialog *ui;
};

#endif // SERIALPORTDIALOG_H

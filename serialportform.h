#ifndef SERIALPORTFORM_H
#define SERIALPORTFORM_H

#include <QWidget>
#include "serialportdialog.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include <QtCore/QIODevice>
#include <QFileDialog>

namespace Ui {
class SerialPortForm;
}

class SerialPortForm : public QWidget
{
    Q_OBJECT

public:
    explicit SerialPortForm(QWidget *parent = nullptr);
    ~SerialPortForm();
    void Read_Date();       //读取串口数据

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_SaveButton_clicked();

    void on_ClosePortButton_clicked();

    void on_ClearButton_clicked();

private:
    Ui::SerialPortForm *ui;
    QVector<double> x,y;
    int i = 0;
    QSerialPort *serialport;
    SerialPortDialog *dlg =new SerialPortDialog;
    QSerialPort *serial;
    bool serialdialogopened;
};

#endif // SERIALPORTFORM_H

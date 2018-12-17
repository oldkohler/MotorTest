#include "serialportdialog.h"
#include "ui_serialportdialog.h"

QString name,baud;
int bit,jiaoyan,stopbit;
SerialPortDialog::SerialPortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialPortDialog)
{
    ui->setupUi(this);
    find_port();
    name = ui->portname->currentText();
    baud = ui->baud->currentText();
    bit = ui->bit->currentIndex();
    jiaoyan = ui->jiaoyan->currentIndex();
    stopbit = ui->stopbit->currentIndex();

}

SerialPortDialog::~SerialPortDialog()
{
    delete ui;
}

void SerialPortDialog::on_SendDataButton_clicked()
{
    name = ui->portname->currentText();
    baud = ui->baud->currentText();
    bit = ui->bit->currentIndex();
    jiaoyan = ui->jiaoyan->currentIndex();
    stopbit = ui->stopbit->currentIndex();
    this->close();
}
//查找串口
void SerialPortDialog::find_port()
{
    //查找可用的串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);   //设置串口
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->portname->addItem(serial.portName());        //显示串口name
            serial.close();
        }
    }
}

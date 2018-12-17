#include "serialportform.h"
#include "ui_serialportform.h"
#include "serialportdialog.h"
#include <QMessageBox>


SerialPortForm::SerialPortForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialPortForm)
{
    ui->setupUi(this);
    serialport = new QSerialPort;
}

SerialPortForm::~SerialPortForm()
{
    delete ui;
}

void SerialPortForm::on_pushButton_4_clicked()
{
    // create graph and assign data to it:
    ui->qCustomPlot->addGraph();
    ui->qCustomPlot->graph(0)->setData(x, y);
    ui->qCustomPlot->graph(0)->rescaleAxes();
    // give the axes some labels:
    ui->qCustomPlot->xAxis->setLabel("时间");
    ui->qCustomPlot->yAxis->setLabel("频率");
    // set axes ranges, so we see all data:

    //ui->qCustomPlot->xAxis->setRange(0, 30);
    //ui->qCustomPlot->yAxis->setRange(-1, 1);
    ui->qCustomPlot->replot();
}

void SerialPortForm::on_pushButton_clicked()
{
    SerialPortDialog *port = new SerialPortDialog(this);
    port->showNormal();
}


void SerialPortForm::on_pushButton_2_clicked()
{
    update();
    serialport->setPortName(name);
    if(serialport->open(QIODevice::ReadWrite))              //打开串口成功
    {
        serialport->setBaudRate(baud.toInt());       //设置波特率
        switch(bit)                   //设置数据位数
        {
            case 8:serialport->setDataBits(QSerialPort::Data8);break;
            default: break;
        }
        switch(jiaoyan)                   //设置奇偶校验
        {
            case 0: serialport->setParity(QSerialPort::NoParity);break;
            default: break;
        }
        switch(stopbit)                     //设置停止位
        {
            case 1: serialport->setStopBits(QSerialPort::OneStop);break;
            case 2: serialport->setStopBits(QSerialPort::TwoStop);break;
            default: break;
        }
        serialport->setFlowControl(QSerialPort::NoFlowControl);     //设置流控制
        QObject::connect(serialport,&QSerialPort::readyRead,this,&SerialPortForm::Read_Date);
    }
    else    //打开失败提示
    {
        QMessageBox::information(this,tr("Erro"),tr("串口打开错误"),QMessageBox::Ok);
    }
}
void SerialPortForm::Read_Date()
{
    QByteArray buf;
    buf = serialport->readAll();
    QString str_data,frequence,Torque;
    str_data = buf.data();
    int j;
    for(j = 0; j < str_data.length(); j++)
    {
        if(str_data[j] == 'x')
            break;
        if((str_data[j] >= '0' && str_data[j] <= '9') || str_data[j] == '.')
        frequence.append(str_data[j]);

    }
//    for(int i = j; i < str_data.length(); i++)
//    {
//        if((str_data[i] >= '0' && str_data[i] <= '9') || str_data[i] == '.')
//        Torque.append(str_data[i]);

//    }

    if(!buf.isEmpty())
        {
            x.append(i++);
            y<<frequence.toDouble();
            QString str = ui->textBrowser->toPlainText();
            str+=tr(buf);
            ui->textBrowser->clear();
            ui->textBrowser->append(str);
        }
        buf.clear();
}


void SerialPortForm::on_SaveButton_clicked()
{
    QString sFilePath=QFileDialog::getSaveFileName(this,
                                                   tr("Save File"),
                                                   "",
                                                   tr("*.txt (*.TXT)")); //选择路径
    QFile file(sFilePath);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
     QMessageBox::critical(NULL,"提示","无法创建文件");
     return;
     }
    QTextStream out(&file);
    QString str = ui->textBrowser->toPlainText();
    out<<str<<endl;//将str存进test.txt文件夹里面
    QMessageBox::information(this,"提示","保存成功");
    out.flush();
    file.close();
}

void SerialPortForm::on_ClosePortButton_clicked()
{
    serialport->clear();        //清空缓存区
    serialport->close();        //关闭串口
}

void SerialPortForm::on_ClearButton_clicked()
{
    ui->textBrowser->clear();
}

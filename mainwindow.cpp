#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QTreeWidget>
#include <QStatusBar>
#include <QLabel>
#include "serialportform.h"
#include <QMdiSubWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serialdialogopened = false;
    //TREEVIEW设置
    ui->dockWidget->setWidget(ui->treeWidget);
    ui->treeWidget->setWindowTitle("测试系统目录");
    ui->treeWidget->setHeaderLabels(QStringList()<<"项目"<<"信息");
    QTreeWidgetItem* item1 = new QTreeWidgetItem(ui->treeWidget);
    item1->setText(0,"参数设置");
    item1->setText(1,"量程和通讯");
    QTreeWidgetItem* child1 = new QTreeWidgetItem(item1);
    child1->setText(0,"通讯设置");
    child1->setText(1," ");
    item1->addChild(child1);
    QTreeWidgetItem* item2 = new QTreeWidgetItem(ui->treeWidget);
    item2->setText(0,"系统管理");

    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
//状态栏设置
    QStatusBar *SB = statusBar();
    QLabel *label = new QLabel(this);
    label->setText("电机测试系统");
    SB->addWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeWidget_itemSelectionChanged()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();
        if (item->text(0) == "参数设置")
        {
            loadSubWindow(new SerialPortForm(this));
        }

}
void MainWindow::loadSubWindow(QWidget *widget)
{
    auto window = ui->mdiArea->addSubWindow(widget);
    window->setWindowTitle(widget->windowTitle());
    window->showMaximized();
}

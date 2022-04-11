#include <QFileDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    ui->lineEdit->setText(QFileDialog::getExistingDirectory());
}

void MainWindow::on_toolButton_2_clicked()
{
    ui->lineEdit_2->setText(QFileDialog::getExistingDirectory());
}

#include <osgDB/WriteFile>
#include <osg/ProxyNode>

void MainWindow::on_pushButton_clicked()
{
    QDir containDir(ui->lineEdit->text());
    QFileInfoList fileList = containDir.entryInfoList(QDir::NoDotAndDotDot|QDir::Readable|QDir::Dirs);
    osg::ProxyNode* pGroup = new osg::ProxyNode;
    pGroup->setCenterMode(pGroup->UNION_OF_BOUNDING_SPHERE_AND_USER_DEFINED);
    pGroup->setDatabasePath(ui->lineEdit->text().toUtf8().data());
    QString sFileName;
    int nIndex=0;
    foreach(auto one,fileList)
    {
        sFileName=one.fileName()+'\\'+one.fileName()+".osgb";
        pGroup->setFileName(nIndex++,sFileName.toLocal8Bit().data());
    }

    bool bCreate=false;
    sFileName = ui->lineEdit_2->text()+"\\out.osgb";
    if(pGroup->getNumFileNames()>0)
    {
        bCreate = osgDB::writeNodeFile(*pGroup,sFileName.toLocal8Bit().data());
    }

    if(bCreate)
    {
        QMessageBox::information(nullptr,  "操作信息",  "生成成功");
    }
    else
    {
        QMessageBox::critical(nullptr,  "操作信息",  "生成失败");
    }
}

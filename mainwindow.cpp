#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httpconnect.h"
#include <QMessageBox>

QString launcherServer = "https://launcher.returnofreckoning.com/launcher.xml";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0); // Create TopLevel-Widget
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{

    HttpConnect http;
    http.getFile(launcherServer);

    QString sopa = ui->formLogin->text()+":"+ui->formPwd->text();

    QMessageBox msgBox;
    msgBox.setText(sopa);
    msgBox.exec();
}

void MainWindow::on_pushButton_clicked()
{
    QApplication::quit();
}

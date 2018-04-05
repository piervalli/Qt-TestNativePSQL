#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_psql_clicked()
{
    if(!m_db.open()) {
         QMessageBox::warning(this, tr("Warnig"),tr(qPrintable(m_db.lastError().text())),QMessageBox::Ok);
        return;
    }
    QSqlQuery query("SELECT version()",m_db);
    if(m_db.lastError().isValid()) {
        QMessageBox::critical(this, tr("Critical"),m_db.lastError().text(),QMessageBox::Ok);
    }else{
        QString vertion;
        while (query.next()) {
            vertion.append(query.value(0).toString());

        }
        QMessageBox::information(this, tr("Information"),vertion,QMessageBox::Ok);
    }

    m_db.close();
}

void MainWindow::on_pushButton_init_clicked()
{
    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName("127.0.0.1");
    m_db.setPort(5432);
    m_db.setDatabaseName("postgres");
    m_db.setUserName("postgres");
    m_db.setPassword("postgres");
    qDebug() << "error" << m_db.lastError().text();
    if(m_db.lastError().isValid())
        QMessageBox::critical(this, tr("Critical"),tr(qPrintable(m_db.lastError().text())),QMessageBox::Ok);
    QMessageBox::warning(this, tr("Warnig"),("Driver loaded!"),QMessageBox::Ok);
    ui->pushButton_init->setEnabled(false);
    ui->pushButton_psql->setEnabled(true);

}

void MainWindow::on_pushButton_esci_clicked()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, tr("Information"),("Author Piergiorgio Valli email: piervalli@gmail.com"),QMessageBox::Ok);
}

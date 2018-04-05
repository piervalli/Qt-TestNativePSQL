#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_psql_clicked();

    void on_pushButton_init_clicked();

    void on_pushButton_esci_clicked();

    void on_actionAbout_Qt_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db;
};

#endif // MAINWINDOW_H

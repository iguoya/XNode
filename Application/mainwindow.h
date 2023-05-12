#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include "host.h"
#include "monitorservice.h"
#include "command.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();
    void readStatus();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QProcess process;
    QVector<Host> hosts;
    MonitorService service;
    Command command;
};
#endif // MAINWINDOW_H

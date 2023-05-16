#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include "host.h"
#include "monitorservice.h"
#include "command.h"
#include <iostream>
#include <QStandardItemModel>
#include <QMap>

#include <nlohmann/json.hpp>
using json = nlohmann::json;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    string contact(QString client, vector<QString> servers);

    string send_message(QString msg, size_t times = 10000, size_t interval = 1000);


private slots:
    void on_pushButton_3_clicked();
    void readStatus();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel model;
    QProcess process;
//    QVector<Host> hosts;
    MonitorService service;
    QMap<QString, pair<QString, uint16_t>> hosts;
};
#endif // MAINWINDOW_H

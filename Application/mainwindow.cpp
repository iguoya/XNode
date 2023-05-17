#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&process, &QProcess::readyRead, this, &MainWindow::readStatus);

    model.setHorizontalHeaderLabels({"执行者", "IP", "端口", "任务类型", "指令内容"});
    ui->tableView->setModel(&model);

//    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //填充表格
//     ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
//     ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
//    ui->tableView->resizeColumnsToContents();

    hosts = {
        {
            "A", {"127.0.0.1", 10000}
        },
        {
            "B", {"127.0.0.1", 10001}
        },
        {
            "C", {"127.0.0.1", 10002}
        },
        {
            "D", {"127.0.0.1", 10003}
        }
    };
    //    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//平均分配列宽
    //    ui->treeWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    auto s = contact("A", {"B", "C", "D"});


    service.command(QString::fromStdString(s));
    //    const QString cmd();
    //    const QStringList args;

    //    process.startDetached("/home/tiger/MultiNode/build-NodeServer-unknown-Debug/NodeServer",
    //                  {"127.0.0.1", "8887", "A"});

    //    process.startDetached("/home/tiger/MultiNode/build-NodeClient-unknown-Debug/NodeClient",
    //                  {"127.0.0.1", "8887", "B"});

    //    process.startDetached("/home/tiger/MultiNode/build-NodeClient-unknown-Debug/NodeClient",
    //                  {"127.0.0.1", "8887", "C"});

    //    process.startDetached("/home/tiger/MultiNode/build-NodeClient-unknown-Debug/NodeClient",
    //                  {"127.0.0.1", "8887", "D"});

    //    const QStringList argsA{"-n"};
    //    const QStringList argsB{"-l"};
    //    process.start("route", argsA);
    //    process.startDetached("ls", argsB);
    //    process.startDetached("route", argsA);
}

void MainWindow::readStatus()
{
    ui->textEdit->append(process.readAll());
}


void MainWindow::on_pushButton_clicked()
{

    auto s = send_message(ui->textEdit->toPlainText(),
                          ui->spinBox_times->value(), ui->spinBox_interval->value());

    service.command(QString::fromStdString(s));
}


string MainWindow::contact(QString client, vector<QString> servers)
{
    json j;
    j["type"] = "contact";
    j["executor"]["ip"] = hosts[client].first.toStdString();
    j["executor"]["port"] = hosts[client].second;

    for(auto i = 0; i < servers.size(); ++i) {
        j["contacts"][i]["name"] = servers[i].toStdString();
        j["contacts"][i]["ip"] = hosts[servers[i]].first.toStdString();
        j["contacts"][i]["port"] = hosts[servers[i]].second;
    }
    //    model.setHorizontalHeaderLabels({"执行者", "IP", "端口", "任务类型", "指令内容"});
    model.appendRow({
                        new QStandardItem(client),
                        new QStandardItem(hosts[client].first),
                        new QStandardItem(QString::number(hosts[client].second)),
                        new QStandardItem("建立节点连接"),
                        new QStandardItem(QString::fromStdString(j.dump()))
                    });
    return j.dump();
}

string MainWindow::send_message(QString content, size_t times, size_t interval)
{
    json j;
    j["type"] = "send";
    //    j["message"] = json::parse(msg);
    j["content"] = content.toStdString();
    j["times"] = times;
    j["interval"] = interval;

    model.appendRow({
                        new QStandardItem("A"),
                        new QStandardItem("127.0.0.1"),
                        new QStandardItem("10000"),
                        new QStandardItem("节点间发送消息"),
                        new QStandardItem(QString::fromStdString(j.dump()))
                    });

    return j.dump();
}


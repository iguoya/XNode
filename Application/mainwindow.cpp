#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&process, &QProcess::readyRead, this, &MainWindow::readStatus);

    connect(&service, &MonitorService::resultReady, this, &MainWindow::handleResult);

    model = new QStandardItemModel;
    model->setHorizontalHeaderLabels({"执行者", "IP", "端口", "任务类型", "指令内容"});

    ui->tableView->horizontalHeader()->setSortIndicatorShown(true);
    ui->tableView->setModel(model);

    sendModel = new QStandardItemModel;
    sendModel->setHorizontalHeaderLabels({"序号", "发送节点", "目的节点",  "时间", "内容"});
    ui->tableViewSend->setModel(sendModel);

    hosts = {
        {
            "A", {"127.0.0.1", 10000}
        },
        {
            "B", {"127.0.0.1", 20001}
        },
        {
            "C", {"127.0.0.1", 20002}
        },
        {
            "D", {"127.0.0.1", 20003}
        }
    };
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    auto s = contact("A", {"B", "C", "D"});
    service.send(QString::fromStdString(s));
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

string MainWindow::generateMessage()
{
    int length = 500;// length: 产生字符串的长度
    char tmp;							// tmp: 暂存一个随机数
    string buffer;						// buffer: 保存返回值

    // 下面这两行比较重要:
    random_device rd;					// 产生一个 std::random_device 对象 rd
    default_random_engine random(rd());	// 用 rd 初始化一个随机数发生器 random

    for (int i = 0; i < length; i++) {
        tmp = random() % 36;	// 随机一个小于 36 的整数，0-9、A-Z 共 36 种字符
        if (tmp < 10) {			// 如果随机数小于 10，变换成一个阿拉伯数字的 ASCII
            tmp += '0';
        } else {				// 否则，变换成一个大写字母的 ASCII
            tmp -= 10;
            tmp += 'A';
        }
        buffer += tmp;
    }
    return buffer;
}



void MainWindow::handleResult(QString result)
{
    cout<<result.toStdString()<<endl;
    json j = json::parse(result.toStdString());
    sendModel->appendRow({
                        new QStandardItem(QString::number(j["sequence"].get<int>())),
                        new QStandardItem(QString::fromStdString(j["sender"].get<string>())),
                        new QStandardItem(QString::fromStdString(j["receiver"].get<string>())),
                        new QStandardItem(QString::fromStdString(j["time"].get<string>())),
                        new QStandardItem(QString::fromStdString(j["content"].get<string>()))
                    });
}


void MainWindow::on_pushButton_clicked()
{
    QString message;
    if(ui->textEdit->toPlainText().isEmpty()) {
        message = QString::fromStdString(generateMessage());
    } else {
        message = ui->textEdit->toPlainText();
    }
    auto s = send_message(message, ui->spinBox_times->value(), ui->spinBox_interval->value());

    service.send(QString::fromStdString(s));
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
    model->appendRow({
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

    model->appendRow({
                        new QStandardItem("A"),
                        new QStandardItem("127.0.0.1"),
                        new QStandardItem("10000"),
                        new QStandardItem("节点间发送消息"),
                        new QStandardItem(QString::fromStdString(j.dump()))
                    });

    return j.dump();
}


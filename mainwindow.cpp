#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QList"
#include "QStringListModel"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto model = new QStringListModel(this);
    ui->listHistory->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_0_clicked()
{
    ui->pole->setText(ui->pole->text()+"0");
    QString nol = ui->pole->text();
    double nuull = nol.toDouble();
    if(nuull==0 && nol=="0."){
        ui->pole->setText("0");
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    ui->pole->setText(ui->pole->text()+"1");
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->pole->setText(ui->pole->text()+"2");
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->pole->setText(ui->pole->text()+"3");
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->pole->setText(ui->pole->text()+"4");
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->pole->setText(ui->pole->text()+"5");
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->pole->setText(ui->pole->text()+"6");
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->pole->setText(ui->pole->text()+"7");
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->pole->setText(ui->pole->text()+"8");
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->pole->setText(ui->pole->text()+"9");
}


void MainWindow::on_pushButton_DEL_clicked()
{
    ui->pole->setText("");
}


void MainWindow::on_pushButton_plus_clicked()
{
    MainWindow::readText();
    delat = 1;
}

void MainWindow::on_pushButton_ravno_clicked()
{
    QString stroka = ui->pole->text();
    number2 = stroka.toDouble();
    if(delat == 1){
        otvet = number1 + number2;
        addHistory("+");
    }
    if(delat==2){
        otvet = number1 - number2;
        addHistory("-");
    }
    if(delat==3){
        otvet = number1 * number2;
        addHistory("*");
    }
    if (delat==4){
        if(number2==0){
            ui->pole->setText("ERROR");
            return;
        }
        otvet = number1 / number2;
        addHistory("/");
    }
    if(delat == 0){
        otvet = 0;
    }

    ui->pole->setText(QString::number(otvet));


}

void MainWindow::on_pushButton_min_clicked()
{
    MainWindow::readText();
    delat = 2;
}

void MainWindow::on_pushButton_umnoj_clicked()
{
    MainWindow::readText();
    delat = 3;
}

void MainWindow::on_pushButton_delit_clicked()
{
    MainWindow::readText();
    delat = 4;
}

void MainWindow::readText()
{
    QString stroka = ui->pole->text();
    number1 = stroka.toDouble();
    ui->pole->setText("");
}

void MainWindow::on_pushButton_DEL_2_clicked()
{
    QString num = ui->pole->text();
    ui->pole->setText(QString::number(num.toDouble() * -1));


}

void MainWindow::on_pushButton_zapitushka_clicked()
{
    QString chslo = ui->pole->text();

    if(chslo.isEmpty()){
        ui->pole->setText("0.");
        return;
    }
    if(chslo.contains(".")){
        ui->pole->setText(chslo);
        return;
    }
    if(!chslo.contains(".")){
        ui->pole->setText(chslo+".");
        return;
    }
}

void MainWindow::on_pushButton_DEL_3_clicked()
{
    QString str = ui->pole->text();
    str.chop(1);
    ui->pole->setText(str);
}

void MainWindow::on_pushButton_MS_clicked()
{
    QString str = ui->pole->text();
    auto model = new QStringListModel(this);
    QStringList List;
    List << str;
    model->setStringList(List);
    ui->listMemory->setModel(model);
    memory = str.toDouble();
    ui->pushButton_MC->setEnabled(true);
    ui->pushButton_MR->setEnabled(true);

}

void MainWindow::on_pushButton_MC_clicked()
{
    ui->listMemory->model()->removeRow(0);
    memory = 0;
    ui->pushButton_MC->setEnabled(false);
    ui->pushButton_MR->setEnabled(false);
}

void MainWindow::on_pushButton_Mplus_clicked()
{
    QString str = ui->pole->text();
    double num = str.toDouble();
    memory = memory + num;
    auto model = new QStringListModel(this);
    QStringList List;
    List << QString::number(memory);
    model->setStringList(List);
    ui->listMemory->setModel(model);
}

void MainWindow::on_pushButton_Mmin_clicked()
{
    QString str = ui->pole->text();
    double num = str.toDouble();
    memory = memory - num;
    auto model = new QStringListModel(this);
    QStringList List;
    List << QString::number(memory);
    model->setStringList(List);
    ui->listMemory->setModel(model);
}

void MainWindow::on_pushButton_MR_clicked()
{
    ui->pole->setText(QString::number(memory));
}

void MainWindow::addHistory(QString znak)
{
    ui->pushButton_DelHistory->setEnabled(true);
    QString otvetS = QString::number(number1,'G') + " " + znak + " " + QString::number(number2) + " = " + QString::number(otvet);
    ui->listHistory->model()->insertRow(0);
    QModelIndex index = ui->listHistory->model()->index(0,0);
    ui->listHistory->model()->setData(index,otvetS);
}

void MainWindow::on_listHistory_clicked(const QModelIndex &index)
{

    QString str = index.data().toString();
    int x = str.indexOf("=")+2;
    str = str.right(str.length()-x);
    ui->pole->setText(str);

}


void MainWindow::on_pushButton_DelHistory_clicked()
{
    auto model = new QStringListModel(this);
    QStringList List;
    model->setStringList(List);
    ui->listHistory->setModel(model);
    ui->pushButton_DelHistory->setEnabled(false);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double number1;
    double number2;
    int delat = 0;
    double otvet;
    double memory = 0;


private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_DEL_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_ravno_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_umnoj_clicked();

    void on_pushButton_delit_clicked();

    void readText();

    void on_pushButton_DEL_2_clicked();

    void on_pushButton_zapitushka_clicked();

    void on_pushButton_DEL_3_clicked();

    void on_pushButton_MS_clicked();

    void on_pushButton_MC_clicked();

    void on_pushButton_Mplus_clicked();

    void on_pushButton_Mmin_clicked();

    void on_pushButton_MR_clicked();

    void addHistory(QString);

    void on_listHistory_clicked(const QModelIndex &index);

    void on_pushButton_DelHistory_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_clicked();

    void on_l00_clicked();
    void on_l01_clicked();
    void on_l02_clicked();
    void on_l10_clicked();
    void on_l11_clicked();
    void on_l12_clicked();
    void on_l20_clicked();
    void on_l21_clicked();
    void on_l22_clicked();

public:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QRadioButton *player1;
    QRadioButton *player2;
    QPushButton *pushButton;
    QPushButton *l00;
    QPushButton *l10;
    QPushButton *l20;
    QPushButton *l21;
    QPushButton *l11;
    QPushButton *l01;
    QPushButton *l22;
    QPushButton *l12;
    QPushButton *l02;
    QLabel *win;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *pvp;
    QLabel *label_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(403, 435);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("*{\n"
"	background: rgb(0,0,0);\n"
"	color: rgb(255, 209, 0);\n"
"}\n"
"\n"
"QPushButton{\n"
"	border: 1px solid rgb(255, 209, 0);\n"
"	background: black;\n"
"	color: rgb(255, 209, 0);\n"
"}\n"
"\n"
"QPushButton[id=\"1\"]{\n"
"	color: rgb(0, 231, 255);\n"
"}\n"
"\n"
"#pushButton[id=\"1\"], #pushButton[id=\"2\"]{\n"
"	color: rgb(255, 209, 0);\n"
"}\n"
"\n"
"QPushButton[id=\"2\"]{\n"
"	color:rgb(102, 255, 0);\n"
"}\n"
"\n"
"#pushButton{\n"
"	border: 2px solid rgb(255, 209, 0);\n"
"	border-radius: 20px;\n"
"	padding: 10px;\n"
"	background: black;\n"
"}\n"
"\n"
"QPushButton:!enabled{\n"
"	border: 1px solid rgba(255, 209, 0, 150);\n"
"}\n"
"\n"
"QLabel, QPushButton{\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"#win[id=\"1\"]{\n"
"	color: rgb(0, 231, 255);\n"
"}\n"
"\n"
"#win[id=\"2\"]{\n"
"	color: rgb(102, 255, 0);\n"
"}\n"
"\n"
"#win[id=\"0\"]{\n"
"	color: rgb(255, 209, 0);\n"
"}"));
        player1 = new QRadioButton(centralWidget);
        player1->setObjectName(QStringLiteral("player1"));
        player1->setGeometry(QRect(110, 220, 111, 22));
        player1->setAutoFillBackground(false);
        player1->setCheckable(true);
        player1->setChecked(true);
        player2 = new QRadioButton(centralWidget);
        player2->setObjectName(QStringLiteral("player2"));
        player2->setGeometry(QRect(110, 250, 111, 22));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 250, 111, 51));
        l00 = new QPushButton(centralWidget);
        l00->setObjectName(QStringLiteral("l00"));
        l00->setEnabled(false);
        l00->setGeometry(QRect(130, 70, 41, 41));
        l10 = new QPushButton(centralWidget);
        l10->setObjectName(QStringLiteral("l10"));
        l10->setEnabled(false);
        l10->setGeometry(QRect(130, 110, 41, 41));
        l20 = new QPushButton(centralWidget);
        l20->setObjectName(QStringLiteral("l20"));
        l20->setEnabled(false);
        l20->setGeometry(QRect(130, 150, 41, 41));
        l21 = new QPushButton(centralWidget);
        l21->setObjectName(QStringLiteral("l21"));
        l21->setEnabled(false);
        l21->setGeometry(QRect(170, 150, 41, 41));
        l11 = new QPushButton(centralWidget);
        l11->setObjectName(QStringLiteral("l11"));
        l11->setEnabled(false);
        l11->setGeometry(QRect(170, 110, 41, 41));
        l01 = new QPushButton(centralWidget);
        l01->setObjectName(QStringLiteral("l01"));
        l01->setEnabled(false);
        l01->setGeometry(QRect(170, 70, 41, 41));
        l22 = new QPushButton(centralWidget);
        l22->setObjectName(QStringLiteral("l22"));
        l22->setEnabled(false);
        l22->setGeometry(QRect(210, 150, 41, 41));
        l12 = new QPushButton(centralWidget);
        l12->setObjectName(QStringLiteral("l12"));
        l12->setEnabled(false);
        l12->setGeometry(QRect(210, 110, 41, 41));
        QPalette palette;
        QBrush brush(QColor(255, 209, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        l12->setPalette(palette);
        l02 = new QPushButton(centralWidget);
        l02->setObjectName(QStringLiteral("l02"));
        l02->setEnabled(false);
        l02->setGeometry(QRect(210, 70, 41, 41));
        win = new QLabel(centralWidget);
        win->setObjectName(QStringLiteral("win"));
        win->setGeometry(QRect(120, 10, 141, 51));
        win->setTextFormat(Qt::RichText);
        win->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 330, 181, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 220, 101, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 280, 101, 21));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        pvp = new QRadioButton(centralWidget);
        pvp->setObjectName(QStringLiteral("pvp"));
        pvp->setGeometry(QRect(110, 280, 111, 22));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 0, 101, 21));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        l20->raise();
        player1->raise();
        player2->raise();
        pushButton->raise();
        l00->raise();
        l10->raise();
        l21->raise();
        l11->raise();
        l01->raise();
        l22->raise();
        l12->raise();
        l02->raise();
        win->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        pvp->raise();
        label_4->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        player1->setText(QApplication::translate("MainWindow", "Player 1", 0));
        player2->setText(QApplication::translate("MainWindow", "Player 2", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Play!", 0));
        l00->setText(QString());
        l10->setText(QString());
        l20->setText(QString());
        l21->setText(QString());
        l11->setText(QString());
        l01->setText(QString());
        l22->setText(QString());
        l12->setText(QString());
        l02->setText(QString());
        win->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Developer - Arpit Saxena", 0));
        label_2->setText(QApplication::translate("MainWindow", "V/S Computer", 0));
        label_3->setText(QApplication::translate("MainWindow", "PVP", 0));
        pvp->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "TIC TAC TOE", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

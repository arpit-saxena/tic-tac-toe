#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tic.h"
#include <QMessageBox>
#include <string>

using namespace std;

// Prototypes
void mark(int input, int id, Ui::MainWindow *ui);
void check(int board[BOARD_SIZE][BOARD_SIZE], Ui::MainWindow *ui);
int check_mark (QPushButton *button);
bool check_win(int board[BOARD_SIZE][BOARD_SIZE], Ui::MainWindow *ui, int man_id);
void enable(Ui::MainWindow *ui, bool ya);
void set_color(int id,int button,Ui::MainWindow *ui);

//Declaring man_id and bot_id
int man_id;
int bot_id;

//PVP
bool pvp;
int beep;

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

void MainWindow::on_pushButton_clicked()
{
    enable(ui,false);
    if(ui->player1->isChecked())
    {
        bot_id = 2;
        man_id = 1;
        pvp = false;
    }
    else if(ui->player2->isChecked())
    {
        bot_id = 1;
        man_id = 2;
        pvp = false;
    }
    else if(ui->pvp->isChecked())
    {
        pvp = true;
        beep = 9;
    }

    int board[BOARD_SIZE][BOARD_SIZE];

    // Clearing the board
    ui->l00->setText("");
    ui->l01->setText("");
    ui->l02->setText("");
    ui->l10->setText("");
    ui->l11->setText("");
    ui->l12->setText("");
    ui->l20->setText("");
    ui->l21->setText("");
    ui->l22->setText("");

    //resetting win
    ui->win->setText("");

    check(board,ui);
    enable(ui,true);

    if(bot_id == 1 && !pvp)
    {
        mark(tic(board,bot_id),bot_id,ui);
        check(board,ui);
    }
}

void mark(int input, int id, Ui::MainWindow *ui)
{
    std::string mark;
    if(id == 1)
        mark = "X";
    else
        mark = "O";
    switch(input)
    {
        case 0 :
            ui->l00->setText(QString::fromStdString(mark));
            ui->l00->setEnabled(false);
            break;
        case 1 :
            ui->l01->setText(QString::fromStdString(mark));
            ui->l01->setEnabled(false);
            break;
        case 2 :
            ui->l02->setText(QString::fromStdString(mark));
            ui->l02->setEnabled(false);
            break;
        case 10 :
            ui->l10->setText(QString::fromStdString(mark));
            ui->l10->setEnabled(false);
            break;
        case 11 :
            ui->l11->setText(QString::fromStdString(mark));
            ui->l11->setEnabled(false);
            break;
        case 12 :
            ui->l12->setText(QString::fromStdString(mark));
            ui->l12->setEnabled(false);
            break;
        case 20 :
            ui->l20->setText(QString::fromStdString(mark));
            ui->l20->setEnabled(false);
            break;
        case 21 :
            ui->l21->setText(QString::fromStdString(mark));
            ui->l21->setEnabled(false);
            break;
        case 22 :
            ui->l22->setText(QString::fromStdString(mark));
            ui->l22->setEnabled(false);
            break;
    }

    set_color(id,input,ui);
}

void check(int board[BOARD_SIZE][BOARD_SIZE], Ui::MainWindow *ui)
{
    for(int i=0; i < BOARD_SIZE; i++)
    {
        switch(i)
        {
            case 0:
                for(int j=0; j < BOARD_SIZE; j++)
                {
                    switch(j)
                    {
                        case 0:
                            board[i][j] = check_mark(ui->l00);
                            break;
                        case 1:
                            board[i][j] = check_mark(ui->l01);
                            break;
                        case 2:
                            board[i][j] = check_mark(ui->l02);
                    }
                }
                break;

            case 1:
                for(int j=0; j < BOARD_SIZE; j++)
                {
                    switch(j)
                    {
                        case 0:
                            board[i][j] = check_mark(ui->l10);
                            break;
                        case 1:
                            board[i][j] = check_mark(ui->l11);
                            break;
                        case 2:
                            board[i][j] = check_mark(ui->l12);
                    }
                }
                break;

            case 2:
                for(int j=0; j < BOARD_SIZE; j++)
                {
                    switch(j)
                    {
                        case 0:
                            board[i][j] = check_mark(ui->l20);
                            break;
                        case 1:
                            board[i][j] = check_mark(ui->l21);
                            break;
                        case 2:
                            board[i][j] = check_mark(ui->l22);
                    }
                }
                break;
        }
    }
}

int check_mark(QPushButton *button)
{
    if(button->text() == "X")
    {
        return 1;
    }
    else if(button->text() == "O")
    {
        return 2;
    }
    else
    {
        return 0;
    }
    return 255;
}

bool check_win(int board[BOARD_SIZE][BOARD_SIZE], Ui::MainWindow *ui, int man_id)
{
    if(!pvp)
    {
        for(int i=0; i < BOARD_SIZE; i++)
        {
            int sum1_row = 0, sum1_col=0;
            int sum2_row = 0, sum2_col=0;
            for(int j=0; j < BOARD_SIZE; j++)
            {
                //checking rows
                if(board[i][j] == 1)
                    sum1_row += 1;
                else if(board[i][j] == 2)
                    sum2_row += 1;

                //Columns
                if(board[j][i] == 1)
                    sum1_col += 1;
                else if(board[j][i] == 2)
                    sum2_col += 1;
            }
            if(sum1_row == 3 || sum1_col == 3)
            {
                enable(ui,false);
                if(man_id == 1)
                {
                    ui->win->setText("You win! Great work!");
                    set_color(1,255,ui);
                }
                else
                {
                    ui->win->setText("You lost!");
                    set_color(2,255,ui);
                }
                return true;
            }
            else if(sum2_row == 3 || sum2_col == 3)
            {
                enable(ui,false);
                if(man_id == 2)
                {
                    ui->win->setText("You win! Great work!");
                    set_color(2,255,ui);
                }
                else
                {
                    ui->win->setText("You lost!");
                    set_color(1,255,ui);
                }
                return true;
            }
        }

        //Checking diagonals
        if(board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1)
        {
            enable(ui,false);
            if(man_id == 1)
            {
                ui->win->setText("You win! Great work!");
                set_color(1,255,ui);
            }
            else
            {
                ui->win->setText("You lost!");
                set_color(2,255,ui);
            }
            return true;
        }
        else if(board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2)
        {
            enable(ui,false);
            if(man_id == 2)
            {
                ui->win->setText("You win! Great work!");
                set_color(2,255,ui);
            }
            else
            {
                ui->win->setText("You lost!");
                set_color(1,255,ui);
            }
            return true;
        }
        else if(board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1)
        {
            if(man_id == 1)
            {
                ui->win->setText("You win! Great work!");
                set_color(1,255,ui);
            }
            else
            {
                ui->win->setText("You lost!");
                set_color(2,255,ui);
            }
            enable(ui,false);
            return true;
        }
        else if(board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2)
        {
            if(man_id == 2)
            {
                ui->win->setText("You win! Great work!");
                set_color(2,255,ui);
            }
            else
            {
                ui->win->setText("You lost!");
                set_color(1,255,ui);
            }
            enable(ui,false);
            return true;
        }

        //Checking for draw
        int count = 0;
        for(int i=0; i < BOARD_SIZE; i++)
        {
            for(int j = 0; j < BOARD_SIZE; j++)
            {
                if(board[i][j] == 1 || board[i][j] == 2)
                {
                    count++;
                }
            }
        }
        if(count == 9)
        {
            ui->win->setText("It was a draw!");
            set_color(0,255,ui);
            enable(ui,false);
            return true;
        }

        //If no one won
        return false;
    }
    else
    {
        for(int i=0; i < BOARD_SIZE; i++)
        {
            int sum1_row = 0, sum1_col=0;
            int sum2_row = 0, sum2_col=0;
            for(int j=0; j < BOARD_SIZE; j++)
            {
                //checking rows
                if(board[i][j] == 1)
                    sum1_row += 1;
                else if(board[i][j] == 2)
                    sum2_row += 1;

                //Columns
                if(board[j][i] == 1)
                    sum1_col += 1;
                else if(board[j][i] == 2)
                    sum2_col += 1;
            }
            if(sum1_row == 3 || sum1_col == 3)
            {
                enable(ui,false);
                ui->win->setText("Player 1 won");
                set_color(1,255,ui);
                return true;
            }
            else if(sum2_row == 3 || sum2_col == 3)
            {
                enable(ui,false);
                ui->win->setText("Player 2 won");
                set_color(2,255,ui);
                return true;
            }
        }

        //Checking diagonals
        if(board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1)
        {
            enable(ui,false);
            ui->win->setText("Player 1 won");
            set_color(1,255,ui);
            return true;
        }
        else if(board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2)
        {
            enable(ui,false);
            ui->win->setText("Player 2 won");
            set_color(2,255,ui);
            return true;
        }
        else if(board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1)
        {
            ui->win->setText("Player 1 won");
            set_color(1,255,ui);
            enable(ui,false);
            return true;
        }
        else if(board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2)
        {
            ui->win->setText("Player 2 won");
            set_color(2,255,ui);
            enable(ui,false);
            return true;
        }

        //Checking for draw
        int count = 0;
        for(int i=0; i < BOARD_SIZE; i++)
        {
            for(int j = 0; j < BOARD_SIZE; j++)
            {
                if(board[i][j] == 1 || board[i][j] == 2)
                {
                    count++;
                }
            }
        }
        if(count == 9)
        {
            ui->win->setText("It was a draw!");
            set_color(0,255,ui);
            enable(ui,false);
            return true;
        }

        //If no one won
        return false;
    }
    return false;
}

//enable or disable the clicking region
void enable(Ui::MainWindow *ui, bool ya)
{
    ui->l00->setEnabled(ya);
    ui->l01->setEnabled(ya);
    ui->l02->setEnabled(ya);
    ui->l10->setEnabled(ya);
    ui->l11->setEnabled(ya);
    ui->l12->setEnabled(ya);
    ui->l20->setEnabled(ya);
    ui->l21->setEnabled(ya);
    ui->l22->setEnabled(ya);
}

void MainWindow::on_l00_clicked()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    check(board,ui);
    if(pvp)
    {
        if(beep % 2 == 1)
            mark(0,1,ui);
        else
            mark(0,2,ui);
        beep--;
    }
    else
        mark(0,man_id,ui);

    bool win;
    check(board,ui);
    if(!(check_win(board,ui,man_id)) && !pvp)
    {
        mark(tic(board,bot_id),bot_id,ui);
        check(board,ui);
        win = check_win(board,ui,man_id);
    }
    ui->l00->setCheckable(false);
}

void MainWindow::on_l01_clicked()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    check(board,ui);
    if(pvp)
    {
        if(beep % 2 == 1)
            mark(1,1,ui);
        else
            mark(1,2,ui);
        beep--;
    }
    else
        mark(1,man_id,ui);

    bool win;
    check(board,ui);
    if(!(check_win(board,ui,man_id)) && !pvp)
    {
        mark(tic(board,bot_id),bot_id,ui);
        check(board,ui);
        win = check_win(board,ui,man_id);
    }
    ui->l01->setCheckable(false);
}

void MainWindow::on_l02_clicked()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    check(board,ui);
    if(pvp)
    {
        if(beep % 2 == 1)
            mark(2,1,ui);
        else
            mark(2,2,ui);
        beep--;
    }
    else
        mark(2,man_id,ui);
    check(board,ui);
    bool win;
    if(!(check_win(board,ui,man_id)) && !pvp)
    {
        mark(tic(board,bot_id),bot_id,ui);
        check(board,ui);
        win = check_win(board,ui,man_id);
    }
    ui->l02->setCheckable(false);
}

void MainWindow::on_l10_clicked()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    check(board,ui);
    if(pvp)
    {
        if(beep % 2 == 1)
            mark(10,1,ui);
        else
            mark(10,2,ui);
        beep--;
    }
    else
        mark(10,man_id,ui);
    check(board,ui);
    bool win;
    if(!(check_win(board,ui,man_id)) && !pvp)
    {
        mark(tic(board,bot_id),bot_id,ui);
        check(board,ui);
        win = check_win(board,ui,man_id);
    }
    ui->l10->setCheckable(false);
}

void MainWindow::on_l11_clicked()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    check(board,ui);
    if(pvp)
    {
        if(beep % 2 == 1)
            mark(11,1,ui);
        else
            mark(11,2,ui);
        beep--;
    }
    else
        mark(11,man_id,ui);
    check(board,ui);
    bool win;
    if(!(check_win(board,ui,man_id)) && !pvp)
    {
        mark(tic(board,bot_id),bot_id,ui);
        check(board,ui);
        win = check_win(board,ui,man_id);
    }
    ui->l11->setCheckable(false);
}

void MainWindow::on_l12_clicked()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    check(board,ui);
    if(pvp)
    {
        if(beep % 2 == 1)
            mark(12,1,ui);
        else
            mark(12,2,ui);
        beep--;
    }
    else
        mark(12,man_id,ui);
    check(board,ui);
    bool win;
    if(!(check_win(board,ui,man_id)) && !pvp)
    {
        mark(tic(board,bot_id),bot_id,ui);
        check(board,ui);
        win = check_win(board,ui,man_id);
    }
    ui->l12->setCheckable(false);
}

void MainWindow::on_l20_clicked()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    check(board,ui);
    if(pvp)
    {
        if(beep % 2 == 1)
            mark(20,1,ui);
        else
            mark(20,2,ui);
        beep--;
    }
    else
        mark(20,man_id,ui);
    check(board,ui);
    bool win;
    if(!(check_win(board,ui,man_id)) && !pvp)
    {
        mark(tic(board,bot_id),bot_id,ui);
        check(board,ui);
        win = check_win(board,ui,man_id);
    }
    ui->l20->setCheckable(false);
}

void MainWindow::on_l21_clicked()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    check(board,ui);
    if(pvp)
    {
        if(beep % 2 == 1)
            mark(21,1,ui);
        else
            mark(21,2,ui);
        beep--;
    }
    else
        mark(21,man_id,ui);
    check(board,ui);
    bool win;
    if(!(check_win(board,ui,man_id)) && !pvp)
    {
        mark(tic(board,bot_id),bot_id,ui);
        check(board,ui);
        win = check_win(board,ui,man_id);
    }
    ui->l21->setCheckable(false);
}

void MainWindow::on_l22_clicked()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    check(board,ui);
    if(pvp)
    {
        if(beep % 2 == 1)
            mark(22,1,ui);
        else
            mark(22,2,ui);
        beep--;
    }
    else
        mark(22,man_id,ui);
    check(board,ui);
    bool win;
    if(!(check_win(board,ui,man_id)) && !pvp)
    {
        mark(tic(board,bot_id),bot_id,ui);
        check(board,ui);
        win = check_win(board,ui,man_id);
    }
    ui->l22->setCheckable(false);
}

void set_color(int id,int button,Ui::MainWindow *ui)
{
    switch(button)
    {
        case 0:
            ui->l00->setProperty("id",id);
            ui->l00->style()->unpolish(ui->l00);
            ui->l00->style()->polish(ui->l00);
            ui->l00->update();
            break;

        case 1:
            ui->l01->setProperty("id",id);
            ui->l01->style()->unpolish(ui->l01);
            ui->l01->style()->polish(ui->l01);
            ui->l01->update();
            break;

        case 2:
            ui->l02->setProperty("id",id);
            ui->l02->style()->unpolish(ui->l02);
            ui->l02->style()->polish(ui->l02);
            ui->l02->update();
            break;

        case 10:
            ui->l10->setProperty("id",id);
            ui->l10->style()->unpolish(ui->l10);
            ui->l10->style()->polish(ui->l10);
            ui->l10->update();
            break;

        case 11:
            ui->l11->setProperty("id",id);
            ui->l11->style()->unpolish(ui->l11);
            ui->l11->style()->polish(ui->l11);
            ui->l11->update();
            break;

        case 12:
            ui->l12->setProperty("id",id);
            ui->l12->style()->unpolish(ui->l12);
            ui->l12->style()->polish(ui->l12);
            ui->l12->update();
            break;

        case 20:
            ui->l20->setProperty("id",id);
            ui->l20->style()->unpolish(ui->l20);
            ui->l20->style()->polish(ui->l20);
            ui->l20->update();
            break;

        case 21:
            ui->l21->setProperty("id",id);
            ui->l21->style()->unpolish(ui->l21);
            ui->l21->style()->polish(ui->l21);
            ui->l21->update();
            break;

        case 22:
            ui->l22->setProperty("id",id);
            ui->l22->style()->unpolish(ui->l22);
            ui->l22->style()->polish(ui->l22);
            ui->l22->update();
            break;

        case 255:
            ui->win->setProperty("id",id);
            ui->win->style()->unpolish(ui->win);
            ui->win->style()->polish(ui->win);
            ui->win->update();
    }
}

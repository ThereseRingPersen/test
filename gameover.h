#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QFile>
#include <QString>
#include <QList>
#include <scoreuser.h>
#include <QDebug>
#include "ui_highscore.h"
#include "highscore.h"


namespace Ui {
class GameOver;
}
/**
 * @brief The GameOver class class that displays game over screen
 */
class GameOver : public QDialog
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = 0);
    ~GameOver();
    void setScore(QString);

private slots:
    void on_AddToscoreBoard_clicked();


private:
    Ui::GameOver *ui;
    void EnterScoreBoard();

};

#endif // GAMEOVER_H

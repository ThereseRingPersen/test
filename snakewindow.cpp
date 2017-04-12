#include "snakewindow.h"
#include "ui_snakewindow.h"
#include <QtCore>
#include <QtGui>
#include <QEvent>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QEvent>
#include "snake.h"
#include <QDebug>
#include "gameover.h"
#include "ui_gameover.h"
#include <QString>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QMediaPlaylist>

SnakeWindow::SnakeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SnakeWindow)
{
    //sets UI form and scene
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,681,451);
    scene->setBackgroundBrush(QBrush(QImage(":/images/resourses/images/background.jpg")));
    ui->graphicsView_snake->setScene(scene);

    scene->setFocus();
    //Adds background music and loops it with playlist
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/resourses/sounds/Chill-house-music-loop-116-bpm.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setMedia(playlist);
    music->play();

}

SnakeWindow::~SnakeWindow()
{
    delete ui;
}

//opens a new game over screen if head crashes in tail
void SnakeWindow::gameOver()
{
    gameOverWindow = new GameOver();
    this->hide();
    gameOverWindow->show();
}

void SnakeWindow::gameLoop()
{
    shead->move();
    shead->getSnakeLength();

    //connecting ui progress bar to a score value
    int score = shead->getGameScore();
    this->ui->progress_bar_level->setTextVisible(false);
    this->ui->progress_bar_level->setMaximum(500);
    this->ui->progress_bar_level->setValue(score);

    //connecting score to ui
    this->ui->label_Score->setText(QString::number(score));
    this->ui->label_Score->setStyleSheet("QLabel{color:blue; "
                                         "font: bold 18px}");

    //opens game over screen
    if(isDead)
    {
        disconnect(gameStart, SIGNAL(timeout()), this, SLOT(gameLoop()));
        disconnect(gameStart, SIGNAL(timeout()), this, SLOT(getCrashed()));
        music->stop();
        gameOver();
    }
}

bool SnakeWindow::getCrashed()
{

    isDead=shead->getHead_in_tail();
    return isDead;
    qDebug()<<"isDead is: "<<isDead;
}


void SnakeWindow::on_exit_Game_Btn_clicked()
{

}

void SnakeWindow::on_pause_Game_Btn_clicked()
{
    gameIsPaused = !gameIsPaused;

    //pauses and pauses game timer and background music
    if(gameIsPaused){
        disconnect(gameStart, SIGNAL(timeout()), this, SLOT(gameLoop()));
        disconnect(gameStart, SIGNAL(timeout()), this, SLOT(getCrashed()));
        music->setMuted(true);
    }
    if(!gameIsPaused){
        connect(gameStart, SIGNAL(timeout()), this, SLOT(gameLoop()));
        connect(gameStart, SIGNAL(timeout()), this, SLOT(getCrashed()));
        gameStart->start(200);
        music->setMuted(false);

    }
}




void SnakeWindow::on_start_Game_Btn_clicked()
{

    //creating head of the snake item
    shead = new Snake(*scene, this);
    scene->addItem(shead);

    //head reacts on key events is true
    shead->setFocus();
    scene->installEventFilter(this);

    //adding a power-up

    PowerUp *pUp = new PowerUp();
    scene->addItem(pUp);


    body = new BodyOfSnake();
    body->setPos(0,20);
    scene->addItem(body);
    shead->appendBodies(*body);
    //starts movement of snake
    //shead->snakeIsMoving();
    connect(gameStart, SIGNAL(timeout()), this, SLOT(gameLoop()));
    connect(gameStart, SIGNAL(timeout()), this, SLOT(getCrashed()));
    gameStart->start(200);


}
//Set key behaviour
void SnakeWindow::handleKeyPressed(QKeyEvent *event)
{    
    //if (!isPause)
    switch (event->key()) {
    case Qt::Key_Left:
        shead->setDirection(Snake::Left);
        break;
    case Qt::Key_Right:
        shead->setDirection(Snake::Right);
        break;
    case Qt::Key_Up:
        shead->setDirection(Snake::Up);
        break;
    case Qt::Key_Down:
        shead->setDirection(Snake::Down);
        break;
    case Qt::Key_Space:
        //pause();
        break;
    }
    //else resume();a
}

bool SnakeWindow::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        handleKeyPressed((QKeyEvent *)event);
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}

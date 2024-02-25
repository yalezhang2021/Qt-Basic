#include "circlewidget.h"
#include <QPainter>
#include <QTimer>
#include <QFile>
#include <QDebug>

CircleWidget::CircleWidget(QWidget *parent):
    QWidget(parent)
{
    m_bg = QImage("D:/Qt/document/QT/pinwheel/000.png");    // image file
    m_pCircleTimer = new QTimer(this);
    m_pCircleTimer->setInterval(100);   // start speed should be low
    periodUpdate(); // update the level in every 6s
    connect(m_pCircleTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

// update the level in every 6s
void CircleWidget::periodUpdate()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateLevel()));
    timer->start(6000);
}

// update the level value by editing the value in "level.txt"
void CircleWidget::updateLevel()
{
    QFile file("D:/Qt/document/QT/pinwheel/level.txt");     // txt file, save the speed level value from 1 to 10
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<< "Can't open the file!\n";
    }
    QString line;

    while (!file.atEnd())
    {
        line = file.readLine();
    }

    int level = line.toInt();
    qDebug()<<level;

    // set different rot interval according to the level value.
    switch (level)
    {
    case 1:
        m_pCircleTimer->setInterval(100);
        break;
    case 2:
        m_pCircleTimer->setInterval(90);
        break;
    case 3:
        m_pCircleTimer->setInterval(80);
        break;
    case 4:
        m_pCircleTimer->setInterval(70);
        break;
    case 5:
        m_pCircleTimer->setInterval(60);
        break;
    case 6:
        m_pCircleTimer->setInterval(50);
        break;
    case 7:
        m_pCircleTimer->setInterval(40);
        break;
    case 8:
        m_pCircleTimer->setInterval(30);
        break;
    case 9:
        m_pCircleTimer->setInterval(20);
        break;
    case 10:
        m_pCircleTimer->setInterval(10);
        break;
    default:
        m_pCircleTimer->setInterval(100);
        break;
    }
}

void CircleWidget::startCircle()
{
    m_pCircleTimer->start();
}
void CircleWidget::stopCircle()
{
    m_pCircleTimer->stop();
}
void CircleWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::NoBrush);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.translate(this->width() / 2, this->height() / 2);               // set the center of rotation
    painter.rotate(m_nAngle);                                               // rot
    painter.translate(-(this->width() / 2), -(this->height() / 2));         // initialize the center point
    painter.drawImage(this->rect(), m_bg);
    QWidget::paintEvent(e);
}

void CircleWidget::onTimeout()
{
    if(m_nAngle == 360)
    {
        m_nAngle = 0;
    }
    m_nAngle += 15;     // every time rot 15 degree, can be adjusted as required
    update();
}

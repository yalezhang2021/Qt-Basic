#ifndef CIRCLEWIDGET_H
#define CIRCLEWIDGET_H

#include <QWidget>

class QTimer;

class CircleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CircleWidget(QWidget *parent = 0);

    void startCircle();
    void stopCircle();
    void periodUpdate();

// slots function
public slots:
    void updateLevel();
    void onTimeout();

protected:
    void paintEvent(QPaintEvent *e);

private:
    QImage m_bg;
    QTimer *m_pCircleTimer = Q_NULLPTR;
    int m_nAngle = 0;

};

#endif // CIRCLEWIDGET_H

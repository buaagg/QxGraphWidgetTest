#ifndef QXGRAPHWIDGETTEST_H
#define QXGRAPHWIDGETTEST_H

#include <QWidget>
#include <QLabel>
#include <QtDebug>
#include <QPaintEvent>
#include <QPainter>
#include <vector>
#include <map>

const int pointsPerLine = 100;

class QxGraphWidgetTest : public QWidget
{
    Q_OBJECT
public:
    explicit QxGraphWidgetTest(QWidget *parent = 0);

    void paintEvent( QPaintEvent *event ) {
        QRect rect = event->rect();/*
        qDebug() << "Width = " << rect.width();
        qDebug() << "Height = " << rect.height();*/
        int w = rect.width();
        int h = rect.height();

        QPainter painter;
        painter.begin( this );
//        painter.setRenderHint( QPainter::HighQualityAntialiasing );
        painter.setRenderHint( QPainter::Antialiasing );
        painter.setPen( QPen(Qt::black, 1) );
        for ( int i = 0; i < pointsPerLine; ++i ) {
            painter.drawLine(
                        QPointF( keyPoints[i].first * w, keyPoints[i].second * h ),
                        QPointF( keyPoints[i+1].first * w, keyPoints[i+1].second * h )
            );
        }
//        painter.drawLine( QPoint(0, 0), QPoint( rect.width(), rect.height() ) );
//        painter.drawLine( QPoint(0, rect.height()), QPoint( rect.width(), 0 ) );

        painter.end();
    }

signals:
public slots:

private:
    QLabel *label;
    std::vector< std::pair<double, double> > keyPoints;
};

#endif // QXGRAPHWIDGETTEST_H

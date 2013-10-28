#include "qxgraphwidgettest.h"

QxGraphWidgetTest::QxGraphWidgetTest(QWidget *parent) :
    QWidget(parent)
{
//    this->label = new QLabel("gg", this);

    keyPoints.push_back( std::make_pair(0, 1) );
    for ( int i = 1; i < pointsPerLine; ++i ) {
        keyPoints.push_back( std::make_pair( (double)i / pointsPerLine, (double)rand() / RAND_MAX ) );
    }
    keyPoints.push_back( std::make_pair(1, 1) );
}

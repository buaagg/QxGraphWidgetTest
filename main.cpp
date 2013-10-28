#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <omp.h>
#include <QtDebug>
#include "qxgraphwidgettest.h"

void fuck() {
    qDebug( (boost::lexical_cast<std::string>( boost::this_thread::get_id() ) + " saying hello!").c_str() );
}

int main(int argc, char *argv[])
{
#pragma omp parallel for default(shared) schedule(static, 1)
    for ( int i = 0; i < 20; ++i ) {
//        qDebug() << "OMP Thread" << boost::lexical_cast<std::string>(omp_get_thread_num()).c_str() << "processing i ="
  //               << boost::lexical_cast<std::string>(i).c_str();
        qDebug( ("OMP Thread " + boost::lexical_cast<std::string>(omp_get_thread_num()) + " processing i = " + boost::lexical_cast<std::string>(i)).c_str() );
    }

    std::vector<boost::thread> t;
    for ( int i = 0; i < 5; ++i ) {
        t.push_back( boost::move(boost::thread(fuck)) );
    }
    for ( auto iter = t.begin(); iter != t.end(); ++iter )
        iter->join();


    QApplication a(argc, argv);
    MainWindow w;

//    new QxGraphWidgetTest(&w);

    w.setCentralWidget( new QxGraphWidgetTest(&w) );

    w.show();


    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <omp.h>

void fuck() {
    qDebug( (boost::lexical_cast<std::string>(boost::this_thread::get_id()) + " saying hello!").c_str() );
}

int main(int argc, char *argv[])
{
    std::vector<boost::thread> t;
    for ( int i = 0; i < 10; ++i ) {
        t.push_back( boost::move(boost::thread(fuck)) );
    }
    for ( auto iter = t.begin(); iter != t.end(); ++iter )
        iter->join();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}

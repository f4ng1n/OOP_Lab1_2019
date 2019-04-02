#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <QCoreApplication>
class TApplication:public QCoreApplication
{
public:
    TApplication(int, char **);
    int run();
};

#endif // TAPPLICATION_H

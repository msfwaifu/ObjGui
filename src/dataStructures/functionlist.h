#ifndef FUNCTIONLIST_H
#define FUNCTIONLIST_H

#include "functionnode.h"

class FunctionList
{
public:
    FunctionList();
    void insert(QString name, QString address, QString section, QString fileOffset, QVector< QVector<QString> > contents);
    void setErrorMsg(QString msg);
    int getLength();
    bool isEmpty();
    bool containsFunction(QString name);
    bool successfullyCreated();
    Function getFunction(QString name);
    Function getFunction(int index);
    QStringList getFunctionNames();
    QString getErrorMsg();
private:
    FunctionNode *head;
    FunctionNode *tail;
    int length;
    QString errorMsg;
};

#endif // FUNCTIONLIST_H

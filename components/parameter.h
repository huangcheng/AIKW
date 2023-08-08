#ifndef PARAMETER_H
#define PARAMETER_H

#include <QObject>
#include <QQmlEngine>
#include <QSqlDatabase>
#include <QQmlListProperty>
#include <QSqlQuery>
#include <QList>
#include <QCoreApplication>
#include <QDir>
#include <QtQml/qqmlregistration.h>

#include "record.h"

class Parameter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Record> categories READ categories CONSTANT FINAL)
    QML_ELEMENT
public:
    explicit Parameter(QObject *parent = nullptr);
    ~Parameter();

public:
    QQmlListProperty<Record> categories();

private:
    QList<Record *> m_categories;
    QSqlDatabase m_database;

signals:

};

#endif // PARAMETER_H

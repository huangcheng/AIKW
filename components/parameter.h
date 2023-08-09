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

#define DATABASE_NAME "midjourney"

class Parameter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Record> categories READ categories CONSTANT FINAL)
    Q_PROPERTY(QQmlListProperty<Record> parameters READ parameters NOTIFY parametersChanged FINAL)
    Q_PROPERTY(QString category READ category WRITE setCategory NOTIFY categoryChanged FINAL)
    QML_ELEMENT
public:
    explicit Parameter(QObject *parent = nullptr);
    ~Parameter();

public:
    QQmlListProperty<Record> categories();
    QQmlListProperty<Record> parameters();
    QString category() const;

public:
    void setCategory(const QString& category);

private:
    QSqlDatabase m_database;

private:
    void fetchCategories();
    void clearParameters();

private:
    QList<Record *> m_categories;
    QList<Record *> m_parameters;
    QString m_category;

signals:
    void categoryChanged();
    void parametersChanged();

public slots:
    void fetchParameters();

};

#endif // PARAMETER_H

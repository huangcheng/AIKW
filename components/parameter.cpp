#include "parameter.h"

Parameter::Parameter(QObject *parent)
    : QObject{parent}
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName(QCoreApplication::applicationDirPath() + QDir::separator() + "db.sqlite");
    m_database.open();

    QSqlQuery query(m_database);

    query.exec("SELECT name, description FROM Category");

    while (query.next())
    {
        QString name = query.value(0).toString();
        QString description = query.value(1).toString();

        Record* record = new Record(name, description);

        m_categories.append(record);
    }
}

Parameter::~Parameter()
{
    for (auto it = m_categories.begin(); it != m_categories.end(); ++it)
    {
        delete *it;

        *it = nullptr;
    }

    m_categories.clear();

    if (m_database.isOpen())
    {
        m_database.close();
    }
}

QQmlListProperty<Record> Parameter::categories()
{
     return QQmlListProperty<Record>(this, &m_categories);
}

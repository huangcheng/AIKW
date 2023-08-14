#include "parameter.h"

Parameter::Parameter(QObject *parent)
    : QObject{parent}
{
    if (QSqlDatabase::contains(DATABASE_NAME))
    {
        m_database = QSqlDatabase::database(DATABASE_NAME, true);
    }
    else
    {
        m_database = QSqlDatabase::addDatabase("QSQLITE", DATABASE_NAME);
        m_database.setDatabaseName(QCoreApplication::applicationDirPath() + QDir::separator() + "db.sqlite");
        m_database.open();
    }

    connect(this, &Parameter::categoryChanged, this, &Parameter::fetchParameters);
}

Parameter::~Parameter()
{
    for (auto it = m_categories.begin(); it != m_categories.end(); ++it)
    {
        delete *it;

        *it = nullptr;
    }

    m_categories.clear();

    clearParameters();

    disconnect(this, &Parameter::categoryChanged, this, &Parameter::fetchParameters);
}

QQmlListProperty<Record> Parameter::categories()
{
    if (m_categories.isEmpty())
    {
        fetchCategories();
    }

    return QQmlListProperty<Record>(this, &m_categories);
}

QQmlListProperty<Record> Parameter::parameters()
{
    return QQmlListProperty<Record>(this, &m_parameters);
}

QString Parameter::category() const
{
    return m_category;
}

QString Parameter::parameter() const
{
    return m_parameter;
}

void Parameter::setCategory(const QString &category)
{
    if (m_category != category)
    {
        m_category = category;

        emit categoryChanged();
    }
}

void Parameter::setParameter(const QString &parameter)
{
    if (m_parameter != parameter)
    {
        if (m_categories.isEmpty())
        {
            fetchCategories();
        }

        if (m_category.isEmpty())
        {
            m_category = fetchCategoryByParameter(parameter);

            emit categoryChanged();
        }

        m_parameter = parameter;

        emit parameterChanged();
    }
}

void Parameter::fetchCategories()
{
    QSqlQuery query(m_database);

    query.exec("SELECT name, description FROM Category");

    while (query.next())
    {
        QString name = query.value(0).toString();
        QString description = query.value(1).toString();

        Record* record = new Record(name, description);

        m_categories.append(record);
    }

    query.finish();
}

void Parameter::clearParameters()
{
    for (auto it = m_parameters.begin(); it != m_parameters.end(); ++it)
    {
        delete *it;

        *it = nullptr;
    }

    m_parameters.clear();
}

QString Parameter::fetchCategoryByParameter(const QString &parameter)
{
    QSqlQuery query(m_database);

    query.prepare("SELECT category FROM Category_Parameter WHERE parameter = ?");
    query.bindValue(0, parameter);
    query.exec();

    QString result;

    while (query.next())
    {
        QString category = query.value(0).toString();

        result = category;
    }

    query.finish();

    return result;
}

void Parameter::fetchParameters()
{
    clearParameters();

    QSqlQuery query(m_database);

    query.prepare("SELECT name, description FROM Parameter INNER JOIN Category_Parameter ON Parameter.name = Category_Parameter.parameter WHERE Category_Parameter.category = ?");
    query.bindValue(0, m_category);
    query.exec();

    while (query.next())
    {
        QString name = query.value(0).toString();
        QString description = query.value(1).toString();

        Record* record = new Record(name, description);

        m_parameters.append(record);
    }

    query.finish();

    emit parametersChanged();
}

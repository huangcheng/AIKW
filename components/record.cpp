#include "record.h"

Record::Record(const QString name, const QString description): QObject{nullptr}, m_name{name}, m_description{description}
{

}

Record::Record(QObject *parent): QObject{parent}
{

}

QString Record::name() const
{
    return m_name;
}

QString Record::description() const
{
    return m_description;
}

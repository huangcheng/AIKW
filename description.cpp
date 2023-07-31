#include "description.h"

Description::Description(QObject *parent)
    : QObject{parent}
{

}

QString Description::description() const
{
    return m_description;
}

void Description::setDescription(const QString &description)
{
    if (m_description != description)
    {
        m_description = description;

        emit descriptionChanged();
    }
}

int Description::weight() const
{
    return m_weight;
}

void Description::setWeight(const int weight)
{
    if (m_weight != weight)
    {
        m_weight = weight;

        emit weightChanged();
    }
}

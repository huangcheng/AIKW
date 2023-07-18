#include "generation.h"

Generation::Generation(QObject *parent)
    : QObject{parent}
{

}

QString Generation::url() const
{
    return m_url;
}

void Generation::setUrl(const QString &url)
{
    if (url != m_url)
    {
        m_url = url;

        emit urlChanged();
    }
}

QString Generation::description() const
{
    return m_description;
}

void Generation::setDescription(const QString &description)
{
    if (description != m_description)
    {
        m_description = description;

        emit descriptionChanged();
    }
}


QString Generation::generate()
{
    QString result;

    if (!m_url.isEmpty()) {
        result += m_url;
    }

    if (!m_description.isEmpty()) {
        result += ' ' + m_description;
    }

    return result;
}

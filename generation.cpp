#include "generation.h"

Generation::Generation(QObject *parent)
    : QObject{parent}
{
    for (size_t i = 0; i < 3; ++i)
    {
        m_descriptions.append(new Description());
    }
}

Generation::~Generation()
{
    for (auto iter = m_descriptions.begin(); iter != m_descriptions.end(); ++iter)
    {
        delete *iter;

        *iter = nullptr;
    }

    m_descriptions.clear();
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

QQmlListProperty<Description> Generation::descriptions()
{
    return QQmlListProperty<Description>(this, &m_descriptions);
}

QString Generation::generate()
{
    QString result;

    if (!m_url.isEmpty()) {
        result += " " + m_url;
    }

    if (!m_description.isEmpty()) {
        result += " " + m_description;
    }

    return result.trimmed();
}

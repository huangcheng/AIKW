#include "generation.h"

Generation::Generation(QObject *parent)
    : QObject{parent}
{
    for (size_t i = 0; i < 3; ++i)
    {
        m_descriptions.append(new Description());

        m_parameters.append(new Description());
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

    for (auto iter = m_parameters.begin(); iter != m_parameters.end(); ++iter)
    {
        delete *iter;

        *iter = nullptr;
    }

    m_parameters.clear();
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

QQmlListProperty<Description> Generation::parameters()
{
    return QQmlListProperty<Description>(this, &m_parameters);
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

void Generation::descriptions_add()
{
    m_descriptions.append(new Description());

    emit descriptionsChanged();
}

void Generation::descriptions_remove(size_t index)
{
    Description* item = m_descriptions.at(index);

    if (item != nullptr)
    {
        delete item;

        item = nullptr;

        m_descriptions.removeAt(index);

        emit descriptionsChanged();
    }
}

void Generation::parameters_add()
{
    m_parameters.append(new Description());

    emit parametersChanged();
}

void Generation::parameters_remove(size_t index)
{
    Description* item = m_parameters.at(index);

    if (item != nullptr)
    {
        delete item;

        item = nullptr;

        m_parameters.removeAt(index);

        emit parametersChanged();
    }
}

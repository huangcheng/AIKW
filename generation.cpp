#include "generation.h"

Generation::Generation(QObject *parent)
    : QObject{parent}, m_result{"/imagine prompt:"}
{
    for (size_t i = 0; i < 3; ++i)
    {
        Description* description = new Description();
        connect(description, &Description::descriptionChanged, this, &Generation::generate);
        connect(description, &Description::weightChanged, this, &Generation::generate);

        m_descriptions.append(description);

        Description* parameter = new Description();
        m_parameters.append(parameter);

        connect(parameter, &Description::descriptionChanged, this, &Generation::generate);
        connect(parameter, &Description::weightChanged, this, &Generation::generate);
    }

    connect(this, &Generation::descriptionsChanged, this, &Generation::generate);
    connect(this, &Generation::parametersChanged, this, &Generation::generate);
    connect(this, &Generation::urlChanged, this, &Generation::generate);
    connect(this, &Generation::descriptionChanged, this, &Generation::generate);
}

Generation::~Generation()
{
    for (auto iter = m_descriptions.begin(); iter != m_descriptions.end(); ++iter)
    {
        disconnect(*iter, &Description::descriptionChanged, this, &Generation::generate);
        disconnect(*iter, &Description::weightChanged, this, &Generation::generate);

        delete *iter;

        *iter = nullptr;
    }

    m_descriptions.clear();

    for (auto iter = m_parameters.begin(); iter != m_parameters.end(); ++iter)
    {
        disconnect(*iter, &Description::descriptionChanged, this, &Generation::generate);
        disconnect(*iter, &Description::weightChanged, this, &Generation::generate);

        delete *iter;

        *iter = nullptr;
    }

    m_parameters.clear();

    disconnect(this, &Generation::descriptionsChanged, this, &Generation::generate);
    disconnect(this, &Generation::parametersChanged, this, &Generation::generate);
    disconnect(this, &Generation::urlChanged, this, &Generation::generate);
    disconnect(this, &Generation::descriptionChanged, this, &Generation::generate);
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

void Generation::generate()
{
    QString result = "/imagine prompt:";

    if (!m_url.isEmpty())
    {
        result += " " + m_url;
    }

    if (!m_description.isEmpty())
    {
        result += " " + m_description;
    }

    for (auto it = m_descriptions.begin(); it != m_descriptions.end(); ++it)
    {
        if ((*it)->description().isEmpty())
        {
            continue;
        }

        result += " " + (*it)->description();

        QString weight = (*it)->weight();

        if (!weight.isEmpty() && weight != "0")
        {
            result += "::" + weight;
        }
    }

    for (auto it = m_parameters.begin(); it != m_parameters.end(); ++it)
    {
        if ((*it)->description().isEmpty())
        {
            continue;
        }

        result += " " + (*it)->description();

        QString weight = (*it)->weight();

        if (!weight.isEmpty() && weight != "0")
        {
            result += "::" + weight;
        }
    }

    m_result = result.trimmed();

    emit resultChanged();
}

void Generation::descriptions_add()
{
    Description* description = new Description();

    connect(description, &Description::descriptionChanged, this, &Generation::generate);
    connect(description, &Description::weightChanged, this, &Generation::generate);

    m_descriptions.append(description);

    emit descriptionsChanged();
}

void Generation::descriptions_remove(size_t index)
{
    Description* item = m_descriptions.at(index);

    if (item != nullptr)
    {
        disconnect(item, &Description::descriptionChanged, this, &Generation::generate);
        disconnect(item, &Description::weightChanged, this, &Generation::generate);

        delete item;

        item = nullptr;

        m_descriptions.removeAt(index);

        emit descriptionsChanged();
    }
}

void Generation::parameters_add()
{
    Description* parameter = new Description();

    connect(parameter, &Description::descriptionChanged, this, &Generation::generate);
    connect(parameter, &Description::weightChanged, this, &Generation::generate);

    m_parameters.append(parameter);

    emit parametersChanged();
}

void Generation::parameters_remove(size_t index)
{
    Description* item = m_parameters.at(index);

    if (item != nullptr)
    {
        disconnect(item, &Description::descriptionChanged, this, &Generation::generate);
        disconnect(item, &Description::weightChanged, this, &Generation::generate);

        delete item;

        item = nullptr;

        m_parameters.removeAt(index);

        emit parametersChanged();
    }
}

QString Generation::result() const {
    return m_result;
}

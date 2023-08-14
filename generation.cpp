#include "generation.h"

Generation::Generation(QObject *parent)
    : QObject{parent}, m_prompt{"/imagine prompt:"}
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
    connect(this, &Generation::styleChanged, this, &Generation::generate);
    connect(this, &Generation::versionChanged, this, &Generation::generate);
    connect(this, &Generation::qualityChanged, this, &Generation::generate);
    connect(this, &Generation::chaosChanged, this, &Generation::generate);
    connect(this, &Generation::seedChanged, this, &Generation::generate);
    connect(this, &Generation::aspectChanged, this, &Generation::generate);
    connect(this, &Generation::noChanged, this, &Generation::generate);
    connect(this, &Generation::repeatChanged, this, &Generation::generate);
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
    disconnect(this, &Generation::styleChanged, this, &Generation::generate);
    disconnect(this, &Generation::versionChanged, this, &Generation::generate);
    disconnect(this, &Generation::qualityChanged, this, &Generation::generate);
    disconnect(this, &Generation::chaosChanged, this, &Generation::generate);
    disconnect(this, &Generation::seedChanged, this, &Generation::generate);
    disconnect(this, &Generation::aspectChanged, this, &Generation::generate);
    disconnect(this, &Generation::noChanged, this, &Generation::generate);
    disconnect(this, &Generation::repeatChanged, this, &Generation::generate);
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

    if (!m_style.isEmpty())
    {
        result += " --s " + m_style;
    }

    if (!m_version.isEmpty())
    {
        result += " --v " + m_version;
    }

    if (!m_quality.isEmpty())
    {
        result += " --q " + m_quality;
    }

    if (!m_chaos.isEmpty())
    {
        result += " --c " + m_chaos;
    }

    if (!m_seed.isEmpty())
    {
        result += " --seed " + m_seed;
    }

    if (!m_aspect.isEmpty())
    {
        result += " --ar " + m_aspect;
    }

    if (!m_no.isEmpty())
    {
        result += " --no " + m_no;
    }

    if (!m_repeat.isEmpty())
    {
        result += " --r " + m_repeat;
    }

    m_prompt = result.trimmed();

    emit promptChanged();
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

QString Generation::prompt() const
{
    return m_prompt;
}

void Generation::copy()
{
    QClipboard* clipboard = QGuiApplication::clipboard();

    clipboard->setText(m_prompt);
}

void Generation::clear() {
    m_prompt = "/imagine prompt:";

    setUrl("");
    setDescription("");
    setStyle("");
    setVersion("");
    setQuality("");
    setChaos("");
    setSeed("");
    setNo("");
    setAspect("");
    setRepeat("");

    for (auto iter = m_descriptions.begin(); iter != m_descriptions.end(); ++iter)
    {
        (*iter)->setDescription("");
        (*iter)->setWeight("");
    }

    for (auto iter = m_parameters.begin(); iter != m_parameters.end(); ++iter)
    {
        (*iter)->setDescription("");
        (*iter)->setWeight("");
    }

    emit promptChanged();
    emit parametersChanged();
    emit descriptionsChanged();
}

QString Generation::style() const {
    return m_style;
}

void Generation::setStyle(const QString &style) {
    if (style != m_style)
    {
        m_style = style;

        emit styleChanged();
    }
}

QString Generation::version() const {
    return m_version;
}

void Generation::setVersion(const QString &version) {
    if (version != m_version)
    {
        m_version = version;

        emit versionChanged();
    }
}

QString Generation::quality() const {
    return m_quality;
}

void Generation::setQuality(const QString &quality) {
    if (quality != m_quality)
    {
        m_quality = quality;

        emit qualityChanged();
    }
}

QString Generation::chaos() const {
    return m_chaos;
}

void Generation::setChaos(const QString &chaos) {
    if (chaos != m_chaos)
    {
        m_chaos = chaos;

        emit chaosChanged();
    }
}

QString Generation::seed() const {
    return m_seed;
}

void Generation::setSeed(const QString &seed) {
    if (seed != m_seed)
    {
        m_seed = seed;

        emit seedChanged();
    }
}

QString Generation::aspect() const {
    return m_aspect;
}

void Generation::setAspect(const QString &aspect) {
    if (aspect != m_aspect)
    {
        m_aspect = aspect;

        emit aspectChanged();
    }
}

QString Generation::no() const {
    return m_no;
}

void Generation::setNo(const QString &no) {
    if (no != m_no)
    {
        m_no = no;

        emit noChanged();
    }
}

QString Generation::repeat() const {
    return m_repeat;
}

void Generation::setRepeat(const QString &repeat) {
    if (repeat != m_repeat)
    {
        m_repeat = repeat;

        emit repeatChanged();
    }
}

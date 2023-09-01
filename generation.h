#ifndef GENERATION_H
#define GENERATION_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QList>
#include <QClipboard>
#include <QRegularExpression>
#include <QGuiApplication>
#include <QQmlListProperty>

#include "description.h"

class Generation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged FINAL)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged FINAL)
    Q_PROPERTY(QQmlListProperty<Description> descriptions READ descriptions NOTIFY descriptionsChanged FINAL)
    Q_PROPERTY(QQmlListProperty<Description> parameters READ parameters NOTIFY parametersChanged FINAL)
    Q_PROPERTY(QString prompt READ prompt NOTIFY promptChanged FINAL)
    Q_PROPERTY(QString style READ style WRITE setStyle NOTIFY styleChanged FINAL)
    Q_PROPERTY(QString version READ version WRITE setVersion NOTIFY versionChanged FINAL)
    Q_PROPERTY(QString quality READ quality WRITE setQuality NOTIFY qualityChanged FINAL)
    Q_PROPERTY(QString chaos READ chaos WRITE setChaos NOTIFY chaosChanged FINAL)
    Q_PROPERTY(QString seed READ seed WRITE setSeed NOTIFY seedChanged FINAL)
    Q_PROPERTY(QString aspect READ aspect WRITE setAspect NOTIFY aspectChanged FINAL)
    Q_PROPERTY(QString no READ no WRITE setNo NOTIFY noChanged FINAL)
    Q_PROPERTY(QString repeat READ repeat WRITE setRepeat NOTIFY repeatChanged FINAL)
public:
    explicit Generation(QObject *parent = nullptr);
    ~Generation();

public:
    QString url() const;
    void setUrl(const QString& url);

    QString description() const;
    void setDescription(const QString& description);

    QString prompt() const;

    QString style() const;
    void setStyle(const QString& style);

    QString version() const;
    void setVersion(const QString& version);

    QString quality() const;
    void setQuality(const QString& quality);

    QString chaos() const;
    void setChaos(const QString& chaos);

    QString seed() const;
    void setSeed(const QString& seed);

    QString aspect() const;
    void setAspect(const QString& aspect);

    QString no() const;
    void setNo(const QString& no);

    QString repeat() const;
    void setRepeat(const QString& repeat);

    QQmlListProperty<Description> descriptions();
    QQmlListProperty<Description> parameters();

public:
    void generate();

private:
    QString m_url;
    QString m_description;
    QString m_prompt;
    QString m_style;
    QString m_version;
    QString m_quality;
    QString m_chaos;
    QString m_seed;
    QString m_aspect;
    QString m_no;
    QString m_repeat;
    QList<Description *> m_descriptions;
    QList<Description *> m_parameters;

public:
    Q_INVOKABLE void descriptions_add();
    Q_INVOKABLE void descriptions_remove(size_t index);
    Q_INVOKABLE void parameters_add();
    Q_INVOKABLE void parameters_remove(size_t index);
    Q_INVOKABLE void copy();
    Q_INVOKABLE void clear();

signals:
    void urlChanged();
    void descriptionChanged();
    void descriptionsChanged();
    void parametersChanged();
    void promptChanged();
    void styleChanged();
    void versionChanged();
    void qualityChanged();
    void chaosChanged();
    void seedChanged();
    void aspectChanged();
    void noChanged();
    void repeatChanged();
};

#endif // GENERATION_H

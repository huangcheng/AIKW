#ifndef GENERATION_H
#define GENERATION_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QList>
#include <QQmlListProperty>

#include "description.h"

class Generation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged FINAL)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged FINAL)
    Q_PROPERTY(QQmlListProperty<Description> descriptions READ descriptions NOTIFY descriptionsChanged FINAL)
    Q_PROPERTY(QQmlListProperty<Description> parameters READ parameters NOTIFY parametersChanged FINAL)
public:
    explicit Generation(QObject *parent = nullptr);
    ~Generation();

public:
    QString url() const;
    void setUrl(const QString& url);

    QString description() const;
    void setDescription(const QString& description);

    QQmlListProperty<Description> descriptions();
    QQmlListProperty<Description> parameters();

private:
    QString m_url;
    QString m_description;
    QList<Description *> m_descriptions;
    QList<Description *> m_parameters;

public:
    Q_INVOKABLE QString generate();
    Q_INVOKABLE void descriptions_add();
    Q_INVOKABLE void descriptions_remove(size_t index);
    Q_INVOKABLE void parameters_add();
    Q_INVOKABLE void parameters_remove(size_t index);

signals:
    void urlChanged();
    void descriptionChanged();
    void descriptionsChanged();
    void parametersChanged();
};

#endif // GENERATION_H

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
    Q_PROPERTY(QQmlListProperty<Description> descriptions READ descriptions FINAL)
public:
    explicit Generation(QObject *parent = nullptr);
    ~Generation();

public:
    QString url() const;
    void setUrl(const QString& url);

    QString description() const;
    void setDescription(const QString& description);

    QQmlListProperty<Description> descriptions();

private:
    QString m_url;
    QString m_description;
    QList<Description *> m_descriptions;

public:
    Q_INVOKABLE QString generate();

private:
    static void append_description(QQmlListProperty<Description>* list, Description* description);
    static qsizetype descriptions_count(QQmlListProperty<Description> *list);

signals:
    void urlChanged();
    void descriptionChanged();
    void descriptionsChanged();
};

#endif // GENERATION_H
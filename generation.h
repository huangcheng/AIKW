#ifndef GENERATION_H
#define GENERATION_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QList>
#include <QClipboard>
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
    Q_PROPERTY(QString result READ result NOTIFY resultChanged FINAL)
public:
    explicit Generation(QObject *parent = nullptr);
    ~Generation();

public:
    QString url() const;
    void setUrl(const QString& url);

    QString description() const;
    void setDescription(const QString& description);

    QString result() const;

    QQmlListProperty<Description> descriptions();
    QQmlListProperty<Description> parameters();

public:
    void generate();

private:
    QString m_url;
    QString m_description;
    QString m_result;
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
    void resultChanged();
};

#endif // GENERATION_H

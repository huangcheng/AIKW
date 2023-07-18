#ifndef GENERATION_H
#define GENERATION_H

#include <QObject>
#include <QString>
#include <QDebug>

class Generation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
public:
    explicit Generation(QObject *parent = nullptr);

public:
    QString url() const;
    void setUrl(const QString& url);

    QString description() const;
    void setDescription(const QString& description);

private:
    QString m_url;
    QString m_description;

public:
    Q_INVOKABLE QString generate();

signals:
    void urlChanged();
    void descriptionChanged();

};

#endif // GENERATION_H

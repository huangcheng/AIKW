#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QtQml/qqmlregistration.h>

class Description : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged FINAL)
    Q_PROPERTY(int weight READ weight WRITE setWeight NOTIFY weightChanged FINAL)
    QML_ELEMENT
public:
    explicit Description(QObject *parent = nullptr);

public:
    QString description() const;
    void setDescription(const QString& description);

    int weight() const;
    void setWeight(const int weight);

private:
    QString m_description;
    int m_weight;

signals:
    void descriptionChanged();
    void weightChanged();
};

#endif // DESCRIPTION_H

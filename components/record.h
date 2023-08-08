#ifndef RECORD_H
#define RECORD_H

#include <QObject>
#include <QString>

class Record : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT FINAL)
    Q_PROPERTY(QString description READ description CONSTANT FINAL)

public:
    explicit Record(QObject *parent = nullptr);
    Record(const QString name, const QString description);

public:
    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;

signals:

};

#endif // RECORD_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFontDatabase>
#include <QFont>
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QDir>

#include "generation.h"
#include "components/parameter.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    if (QFontDatabase::addApplicationFont(":/fonts/SourceHanSansSC-Regular.otf") == -1)
    {
        qDebug() << "Failed to load font Source Han Sans SC Regular";
    }

    if (QFontDatabase::addApplicationFont(":/fonts/SourceHanSansSC-Bold.otf") == -1)
    {
        qDebug() << "Failed to load font Source Han Sans SC Bold";
    }

    QFont font = QFontDatabase::font("Source Han Sans SC", "Regular", -1);

    app.setFont(font);

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", DATABASE_NAME);

    database.setDatabaseName(QCoreApplication::applicationDirPath() + QDir::separator() + "db.sqlite");
    database.open();

    if (!database.isOpen() || database.isOpenError())
    {
        qDebug() << "Failed to open the database";

        app.exit(-1);
    }

    Generation generation;

    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    QQmlContext *context = engine.rootContext();

    context->setContextProperty("generation", &generation);

    engine.addImportPath(QStringLiteral(":/"));

    engine.loadFromModule("AIKW", "Main");

    return app.exec();
}

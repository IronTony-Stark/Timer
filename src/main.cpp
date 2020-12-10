#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "include/timer.h"

int main(int argc, char* argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QGuiApplication::setOrganizationName("IronTony");
    QGuiApplication::setOrganizationDomain("github.com/IronTony-Stark");

    Timer timer;
    QStringListModel& timeListModel = timer.getTimeListModel();

    QQmlApplicationEngine engine;
    engine.addImportPath(":/qml");

    engine.rootContext()->setContextProperty(QStringLiteral("timer"), &timer);
    engine.rootContext()->setContextProperty(QStringLiteral("timeListModel"), &timeListModel);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject* obj, const QUrl& objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
    engine.load(url);

    return QGuiApplication::exec();
}

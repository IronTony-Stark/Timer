#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <include/timer.h>

int main(int argc, char* argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QGuiApplication::setOrganizationName("IronTony");
    QGuiApplication::setOrganizationDomain("github.com/IronTony-Stark");

    QQmlApplicationEngine engine;

    qmlRegisterType<Timer>("com.irontony.timer", 1, 0, "Timer");

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject* obj, const QUrl& objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
    engine.load(url);

    return QGuiApplication::exec();
}

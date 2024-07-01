#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "calculator_1_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    Calculator calculator;
    calculator.setWindowTitle("Calculator");
    calculator.resize(230,200);

    calculator.show();

    return a.exec();
}

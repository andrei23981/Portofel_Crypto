#include "utils.h"
#include <QLocale>
#include <QRegularExpression>

QString Utils::formatMoney(float value, int decimals)
{
    return QLocale().toString(value, 'f', decimals) + " RON";
}

QString Utils::formatCrypto(float value, int decimals)
{
    return QLocale().toString(value, 'f', decimals);
}

bool Utils::isValidAmount(const QString& text)
{
    QRegularExpression re("^\\d+(\\.\\d+)?$");
    return re.match(text).hasMatch();
}

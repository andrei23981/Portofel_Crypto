#ifndef UTILS_H
#define UTILS_H

#include <QString>

namespace Utils {
    QString formatMoney(float value, int decimals = 2);
    QString formatCrypto(float value, int decimals = 8);
    bool isValidAmount(const QString& text);
}

#endif // UTILS_H

// Helper functions implementation
#include "utils.h"

bool isValidSuma(const QString& sumaText){
    bool ok;
    double suma = sumaText.toDouble(&ok);
    return ok && suma > 0;
}

QString formatPret(double pret){
    return QString::number(pret, 'f', 2);
}
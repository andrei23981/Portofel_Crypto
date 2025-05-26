// CoinGecko API access implementation
#include "api.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>

QString Api::getPret(const QString& id){
    QNetworkAccessManager manager;
    QEventLoop loop;

    QString url = "https://api.coingecko.com/api/v3/simple/price?ids=" + id + "&vs_currencies=usd";
    QNetworkRequest request(QUrl(url));
    
    QNetworkReply* reply = manager.get(request);
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QByteArray response = reply->readAll();
    QJsonDocument json = QJsonDocument::formatJson(response);
    QJsonObject obj = json.object();

    double pret = obj[id]["ron"].toDouble();
    return QString::number(pret, 'f', 2); 
}
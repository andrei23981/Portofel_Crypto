#include "api.h"

API::API()
{
    manager = new QNetworkAccessManager();
}

API::~API()
{
    delete manager;
}

QString API::getPret(QString id)
{
    QEventLoop loop;
    QNetworkReply* reply;

    QString url = "https://api.coingecko.com/api/v3/simple/price?ids=" + id + "&vs_currencies=ron";
    QNetworkRequest request((QUrl(url)));

    reply = manager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() != QNetworkReply::NoError) {
        reply->deleteLater();
        return "Eroare API";
    }

    QByteArray response = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response);
    QJsonObject object = json.object();

    if (object.isEmpty() || !object.contains(id) || !object.value(id).toObject().contains("ron")) {
        reply->deleteLater();
        return "N/A";
    }

    double pret = object.value(id).toObject().value("ron").toDouble();
    reply->deleteLater();
    return QString::number(pret, 'f', 2);
}

QJsonArray API::getTopMonede(int limit)
{
    QEventLoop loop;
    QNetworkReply* reply;

    QString url = "https://api.coingecko.com/api/v3/coins/markets?vs_currency=ron&order=market_cap_desc&per_page=" + 
                  QString::number(limit) + "&page=1";
    QNetworkRequest request((QUrl(url)));
    
    reply = manager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QByteArray response = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response);
    QJsonArray array = json.array();

    reply->deleteLater();
    return array;
}

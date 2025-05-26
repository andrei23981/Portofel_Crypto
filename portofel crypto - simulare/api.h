#ifndef API_H
#define API_H

#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class API
{
public:
    API();
    ~API();
    
    QString getPret(QString id);
    QJsonArray getTopMonede(int limit = 10);
    
private:
    QNetworkAccessManager *manager;
};

#endif // API_H

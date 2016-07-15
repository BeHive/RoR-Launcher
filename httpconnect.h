
#ifndef HTTPCONNECT_H
#define HTTPCONNECT_H

#include <QNetworkAccessManager>
#include <QUrl>
#include <QObject>
#include "mainwindow.h"

class QNetworkReply;


class HttpConnect : public QObject
{
    Q_OBJECT

public:
    explicit HttpConnect(QObject *parent = Q_NULLPTR);

    void startRequest(const QUrl &requestedUrl);
    void getFile(const QString &fileName);
    void readXML(const QString &data);
    void readLocalXML();

    QString RORVERSION;
    QString RORPWDMODE;
    QString RORLOGINADDR;
    QString RORLOGINPORT;
    QString loginAddr;
    QString loginPort;
    MainWindow w;

private slots:
    void httpFinished();

private:
    QUrl url;
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
};

#endif

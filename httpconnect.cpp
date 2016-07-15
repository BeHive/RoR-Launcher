#include <QtNetwork>
#include <QUrl>
#include <QObject>
#include <QMessageBox>
#include "httpconnect.h"
#include "mainwindow.h"
HttpConnect::HttpConnect(QObject *parent) : QObject(parent){}

void HttpConnect::startRequest(const QUrl &requestedUrl)
{
    url = requestedUrl;
    reply = qnam.get(QNetworkRequest(url));
    connect(reply, &QNetworkReply::finished, this, &HttpConnect::httpFinished);
}

void HttpConnect::getFile(const QString &url)
{
    const QUrl newUrl = QUrl::fromUserInput(url);
    startRequest(newUrl);
}

void HttpConnect::httpFinished()
{
    HttpConnect::readXML(reply->readAll());
    HttpConnect::readLocalXML();

    qDebug() << RORVERSION;
    qDebug() << RORPWDMODE;
    qDebug() << RORLOGINADDR+":"+RORLOGINPORT;

    qDebug() << loginAddr+":"+loginPort;


}


void HttpConnect::readXML(const QString &data){

    QXmlStreamReader xmlReader;
    xmlReader.addData(data);

    while(!xmlReader.atEnd() && !xmlReader.hasError()) {
            // Read next element
            QXmlStreamReader::TokenType token = xmlReader.readNext();
            //If token is StartElement - read it
            if(token == QXmlStreamReader::StartElement) {
                    if(xmlReader.name() == "Launcher") {
                        while(!xmlReader.atEnd() && !xmlReader.hasError()) {
                            QXmlStreamReader::TokenType innerToken = xmlReader.readNext();
                            if(innerToken == QXmlStreamReader::StartElement) {
                                if(xmlReader.name() == "Version") {
                                    RORVERSION = xmlReader.readElementText();
                                }
                                if(xmlReader.name() == "PasswordMode") {
                                    RORPWDMODE = xmlReader.readElementText();
                                }
                                if(xmlReader.name() == "LauncherServer") {
                                    while(!xmlReader.atEnd() && !xmlReader.hasError()) {
                                        QXmlStreamReader::TokenType LauncherServerToken = xmlReader.readNext();
                                        if(LauncherServerToken == QXmlStreamReader::StartElement) {
                                            if(xmlReader.name() == "Ip") {
                                                RORLOGINADDR = xmlReader.readElementText();
                                            }
                                            if(xmlReader.name() == "Port") {
                                                RORLOGINPORT = xmlReader.readElementText();
                                            }

                                        }
                                    }
                                }
                            }
                        }
                    }
            }
    }

}

void HttpConnect::readLocalXML(){

    QString filename = "mythloginserviceconfig.xml";
    QXmlStreamReader xmlReader;

    QFile xmlFile(filename);
            if (!xmlFile.open(QFile::ReadOnly | QFile::Text)) {
                QMessageBox msgBox;
                msgBox.setText("error");
                msgBox.exec();
            }
    xmlReader.setDevice(&xmlFile);


    while(!xmlReader.atEnd() && !xmlReader.hasError()) {
            // Read next element
            QXmlStreamReader::TokenType token = xmlReader.readNext();
            //If token is StartElement - read it
            if(token == QXmlStreamReader::StartElement) {
                    if(xmlReader.name() == "LoginServer") {
                        while(!xmlReader.atEnd() && !xmlReader.hasError()) {
                            QXmlStreamReader::TokenType innerToken = xmlReader.readNext();
                            if(innerToken == QXmlStreamReader::StartElement) {
                                if(xmlReader.name() == "Address") {
                                    loginAddr = xmlReader.readElementText();
                                }
                                if(xmlReader.name() == "Port") {
                                    loginPort = xmlReader.readElementText();
                                }
                            }
                        }
                    }
            }
    }

}

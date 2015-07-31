#ifndef MEGADOWNLOADER_H
#define MEGADOWNLOADER_H

#include <QObject>
#include <QString>
#include <QFileInfo>
#include <QDir>
#include <QQueue>
#include <QMap>
#include "megaapi.h"

class MegaDownloader : public QObject
{
    Q_OBJECT

public:
    MegaDownloader(mega::MegaApi *megaApi);
    virtual ~MegaDownloader();
    void processDownloadQueue(QQueue<mega::MegaNode *> *downloadQueue, QString path, mega::MegaApi *megaApiLinks = NULL);
    void download(mega::MegaNode *parent, QString path, mega::MegaApi *apiLinks = NULL);

signals:
    void dupplicateDownload(QString localPath, QString name, mega::MegaHandle handle);

protected:
    void download(mega::MegaNode *parent, QFileInfo info, mega::MegaApi *apiLinks = NULL);

    mega::MegaApi *megaApi;
    QMap<mega::MegaHandle, QString> pathMap;
};

#endif // MEGADOWNLOADER_H

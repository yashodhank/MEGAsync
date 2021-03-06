
#ifndef _MEGA_SYNC_PLUGIN_H_
#define _MEGA_SYNC_PLUGIN_H_

#include <kabstractfileitemactionplugin.h>
#include <QLocalSocket>

class MEGASyncPlugin: public KAbstractFileItemActionPlugin
{
    Q_OBJECT
private:
    QLocalSocket sock;
    QString sockPath;
    QString selectedFilePath;
    int getState();
    QString sendRequest(char type, QString command);
public:
    MEGASyncPlugin(QObject* parent = 0, const QVariantList & args = QVariantList());
    virtual ~MEGASyncPlugin();
    virtual QList<QAction*> actions(const KFileItemListProperties & fileItemInfos, QWidget * parentWidget);

private slots:
    void getLink();
    void uploadFile();
};

#endif

#ifndef NYSSE_WRAP_HH
#define NYSSE_WRAP_HH

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>


class BusDataFetcher : public QObject
{
    Q_OBJECT

public:
    explicit BusDataFetcher(QObject *parent = nullptr);
    ~BusDataFetcher();

    void fetchData(const QString &busStopId);

signals:
    void dataReceived(const QString &data);
    void errorOccurred(const QString &errorMessage);

private slots:
    void onNetworkReplyFinished();

private:
    QNetworkAccessManager *networkManager;
};


#endif // NYSSE_WRAP_HH

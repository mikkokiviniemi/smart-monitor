#include "nysse_wrap.hh"
#include <QNetworkRequest>
#include <QUrlQuery>

BusDataFetcher::BusDataFetcher(QObject *parent) : QObject(parent)
{
    // Initialize the network manager
    networkManager = new QNetworkAccessManager(this);

    // Connect the finished signal of the network manager to our slot
    connect(networkManager, &QNetworkAccessManager::finished, this, &BusDataFetcher::onNetworkReplyFinished);
}

BusDataFetcher::~BusDataFetcher()
{
    // Clean up the network manager
    delete networkManager;
}

void BusDataFetcher::fetchData(const QString &busStopId)
{
    // Define the URL for the bus data API
    QUrl url("http://data.itsfactory.fi/journeys/api/1/journeys");
    QUrlQuery query;

    // Add parameters to the URL
    query.addQueryItem("stopPointId", busStopId);

    // Determine the current day of the week (0 = Monday, 6 = Sunday)
    int today = QDate::currentDate().dayOfWeek() - 1; // Adjust for 0-based index

    if (today < 0) {
        today = 6; // Sunday
    }

    QString weekdays[] = {"0", "1", "2", "3", "4", "5", "6"};
    query.addQueryItem("dayTypes", weekdays[today]);

    url.setQuery(query);

    // Create a network request
    QNetworkRequest request(url);

    // Perform a GET request to fetch data
    networkManager->get(request);
}

void BusDataFetcher::onNetworkReplyFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());

    if (reply && reply->error() == QNetworkReply::NoError) {
        // Read the response data
        QString data = QString::fromUtf8(reply->readAll());

        // Emit the dataReceived signal
        emit dataReceived(data);
    } else {
        // Handle the error
        QString errorMessage = "Error fetching bus data: " + reply->errorString();

        // Emit the errorOccurred signal
        emit errorOccurred(errorMessage);
    }

    // Clean up the reply object
    reply->deleteLater();
}

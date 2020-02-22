#pragma once

// =======================INCLUDES
#include <QObject>
#include <QThread>
// =======================SYNOPSIS
// ===============================

class QNetworkAccessManager;
class QNetworkReply;

// ===============================
class APIHandler : public QObject
// ===============================
{
   Q_OBJECT
public:
   APIHandler( QObject *parent = nullptr );
   ~APIHandler();

   void requestAllRoutes();
   void requestRouteSchedule( const QString& number );

signals:
   void allRoutesReceived    ( const QJsonDocument& json );
   void routeScheduleReceived( const QJsonDocument& json );

protected slots:
   void replyHandler( QNetworkReply* reply );

private:
   QNetworkAccessManager *m_networkAccessManager;

   QThread m_apiThread;

   class LastRequestInfo
   {
   public:
      enum REQUEST_TYPE
      {
         ALL_ROUTES = 0,
         ROUTE_SCHEDULE,

         UNKNOWN
      };

      LastRequestInfo ()
         : m_type     ( UNKNOWN )
         , m_requestID( -1 )
      {};

      REQUEST_TYPE getRequestType() const { return m_type; }
      int          getRequestID  () const { return m_requestID; }

      int generateNewRequestID( const REQUEST_TYPE type )
      {
         m_type = type;
         return ++m_requestID;
      }

   private:
      REQUEST_TYPE m_type;
      int          m_requestID;
   } m_lastRequestInfo;
};

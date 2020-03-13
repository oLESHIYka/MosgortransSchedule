// =======================INCLUDES
#include "APIHandler.h"
// =======================SYNOPSIS
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkProxy>
#include <QSettings>
// ===============================

// =======================CONSTANTS
static const QString c_HttpAPIPrefix            = "http://c926788g.bget.ru/MosgortransSchedule/php/";
static const QString c_allRoutesRequetURL       = c_HttpAPIPrefix + "GetAllRoutes.php";
static const QString c_routesScheduleRequetURL  = c_HttpAPIPrefix + "GetRouteSchedule.php";
// ===============================

// ===============================
APIHandler::APIHandler( QObject *parent )
   : QObject( parent )
   , m_apiThread( parent )
// ===============================
{
   m_networkAccessManager = new QNetworkAccessManager( this );

   QObject::connect(
      m_networkAccessManager, &QNetworkAccessManager::finished,
      this                  , &APIHandler::replyHandler      
   );

   m_apiThread.start();

   moveToThread(&m_apiThread);
}

// ===============================
APIHandler::~APIHandler()
// ===============================
{
   moveToThread(0);
   m_apiThread.terminate();
}

// ===============================
void APIHandler::init()
// ===============================
{
   QSettings settings( "./configuration.ini", QSettings::IniFormat ); // TO DO: вынести в singleton!!

   if ( settings.status() == QSettings::NoError )
   {
      if ( settings.childGroups().contains("HttpProxy") )
      {
         settings.beginGroup("HttpProxy");
            if (  settings.contains("Host")
               && settings.contains("Port")
               )
            {
               QNetworkProxy proxy;

               proxy.setType( QNetworkProxy::HttpProxy );
               proxy.setHostName( settings.value( "Host" ).toString() );
               proxy.setPort    ( settings.value( "Port" ).toInt() );

               m_networkAccessManager->setProxy( proxy );
            }
         settings.endGroup();
      }
   }
   else
   {
      auto status = settings.status();
   }
}

// ===============================
void APIHandler::requestAllRoutes()
// ===============================
{
   auto requestURL = QUrl( c_allRoutesRequetURL );

   QUrlQuery query;
   query.addQueryItem( "requestID", QString::number( m_lastRequestInfo.generateNewRequestID( LastRequestInfo::REQUEST_TYPE::ALL_ROUTES ) ) );

   requestURL.setQuery(query);

   m_networkAccessManager->get( QNetworkRequest( requestURL ) );
}

// ===============================
void APIHandler::requestRouteSchedule( const QString& number )
// ===============================
{
   auto requestURL = QUrl ( c_routesScheduleRequetURL );
   
   QUrlQuery query;
   query.addQueryItem( "number"   , number );
   query.addQueryItem( "requestID", QString::number( m_lastRequestInfo.generateNewRequestID( LastRequestInfo::REQUEST_TYPE::ROUTE_SCHEDULE ) ) );

   requestURL.setQuery( query );
   m_networkAccessManager->get( QNetworkRequest( requestURL ) );
}

// ===============================
void APIHandler::replyHandler( QNetworkReply* reply )
// ===============================
{
   auto jsonStr = reply->readAll();
   auto json = QJsonDocument::fromJson( jsonStr );

   if ( json.isObject() )
   {
      auto jsonObj = json.object();
      auto recivedRequestID = jsonObj["requestID"].toInt();

      if ( recivedRequestID == m_lastRequestInfo.getRequestID() )
      {
         switch ( m_lastRequestInfo.getRequestType() )
         {
            case LastRequestInfo::REQUEST_TYPE::ALL_ROUTES:
            {
               if ( jsonObj["data"].isObject() )
               {
                  const auto data = QJsonDocument( jsonObj["data"].toObject() );

                  emit allRoutesReceived( data );
               }
               else
               {
                  // Unexpected data received
                  // TO DO: emit error signal to display error
               }

               break;
            }
            case LastRequestInfo::REQUEST_TYPE::ROUTE_SCHEDULE:
            {
               if ( jsonObj["data"].isArray() )
               {
                  const auto data = QJsonDocument( jsonObj["data"].toArray() );

                  emit routeScheduleReceived( data );
               }
               else
               {
                  // Unexpected data received
                  // TO DO: emit error signal to display error
               }

               break;
            }
            case LastRequestInfo::REQUEST_TYPE::UNKNOWN:
            default:
            {
               // Request type is unknown
               // TO DO: emit error signal to display error
               break;
            }
         }
      }
      else if ( recivedRequestID > m_lastRequestInfo.getRequestID() )
      {
         // Received unknown ID
         // TO DO: error to log
      }
      else
      {
         // Received out of date request
         // TO DO: error to log
      }
   }
   else
   {
      // Received unexpected data
   }
}
// ========================================= INCLUDES
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
// ========================================= SYNOPSIS
#include "MosgortransSchedule\Data\RoutesScheduleData\RoutesScheduleData.h"
// ==================================================

// ==================================================
RoutesScheduleData::RoutesScheduleData( QObject* parent )
   : BaseScheduleData( parent )
// ==================================================
{
   m_data = std::make_shared< RoutesSchedule >();
}

// ==================================================
void RoutesScheduleData::clearData()
// ==================================================
{
   m_data->clear();
}

// ==================================================
void RoutesScheduleData::updateFromJSON( const QJsonDocument& data )
// ==================================================
{
   if ( data.isArray() )
   {
      auto routesSchedule = data.array();

      foreach ( const QJsonValue &value, routesSchedule )
      {
         if ( value.isObject() )
         {
            auto routeDataPtr = std::make_shared< RouteScheduleData >( this );

            routeDataPtr->updateFromJSON( QJsonDocument( value.toObject() ) );

            m_data->push_back( routeDataPtr );
         }
      }
   }
}

// ==================================================
void RouteScheduleData::updateFromJSON( const QJsonDocument& data )
// ==================================================
{
   if ( data.isObject() )
   {
      static std::map< QString, ROUTE_TYPE > s_routeTypeMap
      {
         { "avto", ROUTE_TYPE::BUS },
         { "trol", ROUTE_TYPE::TROL },
         { "tram", ROUTE_TYPE::TRAM }
      };

      auto routeScheduleData = data.object();

      if ( routeScheduleData["type"].isString() )
      {
         auto routeTypeIt = s_routeTypeMap.find( routeScheduleData["type"].toString() );
         if ( routeTypeIt != s_routeTypeMap.cend())
         {
            m_type = routeTypeIt->second;
         }
      }

      if ( routeScheduleData["number"].isString() )
      {
         m_number = routeScheduleData["number"].toString();
      }

      if ( routeScheduleData["directionsSchedule"].isArray() )
      {
         auto directionsSchedule = routeScheduleData["directionsSchedule"].toArray();

         m_directionsSchedule.updateFromJSON( QJsonDocument( routeScheduleData["directionsSchedule"].toArray() ) );
      }
   }
}
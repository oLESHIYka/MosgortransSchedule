// ========================================= INCLUDES
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
// ========================================= SYNOPSIS
#include "MosgortransSchedule\Data\RoutesScheduleData\RoutesScheduleData.h"
// ==================================================

//// ==================================================
//RouteScheduleData::RouteScheduleData( const RouteScheduleData& data )
//   : BaseScheduleData( data )
//   , m_type( data.getType() )
//   , m_number( data.getNumber() )
//   , m_directionsSchedule( data.getDirectionsSchedule() )
//// ==================================================
//{
//
//}

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

            m_data.push_back( routeDataPtr );
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
      static std::map<QString, ROUTE_TYPE> routeTypeMap
      {
         { "avto", ROUTE_TYPE::BUS }
      };
   }
}
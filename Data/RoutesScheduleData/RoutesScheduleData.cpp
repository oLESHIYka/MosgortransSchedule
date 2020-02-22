// ========================================= INCLUDES
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonDocument>
// ========================================= SYNOPSIS
#include "MosgortransSchedule\Data\RoutesScheduleData\RoutesScheduleData.h"
// ==================================================

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

         }
      }
   }
}

// ==================================================
void RouteScheduleData::updateFromJSON( const QJsonDocument& data )
// ==================================================
{
   
}
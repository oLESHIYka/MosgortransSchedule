// ========================================= INCLUDES
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
// ========================================= SYNOPSIS
#include "MosgortransSchedule\Data\DirectionsScheduleData\DirectionsScheduleData.h"
// ==================================================

// ==================================================
void DirectionsScheduleData::updateFromJSON( const QJsonDocument& data )
// ==================================================
{
   if ( data.isArray() )
   {
      auto directionsSchedule = data.array();

      static std::map< QString, DIRECTION_TYPE > s_directionTypeMap
      {
         { "AB", DIRECTION_TYPE::AB },
         { "BA", DIRECTION_TYPE::BA }
      };

      foreach ( const QJsonValue &value, directionsSchedule )
      {
         if ( value.isObject() )
         {
            auto directionSchedule = value.toObject();

            if ( directionSchedule["type"].isString() )
            {
               auto typeIt = s_directionTypeMap.find( directionSchedule["type"].toString() );
               if ( typeIt != s_directionTypeMap.cend() )
               {
                  DirectionScheduleDataPtr directionDataPtr = std::make_shared< DirectionScheduleData >( this );

                  directionDataPtr->updateFromJSON( QJsonDocument( directionsSchedule ) );

                  m_directionScheduleData[typeIt->second] = directionDataPtr;

                  if ( m_curDirection == DIRECTION_TYPE::UNKNOWN )
                  {
                     m_curDirection = typeIt->second;
                  }
               }
            }
         }
      }
   }
}


// ==================================================
void DirectionScheduleData::parseStations( const QString& combinedStations )
// ==================================================
{

}

// ==================================================
void DirectionScheduleData::updateFromJSON( const QJsonDocument& data )
// ==================================================
{
   
}
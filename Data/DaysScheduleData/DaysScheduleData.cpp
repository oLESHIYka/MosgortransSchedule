// ========================================= INCLUDES
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
// ========================================= SYNOPSIS
#include "MosgortransSchedule\Data\DaysScheduleData\DaysScheduleData.h"
// ==================================================

// ==================================================
void DaysScheduleData::updateFromJSON( const QJsonDocument& data )
// ==================================================
{
   if ( data.isArray() )
   {
      auto daysSchedule = data.array();

      foreach( const QJsonValue &daySchedule, daysSchedule)
      {
         if (  daySchedule.isObject()
            && daySchedule["days"].isString()
            )
         {
            auto dayScheduleData = std::make_shared< DayScheduleData >(this);

            dayScheduleData->updateFromJSON( QJsonDocument( daySchedule.toObject() ) );

            m_daysSchedule[daySchedule["days"].toString()] = dayScheduleData;
         }
      }
   }
}

// ==================================================
void DayScheduleData::updateFromJSON( const QJsonDocument& data )
// ==================================================
{
   if ( data.isObject() )
   {
      auto daySchedule = data.object();

      if ( daySchedule["schedule"].isString() )
      {
         m_daySchedule = daySchedule["schedule"].toString();
      }
   }
}
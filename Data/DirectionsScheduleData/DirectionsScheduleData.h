#pragma once
// ========================================= INCLUDES
#include <unordered_map>
#include <memory>
// ========================================= SYNOPSIS
#include "MosgortransSchedule\Data\BaseScheduleData\BaseScheduleData.h"
#include "MosgortransSchedule\Data\DaysScheduleData\DaysScheduleData.h"
// ==================================================

// ==================================================
class DirectionScheduleData : public BaseScheduleData
// ==================================================
{
   Q_OBJECT

public:
   DirectionScheduleData( QObject* parent = nullptr ) : BaseScheduleData( parent ) {};

   virtual void updateFromJSON( const QJsonDocument& data ) override;

private:
   QString m_fromStation;
   QString m_toStation;
   DaysScheduleData m_daysSchedule;
};


// ==================================================
class DirectionsScheduleData : public BaseScheduleData
// ==================================================
{
   Q_OBJECT

public:
   DirectionsScheduleData( QObject* parent = nullptr ) : BaseScheduleData( parent ), m_curDirection( DIRECTION_TYPE::UNKNOWN ) {};

   virtual void updateFromJSON( const QJsonDocument& data ) override;

   enum DIRECTION_TYPE
   {
      AB = 0,
      BA,

      UNKNOWN
   };
private:
   DIRECTION_TYPE m_curDirection;

   using DirectionScheduleDataPtr = std::shared_ptr< DirectionScheduleData >;
   std::unordered_map< DIRECTION_TYPE, DirectionScheduleDataPtr > m_directionScheduleData;
};

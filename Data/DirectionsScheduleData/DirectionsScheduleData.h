#pragma once
// ========================================= INCLUDES
#include <unordered_map>
// ========================================= SYNOPSIS
#include "MosgortransSchedule\Data\BaseScheduleData\BaseScheduleData.h"
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
};


// ==================================================
class DirectionsScheduleData : public BaseScheduleData
// ==================================================
{
   Q_OBJECT

public:
   DirectionsScheduleData( QObject* parent = nullptr ) : BaseScheduleData( parent ) {};

   virtual void updateFromJSON( const QJsonDocument& data ) override;

   enum DIRECTION_TYPE
   {
      AB = 0,
      BA
   };
private:
   DIRECTION_TYPE m_curDirection;
   std::unordered_map< DIRECTION_TYPE, DirectionScheduleData > m_directionScheduleData;
};

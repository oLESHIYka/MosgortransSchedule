#pragma once
// ========================================= INCLUDES
// ========================================= SYNOPSIS
#include "MosgortransSchedule\Data\BaseScheduleData\BaseScheduleData.h"
// ==================================================

// ==================================================
class RouteScheduleData : public BaseScheduleData
// ==================================================
{
   Q_OBJECT

public:
   RouteScheduleData( QObject* parent = nullptr ) : BaseScheduleData( parent ) {};

   enum ROUTE_TYPE
   {
      BUS = 0,
      TROL,
      TRAM
   };

   virtual void updateFromJSON( const QJsonDocument& data ) override;
private:
   ROUTE_TYPE m_type;
   QString m_number;
   DirectionsScheduleData m_directionsSchedule;
};

// ==================================================
class RoutesScheduleData : public BaseScheduleData
// ==================================================
{
   Q_OBJECT

public:
   RoutesScheduleData( QObject* parent = nullptr ) : BaseScheduleData( parent ) {};

   virtual void updateFromJSON( const QJsonDocument& data ) override;

private:
   std::vector<RouteScheduleData> m_Data;
};

#pragma once
// ========================================= INCLUDES
#include <memory>
// ========================================= SYNOPSIS
#include "MosgortransSchedule\Data\BaseScheduleData\BaseScheduleData.h"
#include "MosgortransSchedule\Data\DirectionsScheduleData\DirectionsScheduleData.h"
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

         ROUTE_TYPE              getType              () const { return m_type; }
         QString                 getNumber            () const { return m_number; }
   const DirectionsScheduleData& getDirectionsSchedule() const { return m_directionsSchedule; }
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
   using RouteScheduleDataPtr = std::shared_ptr< RouteScheduleData >;
   std::vector<RouteScheduleDataPtr> m_data;
};

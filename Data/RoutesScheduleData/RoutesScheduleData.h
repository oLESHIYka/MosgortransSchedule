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
   RoutesScheduleData( QObject* parent = nullptr );

   virtual void updateFromJSON( const QJsonDocument& data ) override;

   void clearData();


   using RouteScheduleDataPtr = std::shared_ptr< RouteScheduleData >;
   using RoutesSchedule       = std::vector    < RouteScheduleDataPtr >;
   using RoutesSchedulePtr    = std::shared_ptr< RoutesSchedule >;

   RoutesSchedulePtr getData() const { return m_data; }

signals:
   void updated( const RoutesSchedulePtr& data );

private:
   RoutesSchedulePtr m_data;
};

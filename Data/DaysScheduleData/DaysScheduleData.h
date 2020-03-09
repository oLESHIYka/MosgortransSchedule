#pragma once
// ========================================= INCLUDES
#include <QHash>
#include <memory>
// ========================================= SYNOPSIS
#include "MosgortransSchedule\Data\BaseScheduleData\BaseScheduleData.h"
// ==================================================

// ==================================================
class DayScheduleData : public BaseScheduleData
// ==================================================
{
   Q_OBJECT

public:
   DayScheduleData( QObject* parent = nullptr ) : BaseScheduleData( parent ) {};

   virtual void updateFromJSON( const QJsonDocument& data ) override;

private:
   QString m_daySchedule;
};


// ==================================================
class DaysScheduleData : public BaseScheduleData
// ==================================================
{
   Q_OBJECT

public:
   DaysScheduleData( QObject* parent = nullptr ) : BaseScheduleData( parent ) {};

   virtual void updateFromJSON( const QJsonDocument& data ) override;

private:
   using DayScheduleDataPtr = std::shared_ptr< DayScheduleData >;
   QHash< QString, DayScheduleDataPtr > m_daysSchedule;
};


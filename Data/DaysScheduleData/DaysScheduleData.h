#pragma once
// ========================================= INCLUDES
#include <QHash>
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
   QHash< QString, DayScheduleData > m_daysSchedule;
};


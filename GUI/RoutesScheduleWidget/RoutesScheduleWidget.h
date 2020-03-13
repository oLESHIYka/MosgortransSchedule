#pragma once
// ========================================= INCLUDES
#include <QToolBar>
// ========================================= SYNOPSIS
#include "MosgortransSchedule\GUI\BaseScheduleGUIElement\BaseScheduleGUIElement.h"
#include "MosgortransSchedule\Data\RoutesScheduleData\RoutesScheduleData.h"
// ==================================================

// ==================================================
class RoutesScheduleWidget : public BaseScheduleGUIElement < QToolBar >
// ==================================================
{
   Q_OBJECT

   using BaseWidget = BaseScheduleGUIElement < QToolBar >;
public:
   RoutesScheduleWidget( QWidget *parent = nullptr );

   virtual void setData( const DataPointer _data ) override;

   //virtual DataPointer getData() const override;

private:
   std::shared_ptr< RoutesScheduleData > m_routesSchedule;
};

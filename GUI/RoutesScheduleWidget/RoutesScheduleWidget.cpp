// ========================================= INCLUDES
// ========================================= SYNOPSIS
#include "MosgortransSchedule\GUI\RoutesScheduleWidget\RoutesScheduleWidget.h"
// ==================================================

// ==================================================
RoutesScheduleWidget::RoutesScheduleWidget( QWidget *parent )
   : BaseWidget ( parent )
// ==================================================
{
   //m_routesSchedule = std::make_shared< RoutesScheduleData >( this );
}

// ==================================================
void RoutesScheduleWidget::setData( const DataPointer _data )
// ==================================================
{
   m_routesSchedule = std::static_pointer_cast< RoutesScheduleData >( _data );
}
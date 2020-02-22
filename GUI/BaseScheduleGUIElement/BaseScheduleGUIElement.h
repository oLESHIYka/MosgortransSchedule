#pragma once
// ========================================= INCLUDES
#include <QWidget>
#include <QThread>
// ========================================= SYNOPSIS
#include "MosgortransSchedule\Data\BaseScheduleData\BaseScheduleData.h"
// ==================================================

template< class BaseWidget >
class BaseScheduleGUIElement : public BaseWidget
{
   static_assert( std::is_base_of< QWidget, BaseWidget >::value, "BaseWidget must be inherited from QWidget" );

public:
   BaseScheduleGUIElement( QWidget* parent = nullptr );
   //~BaseScheduleGUIElement();

   using DataPointer = std::shared_ptr< BaseScheduleData >;
   virtual void setData           ( DataPointer _data ) = 0;

           void updateFromData    ( DataPointer _data );

   virtual void updateFromDataImpl() {}

   //virtual void init();
   //
   //using DataPointer = std::shared_ptr< BaseScheduleData >;
   //virtual DataPointer getData() const = 0;
   //
//private:
   //QThread m_dataThread;
};

// ==================================================
template< class BaseWidget >
BaseScheduleGUIElement<BaseWidget>::BaseScheduleGUIElement( QWidget *parent )
   : BaseWidget( parent )
// ==================================================
{

}

// ==================================================
template< class BaseWidget >
void BaseScheduleGUIElement< BaseWidget >::updateFromData( DataPointer _data )
// ==================================================
{
   setData( _data );

   updateFromDataImpl();
}

//// ==================================================
//template< class BaseWidget >
//void BaseScheduleGUIElement<BaseWidget>::init()
//// ==================================================
//{
//   if ( auto data = getData() )
//   {
//      m_dataThread.start();
//      
//      data->moveToThread( &m_dataThread );
//   }
//} 
//
//// ==================================================
//template< class BaseWidget >
//BaseScheduleGUIElement<BaseWidget>::~BaseScheduleGUIElement()
//// ==================================================
//{
//   m_dataThread.terminate();
//}

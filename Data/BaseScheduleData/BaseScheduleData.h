#pragma once
// ========================================= INCLUDES
#include <QObject>
// ========================================= SYNOPSIS
// ==================================================

class BaseScheduleData : public QObject
{
  Q_OBJECT

public:
   BaseScheduleData( QObject* parent = nullptr ) : QObject( parent ) {}

   virtual void updateFromJSON( const QJsonDocument& data ) = 0;
};
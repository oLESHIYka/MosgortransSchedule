// ========================================= INCLUDES
#include <QTextEdit>
#include <QJsonDocument>
// ========================================= SYNOPSIS
#include "MosgortransSchedule.h"
#include "ui_MosgortransSchedule.h"
#include "APIHandler\APIHandler.h"
// ==================================================

// ==================================================
MosgortransSchedule::MosgortransSchedule(QWidget *parent)
   : QMainWindow ( parent )
   , m_routesSchedule ( this )
// ==================================================
{
   m_ui = new Ui::MosgortransSchedule();
   m_ui->setupUi( this );

   m_apiHandler = std::make_shared< APIHandler >( this );

   // $$$ TEMP
   //m_textEdit   = std::make_shared< QTextEdit > ( this );

   m_ui->gridLayout->addWidget( &m_routesSchedule );
}

// ==================================================
MosgortransSchedule::~MosgortransSchedule()
// ==================================================
{
   delete m_ui;
}

// ==================================================
void MosgortransSchedule::init()
// ==================================================
{
   QObject::connect(
      m_apiHandler.get(), &APIHandler::allRoutesReceived,
      [this]( const QJsonDocument& json )
      {
         // Заполнение списка всех доступных маршрутов. Будет использоваться для валидации ввода и отображения подсказок
      }
   );

   QObject::connect(
      m_ui->findRows, &QPushButton::clicked,
      [this]
      {
         const QString routeNumber = m_ui->routeNumber->text();
         if ( !routeNumber.isEmpty() )
         {
            emit m_apiHandler->requestRouteSchedule( routeNumber );
         }
      }
   );

   QObject::connect(
      m_apiHandler.get(), &APIHandler::routeScheduleReceived,
      [this]( const QJsonDocument& json )
      {
         QString jsonStr = json.toJson();

         //m_textEdit->setText( jsonStr );
      }
   );
}

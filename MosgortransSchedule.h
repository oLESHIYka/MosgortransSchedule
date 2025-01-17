#pragma once
// ========================================= INCLUDES
#include <QMainWindow>
#include <QTHread>
#include <memory>
// ========================================= SYNOPSIS
#include "MosgortransSchedule\GUI\RoutesScheduleWidget\RoutesScheduleWidget.h"
#include "MosgortransSchedule\\Data\RoutesScheduleData\RoutesScheduleData.h"
// ==================================================

namespace Ui { class MosgortransSchedule; };
class APIHandler;

class QTextEdit;

// ==================================================
class MosgortransSchedule : public QMainWindow
// ==================================================
{
    Q_OBJECT

public:
    MosgortransSchedule(QWidget *parent = Q_NULLPTR);
    ~MosgortransSchedule();

    void init();

private:
    Ui::MosgortransSchedule *m_ui;

    std::shared_ptr< APIHandler > m_apiHandler;

    RoutesScheduleWidget m_routesSchedule;

    using RoutesScheduleDataPtr = std::shared_ptr< RoutesScheduleData >;
    RoutesScheduleDataPtr m_routesScheduleData;

    QThread m_routesScheduleDataThread;

    // $$$ TEMP
    //std::shared_ptr< QTextEdit > m_textEdit;
};

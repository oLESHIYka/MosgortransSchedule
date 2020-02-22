#pragma once
// ========================================= INCLUDES
#include <QMainWindow>
#include <memory>
// ========================================= SYNOPSIS
#include "MosgortransSchedule\GUI\RoutesScheduleWidget\RoutesScheduleWidget.h"
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

    // $$$ TEMP
    std::shared_ptr< QTextEdit > m_textEdit;
};

#include "EyeLeoX.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>
#include <QVBoxLayout>

EyeLeoX::EyeLeoX(QWidget *parent)
	: QDialog(parent)
{
	settingUi.setupUi(this);
	
	initSettings();
	createTrayIcon();
}

EyeLeoX::~EyeLeoX()
{

}

void EyeLeoX::closeEvent(QCloseEvent *e)
{
	hide();
	e->ignore();
}

void EyeLeoX::initSettings()
{

}

void EyeLeoX::createTrayIcon()
{
	// TrayIconMenu actions
	m_settingAction = new QAction("EyeLeoX Settings", this);
	connect(m_settingAction, &QAction::triggered, this, &EyeLeoX::show);
	m_pauseAction = new QAction("Pause monitoring", this);
	connect(m_pauseAction, &QAction::triggered, this, &EyeLeoX::onPauseActionTriggered);
	m_quitAction = new QAction("Quit", this);
	connect(m_quitAction, &QAction::triggered, qApp, &QApplication::quit);
	
	// TrayIconMenu
	m_trayIconMenu = new QMenu(this);
	m_trayIconMenu->addAction(m_settingAction);
	m_trayIconMenu->addAction(m_pauseAction);
	m_trayIconMenu->addSeparator();
	m_trayIconMenu->addAction(m_quitAction);
	
	// TrayIcon
	m_trayIcon = new QSystemTrayIcon(QIcon(":/EyeLeoX/trayIcon"), this);
	m_trayIcon->setContextMenu(m_trayIconMenu);
	m_trayIcon->show();
}

void EyeLeoX::onPauseActionTriggered()
{
	static const QString pauseStr = "Pause monitoring";
	static const QString resumeStr = "Resume monitoring";

	if (pauseStr == m_pauseAction->text()) {
		// Stop timer
		//@todo
		m_pauseAction->setText(resumeStr);
	} else {
		// Resume timer
		//@todo
		m_pauseAction->setText(pauseStr);
	}
}
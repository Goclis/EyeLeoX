#include "EyeLeoX.h"
#include "SettingWidget.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>

EyeLeoX::EyeLeoX(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	createActions();
	createTrayIcon();

	m_settingWidget = new SettingWidget(this);
}

EyeLeoX::~EyeLeoX()
{

}

void EyeLeoX::closeEvent(QCloseEvent *e)
{
	hide();
	e->ignore();
}

void EyeLeoX::createActions()
{
	m_settingAction = new QAction("EyeLeoX Settings", this);
	connect(m_settingAction, &QAction::triggered, this, &EyeLeoX::show);

	m_pauseAction = new QAction("Pause monitoring", this);
	connect(m_pauseAction, &QAction::triggered, this, &EyeLeoX::onPauseActionTriggered);

	m_quitAction = new QAction("Quit", this);
	connect(m_quitAction, &QAction::triggered, qApp, &QApplication::quit);
}

void EyeLeoX::createTrayIcon()
{
	m_trayIconMenu = new QMenu(this);
	m_trayIconMenu->addAction(m_settingAction);
	m_trayIconMenu->addAction(m_pauseAction);
	m_trayIconMenu->addSeparator();
	m_trayIconMenu->addAction(m_quitAction);

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
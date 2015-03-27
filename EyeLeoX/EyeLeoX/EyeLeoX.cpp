#include "EyeLeoX.h"
#include "ShortBreakWidget.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>
#include <QTimer>
#include <QDebug>

EyeLeoX::EyeLeoX(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	initSettings();
	restartMonitor();
	createTrayIcon();
}

EyeLeoX::~EyeLeoX()
{
	if (m_shortBreak)
		delete m_shortBreak;
}

void EyeLeoX::closeEvent(QCloseEvent *e)
{
	hide();
	e->ignore();
}

void EyeLeoX::initSettings()
{
	// 设置初始值
	m_longBreakInterval = getCurrentLongBreakInterval();
	m_longBreakDuration = getCurrentLongBreakDuration();
	m_longBreakNotificationTime = getCurrentLongBreakNotificationTime();
	m_shortBreakInterval = getCurrentShortBreakInterval();
	
	m_enableLongBreak = ui.longBreakCkBox->isChecked();
	m_enableLongBreakNotify = ui.notifyLongBreakCkBox->isChecked();
	m_enableShortBreak = ui.shortBreakCkBox->isChecked();
	m_enableSound = ui.soundEnableCkBox->isChecked();

	// 设置界面的按钮响应
	connect(ui.tryShortBreakBtn, &QPushButton::clicked, 
		this, &EyeLeoX::onTryShortBreakBtnClicked);
	connect(ui.tryLongBreakBtn, &QPushButton::clicked, 
		this, &EyeLeoX::onTryLongBreakBtnClicked);
	connect(ui.saveAndCloseBtn, &QPushButton::clicked,
		this, &EyeLeoX::onSaveAndCloseBtnClicked);

	// 监视器相关设置
	m_regularTimer = new QTimer(this);
	m_regularTimer->setSingleShot(true);
	m_regularTimer->setInterval(m_timerInterval * 1000);
	connect(m_regularTimer, &QTimer::timeout, this, &EyeLeoX::onTimeout);

	// ShortBreakWidget and LongBreakWidget
	m_shortBreak = new ShortBreakWidget;
	connect(m_shortBreak, &ShortBreakWidget::breakTimeout, 
		this, &EyeLeoX::onShortBreakTimeout);
}

void EyeLeoX::restartMonitor()
{
	resetLongBreakMonitorState();
	resetShortBreakMonitorState();
	restartTimer();
}

void EyeLeoX::resetLongBreakMonitorState()
{
	m_restSecondsToLongBreak = m_longBreakInterval;
}

void EyeLeoX::resetShortBreakMonitorState()
{
	m_restSecondsToShortBreak = m_shortBreakInterval;
}

void EyeLeoX::restartTimer()
{
	m_regularTimer->stop();
	m_currentState = BUSY;
	if (m_enableLongBreak || m_enableShortBreak)
		m_regularTimer->start();
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
		// 停止监视定时器
		m_regularTimer->stop();
		m_pauseAction->setText(resumeStr);
	} else {
		// 恢复监视定时器
		restartTimer();
		m_pauseAction->setText(pauseStr);
	}
}

void EyeLeoX::onTryShortBreakBtnClicked()
{
	qDebug() << "Try Short Break clicked";
	m_shortBreak->takeShortBreak(m_shortBreakDuration);
}

void EyeLeoX::onTryLongBreakBtnClicked()
{
	qDebug() << "Try Long Break clicked";
}

void EyeLeoX::onSaveAndCloseBtnClicked()
{
	qDebug() << "Save and Close clicked";

	// Sound enable
	m_enableSound = ui.soundEnableCkBox->isChecked();

	// 暂停定时器，配置和定时器相关的值
	m_regularTimer->stop();
	m_longBreakDuration = getCurrentLongBreakDuration();

	bool enableLongBreak = ui.longBreakCkBox->isChecked();
	unsigned long longBreakInterval = getCurrentLongBreakInterval();
	unsigned long notifyLongBreakTime = getCurrentLongBreakNotificationTime();
	bool enableShortBreak = ui.shortBreakCkBox->isChecked();
	unsigned long shortBreakInterval = getCurrentShortBreakInterval();
	
	// 当下面这些值发生改变时，要重启监视
	bool restartMt = (enableLongBreak != m_enableLongBreak)
		|| (longBreakInterval != m_longBreakInterval)
		|| (enableShortBreak != m_enableShortBreak)
		|| (shortBreakInterval != m_shortBreakInterval)
		|| (notifyLongBreakTime != m_longBreakNotificationTime);
	if (restartMt) {
		m_enableLongBreak = enableLongBreak;
		m_enableShortBreak = enableShortBreak;
		m_longBreakInterval = longBreakInterval;
		m_shortBreakInterval = shortBreakInterval;
		m_longBreakNotificationTime = notifyLongBreakTime;
		restartMonitor();
	} else {
		m_regularTimer->start();
	}

	hide();
}

void EyeLeoX::onTimeout()
{
	qDebug() << "Timeout";

	// 检查LongBreak
	if (m_enableLongBreak) {
		m_restSecondsToLongBreak -= m_timerInterval;
		if (0 == m_restSecondsToLongBreak) {
			// 进入LongBreak状态
			m_currentState = LONG_BREAK;
			//@todo
			// m_longBreakWidget->customShow(m_longBreakDuration);
			// In customShow, the widget show and set up a timer to count down,
			// when timeout, emit signal to EyeLeoX main window. Then, in the
			// slot function, main window call resetLongRestMonitorState() and
			// restart timer (via restartTimer()).

			//@todo 实现这样的一个行为
			// setTimeout(m_longBreakDuration, resetLongRestMonitor);
			// LongBreak结束后需要restartTimer();
			// resetLongRestMonitorState();
			// restartTimer();
		} else if (m_enableLongBreakNotify 
			&& (m_restSecondsToLongBreak == m_longBreakNotificationTime))
		{
			// 通知用户即将进入LongBreak状态
			m_trayIcon->showMessage("Notification", "Long break is coming soon");
		}
	}

	// 检查ShortBreak
	if (m_enableShortBreak) {
		m_restSecondsToShortBreak -= m_timerInterval;
		if (0 == m_restSecondsToShortBreak) {
			if (m_currentState != LONG_BREAK) {
				// 进入ShortBreak状态
				m_currentState = SHORT_BREAK;
				m_shortBreak->takeShortBreak(m_shortBreakDuration);
			}
		}
	}
	
	// 处于任意的休息状态都会停止监视定时器，需要在休息结束后恢复
	// （因此，短休息实际上会延后长休息的时间）
	if (BUSY == m_currentState)
		m_regularTimer->start();
}

void EyeLeoX::onShortBreakTimeout()
{
	qDebug() << "Short break timeout.";
	
	/**
	 * 短休息结束后需要重置短休息的监视状态。
	 * 短休息结束时有可能正处于长休息状态，如果处于长休息状态，将重启定时器的任务推迟到
	 * 长休息结束后。
	 */
	resetShortBreakMonitorState();
	if (LONG_BREAK != m_currentState) {
		restartTimer();
	}
}

unsigned long EyeLeoX::getSecondsFromString(const QString &str) const
{
	int spacePos = str.indexOf(" ");
	if (-1 == spacePos)
		return 0; // 不符合规则的字符串

	QString number = str.left(spacePos);
	unsigned long inum = number.toULong();
	unsigned long unit = 1;
	if (str.indexOf("minute") != -1) {
		unit = 60;
	}

	return inum * unit;
}

unsigned long EyeLeoX::getCurrentLongBreakInterval() const
{
	return getSecondsFromString(ui.longBreakIntervalCbBox->currentText());
}

unsigned long EyeLeoX::getCurrentLongBreakDuration() const
{
	return getSecondsFromString(ui.longBreakDurationCbBox->currentText());
}

unsigned long EyeLeoX::getCurrentLongBreakNotificationTime() const
{
	return getSecondsFromString(ui.notifyLongBreakTimeCbBox->currentText());
}

unsigned long EyeLeoX::getCurrentShortBreakInterval() const
{
	return getSecondsFromString(ui.shortBreakIntervalCbBox->currentText());
}

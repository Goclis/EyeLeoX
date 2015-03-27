#ifndef EYELEOX_H
#define EYELEOX_H

#include <QtWidgets/QDialog>
#include "ui_EyeLeoX.h"

class QSystemTrayIcon;
class QMenu;
class QAction;
class QTimer;
class ShortBreakWidget;
class LongBreakWidget;

class EyeLeoX : public QDialog
{
	Q_OBJECT

public:
	EyeLeoX(QWidget *parent = 0);
	~EyeLeoX();

protected:
	// 重写避免程序退出
	virtual void closeEvent(QCloseEvent *);

public slots:
	// 处理托盘暂停/恢复监视器
	void onPauseActionTriggered();

	void onTryShortBreakBtnClicked();

	void onTryLongBreakBtnClicked();

	// 处理设置页面保存设置
	void onSaveAndCloseBtnClicked();

	// 处理监视定时器超时
	void onTimeout();

	// ShortBreak timeout
	void onShortBreakTimeout();

	// LongBreak timeout
	void onLongBreakTimeout();

private:
	// 设置一些初始值以及绑定一些信号/槽
	void initSettings();

	// 重启整个监视器
	void restartMonitor();

	// 重置对LongBreak的监视状态
	void resetLongBreakMonitorState();

	// 重置对ShortBreak的监视状态
	void resetShortBreakMonitorState();

	// 重启监视使用的定时器
	void restartTimer();

	// 创建系统托盘
	void createTrayIcon();

	// 获取时间的辅助方法
	// 从字符串中提取时间转换为秒数，字符串格式为『数字 单位』
	unsigned long getSecondsFromString(const QString &str) const;
	unsigned long getCurrentLongBreakInterval() const;
	unsigned long getCurrentLongBreakDuration() const;
	unsigned long getCurrentLongBreakNotificationTime() const;
	unsigned long getCurrentShortBreakInterval() const;

private:
	// 主界面即设置界面，使用Qt Designer
	Ui::EyeLeoXSettingClass ui;

	// ShortBreakWidget and LongBreakWidget
	ShortBreakWidget *m_shortBreak;
	LongBreakWidget *m_longBreak;

	// 配置信息
	// 时间相关的值，以秒为单位
	unsigned long m_longBreakInterval;
	unsigned long m_longBreakDuration;
	unsigned long m_longBreakNotificationTime;
	unsigned long m_shortBreakInterval;
	const unsigned long m_shortBreakDuration = 10;
	// 选项的状态
	bool m_enableLongBreak;
	bool m_enableLongBreakNotify;
	bool m_enableShortBreak;
	bool m_enableSound;
	// 当前状态
	enum
	{
		LONG_BREAK,
		SHORT_BREAK,
		BUSY
	} m_currentState;

	// 系统托盘及其相关的Menu和Action
	QSystemTrayIcon *m_trayIcon;
	QMenu *m_trayIconMenu;
	QAction *m_settingAction;
	QAction *m_pauseAction;
	QAction *m_quitAction;

	// 监视状态，使用一个1s的定时器去不断更新这些值
	unsigned long m_restSecondsToLongBreak;
	unsigned long m_restSecondsToShortBreak;
	QTimer *m_regularTimer;
	const unsigned int m_timerInterval = 1; // s
};

#endif // EYELEOX_H

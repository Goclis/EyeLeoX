#ifndef EYELEOX_H
#define EYELEOX_H

#include <QtWidgets/QDialog>
#include "ui_EyeLeoX.h"

class QSystemTrayIcon;
class QMenu;
class QAction;
class SettingWidget;


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
	void onPauseActionTriggered();

private:
	void createActions();
	void createTrayIcon();

	Ui::EyeLeoXClass ui;

	// 系统托盘及其相关的Menu和Action
	QSystemTrayIcon *m_trayIcon;
	QMenu *m_trayIconMenu;
	QAction *m_settingAction;
	QAction *m_pauseAction;
	QAction *m_quitAction;

	// 设置Widget，嵌入主窗口
	SettingWidget *m_settingWidget;
};

#endif // EYELEOX_H

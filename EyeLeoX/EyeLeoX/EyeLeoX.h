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
	// ��д��������˳�
	virtual void closeEvent(QCloseEvent *);

public slots:
	void onPauseActionTriggered();

private:
	void createActions();
	void createTrayIcon();

	Ui::EyeLeoXClass ui;

	// ϵͳ���̼�����ص�Menu��Action
	QSystemTrayIcon *m_trayIcon;
	QMenu *m_trayIconMenu;
	QAction *m_settingAction;
	QAction *m_pauseAction;
	QAction *m_quitAction;

	// ����Widget��Ƕ��������
	SettingWidget *m_settingWidget;
};

#endif // EYELEOX_H

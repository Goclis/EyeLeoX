#ifndef EYELEOX_H
#define EYELEOX_H

#include <QtWidgets/QDialog>
#include "ui_EyeLeoX.h"

class QSystemTrayIcon;
class QMenu;
class QAction;


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
	void initSettings();
	void createTrayIcon();

	// �����漴���ý��棬ʹ��Qt Designer
	Ui::EyeLeoXSettingClass settingUi;

	// ����ֵ
	// ...

	// ϵͳ���̼�����ص�Menu��Action
	QSystemTrayIcon *m_trayIcon;
	QMenu *m_trayIconMenu;
	QAction *m_settingAction;
	QAction *m_pauseAction;
	QAction *m_quitAction;
};

#endif // EYELEOX_H

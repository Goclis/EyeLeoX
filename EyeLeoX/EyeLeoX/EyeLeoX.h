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
	// ��д��������˳�
	virtual void closeEvent(QCloseEvent *);

public slots:
	// ����������ͣ/�ָ�������
	void onPauseActionTriggered();

	void onTryShortBreakBtnClicked();

	void onTryLongBreakBtnClicked();

	// ��������ҳ�汣������
	void onSaveAndCloseBtnClicked();

	// ������Ӷ�ʱ����ʱ
	void onTimeout();

	// ShortBreak timeout
	void onShortBreakTimeout();

	// LongBreak timeout
	void onLongBreakTimeout();

private:
	// ����һЩ��ʼֵ�Լ���һЩ�ź�/��
	void initSettings();

	// ��������������
	void restartMonitor();

	// ���ö�LongBreak�ļ���״̬
	void resetLongBreakMonitorState();

	// ���ö�ShortBreak�ļ���״̬
	void resetShortBreakMonitorState();

	// ��������ʹ�õĶ�ʱ��
	void restartTimer();

	// ����ϵͳ����
	void createTrayIcon();

	// ��ȡʱ��ĸ�������
	// ���ַ�������ȡʱ��ת��Ϊ�������ַ�����ʽΪ������ ��λ��
	unsigned long getSecondsFromString(const QString &str) const;
	unsigned long getCurrentLongBreakInterval() const;
	unsigned long getCurrentLongBreakDuration() const;
	unsigned long getCurrentLongBreakNotificationTime() const;
	unsigned long getCurrentShortBreakInterval() const;

private:
	// �����漴���ý��棬ʹ��Qt Designer
	Ui::EyeLeoXSettingClass ui;

	// ShortBreakWidget and LongBreakWidget
	ShortBreakWidget *m_shortBreak;
	LongBreakWidget *m_longBreak;

	// ������Ϣ
	// ʱ����ص�ֵ������Ϊ��λ
	unsigned long m_longBreakInterval;
	unsigned long m_longBreakDuration;
	unsigned long m_longBreakNotificationTime;
	unsigned long m_shortBreakInterval;
	const unsigned long m_shortBreakDuration = 10;
	// ѡ���״̬
	bool m_enableLongBreak;
	bool m_enableLongBreakNotify;
	bool m_enableShortBreak;
	bool m_enableSound;
	// ��ǰ״̬
	enum
	{
		LONG_BREAK,
		SHORT_BREAK,
		BUSY
	} m_currentState;

	// ϵͳ���̼�����ص�Menu��Action
	QSystemTrayIcon *m_trayIcon;
	QMenu *m_trayIconMenu;
	QAction *m_settingAction;
	QAction *m_pauseAction;
	QAction *m_quitAction;

	// ����״̬��ʹ��һ��1s�Ķ�ʱ��ȥ���ϸ�����Щֵ
	unsigned long m_restSecondsToLongBreak;
	unsigned long m_restSecondsToShortBreak;
	QTimer *m_regularTimer;
	const unsigned int m_timerInterval = 1; // s
};

#endif // EYELEOX_H

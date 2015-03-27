#ifndef LONGBREAKWIDGET_H
#define LONGBREAKWIDGET_H

#include <QWidget>
#include "ui_LongBreakWidget.h"

class QTimer;

class LongBreakWidget : public QWidget
{
	Q_OBJECT

public:
	LongBreakWidget(QWidget *parent = 0);
	~LongBreakWidget();

	/**
	* @brief 进入LongBreak，执行完毕后会发送breakTimeout信号
	*
	* @param duration 休息的时间，单位为秒
	*/
	void takeLongBreak(unsigned long duration);

signals:
	void breakTimeout();

private:
	void onTimeout();

	Ui::LongBreakWidget ui;
	QTimer *m_minuteTimer;
	unsigned long m_breakMinutes;

	QString m_formatString;
};

#endif // LONGBREAKWIDGET_H

#ifndef SHORTRESTWIDGET_H
#define SHORTRESTWIDGET_H

#include <QWidget>
#include "ui_ShortBreakWidget.h"

class QTimer;

class ShortBreakWidget : public QWidget
{
	Q_OBJECT

public:
	ShortBreakWidget(QWidget *parent = 0);
	~ShortBreakWidget();

	/**
	 * @brief 进入ShortBreak，执行完毕后会发送breakTimeout信号
	 *
	 * @param duration 休息的时间
	 */
	void takeShortBreak(unsigned long duration);

signals:
	void breakTimeout();

private:
	void onTimeout();

	Ui::ShortBreakWidget ui;
	QTimer *m_countingDownTimer;
	unsigned long m_countNumber;
};

#endif // SHORTRESTWIDGET_H

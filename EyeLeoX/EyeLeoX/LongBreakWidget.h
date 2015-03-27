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
	* @brief ����LongBreak��ִ����Ϻ�ᷢ��breakTimeout�ź�
	*
	* @param duration ��Ϣ��ʱ�䣬��λΪ��
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

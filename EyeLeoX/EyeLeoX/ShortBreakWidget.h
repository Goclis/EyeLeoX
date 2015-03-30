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
	 * @brief ����ShortBreak��ִ����Ϻ�ᷢ��breakTimeout�ź�
	 *
	 * @param duration ��Ϣ��ʱ�䣬��λΪ��
	 */
	void takeShortBreak(unsigned long duration);

signals:
	void breakTimeout();

private:
	void onTimeout();

	Ui::ShortBreakWidget ui;
	QTimer *m_countingDownTimer;
	unsigned long m_countNumber;

	QString m_formatString;
};

#endif // SHORTRESTWIDGET_H

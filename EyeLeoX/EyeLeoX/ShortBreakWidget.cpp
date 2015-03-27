#include "ShortBreakWidget.h"
#include <QTimer>

ShortBreakWidget::ShortBreakWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_countingDownTimer = new QTimer(this);
	m_countingDownTimer->setInterval(1 * 1000);
	connect(m_countingDownTimer, &QTimer::timeout, this, &ShortBreakWidget::onTimeout);
}

ShortBreakWidget::~ShortBreakWidget()
{

}

void ShortBreakWidget::takeShortBreak(unsigned long duration)
{
	m_countNumber = duration - 1;
	ui.countNumberLabel->setText(QString::number(m_countNumber));
	show();
	m_countingDownTimer->start();
}


void ShortBreakWidget::onTimeout()
{
	if (0 == m_countNumber) {
		hide();
		m_countingDownTimer->stop();
		emit breakTimeout();
	} else {
		ui.countNumberLabel->setText(QString::number(--m_countNumber));
	}
}

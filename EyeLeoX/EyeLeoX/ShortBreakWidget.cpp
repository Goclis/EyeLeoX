#include "ShortBreakWidget.h"
#include <QTimer>

ShortBreakWidget::ShortBreakWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setStyleSheet(
		"border:1px solid rgb(5,5,5); border-radius:10px;");
	

	m_countingDownTimer = new QTimer(this);
	m_countingDownTimer->setInterval(1 * 1000);
	connect(m_countingDownTimer, &QTimer::timeout, this, &ShortBreakWidget::onTimeout);

	m_formatString = "Take a short break!!! %1";
}

ShortBreakWidget::~ShortBreakWidget()
{

}

void ShortBreakWidget::takeShortBreak(unsigned long duration)
{
	m_countNumber = duration - 1;
	ui.countNumberLabel->setText(m_formatString.arg(m_countNumber));
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
		ui.countNumberLabel->setText(m_formatString.arg(--m_countNumber));
	}
}

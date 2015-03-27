#include "LongBreakWidget.h"
#include <QTimer>

LongBreakWidget::LongBreakWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

	m_minuteTimer = new QTimer(this);
	m_minuteTimer->setInterval(60 * 1000);
	connect(m_minuteTimer, &QTimer::timeout, this, &LongBreakWidget::onTimeout);

	m_formatString = "Take a long break now!! %1 minutes left...";
}

LongBreakWidget::~LongBreakWidget()
{

}

void LongBreakWidget::takeLongBreak(unsigned long duration)
{
	// 转换成分钟
	m_breakMinutes = duration / 60;
	ui.label->setText(m_formatString.arg(m_breakMinutes));

	// Windows下使用全屏
#if defined(WIN32)
	showFullScreen();
#else
	showMaximized();
#endif
	
	m_minuteTimer->start();
}

void LongBreakWidget::onTimeout()
{
	--m_breakMinutes;
	if (0 == m_breakMinutes) {
		hide();
		m_minuteTimer->stop();
		emit breakTimeout();
	} else {
		ui.label->setText(m_formatString.arg(m_breakMinutes));
	}

}

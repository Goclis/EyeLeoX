/********************************************************************************
** Form generated from reading UI file 'ShortBreakWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTBREAKWIDGET_H
#define UI_SHORTBREAKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShortBreakWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *countNumberLabel;

    void setupUi(QWidget *ShortBreakWidget)
    {
        if (ShortBreakWidget->objectName().isEmpty())
            ShortBreakWidget->setObjectName(QStringLiteral("ShortBreakWidget"));
        ShortBreakWidget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(ShortBreakWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        countNumberLabel = new QLabel(ShortBreakWidget);
        countNumberLabel->setObjectName(QStringLiteral("countNumberLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(48);
        countNumberLabel->setFont(font);
        countNumberLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(countNumberLabel);


        retranslateUi(ShortBreakWidget);

        QMetaObject::connectSlotsByName(ShortBreakWidget);
    } // setupUi

    void retranslateUi(QWidget *ShortBreakWidget)
    {
        ShortBreakWidget->setWindowTitle(QApplication::translate("ShortBreakWidget", "Take a short break", 0));
        countNumberLabel->setText(QApplication::translate("ShortBreakWidget", "10", 0));
    } // retranslateUi

};

namespace Ui {
    class ShortBreakWidget: public Ui_ShortBreakWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTBREAKWIDGET_H

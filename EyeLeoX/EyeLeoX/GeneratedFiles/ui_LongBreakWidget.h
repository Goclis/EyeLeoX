/********************************************************************************
** Form generated from reading UI file 'LongBreakWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LONGBREAKWIDGET_H
#define UI_LONGBREAKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LongBreakWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *LongBreakWidget)
    {
        if (LongBreakWidget->objectName().isEmpty())
            LongBreakWidget->setObjectName(QStringLiteral("LongBreakWidget"));
        LongBreakWidget->resize(847, 662);
        LongBreakWidget->setWindowOpacity(0.8);
        LongBreakWidget->setStyleSheet(QStringLiteral("background-color:rgb(25,25,25);"));
        horizontalLayout = new QHBoxLayout(LongBreakWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(LongBreakWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:white;"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        retranslateUi(LongBreakWidget);

        QMetaObject::connectSlotsByName(LongBreakWidget);
    } // setupUi

    void retranslateUi(QWidget *LongBreakWidget)
    {
        LongBreakWidget->setWindowTitle(QApplication::translate("LongBreakWidget", "LongBreakWidget", 0));
        label->setText(QApplication::translate("LongBreakWidget", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class LongBreakWidget: public Ui_LongBreakWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LONGBREAKWIDGET_H

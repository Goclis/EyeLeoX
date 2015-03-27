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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LongBreakWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *LongBreakWidget)
    {
        if (LongBreakWidget->objectName().isEmpty())
            LongBreakWidget->setObjectName(QStringLiteral("LongBreakWidget"));
        LongBreakWidget->resize(400, 300);
        LongBreakWidget->setWindowOpacity(0.5);
        horizontalLayout = new QHBoxLayout(LongBreakWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(LongBreakWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(LongBreakWidget);

        QMetaObject::connectSlotsByName(LongBreakWidget);
    } // setupUi

    void retranslateUi(QWidget *LongBreakWidget)
    {
        LongBreakWidget->setWindowTitle(QApplication::translate("LongBreakWidget", "LongBreakWidget", 0));
        label->setText(QApplication::translate("LongBreakWidget", "Take a long break now!! 5 minutes left...", 0));
    } // retranslateUi

};

namespace Ui {
    class LongBreakWidget: public Ui_LongBreakWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LONGBREAKWIDGET_H

/********************************************************************************
** Form generated from reading UI file 'EyeLeoX.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EYELEOX_H
#define UI_EYELEOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_EyeLeoXClass
{
public:

    void setupUi(QDialog *EyeLeoXClass)
    {
        if (EyeLeoXClass->objectName().isEmpty())
            EyeLeoXClass->setObjectName(QStringLiteral("EyeLeoXClass"));
        EyeLeoXClass->resize(600, 400);

        retranslateUi(EyeLeoXClass);

        QMetaObject::connectSlotsByName(EyeLeoXClass);
    } // setupUi

    void retranslateUi(QDialog *EyeLeoXClass)
    {
        EyeLeoXClass->setWindowTitle(QApplication::translate("EyeLeoXClass", "EyeLeoX", 0));
    } // retranslateUi

};

namespace Ui {
    class EyeLeoXClass: public Ui_EyeLeoXClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EYELEOX_H

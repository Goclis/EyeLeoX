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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EyeLeoXSettingClass
{
public:
    QTabWidget *tabWidget;
    QWidget *settingSubTab;
    QGroupBox *generalGroupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *longBreakHLayout;
    QCheckBox *longBreakCkBox;
    QComboBox *longBreakIntervalCbBox;
    QLabel *label;
    QComboBox *longBreakDurationCbBox;
    QHBoxLayout *notifyLongBreakHLayout;
    QCheckBox *notifyLongBreakCkBox;
    QComboBox *notifyLongBreakTimeCbBox;
    QHBoxLayout *shortBreakHLayout;
    QCheckBox *shortBreakCkBox;
    QComboBox *shortBreakIntervalCbBox;
    QCheckBox *soundEnableCkBox;
    QGridLayout *gridLayout;
    QPushButton *tryShortBreakBtn;
    QPushButton *tryLongBreakBtn;
    QLabel *label_2;
    QPushButton *saveAndCloseBtn;
    QWidget *inforamtionSubTab;

    void setupUi(QDialog *EyeLeoXSettingClass)
    {
        if (EyeLeoXSettingClass->objectName().isEmpty())
            EyeLeoXSettingClass->setObjectName(QStringLiteral("EyeLeoXSettingClass"));
        EyeLeoXSettingClass->resize(459, 326);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EyeLeoXSettingClass->sizePolicy().hasHeightForWidth());
        EyeLeoXSettingClass->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/EyeLeoX/trayIcon"), QSize(), QIcon::Normal, QIcon::Off);
        EyeLeoXSettingClass->setWindowIcon(icon);
        EyeLeoXSettingClass->setSizeGripEnabled(false);
        tabWidget = new QTabWidget(EyeLeoXSettingClass);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 461, 326));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(321, 0));
        tabWidget->setMaximumSize(QSize(165656, 16777215));
        settingSubTab = new QWidget();
        settingSubTab->setObjectName(QStringLiteral("settingSubTab"));
        generalGroupBox = new QGroupBox(settingSubTab);
        generalGroupBox->setObjectName(QStringLiteral("generalGroupBox"));
        generalGroupBox->setGeometry(QRect(0, 10, 455, 246));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        generalGroupBox->setFont(font);
        generalGroupBox->setFlat(false);
        generalGroupBox->setCheckable(false);
        layoutWidget = new QWidget(generalGroupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 406, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        longBreakHLayout = new QHBoxLayout();
        longBreakHLayout->setSpacing(4);
        longBreakHLayout->setObjectName(QStringLiteral("longBreakHLayout"));
        longBreakCkBox = new QCheckBox(layoutWidget);
        longBreakCkBox->setObjectName(QStringLiteral("longBreakCkBox"));
        QFont font1;
        font1.setPointSize(9);
        longBreakCkBox->setFont(font1);
        longBreakCkBox->setChecked(true);

        longBreakHLayout->addWidget(longBreakCkBox);

        longBreakIntervalCbBox = new QComboBox(layoutWidget);
        longBreakIntervalCbBox->setObjectName(QStringLiteral("longBreakIntervalCbBox"));

        longBreakHLayout->addWidget(longBreakIntervalCbBox);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        longBreakHLayout->addWidget(label);

        longBreakDurationCbBox = new QComboBox(layoutWidget);
        longBreakDurationCbBox->setObjectName(QStringLiteral("longBreakDurationCbBox"));

        longBreakHLayout->addWidget(longBreakDurationCbBox);


        verticalLayout->addLayout(longBreakHLayout);

        notifyLongBreakHLayout = new QHBoxLayout();
        notifyLongBreakHLayout->setSpacing(5);
        notifyLongBreakHLayout->setObjectName(QStringLiteral("notifyLongBreakHLayout"));
        notifyLongBreakHLayout->setContentsMargins(-1, 0, -1, -1);
        notifyLongBreakCkBox = new QCheckBox(layoutWidget);
        notifyLongBreakCkBox->setObjectName(QStringLiteral("notifyLongBreakCkBox"));
        notifyLongBreakCkBox->setChecked(true);

        notifyLongBreakHLayout->addWidget(notifyLongBreakCkBox);

        notifyLongBreakTimeCbBox = new QComboBox(layoutWidget);
        notifyLongBreakTimeCbBox->setObjectName(QStringLiteral("notifyLongBreakTimeCbBox"));

        notifyLongBreakHLayout->addWidget(notifyLongBreakTimeCbBox);


        verticalLayout->addLayout(notifyLongBreakHLayout);

        shortBreakHLayout = new QHBoxLayout();
        shortBreakHLayout->setSpacing(3);
        shortBreakHLayout->setObjectName(QStringLiteral("shortBreakHLayout"));
        shortBreakHLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        shortBreakHLayout->setContentsMargins(-1, 0, -1, -1);
        shortBreakCkBox = new QCheckBox(layoutWidget);
        shortBreakCkBox->setObjectName(QStringLiteral("shortBreakCkBox"));
        shortBreakCkBox->setChecked(true);

        shortBreakHLayout->addWidget(shortBreakCkBox);

        shortBreakIntervalCbBox = new QComboBox(layoutWidget);
        shortBreakIntervalCbBox->setObjectName(QStringLiteral("shortBreakIntervalCbBox"));

        shortBreakHLayout->addWidget(shortBreakIntervalCbBox);


        verticalLayout->addLayout(shortBreakHLayout);

        soundEnableCkBox = new QCheckBox(layoutWidget);
        soundEnableCkBox->setObjectName(QStringLiteral("soundEnableCkBox"));

        verticalLayout->addWidget(soundEnableCkBox);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tryShortBreakBtn = new QPushButton(layoutWidget);
        tryShortBreakBtn->setObjectName(QStringLiteral("tryShortBreakBtn"));

        gridLayout->addWidget(tryShortBreakBtn, 0, 0, 1, 1);

        tryLongBreakBtn = new QPushButton(layoutWidget);
        tryLongBreakBtn->setObjectName(QStringLiteral("tryLongBreakBtn"));

        gridLayout->addWidget(tryLongBreakBtn, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        saveAndCloseBtn = new QPushButton(settingSubTab);
        saveAndCloseBtn->setObjectName(QStringLiteral("saveAndCloseBtn"));
        saveAndCloseBtn->setGeometry(QRect(5, 260, 101, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/EyeLeoX/settingIcon"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(settingSubTab, icon1, QString());
        inforamtionSubTab = new QWidget();
        inforamtionSubTab->setObjectName(QStringLiteral("inforamtionSubTab"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/EyeLeoX/infoIcon"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(inforamtionSubTab, icon2, QString());

        retranslateUi(EyeLeoXSettingClass);

        tabWidget->setCurrentIndex(0);
        shortBreakIntervalCbBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EyeLeoXSettingClass);
    } // setupUi

    void retranslateUi(QDialog *EyeLeoXSettingClass)
    {
        EyeLeoXSettingClass->setWindowTitle(QApplication::translate("EyeLeoXSettingClass", "EyeLeoX Settings", 0));
        generalGroupBox->setTitle(QApplication::translate("EyeLeoXSettingClass", "General", 0));
        longBreakCkBox->setText(QApplication::translate("EyeLeoXSettingClass", "Take a long break every", 0));
        longBreakIntervalCbBox->clear();
        longBreakIntervalCbBox->insertItems(0, QStringList()
         << QApplication::translate("EyeLeoXSettingClass", "30 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "40 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "50 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "60 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "90 minutes", 0)
        );
        longBreakIntervalCbBox->setCurrentText(QApplication::translate("EyeLeoXSettingClass", "30 minutes", 0));
        label->setText(QApplication::translate("EyeLeoXSettingClass", "for", 0));
        longBreakDurationCbBox->clear();
        longBreakDurationCbBox->insertItems(0, QStringList()
         << QApplication::translate("EyeLeoXSettingClass", "2 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "3 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "4 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "5 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "7 minutes", 0)
        );
        longBreakDurationCbBox->setCurrentText(QApplication::translate("EyeLeoXSettingClass", "2 minutes", 0));
        notifyLongBreakCkBox->setText(QApplication::translate("EyeLeoXSettingClass", "Notify long break coming before", 0));
        notifyLongBreakTimeCbBox->clear();
        notifyLongBreakTimeCbBox->insertItems(0, QStringList()
         << QApplication::translate("EyeLeoXSettingClass", "30 seconds", 0)
         << QApplication::translate("EyeLeoXSettingClass", "1 minute", 0)
         << QApplication::translate("EyeLeoXSettingClass", "2 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "3 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "5 minutes", 0)
        );
        shortBreakCkBox->setText(QApplication::translate("EyeLeoXSettingClass", "Take a short break every", 0));
        shortBreakIntervalCbBox->clear();
        shortBreakIntervalCbBox->insertItems(0, QStringList()
         << QApplication::translate("EyeLeoXSettingClass", "3 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "5 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "8 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "10 minutes", 0)
         << QApplication::translate("EyeLeoXSettingClass", "15 minutes", 0)
        );
        soundEnableCkBox->setText(QApplication::translate("EyeLeoXSettingClass", "Enable sounds", 0));
        tryShortBreakBtn->setText(QApplication::translate("EyeLeoXSettingClass", "Try short break", 0));
        tryLongBreakBtn->setText(QApplication::translate("EyeLeoXSettingClass", "Try long break", 0));
        label_2->setText(QString());
        saveAndCloseBtn->setText(QApplication::translate("EyeLeoXSettingClass", "Save and Close", 0));
        tabWidget->setTabText(tabWidget->indexOf(settingSubTab), QApplication::translate("EyeLeoXSettingClass", " Settings", 0));
        tabWidget->setTabText(tabWidget->indexOf(inforamtionSubTab), QApplication::translate("EyeLeoXSettingClass", " Information", 0));
    } // retranslateUi

};

namespace Ui {
    class EyeLeoXSettingClass: public Ui_EyeLeoXSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EYELEOX_H

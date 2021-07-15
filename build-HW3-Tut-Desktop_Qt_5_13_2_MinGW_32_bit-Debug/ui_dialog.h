/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include "myopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *clearPushButton;
    QHBoxLayout *horizontalLayout;
    QRadioButton *vertexModeRad;
    QRadioButton *translateModeRad;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *currModeLabel;
    MyOpenGLWidget *openGLWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *currAxisLabel;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *xAxisRad;
    QRadioButton *yAxisRad;
    QRadioButton *zAxisRad;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(420, 527);
        Dialog->setMinimumSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(Dialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        clearPushButton = new QPushButton(Dialog);
        clearPushButton->setObjectName(QString::fromUtf8("clearPushButton"));

        verticalLayout->addWidget(clearPushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        vertexModeRad = new QRadioButton(Dialog);
        vertexModeRad->setObjectName(QString::fromUtf8("vertexModeRad"));

        horizontalLayout->addWidget(vertexModeRad);

        translateModeRad = new QRadioButton(Dialog);
        translateModeRad->setObjectName(QString::fromUtf8("translateModeRad"));

        horizontalLayout->addWidget(translateModeRad);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        currModeLabel = new QLineEdit(Dialog);
        currModeLabel->setObjectName(QString::fromUtf8("currModeLabel"));

        horizontalLayout_5->addWidget(currModeLabel);


        verticalLayout->addLayout(horizontalLayout_5);

        openGLWidget = new MyOpenGLWidget(Dialog);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setMinimumSize(QSize(400, 400));
        openGLWidget->setMaximumSize(QSize(400, 400));

        verticalLayout->addWidget(openGLWidget);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        currAxisLabel = new QLineEdit(Dialog);
        currAxisLabel->setObjectName(QString::fromUtf8("currAxisLabel"));

        horizontalLayout_2->addWidget(currAxisLabel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        xAxisRad = new QRadioButton(Dialog);
        xAxisRad->setObjectName(QString::fromUtf8("xAxisRad"));

        horizontalLayout_4->addWidget(xAxisRad);

        yAxisRad = new QRadioButton(Dialog);
        yAxisRad->setObjectName(QString::fromUtf8("yAxisRad"));

        horizontalLayout_4->addWidget(yAxisRad);

        zAxisRad = new QRadioButton(Dialog);
        zAxisRad->setObjectName(QString::fromUtf8("zAxisRad"));

        horizontalLayout_4->addWidget(zAxisRad);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        clearPushButton->setText(QCoreApplication::translate("Dialog", "Clear", nullptr));
        vertexModeRad->setText(QCoreApplication::translate("Dialog", "Vertex Mode", nullptr));
        translateModeRad->setText(QCoreApplication::translate("Dialog", "Translate Mode", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Current Mode:", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Current Mode: ", nullptr));
        xAxisRad->setText(QCoreApplication::translate("Dialog", "X-Axis", nullptr));
        yAxisRad->setText(QCoreApplication::translate("Dialog", "Y-Axis", nullptr));
        zAxisRad->setText(QCoreApplication::translate("Dialog", "Z-Axis", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

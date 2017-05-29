/********************************************************************************
** Form generated from reading UI file 'Dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *angleEdit;
    QLabel *label_2;
    QLineEdit *n1Edit;
    QLabel *label_4;
    QLineEdit *regionsEdit;
    QLabel *label_3;
    QLineEdit *n2Edit;
    QLabel *label_5;
    QLineEdit *aEdit;
    QCheckBox *randomBox;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *fiberButton;
    QPushButton *basicButton;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *startButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(870, 729);
        verticalLayout_3 = new QVBoxLayout(Dialog);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        angleEdit = new QLineEdit(groupBox);
        angleEdit->setObjectName(QStringLiteral("angleEdit"));

        verticalLayout_2->addWidget(angleEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        n1Edit = new QLineEdit(groupBox);
        n1Edit->setObjectName(QStringLiteral("n1Edit"));

        verticalLayout_2->addWidget(n1Edit);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        regionsEdit = new QLineEdit(groupBox);
        regionsEdit->setObjectName(QStringLiteral("regionsEdit"));

        verticalLayout_2->addWidget(regionsEdit);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        n2Edit = new QLineEdit(groupBox);
        n2Edit->setObjectName(QStringLiteral("n2Edit"));

        verticalLayout_2->addWidget(n2Edit);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        aEdit = new QLineEdit(groupBox);
        aEdit->setObjectName(QStringLiteral("aEdit"));

        verticalLayout_2->addWidget(aEdit);

        randomBox = new QCheckBox(groupBox);
        randomBox->setObjectName(QStringLiteral("randomBox"));

        verticalLayout_2->addWidget(randomBox);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        fiberButton = new QPushButton(groupBox);
        fiberButton->setObjectName(QStringLiteral("fiberButton"));

        verticalLayout->addWidget(fiberButton);

        basicButton = new QPushButton(groupBox);
        basicButton->setObjectName(QStringLiteral("basicButton"));

        verticalLayout->addWidget(basicButton);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox);

        graphicsView = new QGraphicsView(Dialog);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout_3->addWidget(graphicsView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        startButton = new QPushButton(Dialog);
        startButton->setObjectName(QStringLiteral("startButton"));

        horizontalLayout_2->addWidget(startButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("Dialog", "Inputs", 0));
        label->setText(QApplication::translate("Dialog", "Incident angle", 0));
        label_2->setText(QApplication::translate("Dialog", "1-Refractive index ", 0));
        label_4->setText(QApplication::translate("Dialog", "Number of regions", 0));
        label_3->setText(QApplication::translate("Dialog", "2-Refractive index", 0));
        label_5->setText(QApplication::translate("Dialog", "a", 0));
        randomBox->setText(QApplication::translate("Dialog", "Random Index placement", 0));
        fiberButton->setText(QApplication::translate("Dialog", "Fiber", 0));
        basicButton->setText(QApplication::translate("Dialog", "Snell", 0));
        startButton->setText(QApplication::translate("Dialog", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

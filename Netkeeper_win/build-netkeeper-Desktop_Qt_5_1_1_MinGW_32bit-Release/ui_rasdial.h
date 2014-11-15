/********************************************************************************
** Form generated from reading UI file 'rasdial.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RASDIAL_H
#define UI_RASDIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rasdial
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *le1_username;
    QLineEdit *le2_password;
    QPushButton *pb_login;
    QPushButton *pb_cancal;
    QCheckBox *check;

    void setupUi(QDialog *rasdial)
    {
        if (rasdial->objectName().isEmpty())
            rasdial->setObjectName(QStringLiteral("rasdial"));
        rasdial->resize(400, 300);
        gridLayoutWidget = new QWidget(rasdial);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 20, 291, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        le1_username = new QLineEdit(gridLayoutWidget);
        le1_username->setObjectName(QStringLiteral("le1_username"));
        le1_username->setEchoMode(QLineEdit::Normal);

        gridLayout->addWidget(le1_username, 1, 1, 1, 1);

        le2_password = new QLineEdit(gridLayoutWidget);
        le2_password->setObjectName(QStringLiteral("le2_password"));
        le2_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(le2_password, 2, 1, 1, 1);

        pb_login = new QPushButton(rasdial);
        pb_login->setObjectName(QStringLiteral("pb_login"));
        pb_login->setGeometry(QRect(70, 230, 91, 31));
        pb_cancal = new QPushButton(rasdial);
        pb_cancal->setObjectName(QStringLiteral("pb_cancal"));
        pb_cancal->setGeometry(QRect(234, 230, 91, 31));
        check = new QCheckBox(rasdial);
        check->setObjectName(QStringLiteral("check"));
        check->setGeometry(QRect(60, 210, 291, 16));
        check->setChecked(true);

        retranslateUi(rasdial);

        QMetaObject::connectSlotsByName(rasdial);
    } // setupUi

    void retranslateUi(QDialog *rasdial)
    {
        rasdial->setWindowTitle(QApplication::translate("rasdial", "rasdial", 0));
        label->setText(QApplication::translate("rasdial", "\345\257\206\347\240\201", 0));
        label_2->setText(QApplication::translate("rasdial", "\351\227\252\350\256\257\350\264\246\345\217\267", 0));
        pb_login->setText(QApplication::translate("rasdial", "\347\231\273\351\231\206", 0));
        pb_cancal->setText(QApplication::translate("rasdial", "\351\200\200\345\207\272", 0));
        check->setText(QApplication::translate("rasdial", "\347\231\273\351\231\206\351\227\252\350\256\257\357\274\210\345\246\202\346\236\234\346\230\257\351\227\252\350\256\257\350\257\267\346\211\223\345\213\276\357\274\214\346\213\250ADSL\350\257\267\345\216\273\346\216\211\357\274\211", 0));
    } // retranslateUi

};

namespace Ui {
    class rasdial: public Ui_rasdial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RASDIAL_H

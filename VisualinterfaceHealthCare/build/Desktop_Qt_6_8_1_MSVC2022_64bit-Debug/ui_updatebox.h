/********************************************************************************
** Form generated from reading UI file 'updatebox.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEBOX_H
#define UI_UPDATEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_updateBox
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QDialog *updateBox)
    {
        if (updateBox->objectName().isEmpty())
            updateBox->setObjectName("updateBox");
        updateBox->resize(939, 617);
        label = new QLabel(updateBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 60, 751, 141));
        label->setStyleSheet(QString::fromUtf8("QLabel{background:light gray;\n"
"font-size:40px;\n"
"color:white}\n"
""));
        label_2 = new QLabel(updateBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 270, 291, 51));
        QFont font;
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{font-size:30px;color:blue}\n"
""));
        lineEdit = new QLineEdit(updateBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(330, 270, 311, 61));
        label_3 = new QLabel(updateBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 400, 291, 51));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{font-size:30px;color:blue}\n"
""));
        lineEdit_2 = new QLineEdit(updateBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(330, 390, 311, 61));
        pushButton = new QPushButton(updateBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 510, 201, 51));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:30px;\n"
"color:red;}"));

        retranslateUi(updateBox);

        QMetaObject::connectSlotsByName(updateBox);
    } // setupUi

    void retranslateUi(QDialog *updateBox)
    {
        updateBox->setWindowTitle(QCoreApplication::translate("updateBox", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("updateBox", "                 Update Window", nullptr));
        label_2->setText(QCoreApplication::translate("updateBox", "Enter Record Number:", nullptr));
        label_3->setText(QCoreApplication::translate("updateBox", "New Section:", nullptr));
        pushButton->setText(QCoreApplication::translate("updateBox", "UPDATE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class updateBox: public Ui_updateBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEBOX_H

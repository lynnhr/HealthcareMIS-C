/********************************************************************************
** Form generated from reading UI file 'findbox.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDBOX_H
#define UI_FINDBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_findBox
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *findBox)
    {
        if (findBox->objectName().isEmpty())
            findBox->setObjectName("findBox");
        findBox->resize(877, 627);
        label = new QLabel(findBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 851, 131));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background:light gray;\n"
"font-size:50px;\n"
"color:white;}\n"
"\n"
""));
        label_2 = new QLabel(findBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 300, 251, 81));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:25px;\n"
"color:blue;\n"
"}"));
        lineEdit = new QLineEdit(findBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(400, 320, 381, 61));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:15px;}\n"
""));
        pushButton = new QPushButton(findBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 480, 241, 61));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{color:blue;\n"
"font-size:15px;}\n"
""));

        retranslateUi(findBox);

        QMetaObject::connectSlotsByName(findBox);
    } // setupUi

    void retranslateUi(QDialog *findBox)
    {
        findBox->setWindowTitle(QCoreApplication::translate("findBox", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("findBox", "       Search Window ", nullptr));
        label_2->setText(QCoreApplication::translate("findBox", "Enter RecordNumber:", nullptr));
        pushButton->setText(QCoreApplication::translate("findBox", "SEARCH", nullptr));
    } // retranslateUi

};

namespace Ui {
    class findBox: public Ui_findBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDBOX_H

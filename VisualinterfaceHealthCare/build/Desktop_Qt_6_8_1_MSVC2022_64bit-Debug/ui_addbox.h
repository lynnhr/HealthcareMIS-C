/********************************************************************************
** Form generated from reading UI file 'addbox.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOX_H
#define UI_ADDBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addBox
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;

    void setupUi(QDialog *addBox)
    {
        if (addBox->objectName().isEmpty())
            addBox->setObjectName("addBox");
        addBox->resize(1016, 609);
        label = new QLabel(addBox);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 20, 591, 221));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background:light gray;\n"
"font-size:30px;\n"
"color:white;}"));
        label_2 = new QLabel(addBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 250, 191, 61));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:15px;\n"
"color:blue;}\n"
""));
        lineEdit = new QLineEdit(addBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(220, 260, 431, 51));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:20px;}\n"
""));
        label_3 = new QLabel(addBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 310, 191, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("PT Dusky")});
        font1.setBold(true);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:15px;\n"
"color:blue;}\n"
""));
        lineEdit_2 = new QLineEdit(addBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(220, 320, 431, 51));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:20px;}\n"
""));
        label_4 = new QLabel(addBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 420, 63, 20));
        label_5 = new QLabel(addBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 380, 191, 61));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:15px;\n"
"color:blue;}\n"
""));
        lineEdit_3 = new QLineEdit(addBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(220, 380, 431, 51));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:20px;}\n"
""));
        pushButton = new QPushButton(addBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(222, 458, 421, 61));
        QFont font2;
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:15px;\n"
"color:blue;}\n"
""));

        retranslateUi(addBox);

        QMetaObject::connectSlotsByName(addBox);
    } // setupUi

    void retranslateUi(QDialog *addBox)
    {
        addBox->setWindowTitle(QCoreApplication::translate("addBox", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addBox", "      Enter Information:", nullptr));
        label_2->setText(QCoreApplication::translate("addBox", "RecordNumber:", nullptr));
        label_3->setText(QCoreApplication::translate("addBox", "Name:", nullptr));
        label_4->setText(QString());
        label_5->setText(QCoreApplication::translate("addBox", "Section:", nullptr));
        pushButton->setText(QCoreApplication::translate("addBox", "ADD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addBox: public Ui_addBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOX_H

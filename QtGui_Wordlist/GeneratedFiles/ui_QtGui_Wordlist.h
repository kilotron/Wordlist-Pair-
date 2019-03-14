/********************************************************************************
** Form generated from reading UI file 'QtGui_Wordlist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUI_WORDLIST_H
#define UI_QTGUI_WORDLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGui_WordlistClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_para_gen_result;
    QVBoxLayout *verticalLayout_para_gen;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_para;
    QVBoxLayout *verticalLayout_para_button;
    QRadioButton *radioButton_w;
    QRadioButton *radioButton_c;
    QCheckBox *checkBox_h;
    QCheckBox *checkBox_t;
    QCheckBox *checkBox_r;
    QVBoxLayout *verticalLayout_para_text;
    QLineEdit *lineEdit_w;
    QLineEdit *lineEdit_c;
    QLineEdit *lineEdit_h;
    QLineEdit *lineEdit_t;
    QLineEdit *lineEdit_r;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_generate_chain;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_result;
    QTextEdit *textEdit_result;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_save_in_file;
    QLineEdit *lineEdit_save_in_file;
    QHBoxLayout *horizontalLayout_input;
    QVBoxLayout *verticalLayout_input_way;
    QRadioButton *radioButton_upload_file;
    QRadioButton *radioButton_input_words;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_choose_file;
    QLineEdit *lineEdit_filename;
    QLineEdit *lineEdit_words;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *QtGui_WordlistClass)
    {
        if (QtGui_WordlistClass->objectName().isEmpty())
            QtGui_WordlistClass->setObjectName(QString::fromUtf8("QtGui_WordlistClass"));
        QtGui_WordlistClass->resize(610, 576);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QtGui_WordlistClass->sizePolicy().hasHeightForWidth());
        QtGui_WordlistClass->setSizePolicy(sizePolicy);
        QtGui_WordlistClass->setMinimumSize(QSize(610, 576));
        QtGui_WordlistClass->setMaximumSize(QSize(610, 576));
        centralWidget = new QWidget(QtGui_WordlistClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(610, 537));
        centralWidget->setMaximumSize(QSize(610, 537));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 591, 521));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_para_gen_result = new QHBoxLayout();
        horizontalLayout_para_gen_result->setSpacing(6);
        horizontalLayout_para_gen_result->setObjectName(QString::fromUtf8("horizontalLayout_para_gen_result"));
        verticalLayout_para_gen = new QVBoxLayout();
        verticalLayout_para_gen->setSpacing(6);
        verticalLayout_para_gen->setObjectName(QString::fromUtf8("verticalLayout_para_gen"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_para_gen->addItem(verticalSpacer_2);

        horizontalLayout_para = new QHBoxLayout();
        horizontalLayout_para->setSpacing(6);
        horizontalLayout_para->setObjectName(QString::fromUtf8("horizontalLayout_para"));
        verticalLayout_para_button = new QVBoxLayout();
        verticalLayout_para_button->setSpacing(6);
        verticalLayout_para_button->setObjectName(QString::fromUtf8("verticalLayout_para_button"));
        radioButton_w = new QRadioButton(gridLayoutWidget);
        buttonGroup_2 = new QButtonGroup(QtGui_WordlistClass);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(radioButton_w);
        radioButton_w->setObjectName(QString::fromUtf8("radioButton_w"));
        radioButton_w->setChecked(true);

        verticalLayout_para_button->addWidget(radioButton_w);

        radioButton_c = new QRadioButton(gridLayoutWidget);
        buttonGroup_2->addButton(radioButton_c);
        radioButton_c->setObjectName(QString::fromUtf8("radioButton_c"));
        radioButton_c->setCheckable(true);
        radioButton_c->setChecked(false);

        verticalLayout_para_button->addWidget(radioButton_c);

        checkBox_h = new QCheckBox(gridLayoutWidget);
        checkBox_h->setObjectName(QString::fromUtf8("checkBox_h"));

        verticalLayout_para_button->addWidget(checkBox_h);

        checkBox_t = new QCheckBox(gridLayoutWidget);
        checkBox_t->setObjectName(QString::fromUtf8("checkBox_t"));

        verticalLayout_para_button->addWidget(checkBox_t);

        checkBox_r = new QCheckBox(gridLayoutWidget);
        checkBox_r->setObjectName(QString::fromUtf8("checkBox_r"));

        verticalLayout_para_button->addWidget(checkBox_r);

        verticalLayout_para_button->setStretch(0, 1);
        verticalLayout_para_button->setStretch(1, 1);
        verticalLayout_para_button->setStretch(2, 1);
        verticalLayout_para_button->setStretch(3, 1);

        horizontalLayout_para->addLayout(verticalLayout_para_button);

        verticalLayout_para_text = new QVBoxLayout();
        verticalLayout_para_text->setSpacing(6);
        verticalLayout_para_text->setObjectName(QString::fromUtf8("verticalLayout_para_text"));
        verticalLayout_para_text->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit_w = new QLineEdit(gridLayoutWidget);
        lineEdit_w->setObjectName(QString::fromUtf8("lineEdit_w"));
        lineEdit_w->setEnabled(false);

        verticalLayout_para_text->addWidget(lineEdit_w);

        lineEdit_c = new QLineEdit(gridLayoutWidget);
        lineEdit_c->setObjectName(QString::fromUtf8("lineEdit_c"));
        lineEdit_c->setEnabled(false);

        verticalLayout_para_text->addWidget(lineEdit_c);

        lineEdit_h = new QLineEdit(gridLayoutWidget);
        lineEdit_h->setObjectName(QString::fromUtf8("lineEdit_h"));

        verticalLayout_para_text->addWidget(lineEdit_h);

        lineEdit_t = new QLineEdit(gridLayoutWidget);
        lineEdit_t->setObjectName(QString::fromUtf8("lineEdit_t"));

        verticalLayout_para_text->addWidget(lineEdit_t);

        lineEdit_r = new QLineEdit(gridLayoutWidget);
        lineEdit_r->setObjectName(QString::fromUtf8("lineEdit_r"));
        lineEdit_r->setEnabled(false);

        verticalLayout_para_text->addWidget(lineEdit_r);


        horizontalLayout_para->addLayout(verticalLayout_para_text);

        horizontalLayout_para->setStretch(0, 10);
        horizontalLayout_para->setStretch(1, 50);

        verticalLayout_para_gen->addLayout(horizontalLayout_para);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_generate_chain = new QPushButton(gridLayoutWidget);
        pushButton_generate_chain->setObjectName(QString::fromUtf8("pushButton_generate_chain"));

        verticalLayout_3->addWidget(pushButton_generate_chain);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_para_gen->addLayout(verticalLayout_3);

        verticalLayout_para_gen->setStretch(1, 6);

        horizontalLayout_para_gen_result->addLayout(verticalLayout_para_gen);

        horizontalLayout_result = new QHBoxLayout();
        horizontalLayout_result->setSpacing(6);
        horizontalLayout_result->setObjectName(QString::fromUtf8("horizontalLayout_result"));
        textEdit_result = new QTextEdit(gridLayoutWidget);
        textEdit_result->setObjectName(QString::fromUtf8("textEdit_result"));

        horizontalLayout_result->addWidget(textEdit_result);


        horizontalLayout_para_gen_result->addLayout(horizontalLayout_result);

        horizontalLayout_para_gen_result->setStretch(0, 2);
        horizontalLayout_para_gen_result->setStretch(1, 5);

        gridLayout->addLayout(horizontalLayout_para_gen_result, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_save_in_file = new QPushButton(gridLayoutWidget);
        pushButton_save_in_file->setObjectName(QString::fromUtf8("pushButton_save_in_file"));

        horizontalLayout->addWidget(pushButton_save_in_file);

        lineEdit_save_in_file = new QLineEdit(gridLayoutWidget);
        lineEdit_save_in_file->setObjectName(QString::fromUtf8("lineEdit_save_in_file"));

        horizontalLayout->addWidget(lineEdit_save_in_file);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        horizontalLayout_input = new QHBoxLayout();
        horizontalLayout_input->setSpacing(6);
        horizontalLayout_input->setObjectName(QString::fromUtf8("horizontalLayout_input"));
        verticalLayout_input_way = new QVBoxLayout();
        verticalLayout_input_way->setSpacing(6);
        verticalLayout_input_way->setObjectName(QString::fromUtf8("verticalLayout_input_way"));
        radioButton_upload_file = new QRadioButton(gridLayoutWidget);
        buttonGroup = new QButtonGroup(QtGui_WordlistClass);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton_upload_file);
        radioButton_upload_file->setObjectName(QString::fromUtf8("radioButton_upload_file"));
        radioButton_upload_file->setChecked(true);

        verticalLayout_input_way->addWidget(radioButton_upload_file);

        radioButton_input_words = new QRadioButton(gridLayoutWidget);
        buttonGroup->addButton(radioButton_input_words);
        radioButton_input_words->setObjectName(QString::fromUtf8("radioButton_input_words"));

        verticalLayout_input_way->addWidget(radioButton_input_words);


        horizontalLayout_input->addLayout(verticalLayout_input_way);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_choose_file = new QHBoxLayout();
        horizontalLayout_choose_file->setSpacing(6);
        horizontalLayout_choose_file->setObjectName(QString::fromUtf8("horizontalLayout_choose_file"));
        lineEdit_filename = new QLineEdit(gridLayoutWidget);
        lineEdit_filename->setObjectName(QString::fromUtf8("lineEdit_filename"));

        horizontalLayout_choose_file->addWidget(lineEdit_filename);

        horizontalLayout_choose_file->setStretch(0, 5);

        verticalLayout_2->addLayout(horizontalLayout_choose_file);

        lineEdit_words = new QLineEdit(gridLayoutWidget);
        lineEdit_words->setObjectName(QString::fromUtf8("lineEdit_words"));

        verticalLayout_2->addWidget(lineEdit_words);


        horizontalLayout_input->addLayout(verticalLayout_2);

        horizontalLayout_input->setStretch(0, 2);
        horizontalLayout_input->setStretch(1, 5);

        gridLayout->addLayout(horizontalLayout_input, 0, 0, 1, 1);

        QtGui_WordlistClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(QtGui_WordlistClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGui_WordlistClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGui_WordlistClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGui_WordlistClass->setStatusBar(statusBar);

        retranslateUi(QtGui_WordlistClass);

        QMetaObject::connectSlotsByName(QtGui_WordlistClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGui_WordlistClass)
    {
        QtGui_WordlistClass->setWindowTitle(QApplication::translate("QtGui_WordlistClass", "QtGui_Wordlist", nullptr));
        radioButton_w->setText(QApplication::translate("QtGui_WordlistClass", "-w", nullptr));
        radioButton_c->setText(QApplication::translate("QtGui_WordlistClass", "-c", nullptr));
        checkBox_h->setText(QApplication::translate("QtGui_WordlistClass", "-h", nullptr));
        checkBox_t->setText(QApplication::translate("QtGui_WordlistClass", "-t", nullptr));
        checkBox_r->setText(QApplication::translate("QtGui_WordlistClass", "-r", nullptr));
        pushButton_generate_chain->setText(QApplication::translate("QtGui_WordlistClass", "generate chain", nullptr));
        pushButton_save_in_file->setText(QApplication::translate("QtGui_WordlistClass", "save in file", nullptr));
        radioButton_upload_file->setText(QApplication::translate("QtGui_WordlistClass", "upload file path", nullptr));
        radioButton_input_words->setText(QApplication::translate("QtGui_WordlistClass", "input words", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGui_WordlistClass: public Ui_QtGui_WordlistClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUI_WORDLIST_H

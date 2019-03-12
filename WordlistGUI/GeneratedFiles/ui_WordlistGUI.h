/********************************************************************************
** Form generated from reading UI file 'WordlistGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORDLISTGUI_H
#define UI_WORDLISTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WordlistGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WordlistGUIClass)
    {
        if (WordlistGUIClass->objectName().isEmpty())
            WordlistGUIClass->setObjectName(QString::fromUtf8("WordlistGUIClass"));
        WordlistGUIClass->resize(600, 400);
        menuBar = new QMenuBar(WordlistGUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        WordlistGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WordlistGUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        WordlistGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(WordlistGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        WordlistGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(WordlistGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WordlistGUIClass->setStatusBar(statusBar);

        retranslateUi(WordlistGUIClass);

        QMetaObject::connectSlotsByName(WordlistGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *WordlistGUIClass)
    {
        WordlistGUIClass->setWindowTitle(QApplication::translate("WordlistGUIClass", "WordlistGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WordlistGUIClass: public Ui_WordlistGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDLISTGUI_H

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_WordlistGUI.h"

class QLabel;
class QTextEdit;
class QVBoxLayout;
class QHBoxLayout;
class QRadioButton;
class QButtonGroup;
class QCheckBox;
class QLineEdit;
class QPushButton;
class QAction;
class QMenu;

class WordlistGUI : public QMainWindow
{
	Q_OBJECT

public:
	WordlistGUI(QWidget *parent = Q_NULLPTR);

private slots:
	void enableHeadLineEdit(int state);
	void enableTailLineEdit(int state);
	void updateExportButton();
	void openFile();
	void findWordlist();
	void exportResult();
	void about();
	void extractWordsAndDisplay();

private:
	Ui::WordlistGUIClass ui;
	QWidget *mainWidget;

	QLabel *inputLabel;
	QLabel *outputLabel;
	QTextEdit *inputTextEdit;
	QTextEdit *outputTextEdit;

	QLabel *maxLabel;
	QRadioButton *wordRadioButton;
	QRadioButton *charRadioButton;
	QButtonGroup *wcRadioButtons;

	QCheckBox *headCheckBox;
	QCheckBox *tailCheckBox;
	QLineEdit *headLineEdit;
	QLineEdit *tailLineEdit;
	QHBoxLayout *headLayout;
	QHBoxLayout *tailLayout;

	QCheckBox *loopCheckBox;

	QPushButton *findButton;
	QPushButton *exportButton;
	QPushButton *extractButton;

	QVBoxLayout *leftLayout;
	QVBoxLayout *rightLayout;
	QHBoxLayout *topRightLayout;
	QHBoxLayout *bottomRightLayout;
	QHBoxLayout *mainLayout;

	QMenu *fileMenu;
	QMenu *helpMenu;
	QAction *openAction;
	QAction *aboutAction;

	QLabel *statusLabel;

	void createActions();
	void createMenus();

	char **extractWords(QString &str, int &size);
};

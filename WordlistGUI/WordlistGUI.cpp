#include "WordlistGUI.h"
#include <QLabel>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QAction>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QIcon>
#include <set>
#include <string>
#include <string.h>
#include <Windows.h>
#include <ctype.h>

using namespace std;

WordlistGUI::WordlistGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setWindowIcon(QIcon(":WordlistGUI/images/icon.png"));

	mainWidget = new QWidget;

	inputLabel = new QLabel("&Input:");
	outputLabel = new QLabel("&Output:");
	inputTextEdit = new QTextEdit;
	outputTextEdit = new QTextEdit;

	outputTextEdit->setReadOnly(true);

	inputLabel->setBuddy(inputTextEdit);
	outputLabel->setBuddy(outputTextEdit);

	maxLabel = new QLabel("Max number of:");
	wordRadioButton = new QRadioButton("&Words");
	charRadioButton = new QRadioButton("&Chars");;
	wcRadioButtons = new QButtonGroup;

	wordRadioButton->setChecked(true);
	wcRadioButtons->addButton(wordRadioButton);
	wcRadioButtons->addButton(charRadioButton);

	headCheckBox = new QCheckBox("&head");
	tailCheckBox = new QCheckBox("&tail");
	headLineEdit = new QLineEdit;
	tailLineEdit = new QLineEdit;
	headLayout = new QHBoxLayout;
	tailLayout = new QHBoxLayout;

	connect(headCheckBox, SIGNAL(stateChanged(int)), this, SLOT(enableHeadLineEdit(int)));
	connect(tailCheckBox, SIGNAL(stateChanged(int)), this, SLOT(enableTailLineEdit(int)));
	headCheckBox->setChecked(false);
	tailCheckBox->setChecked(false);
	headLineEdit->setEnabled(false);
	tailLineEdit->setEnabled(false);
	headLayout->addWidget(headCheckBox);
	headLayout->addWidget(headLineEdit);
	tailLayout->addWidget(tailCheckBox);
	tailLayout->addWidget(tailLineEdit);

	loopCheckBox = new QCheckBox("Enable loop");
	findButton = new QPushButton("&Find");
	exportButton = new QPushButton("&Export");
	extractButton = new QPushButton("Extract Words");

	connect(findButton, SIGNAL(clicked()), this, SLOT(findWordlist()));
	connect(exportButton, SIGNAL(clicked()), this, SLOT(exportResult()));
	connect(extractButton, SIGNAL(clicked()), this, SLOT(extractWordsAndDisplay()));
	connect(outputTextEdit, SIGNAL(textChanged()), this, SLOT(updateExportButton()));
	findButton->setDefault(true);
	exportButton->setEnabled(false);
	exportButton->setToolTip("Export result to a file.");
	extractButton->setToolTip("Extract words from input and replace content in input box.");

	statusLabel = new QLabel;
	statusBar()->addWidget(statusLabel);

	leftLayout = new QVBoxLayout;
	rightLayout = new QVBoxLayout;
	topRightLayout = new QHBoxLayout;
	bottomRightLayout = new QHBoxLayout;
	mainLayout = new QHBoxLayout;

	leftLayout->addWidget(inputLabel);
	leftLayout->addWidget(inputTextEdit);
	leftLayout->addWidget(outputLabel);
	leftLayout->addWidget(outputTextEdit);

	topRightLayout->addWidget(maxLabel);
	topRightLayout->addWidget(wordRadioButton);
	topRightLayout->addWidget(charRadioButton);
	bottomRightLayout->addWidget(findButton);
	bottomRightLayout->addWidget(exportButton);

	rightLayout->addLayout(topRightLayout);
	rightLayout->addLayout(headLayout);
	rightLayout->addLayout(tailLayout);
	rightLayout->addWidget(loopCheckBox);
	rightLayout->addWidget(extractButton);
	rightLayout->addLayout(bottomRightLayout);

	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);

	mainWidget->setLayout(mainLayout);

	this->setCentralWidget(mainWidget);

	createActions();
	createMenus();

}

void WordlistGUI::createActions()
{
	openAction = new QAction("&Open", this);
	openAction->setShortcut(QKeySequence::Open);
	openAction->setStatusTip("Open a file.");
	openAction->setIcon(QIcon(":WordlistGUI/images/icon.png"));
	connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));

	aboutAction = new QAction("&About", this);
	aboutAction->setStatusTip("About Wordlist");
	aboutAction->setIcon(QIcon(":WordlistGUI/images/icon.png"));
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}

void WordlistGUI::createMenus()
{
	fileMenu = menuBar()->addMenu("&File");
	fileMenu->addAction(openAction);
	helpMenu = menuBar()->addMenu("&Help");
	helpMenu->addAction(aboutAction);
}

void WordlistGUI::enableHeadLineEdit(int state)
{
	headLineEdit->setEnabled(state == Qt::Checked);
}

void WordlistGUI::enableTailLineEdit(int state)
{
	tailLineEdit->setEnabled(state == Qt::Checked);
}

void WordlistGUI::updateExportButton()
{
	exportButton->setEnabled(outputTextEdit->toPlainText().length() != 0);
}

void WordlistGUI::openFile()
{
	QFileDialog *fileDialog = new QFileDialog(this);
	fileDialog->setWindowTitle("Open file");
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	QStringList fileNames;
	if (fileDialog->exec()) {
		fileNames = fileDialog->selectedFiles();
		QFile file(fileNames[0]);
		file.open(QIODevice::ReadOnly);
		QTextStream in(&file);
		QString content = in.readAll();
		if (content.length() == 0) {
			QMessageBox::information(this, "Warning", "Empty file.", QMessageBox::Yes);
		}
		inputTextEdit->setText(content);
		file.close();
	}
}

void WordlistGUI::exportResult()
{
	QFileDialog *fileDialog = new QFileDialog(this);
	fileDialog->setWindowTitle("Export result");
	fileDialog->setDefaultSuffix(".txt");
	fileDialog->setNameFilter("Text (*.txt)");
	fileDialog->setFileMode(QFileDialog::AnyFile);
	QStringList fileNames;
	if (fileDialog->exec()) {
		fileNames = fileDialog->selectedFiles();
		QFile file(fileNames[0]);
		file.open(QIODevice::WriteOnly);
		QTextStream out(&file);
		out << outputTextEdit->toPlainText();
		file.close();
		QMessageBox::information(this, "Info", "Saved.", QMessageBox::Yes);
	}
}

void WordlistGUI::about()
{
	QMessageBox::about(this, "About WordlistGUI",
		"<h2>Wordlist</h2>"
		"<p>Copyright &copy; 2019 Kilotron</p>"
		"<p>No help document here. Figure out how to use this by yourself!</p>"
	);
}

void WordlistGUI::extractWordsAndDisplay()
{
	int size;
	QString str = inputTextEdit->toPlainText();
	QString content;
	char **result = extractWords(str, size);
	for (int i = 0; i < size; i++) {
		content.append(result[i]).append("\n");
	}
	inputTextEdit->setText(content);
	if (size == 0) {
		QMessageBox::information(this, "No words found.", "No words found.");
	}
}

void WordlistGUI::findWordlist()
{
	char head = 0;
	char tail = 0;
	bool enableLoop;

	if (headCheckBox->isChecked()) {
		QString s = headLineEdit->text();
		if (s.length() != 1 || !isalpha(s.at(0).toLatin1())) {
			QMessageBox::critical(this, "Invalid head", "head is expected to be one English letter.");
			return;
		}
		head = tolower(s.at(0).toLatin1());
	}

	if (tailCheckBox->isChecked()) {
		QString s = tailLineEdit->text();
		if (s.length() != 1 || !isalpha(s.at(0).toLatin1())) {
			QMessageBox::critical(this, "Invalid tail", "tail is expected to be one English letter.");
			return;
		}
		tail = tolower(s.at(0).toLatin1());
	}

	enableLoop = loopCheckBox->isChecked();

	QString str = inputTextEdit->toPlainText();
	int size;
	char **words = extractWords(str, size);

	if (size < 2) {
		QMessageBox::warning(this, "Too few words", "Please input more than 2 words.", QMessageBox::Ok);
		return;
	}

	typedef int(*p_gen_chain_word)(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	typedef int(*p_gen_chain_char)(char* words[], int len, char* result[], char head, char tail, bool enable_loop);

	HMODULE CoreDLL = LoadLibrary(L"Core.dll");

	if (CoreDLL == nullptr) {
		QMessageBox::critical(this, "Error", "Cannot find Core.dll", QMessageBox::Ok);
		return;
	}

	p_gen_chain_word gen_chain_word = p_gen_chain_word(GetProcAddress(CoreDLL, "gen_chain_word"));
	p_gen_chain_char gen_chain_char = p_gen_chain_char(GetProcAddress(CoreDLL, "gen_chain_char"));

	if (gen_chain_char == nullptr || gen_chain_word == nullptr) {
		QMessageBox::critical(this, "Error", "Bad Core.dll", QMessageBox::Ok);
		return;
	}

	char **result = new char *[size];
	int resultLen;
	try {
		statusLabel->setText("Computing, please wait...");
		statusLabel->adjustSize();
		repaint();
		if (wordRadioButton->isChecked()) {
			resultLen = gen_chain_word(words, size, result, head, tail, enableLoop);
		}
		else {
			resultLen = gen_chain_char(words, size, result, head, tail, enableLoop);
		}
		statusLabel->setText("Done.");
	}
	catch (exception e) {
		statusLabel->setText("");
		QMessageBox::critical(this, "Error", "Loop detected. Please check the loop checkbox.", QMessageBox::Ok);
		return;
	}
	
	if (resultLen < 2) {
		QMessageBox::warning(this, "Empty Result", "No wordlist found.", QMessageBox::Ok);
		return;
	}

	QString content;
	for (int i = 0; i < resultLen; i++) {
		content.append(result[i]).append("\n");
	}
	outputTextEdit->setText(content);
}

char **WordlistGUI::extractWords(QString &str, int &size)
{
	set<string> words;
	QRegExp rx("[a-zA-Z]+");
	int pos = 0;
	while ((pos = rx.indexIn(str, pos)) != -1) {
		QString s = rx.cap(0);
		s = s.toLower();
		words.insert(s.toStdString());
		pos += rx.matchedLength();
	}

	size = words.size();
	char **result = new char *[size];
	int index = 0;
	for (set<string>::iterator i = words.begin(); i != words.end(); i++) {
		result[index] = new char[(*i).length() + 1];
		strcpy_s(result[index], (*i).length() + 1, (*i).c_str());
		index++;
	}
	return result;
}
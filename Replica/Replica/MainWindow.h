#pragma once

#include <QtWidgets/QMainWindow>
#include <QRemoteObjectNode>

#include "ui_MainWindow.h"
#include "x64/Debug/repc/rep_FileReader_replica.h"
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
public	slots :
	void on_pushButton_clicked();
	void slotContentChange(QByteArray content);
private:
	Ui::MainWindowClass ui;
	QRemoteObjectNode *m_remoteNode = nullptr;
	FileReaderReplica *m_fileReaderReplica = nullptr;
};

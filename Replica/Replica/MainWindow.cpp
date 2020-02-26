#include "MainWindow.h"
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_remoteNode = new QRemoteObjectNode(this);
	m_remoteNode->connectToNode(QUrl("local:FileReader"));
	m_fileReaderReplica = m_remoteNode->acquire<FileReaderReplica>();
	connect(m_fileReaderReplica, &FileReaderReplica::contentChanged,
		this, &MainWindow::slotContentChange);
	
	if (!m_fileReaderReplica->waitForSource(1000))
	{
		qWarning() << "remote init failed !";
	}
	else
	{
		qWarning() << "remote init success!";
	}
	
}
#include <time.h>
void MainWindow::on_pushButton_clicked()
{
	QString path = QFileDialog::getOpenFileName(this, "open file", "./ ", "text file(*.h *.cpp *.txt)");
	ui.lineEdit->setText(path);

	auto startTime = clock();
	auto res = m_fileReaderReplica->read(path);
	if (res.waitForFinished(60000))
	{
		auto interval = clock() - startTime;
		qDebug() <<"time interval:"<< interval <<"ms, receive file ! \n";
		auto &data = res.returnValue();
	}
	else
	{
		ui.textEdit->setText("receive  error! \n");
	}
}

void MainWindow::slotContentChange(QByteArray content)
{
	//ui.textEdit->clear();
	ui.textEdit->setText(QString(content));
}

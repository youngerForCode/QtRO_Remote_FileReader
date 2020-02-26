#include <QtCore/QCoreApplication>
#include <QRemoteObjectHost>
#include "FileReader.h"


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QRemoteObjectHost remoteObjectHost;
	remoteObjectHost.setHostUrl(QUrl("local:FileReader"));
	
	FileReader *fileReader = new FileReader;
	remoteObjectHost.enableRemoting(fileReader);

	auto result = a.exec();
	remoteObjectHost.disableRemoting(fileReader);
	delete fileReader;

	return result;
}

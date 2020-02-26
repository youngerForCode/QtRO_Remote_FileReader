#include "FileReader.h"

#include <QFile>
#include <QImage>

FileReader::FileReader(QObject *parent)
	: FileReaderSource(parent)
{
}


FileReader::~FileReader()
{
}

QByteArray FileReader::content() const
{
	return m_content;
}

QImage FileReader::read(QString path)
{
	QFile file(path);
	if (!file.exists())
	{
		qWarning() << "file " << path << " does not exist!";
		return m_image;
	}

	if (!file.open(QIODevice::ReadOnly))
	{
		qWarning() << "cannot open file " << path ;
		return m_image;
	}

	m_content = file.readAll();
	emit contentChanged(m_content);

	return m_image;
}

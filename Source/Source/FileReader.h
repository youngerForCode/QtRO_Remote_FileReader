#pragma once

#include "./x64/Debug/repc/rep_FileReader_source.h"

class FileReader : public FileReaderSource
{
public:
	FileReader(QObject *parent = nullptr) ;
	~FileReader();

	virtual QByteArray content() const override;

public Q_SLOTS:
	virtual QImage read(QString path) override;

private:
	QByteArray m_content;
	QImage m_image = QImage(1024 * 32, 1024, QImage::Format_RGBA8888);
};


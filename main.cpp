#include <QCoreApplication>
#include <QPainter>
#include <epframebuffer.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QString splashscreen_path = "/usr/share/remarkable/poweroff.png";

	qputenv("QT_QPA_PLATFORM", "epaper");

    QCoreApplication app(argc, argv);

    auto arg = app.arguments();
	if (arg.count() > 1) {
		splashscreen_path = arg[1];
	} else {
		qDebug() << "showing the poweroff image";
	}
	auto size = EPFrameBuffer::framebuffer()->size();
	QRect rect(0,0, size.width(), size.height());

    QPainter painter(EPFrameBuffer::framebuffer());
    QImage img(splashscreen_path);
    painter.drawImage(rect, img);
    EPFrameBuffer::sendUpdate(rect, EPFrameBuffer::Grayscale, EPFrameBuffer::FullUpdate);

    return 0;
}

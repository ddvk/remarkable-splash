#include <QPainter>
#include <epframebuffer.h>
#include <iostream>


void nullOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
}
int main(int argc, char *argv[])
{
	qInstallMessageHandler(nullOutput);
    QString splashscreen_path = "/usr/share/remarkable/poweroff.png";

    if (argc > 1) {
        splashscreen_path = argv[1];
    } else {
		std::cout << "no argument supplied, showing the poweroff image\n";
    }
    QImage img(splashscreen_path);
	if (img.isNull()) {
		std::cerr << "the image does not exist\n";
		return 1;
	}

    auto size = EPFrameBuffer::framebuffer()->size();
    QRect rect(0,0, size.width(), size.height());

    QPainter painter(EPFrameBuffer::framebuffer());
    painter.drawImage(rect, img);

    EPFrameBuffer::sendUpdate(rect, EPFrameBuffer::HighQualityGrayscale, EPFrameBuffer::FullUpdate);

    return 0;
}

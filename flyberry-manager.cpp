#include <iostream>
#include <unistd.h>
#include <wiringPi.h>
#include "Shutdown.h"
#include <QApplication>
#include <QTextCodec>
#include "Gpio.h"

#define SWITCH_ON_OFF_GPIO 3

void shutdownInterrupt();

static GPIO input(SWITCH_ON_OFF_GPIO, GPIO_INPUT, shutdownInterrupt);

void shutdownInterrupt(void)
{
	  input.isrCallback();
}



int main(int argc, char **argv) {

	QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	// display counter value every second.

    ShutDown w;
    //w.setVisible(false);
   QObject::connect(&input, &GPIO::inputChanged, &w, &ShutDown::setVisible);
    return a.exec();
}

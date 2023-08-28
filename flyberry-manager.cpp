#include <iostream>
#include <unistd.h>
#include <wiringPi.h>
#include "Shutdown.h"
#include <QApplication>
#include <QTextCodec>
#include "Gpio.h"

#define SWITCH_ON_OFF_GPIO 0

void shutdownInterrupt();

static GPIO input(0, GPIO_INPUT, shutdownInterrupt);

void shutdownInterrupt(void)
{
	  input.isrCallback();
}


int main(int argc, char **argv) {

	wiringPiSetupGpio();

	// set Pin 17/0 generate an interrupt on high-to-low transitions
	// and attach myInterrupt() to the interrupt
	if ( wiringPiISR (SWITCH_ON_OFF_GPIO, INT_EDGE_FALLING, &shutdownInterrupt) < 0 ) {
	  fprintf (stderr, "Unable to setup ISR: %s\n", strerror (errno));
	  return 1;
	}

	QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	// display counter value every second.

    ShutDown w;
//    w.show();
    QObject::connect(&input, &GPIO::inputChanged, &w, &ShutDown::setVisible);
    return a.exec();
}

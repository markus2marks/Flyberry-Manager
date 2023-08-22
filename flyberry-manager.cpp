#include <iostream>
#include <unistd.h>
#include "config.h"
#include <wiringPi.h>
#include "Shutdown.h"
#include <QApplication>
#include <QTextCodec>

#define SWITCH_ON_OFF_GPIO 0

ShutDown* test;

void shutdownInterrupt(void)
{
	if(test != 0x00)
	{
		test->show();
	}
}


int main(int argc, char **argv) {

#ifdef __arm__
		wiringPiSetupGpio();

	// set Pin 17/0 generate an interrupt on high-to-low transitions
	// and attach myInterrupt() to the interrupt
	if ( wiringPiISR (SWITCH_ON_OFF_GPIO, INT_EDGE_FALLING, &shutdownInterrupt) < 0 ) {
	  fprintf (stderr, "Unable to setup ISR: %s\n", strerror (errno));
	  return 1;
	}
#endif

	QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	// display counter value every second.

    ShutDown w;
    test = &w;
//    w.show();

    return a.exec();
}

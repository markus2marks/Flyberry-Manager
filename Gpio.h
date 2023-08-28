/*
 * Gpio.h
 *
 *  Created on: Aug 24, 2023
 *      Author: markus
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <QObject>
#include "wiringPi.h"

#define GPIO_INPUT   0
#define GPIO_OUTPUT  1
#define GPIO_PWM     2

class GPIO : public QObject
{
    Q_OBJECT
public:
    explicit GPIO(int pin, int type, void (*isrInput)(void) = nullptr, QObject *parent = nullptr);
    void isrCallback();

private:
    int m_pin;

signals:
    void inputChanged(int value);
};

#endif /* GPIO_H_ */

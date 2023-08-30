/*
 * Shutdown.h
 *
 *  Created on: Aug 19, 2023
 *      Author: markus
 */

#ifndef SHUTDOWN_H_
#define SHUTDOWN_H_

#include <QMainWindow>
#include <QCloseEvent>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QVBoxLayout>
#include <QCoreApplication>
#include <QProcess>

#define SET_SHUTDOWN_VISIBLE 0
#define SET_SHUTDOWN_INVISIBLE 1

namespace Ui {
class ShutDown;
}

class ShutDown : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShutDown(QWidget *parent = 0);
//    ~ShutDown();

public slots:
	void setVisible(int value);

private slots:
    void slot_timer();

private:
    QTimer *timer;
    int counter;
    QLabel *labelCounter;
    QLabel *labelText;
    QVBoxLayout *layout;
    QWidget *window;
};



#endif /* SHUTDOWN_H_ */

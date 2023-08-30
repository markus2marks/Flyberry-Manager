/*
 * Shutdown.cpp
 *
 *  Created on: Aug 19, 2023
 *      Author: markus
 */

#include "Shutdown.h"
//#include "ui_shutdown.h"

#include <QMessageBox>
#include <QDebug>


ShutDown::ShutDown(QWidget *parent) :
    QMainWindow(parent)
{

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_timer()));



//set labels
    labelText = new QLabel;
    QFont font1 = labelText->font();
	font1.setPointSize(24);
	font1.setBold(true);
	labelText->setFont(font1);
	labelText->setText("Shutdown in");

    labelCounter = new QLabel;
    labelCounter->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    labelCounter->setAlignment(Qt::AlignVCenter| Qt::AlignHCenter);

    QFont font2 = labelCounter->font();
    font2.setPointSize(24);
    font2.setBold(true);
    labelCounter->setFont(font2);


    counter = 3;
    labelCounter->setNum(counter);


	 window = new QWidget();
	 this->setCentralWidget(window);

   // Set layout
   layout = new QVBoxLayout(window);
   layout->setSizeConstraint(QLayout::SetMinimumSize);
   layout->addWidget(labelText);
   layout->addWidget(labelCounter);

}

void ShutDown::slot_timer()
{
	if(counter > 0)
	{
		counter--;
	}
	else
	{
		QProcess::execute("poweroff");
	}
	labelCounter->setNum(counter);
}

void ShutDown::setVisible(int value)
{
	if(!value)
	{
		this->show();
	    // msec
	    timer->start(1000);
	    labelCounter->setNum(counter);
	}
	else
	{
		this->hide();
		timer->stop();
		counter = 3;
	}
}

#ifndef CUSTOMTITLE_H
#define CUSTOMTITLE_H

#include <QtWidgets/QMainWindow>
#include "ui_customtitle.h"

class CustomTitle : public QMainWindow
{
	Q_OBJECT

public:
	CustomTitle(QWidget *parent = 0);
	~CustomTitle();

private:
	Ui::CustomTitleClass ui;
};

#endif // CUSTOMTITLE_H

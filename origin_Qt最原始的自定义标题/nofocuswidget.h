#ifndef NOFOCUSWIDGET_H
#define NOFOCUSWIDGET_H

#include <QWidget>
#include <QProxyStyle>
#include "ui_nofocuswidget.h"
#include "basewindow.h"

class NoFocusWidget : public BaseWindow
{
	Q_OBJECT

public:
	NoFocusWidget(QWidget *parent = 0);
	~NoFocusWidget();

private:
	void initTitleBar();

private:
	Ui::NoFocusWidget ui;
};

#endif // NOFOCUSWIDGET_H

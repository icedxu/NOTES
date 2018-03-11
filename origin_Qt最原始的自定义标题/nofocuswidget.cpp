#include "nofocuswidget.h"

NoFocusWidget::NoFocusWidget(QWidget *parent)
	: BaseWindow(parent)
{
	ui.setupUi(this);
	// ��ʼ��������;
	initTitleBar();
}

NoFocusWidget::~NoFocusWidget()
{

}

void NoFocusWidget::initTitleBar()
{
	// ���ñ����������Ч�������Բ�����;
	m_titleBar->setTitleRoll();

	m_titleBar->setTitleIcon(":/Resources/titleicon.png");
	m_titleBar->setTitleContent(QStringLiteral("ǰ���е�С��-ǰ��֮·����ǰ��"));
	m_titleBar->setButtonType(MIN_MAX_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

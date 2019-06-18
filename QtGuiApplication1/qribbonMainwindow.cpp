#include "qribbonsection.h"
#include "qribbonMainwindow.h"

#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>
#include <osgQt/GraphicsWindowQt>
#include <osg/MatrixTransform>
#include <osgManipulator/TabBoxDragger>
#include <osgGA/StateSetManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgDB/ReadFile>
#include <osgEarth/Map>
#include <osgEarth/MapNode>
#include <osgEarthDrivers/gdal/GDALOptions>
#include <osgEarthDrivers/tms/TMSOptions>
#include <osgEarth/ImageLayer>
#include<osgEarthDrivers/gdal/GDALOptions>

#include<osgEarthDrivers/bing/BingOptions>

#include <QComboBox>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include "qribbon.h"
#include <stdio.h>

QRibbonMainwindow::QRibbonMainwindow()
{
	//! ����������ư汾��Ϣ
	setWindowTitle(QString::fromLocal8Bit("��άGIS��ͼƽ̨"));

    //! ����ribbob�˵�
	CreateRibbonMenu();


}

QRibbonMainwindow::~QRibbonMainwindow()
{

}

void QRibbonMainwindow::CreateRibbonMenu()
{
	QWidget *widget = new QWidget(this);
	QVBoxLayout *layout = new QVBoxLayout();
	m_layout = layout;
	widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);

	QRibbon *ribbon = new QRibbon(this);

	//***************************************************************
	QWidget* tab = ribbon->addRibbonTab(QString::fromLocal8Bit("��ʼ"), "start");

	QRibbonSection *cloud = new QRibbonSection(tab, QString::fromLocal8Bit("�ƶ�"), "cloud");

	QAction *a11 = new QAction(QIcon(":/menuaction/Resources/menu/onlineact.png"), "", cloud);
	cloud->addLargeAction(a11, "a11");
	connect(a11, SIGNAL(triggered()), this, SLOT(action()));

	QAction *a12 = new QAction(QIcon(":/menuaction/Resources/menu/cloudact.png"), "", cloud);
	cloud->addLargeAction(a12, "a12");
	connect(a12, SIGNAL(triggered()), this, SLOT(action()));

	QRibbonSection *local = new QRibbonSection(tab, QString::fromLocal8Bit("��������"), "local");
	QAction *a21 = new QAction(QIcon(":/menuaction/Resources/menu/createLayeract.png"), "", local);
	local->addLargeAction(a21, "a21");
	connect(a21, SIGNAL(triggered()), this, SLOT(action()));

	QAction *a22 = new QAction(QIcon(":/menuaction/Resources/menu/loadLayeract.png"), "", local);
	local->addLargeAction(a22, "a22");
	connect(a22, SIGNAL(triggered()), this, SLOT(action()));

	QAction *a23 = new QAction(QIcon(":/menuaction/Resources/menu/loadTerrainact.png"), "", local);
	local->addLargeAction(a23, "a23");
	connect(a23, SIGNAL(triggered()), this, SLOT(action()));

	QRibbonSection *setting = new QRibbonSection(tab, QString::fromLocal8Bit("����"), "setting");
	QAction *a31 = new QAction(QIcon(":/menuaction/Resources/menu/settingact.png"), "", setting);
	setting->addLargeAction(a31, "a31");
	connect(a31, SIGNAL(triggered()), this, SLOT(action()));

	ribbon->addSection("start", cloud);
	ribbon->addSection("start", local);
	ribbon->addSection("start", setting);

	//*********************************************************************
	QWidget *tab2 = new QWidget();
	ribbon->addTab(tab2, QString::fromLocal8Bit("���ߵ�ͼ"), "onlineMap");

	QRibbonSection *googleDataSec = new QRibbonSection(tab2, QString::fromLocal8Bit("�ȸ�����"), "googleData");
	QAction *a211 = new QAction(QIcon(":/menuaction/Resources/menu/googlemapact.png"), "", googleDataSec);
	googleDataSec->addLargeAction(a211, "a211");
	connect(a211, SIGNAL(triggered()), this, SLOT(action()));
	/*QComboBox *cbox = new QComboBox();
	cbox->addItem(QString::fromLocal8Bit("�ȸ��·"));
	cbox->addItem(QString::fromLocal8Bit("�ȸ��ͼ"));
	cbox->addItem(QString::fromLocal8Bit("�ȸ����"));
	googleDataSec->addWidget(cbox, "cbox", 1);
	connect(cbox, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));*/

	ribbon->addSection("onlineMap", googleDataSec);

	//**************************************************************************
	QWidget *tab3 = new QWidget();
	ribbon->addTab(tab3, QString::fromLocal8Bit("�༭"), "edit");

	//**************************************************************************
	QWidget *tab4 = new QWidget();
	ribbon->addTab(tab4, QString::fromLocal8Bit("����"), "download");

	//**************************************************************************
	QWidget *tab5 = new QWidget();
	ribbon->addTab(tab5, QString::fromLocal8Bit("����"), "tool");

	//**************************************************************************
	QWidget *tab6 = new QWidget();
	ribbon->addTab(tab6, QString::fromLocal8Bit("����"), "analysis");

	//**************************************************************************
	QWidget *tab7 = new QWidget();
	ribbon->addTab(tab7, QString::fromLocal8Bit("����"), "scene");

	//**************************************************************************
	QWidget *tab8 = new QWidget();
	ribbon->addTab(tab8, QString::fromLocal8Bit("��ͼ"), "view");

	//**************************************************************************
	QWidget *tab9 = new QWidget();
	ribbon->addTab(tab9, QString::fromLocal8Bit("����"), "help");

	//*****************************************************************************
	QWidget *tab10 = new QWidget();
	ribbon->addTab(tab10, QString::fromLocal8Bit("����"), "test");

	QRibbonSection *local10 = new QRibbonSection(tab10, QString::fromLocal8Bit("����"), "test");
	QAction *aa10 = new QAction(QIcon(":/icons/test.svg"), "", local10);
	aa10->setObjectName("aa");
	connect(aa10, SIGNAL(triggered()), this, SLOT(action()));
	local10->addLargeAction(aa10, "aa");
	QAction *bb10 = new QAction(QIcon(":/icons/RibbonPoint.svg"), "", local10);
	bb10->setObjectName("bb");
	connect(bb10, SIGNAL(triggered()), this, SLOT(action()));
	local10->addLargeAction(bb10, "bb");
	QAction *det10 = new QAction(local10);
	local10->setDetailsAction(det10);

	ribbon->addSection("test", local10);
	

	//! ��ӵ�������
	layout->addWidget(ribbon);
	widget->setLayout(layout);
	setCentralWidget(widget);

}

void QRibbonMainwindow::addOSGViewerWidget(QWidget* wgt)
{
	m_layout->addWidget(wgt);
}

void QRibbonMainwindow::indexChanged(int tab) {
    printf("current tab = %d\n", tab);
    fflush(stdout);
}

void QRibbonMainwindow::action() {
    QAction *a = (QAction *) sender();
    printf("action = %p\n",a);
    if (a->objectName() == "bb") {
        printf("JE!\n");
        QApplication::quit();
    }
    fflush(stdout);
}

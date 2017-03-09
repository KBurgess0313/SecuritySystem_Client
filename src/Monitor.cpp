#include "Monitor.h"

Monitor::Monitor(const std::string& aCameraLogin,
                 const std::string& aCameraPass,
                 const std::string& aCameraIp,
                 const std::string& aMyName,
                 QWidget *parent) :
  Common::Types::CameraFeed(aCameraLogin,
                            aCameraPass,
                            aCameraIp),
  mName(aMyName)
{
  mMonitorLbl = new QLabel(parent);
  mMonitorLbl->setText("Test");

  QVBoxLayout* layout = new QVBoxLayout(parent);

  layout->addWidget(mMonitorLbl);

  QGroupBox* grp = new QGroupBox(QString::fromStdString(mName), 
                                 parent);
  grp->setLayout(layout);

  QVBoxLayout* widgetLayout = new QVBoxLayout(this);

  widgetLayout->addWidget(grp);

  setLayout(widgetLayout);

  connect(this, SIGNAL(cameraFrame(const QPixmap&)), this, SLOT(receiveNewFrame(const QPixmap&)));

  init();
}

Monitor::~Monitor()
{
  terminate();
}

void Monitor::receiveNewFrame(const QPixmap& frame)
{
  mMonitorLbl->setPixmap(frame);
  this->repaint();
}

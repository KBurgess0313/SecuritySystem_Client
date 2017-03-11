#include "Monitor.h"

Monitor::Monitor(const Common::Types::CameraFeedPtr& aCamera,
                 QWidget *parent) :
  mCamera(aCamera)
{
  mMonitorLbl = new QLabel(parent);
  QVBoxLayout* layout = new QVBoxLayout(parent);

  layout->addWidget(mMonitorLbl);

  QGroupBox* grp = new QGroupBox(QString::fromStdString(mCamera->getName()), 
                                 parent);
  grp->setLayout(layout);

  QVBoxLayout* widgetLayout = new QVBoxLayout(this);

  widgetLayout->setAlignment(Qt::AlignCenter);
  widgetLayout->addWidget(grp);

  setLayout(widgetLayout);

  connect(mCamera.get(), &Common::Types::CameraFeed::cameraFrame, this, &Monitor::receiveNewFrame);

  mCamera->init();
}

Monitor::~Monitor()
{
  mCamera->terminate();
}

void Monitor::receiveNewFrame(const QPixmap& frame)
{
  mMonitorLbl->setPixmap(frame);
  this->repaint();
}

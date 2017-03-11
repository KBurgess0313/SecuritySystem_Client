#include "SecuritySystem_Client.h"

#include "Common/Types/Account.h"

#include "ConfigFile.h"

#include "Monitor.h"
#include "LoginForm.h"

#include <QGridLayout>

#include <boost/bind.hpp>
#include <boost/function.hpp>


SecuritySystem_Client::SecuritySystem_Client(QWidget *parent)
    : QMainWindow(parent)
{
  ui.setupUi(this);
}

SecuritySystem_Client::~SecuritySystem_Client()
{
}

void SecuritySystem_Client::successfulLogin(const Common::Types::Account&)
{
  QGridLayout* grid = new QGridLayout(this);

  ConfigFilePtr config = ConfigFile::instance();

  Common::Types::CameraFeedPtrList cameras = config->getCameraFeeds();

  for(const Common::Types::CameraFeedPtr cam : cameras)
  {
    addCameraToUi(cam);
  }

  show();
}

void SecuritySystem_Client::addCameraToUi(const Common::Types::CameraFeedPtr& cam)
{
  static int cameraCount = 0;

  QGridLayout* gridLayout = dynamic_cast<QGridLayout*>(ui.cameraGroupBox->layout());


  if (!gridLayout)
    return;

  Monitor* monitor = new Monitor(cam, this);
  
  int row = (cameraCount & 2) >> 1;
  int col = cameraCount & 1;

  gridLayout->addWidget(monitor, row, col);

  cameraCount++;
}
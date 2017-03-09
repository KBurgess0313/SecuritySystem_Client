#include "SecuritySystem.h"
#include "ui_SecuritySystem.h"

#include "Accounts.h"
#include "ConfigFile.h"
#include "CameraFeed.h"
#include "Monitor.h"

#include "LoginForm.h"

#include <QGridLayout>

SecuritySystem::SecuritySystem(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::SecuritySystem)
{
  ui->setupUi(this);

  LoginForm* login = new LoginForm(this);
  login->show();

  connect(login, SIGNAL(successfulLogin(AccountPtr)), this, SLOT(successfulLogin(AccountPtr)));
}

SecuritySystem::~SecuritySystem()
{
  delete ui;
}

void SecuritySystem::successfulLogin(AccountPtr aAccount)
{
  ConfigFilePtr config = ConfigFile::instance();

  CameraFeedPtrList cameras = config->getCameraFeeds();

  CameraFeedPtrList::const_iterator it = cameras.begin();

  QGridLayout* grid = new QGridLayout();

  for(; it != cameras.end(); ++it)
  {
    MonitorPtr monitor = MonitorPtr(new Monitor(*it, ui->tempLbl, this));

    grid->addWidget(monitor.get());
    mMonitors.push_back(monitor);
  }

  ui->cameraGroupBox->setLayout(grid);
  show();
}

#include "SecuritySystem_Client.h"

#include "Common/Types/Account.h"

#include "Monitor.h"
#include "LoginForm.h"

#include <QGridLayout>

#include <boost/bind.hpp>

SecuritySystem_Client::SecuritySystem_Client(QWidget *parent)
    : QMainWindow(parent)
{
  ui.setupUi(this);
  successfulLogin();
 // mLoginForm = new LoginForm(this);
 // mLoginForm->show();

 // connect(mLoginForm, &LoginForm::successfulLogin, this, &SecuritySystem_Client::successfulLogin);
}

SecuritySystem_Client::~SecuritySystem_Client()
{
}

void SecuritySystem_Client::successfulLogin()
{
  //mLoginForm->close();

  QGridLayout* grid = new QGridLayout(this);

  int numCams = 8;

  int numRows = sqrt(static_cast<double>(numCams));
  int numCols = numRows;

  if ((numRows * numCols) < numCams)
  {
    numRows++;
  }

  int count = 0;
  for (int i = 0; i < numRows; ++i)
  {
    for (int j = 0; j < numCols; ++j)
    {
      std::string title = "Living Room" + QString::number(++count).toStdString();
      Monitor* monitor = new Monitor("admin", "123456", "192.168.1.223", title, this);
      grid->addWidget(monitor, i, j);
    }
  }

  ui.cameraGroupBox->setLayout(grid);

  show();
}
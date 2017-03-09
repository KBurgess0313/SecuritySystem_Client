#include "SecuritySystem_Client.h"
#include "LoginForm.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  LoginForm l;
  l.show();

  SecuritySystem_Client w;

  return a.exec();
}

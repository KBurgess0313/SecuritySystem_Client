#include "SecuritySystem_Client.h"
#include "LoginForm.h"
#include "Common\Types\Account.h"

#include <QtWidgets/QApplication>

Q_DECLARE_METATYPE(Common::Types::Account);

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  qRegisterMetaType<Common::Types::Account>("Common::Types::Account");

  LoginForm l;
  l.show();

  SecuritySystem_Client w;

  QObject::connect(&l, &LoginForm::successfulLogin, &w, &SecuritySystem_Client::successfulLogin);

  return a.exec();
}

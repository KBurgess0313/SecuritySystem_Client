#include "LoginForm.h"
#include "ui_LoginForm.h"

#include "Common\Types\Account.h"
#include "ConfigFile.h"

LoginForm::LoginForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::LoginForm)
{
  ui->setupUi(this);

  connect(ui->btnLogin, &QPushButton::clicked, this, &LoginForm::attemptLogin);
}

LoginForm::~LoginForm()
{
  delete ui;
}

void LoginForm::attemptLogin()
{
  using namespace Common::Types;
  ConfigFilePtr config = ConfigFile::instance();

  std::string login = ui->txtUsername->text().toStdString();
  std::string passwd = ui->txtPassword->text().toStdString();

  AccountList accounts = config->getAccounts();

  for (auto it = accounts.begin(); it != accounts.end(); ++it)
  {
    if ((*it).isValidLogin(login, passwd))
    {
      emit successfulLogin(*it);
      close();
    }
  }
}

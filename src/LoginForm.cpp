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

  AccountPtr acct = AccountPtr(new Account("Admin", 
                                           "Burgess", 
                                           "admin", 
                                           "Scuba5199", 
                                           Common::Types::Privelages::ADMIN, 
                                           std::vector<std::string>()));
  successfulLogin();
}

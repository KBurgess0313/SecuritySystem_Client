#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <boost/signals2.hpp>
#include <boost/bind.hpp>

#include "Common\Types\Account.h"

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
  Q_OBJECT

public:
  explicit LoginForm(QWidget *parent = 0);
  ~LoginForm();

signals:
  void successfulLogin();

public slots:
  void attemptLogin();


private:
  Ui::LoginForm *ui;
};

#endif // LOGINFORM_H

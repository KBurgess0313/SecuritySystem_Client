#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H

#include "Accounts.h"
#include "Monitor.h"

#include <QMainWindow>

#include <boost/shared_ptr.hpp>
#include <vector>

namespace Ui {
class SecuritySystem;
} //namespace ui


class SecuritySystem : public QMainWindow
{
  Q_OBJECT

public:
  explicit SecuritySystem(QWidget *parent = 0);
  ~SecuritySystem();

private slots:
  void successfulLogin(AccountPtr aAccount);

private:
  Ui::SecuritySystem *ui;
  MonitorPtrList mMonitors;
};

#endif // SECURITYSYSTEM_H

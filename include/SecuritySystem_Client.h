#include <QMetaType>
#include <QtWidgets/QMainWindow>
#include <boost/shared_ptr.hpp>

#include "ui_SecuritySystem_Client.h"

namespace Common
{
namespace Types
{
  struct Account;
  typedef boost::shared_ptr<Account> AccountPtr;

  class CameraFeed;
  typedef boost::shared_ptr<CameraFeed> CameraFeedPtr;
} //namepace Common
} //namepace Types

typedef class Monitor;
typedef boost::shared_ptr<Monitor> MonitorPtr;
typedef std::vector<MonitorPtr> MonitorPtrList;

class SecuritySystem_Client : public QMainWindow
{
    Q_OBJECT

public:
    SecuritySystem_Client(QWidget *parent = Q_NULLPTR);
    ~SecuritySystem_Client();

public slots:
  void successfulLogin(const Common::Types::Account&);
  void addCameraToUi(const Common::Types::CameraFeedPtr&);

private:
  Ui::SecuritySystem_ClientClass ui;

  MonitorPtrList mMonitors;
};

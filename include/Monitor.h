#ifndef MONITOR_H
#define MONITOR_H

#include "Common\Types\CameraFeed.h"

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>

#include <QPixmap>

#include <boost/shared_ptr.hpp>
#include <vector>

class Monitor : public Common::Types::CameraFeed
{
  Q_OBJECT

public:
  Monitor(const std::string& aCameraLogin,
          const std::string& aCameraPass,
          const std::string& aCameraIp,
          const std::string& aMyName,
          QWidget *parent = 0);

  ~Monitor();

public slots:
  void receiveNewFrame(const QPixmap& frame);

private:
  Monitor();

private:
  std::string mName;
  QLabel* mMonitorLbl;
};

typedef boost::shared_ptr<Monitor> MonitorPtr;
typedef std::vector<MonitorPtr> MonitorPtrList;

#endif // MONITOR_H

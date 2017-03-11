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

class Monitor : public QWidget
{
  Q_OBJECT

public:
  Monitor(const Common::Types::CameraFeedPtr& aCamera,
          QWidget *parent = 0);

  ~Monitor();

public slots:
  void receiveNewFrame(const QPixmap& frame);

private:
  Monitor();

private:
  Common::Types::CameraFeedPtr mCamera;
  QLabel* mMonitorLbl;
};

typedef boost::shared_ptr<Monitor> MonitorPtr;
typedef std::vector<MonitorPtr> MonitorPtrList;

#endif // MONITOR_H

#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include "Common\Types\Account.h"
#include "Common\Types\CameraFeed.h"

#include <boost/shared_ptr.hpp>
#include <boost/property_tree/ptree.hpp>

class ConfigFile;
typedef boost::shared_ptr<ConfigFile> ConfigFilePtr;

class ConfigFile
{
public:
  static ConfigFilePtr instance();
  Common::Types::AccountList getAccounts();
  Common::Types::CameraFeedPtrList getCameraFeeds();

private:
  ConfigFile();

private:
  std::string mFileName;

  boost::property_tree::ptree mFile;
};

#endif // CONFIGFILE_H

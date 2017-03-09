#include "ConfigFile.h"

#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
#include <vector>

ConfigFilePtr ConfigFile::instance()
{
  static ConfigFilePtr config = ConfigFilePtr(new ConfigFile());

  return config;
}

Common::Types::AccountPtrList ConfigFile::getAccounts()
{
  using namespace boost::property_tree;
  using namespace Common::Types;

  AccountPtrList out;

  if(!mFile.empty())
  {
    for(const ptree::value_type& value : mFile.get_child("SecuritySystem.UserAccounts"))
    {
      AccountPtr acct = AccountPtr(new Account(value));
      out.push_back(acct);
    }
  }
  return out;
}

Common::Types::CameraFeedPtrList ConfigFile::getCameraFeeds()
{
  using namespace boost::property_tree;
  using namespace Common::Types;

  Common::Types::CameraFeedPtrList out;

  if(!mFile.empty())
  {
    for(const ptree::value_type& value : mFile.get_child("SecuritySystem.Cameras"))
    {
      CameraFeedPtr camera = CameraFeedPtr(new CameraFeed(value));
      out.push_back(camera);
    }
  }

  return out;
}

ConfigFile::ConfigFile() :
  //mFileName("/opt/SecuritySystem/config.xml"),
  mFileName("/home/pi/Developer/SecuritySystem_UI/config/config.xml"),
  mFile()
{
  try
  {
  boost::property_tree::read_xml(mFileName, mFile);
  }
  catch(std::exception e)
  {
    std::cout << e.what() << "\n";
  }
}

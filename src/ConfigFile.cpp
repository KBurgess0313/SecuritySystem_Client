#include "ConfigFile.h"

#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
#include <vector>

ConfigFilePtr ConfigFile::instance()
{
  static ConfigFilePtr config = ConfigFilePtr(new ConfigFile());

  return config;
}

Common::Types::AccountList ConfigFile::getAccounts()
{
  using namespace boost::property_tree;
  using namespace Common::Types;

  AccountList out;

  if(!mFile.empty())
  {
    for(const ptree::value_type& value : mFile.get_child("SecuritySystem.UserAccounts"))
    {
      Account acct =  Account(value);
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
  mFile()
{
  char* appdata = getenv("APPDATA");
  mFileName = std::string(appdata) + "\\SecuritySystem\\config\\config.xml";
  try
  {
    boost::property_tree::read_xml(mFileName, mFile);
  }
  catch(std::exception e)
  {
    std::cout << e.what() << "\n";
  }
}

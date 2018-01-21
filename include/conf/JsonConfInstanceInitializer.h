#pragma once

#include "JsonConfHandler.h"

RACconf::JsonConfHandler* RACconf::JsonConfHandler::pInstance = nullptr;
boost::property_tree::ptree   RACconf::JsonConfHandler::oRoot;


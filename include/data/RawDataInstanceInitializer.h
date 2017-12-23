#pragma once

#include "PacketData.h"

std::queue<std::tuple<const char*, int>*>   RACdata::RawData::qData;
std::mutex				    RACdata::RawData::oMutex;

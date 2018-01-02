#pragma once

#include "PacketData.h"
#include "DecodedData.h"

std::mutex		RACdata::RawData::oMutex;
std::mutex		RACdata::DecodedData::oMutex;
std::queue<std::tuple<const char*, int>>   RACdata::RawData::qData;
std::queue<std::tuple<const char*, int>>   RACdata::DecodedData::qData;



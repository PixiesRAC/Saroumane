#pragma once

#include "LogHandler.h"

RAClog::FileLogHandler *RAClog::FileLogHandler::pInstance = nullptr;
std::ofstream       RAClog::FileLogHandler::oFileStream; 

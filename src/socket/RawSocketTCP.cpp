#include "RawSocketTCP.h"
#include "LogHandler.h"

RACsocket::RawSocketTCP::RawSocketTCP()
{
    this->open();
    LOG(INFO, "Creation of Raw Socket TCP");
}

RACsocket::RawSocketTCP::~RawSocketTCP()
{
    this->close();
}

int RACsocket::RawSocketTCP::open()
{
}

int RACsocket::RawSocketTCP::close()
{
}

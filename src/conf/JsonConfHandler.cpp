#include "JsonConfHandler.h"

namespace RACconf
{
    JsonConfHandler::JsonConfHandler()
    {
	boost::property_tree::read_json(pJsonPathFilename, oRoot);
    }
}

#include "gtest/gtest.h"

#include "JsonConfHandler.h"
#include "JsonConfInstanceInitializer.h"


TEST(conf_test_case, should_return_the_value_4242_when_the_port_is_set_to_4242_on_the_conf_file)
{
    
    EXPECT_EQ(RACconf::JsonConfHandler::GetOrCreateInstance()->GetValueFromConfigFile<int>("port"), 4242);
}

TEST(conf_test_case, should_throw_an_exception_when_the_balise_is_not_defined)
{
    try{
	RACconf::JsonConfHandler::GetOrCreateInstance()->GetValueFromConfigFile<int>("BADBALISE.dd.f");
    }
    catch(std::exception &e)
    {
	EXPECT_STREQ(e.what(), "No such node (BADBALISE.dd.f)");
    }
}

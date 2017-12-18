#include "gtest/gtest.h"

#define LOG_UNIT_TEST 1

#include "LogHandler.h"

TEST(sample_test_case, sample_test)
{
        EXPECT_EQ(1, 1);
}

TEST(log_test_case, should_display_in_info_mode_when_the_first_parameter_is_set_to_info)
{
    EXPECT_STREQ(LOG(INFO, ""),
		    "[ INFO ] ");
}

TEST(log_test_case, should_display_in_warn_mode_when_the_first_parameter_is_set_to_warn)
{
    EXPECT_STREQ(LOG(WARN, ""),
		    "[ WARN ] ");
}

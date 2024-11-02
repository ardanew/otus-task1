#include <sstream>
#include <gtest/gtest.h>
#include "hello.h"
#include "version.h"

TEST(Hello, simple) {
  std::stringstream ss;
  hello::greetings(ss);
  EXPECT_NE(std::string::npos, ss.str().find("Hello, world!"));
  EXPECT_TRUE(std::atoi(PATCH_NUM) > 0);
}

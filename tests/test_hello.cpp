#include <sstream>

#include <gtest/gtest.h>

#include <hello.h>

TEST(Hello, simple) {
  std::stringstream ss;
  hello::greetings(ss);
  ASSERT_NE(std::string::npos, ss.str().find("Hello, world!"));
}

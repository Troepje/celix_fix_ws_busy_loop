/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *  KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <gtest/gtest.h>

#include "celix/Filter.h"

class CxxFilterTestSuite : public ::testing::Test {
public:
};


TEST_F(CxxFilterTestSuite, CreateDestroy) {
    //TODO support empty filter
//    celix::Filter filter{};
//    EXPECT_TRUE(filter.getCFilter() != nullptr);
}

TEST_F(CxxFilterTestSuite, FilterString) {
    //TODO
//    celix::Filter filter1{};
//    EXPECT_EQ(std::string{}, filter1.getFilterString());

    celix::Filter filter2{"(key=value)"};
    EXPECT_EQ(std::string{"(key=value)"}, filter2.getFilterString());
}

TEST_F(CxxFilterTestSuite, EmptyFilterTest) {
    //TODO match test that match is always true
}

TEST_F(CxxFilterTestSuite, MatchTest) {
    celix::Filter filter1{"(key=value)"};
    celix::Filter filter2{"(key=value2)"};
    celix::Properties props1{};
    props1.set("key", "value");
    celix::Properties props2{};

    EXPECT_TRUE(filter1.match(props1));
    EXPECT_FALSE(filter2.match(props1));
    EXPECT_FALSE(filter1.match(props2));
    EXPECT_FALSE(filter2.match(props2));
}

TEST_F(CxxFilterTestSuite, FindAttributes) {
    celix::Filter filter1{"(&(key1=value1)(key2=value2)(|(key3=value3)(key4=*)))"};

    EXPECT_TRUE(filter1.hasAttribute("key1"));
    EXPECT_TRUE(filter1.hasAttribute("key2"));
    EXPECT_TRUE(filter1.hasAttribute("key3"));
    EXPECT_TRUE(filter1.hasAttribute("key4"));
    EXPECT_FALSE(filter1.hasAttribute("key"));

    EXPECT_EQ(filter1.findAttribute("key1"), std::string{"value1"});
    EXPECT_EQ(filter1.findAttribute("key2"), std::string{"value2"});
    EXPECT_EQ(filter1.findAttribute("key3"), std::string{"value3"});
    EXPECT_EQ(filter1.findAttribute("key4"), std::string{"*"});
    EXPECT_TRUE(filter1.findAttribute("key").empty());
}
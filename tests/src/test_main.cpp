// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include<iostream>
using namespace std;

#include <limits.h>
#include "gtest/gtest.h"
#include <QApplication>

#if defined(CMAKE_SAFETYTEST_ARG_ON)
#include <sanitizer/asan_interface.h>
#endif

//  gtest的入口函数
int main(int argc, char **argv) {
    qputenv("QT_QPA_PLATFORM","offscreen");
    QApplication a(argc,argv);
    ::testing::InitGoogleTest(&argc, argv);
    auto c= RUN_ALL_TESTS();

#if defined(CMAKE_SAFETYTEST_ARG_ON)
    __sanitizer_set_report_path("asan.log");
#endif
    return c;
}

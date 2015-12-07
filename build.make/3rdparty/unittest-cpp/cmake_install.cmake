# Install script for directory: /Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/build.make/3rdparty/unittest-cpp/libUnitTest++.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libUnitTest++.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libUnitTest++.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libUnitTest++.a")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/UnitTest++" TYPE FILE FILES
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/AssertException.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/CheckMacros.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/Checks.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/CompositeTestReporter.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/Config.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/CurrentTest.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/DeferredTestReporter.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/DeferredTestResult.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/ExceptionMacros.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/ExecuteTest.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/HelperMacros.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/MemoryOutStream.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/ReportAssert.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/ReportAssertImpl.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/Test.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/TestDetails.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/TestList.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/TestMacros.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/TestReporter.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/TestReporterStdout.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/TestResults.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/TestRunner.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/TestSuite.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/TimeConstraint.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/TimeHelpers.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/UnitTest++.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/UnitTestPP.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/XmlTestReporter.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/UnitTest++/Posix" TYPE FILE FILES
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/Posix/SignalTranslator.h"
    "/Users/mengchaowang/Library/Mobile Documents/com~apple~CloudDocs/Northwestern University/EECS-495-Intensive Program Design/HW7/hw-project copy/3rdparty/unittest-cpp/UnitTest++/Posix/TimeHelpers.h"
    )
endif()


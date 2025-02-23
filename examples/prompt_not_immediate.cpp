/*
* cpp-terminal
* C++ library for writing multi-platform terminal applications.
*
* SPDX-FileCopyrightText: 2019-2023 cpp-terminal
*
* SPDX-License-Identifier: MIT
*/

#include "cpp-terminal/exception.hpp"
#include "cpp-terminal/prompt.hpp"
#include "cpp-terminal/version.hpp"

#include <iostream>

int main()
{
  std::cout << "Running cpp-terminal version: " << Term::Version::string << std::endl;
  try
  {
    std::cout << "CPP-Terminal basic prompt example: \n\n";
    switch(Term::prompt("Proceed?", "Y", "n", ":", false))
    {
      case Term::Result::None:  // no input was given
        std::cout << "No input given, proceeding anyway...\n";
        break;
      case Term::Result::Invalid: std::cout << "Invalid input given, proceeding anyway\n"; break;
      case Term::Result::Yes: std::cout << "Proceeding...\n"; break;
      case Term::Result::No: std::cout << "Stopping...\n"; break;
      case Term::Result::Abort: std::cout << "Exit signal received, exiting now...\n"; break;
      case Term::Result::Error:
        std::cout << "Error while capturing input, is your terminal attached to a TTY?\n";
        std::cout << "Aborting...\n";
        break;
    }
  }
  catch(const Term::Exception& re)
  {
    std::cerr << "cpp-terminal error: " << re.what() << std::endl;
    return 2;
  }
  catch(...)
  {
    std::cerr << "Unknown error." << std::endl;
    return 1;
  }
  return 0;
}

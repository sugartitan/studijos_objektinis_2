#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>

struct FileNotFound : public std::exception {
   const char * what () const throw () {
      return "File not found";
   }
};

#endif
// vim:ts=2:sw=2:expandtab:autoindent:filetype=cpp:
/*
The MIT License

Copyright (c) 2008, 2009 Aristid Breitkreuz, Ash Berlin, Ruediger Sonderfeld

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef FLUSSPFERD_SECURITY_HPP
#define FLUSSPFERD_SECURITY_HPP

#include "detail/api.hpp"
#include "native_object_base.hpp"
#include "class.hpp"
#include "class_description.hpp"

namespace flusspferd {

FLUSSPFERD_CLASS_DESCRIPTION(
  security,
  (full_name, "$security")
  (constructor_name, "")
  (constructible, false)
  (api, FLUSSPFERD_API))
{
public:
  static FLUSSPFERD_API security &create(object container);
  static FLUSSPFERD_API security &get();

  security(object const &);
  ~security();

  enum mode_t { 
    READ = 1,
    WRITE = 2,
    READ_WRITE = READ|WRITE,
    CREATE = 4,
    ACCESS = 8
  };

  bool check_path(std::string const &filename, unsigned mode);
  bool check_url(std::string const &url, unsigned mode);

private:
  class impl;
  boost::scoped_ptr<impl> p;
};

}

#endif

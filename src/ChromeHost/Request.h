/*
Jabra Browser Integration
https://github.com/gnaudio/jabra-browser-integration

MIT License

Copyright (c) 2017 GN Audio A/S (Jabra)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <string>
#include <iostream>
#include "Context.h"

/**
 * Contains an incomming request from the chrome extension.
 */
class Request : public Context {
  public:
  const std::string message;

  explicit Request(const std::string& message, const std::string& requestId, const std::string& apiClientId)
         : Context(requestId, apiClientId), message(message) {}

  Request(const Request&) = delete;
  Request& operator=(const Request&) = delete;

  friend std::ostream& operator<<(std::ostream& os, const Request& r);
};

inline std::ostream& operator<<(std::ostream& os, const Request& r)
{
	os << "Response { ";
	os << "message: " << r.message;
	os << ", requestId: " << r.requestId;
	os << ", apiClientId: " << r.apiClientId;
	os << "}";
	return os;
}
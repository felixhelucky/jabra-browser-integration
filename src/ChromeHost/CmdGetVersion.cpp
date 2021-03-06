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

#include "stdafx.h"
#include "CmdGetVersion.h"
#include "meta.h"

CmdGetVersion::CmdGetVersion(HeadsetIntegrationService* headsetIntegrationService)
{
  m_headsetIntegrationService = headsetIntegrationService;
}

CmdGetVersion::~CmdGetVersion()
{
}

bool CmdGetVersion::CanExecute(const Request& request)
{
  return (request.message == "getversion");
}

void CmdGetVersion::Execute(const Request& request)
{
  // Nb. Don't change the version number 0.5 unless you want to break old browser extensions !
  // Changing this number will break <= 0.5 versions of chrome browser extension, so it can't
  // currently be used for anything useful.
  m_headsetIntegrationService->Event(request, "Version 0.5", {
    std::make_pair("version", "0.5"),
    std::make_pair("version_chromehost", VERSION),
    std::make_pair("version_nativesdk", getNativeSDKVersion())
  });
}

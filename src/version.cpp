// This file is a part of the IncludeOS unikernel - www.includeos.org
//
// Copyright 2015-2016 Oslo and Akershus University College of Applied Sciences
// and Alfred Bratterud
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <version.hpp>

namespace http {

///////////////////////////////////////////////////////////////////////////////
Version::Version(const unsigned major, const unsigned minor) noexcept:
  major_{major},
  minor_{minor}
{}

///////////////////////////////////////////////////////////////////////////////
unsigned Version::get_major() const noexcept {
  return major_;
}

///////////////////////////////////////////////////////////////////////////////
void Version::set_major(const unsigned major) noexcept {
  major_ = major;
}

///////////////////////////////////////////////////////////////////////////////
unsigned Version::get_minor() const noexcept {
  return minor_;
}

///////////////////////////////////////////////////////////////////////////////
void Version::set_minor(const unsigned minor) noexcept {
  minor_ = minor;
}

///////////////////////////////////////////////////////////////////////////////
std::string Version::to_string() const {
  return *this;
}

///////////////////////////////////////////////////////////////////////////////
Version::operator std::string () const {
  std::ostringstream ver_data;
  //----------------------------
  ver_data << "HTTP/" << major_
           << "."     << minor_;
 //-----------------------------
  return ver_data.str();
}

///////////////////////////////////////////////////////////////////////////////
bool operator == (const Version& lhs, const Version& rhs) noexcept {
  return lhs.get_major() == rhs.get_major()
         and
         lhs.get_minor() == rhs.get_minor();
}

///////////////////////////////////////////////////////////////////////////////
bool operator != (const Version& lhs, const Version& rhs) noexcept {
  return not (lhs == rhs);
}

///////////////////////////////////////////////////////////////////////////////
bool operator < (const Version& lhs, const Version& rhs) noexcept {
  return lhs.get_major() < rhs.get_major()
         or
         lhs.get_minor() < rhs.get_minor();
}

///////////////////////////////////////////////////////////////////////////////
bool operator > (const Version& lhs, const Version& rhs) noexcept {
  return lhs.get_major() > rhs.get_major()
         or
         lhs.get_minor() > rhs.get_minor();
}

///////////////////////////////////////////////////////////////////////////////
bool operator <= (const Version& lhs, const Version& rhs) noexcept {
  return (lhs < rhs) or (lhs == rhs);
}

///////////////////////////////////////////////////////////////////////////////
bool operator >= (const Version& lhs, const Version& rhs) noexcept {
  return (lhs > rhs) or (lhs == rhs);
}

} //< namespace http

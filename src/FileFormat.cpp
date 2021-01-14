#include "FileFormat.hpp"

namespace Ranty::SPC
{
  namespace
  {
    constexpr const char* magic = "SNES-SPC700 Sound File Data v0.30\x1A\x1A";
  }

  FileFormat::FileFormat()
  {
    memcpy(header.magic, magic, sizeof(header.magic));
    header.id666 = Ranty::SPC::FileFormat::Header::ID666Tag::Present;
    header.versionMinor = 30;
  }
}

std::ostream& operator << (std::ostream& stream, Ranty::SPC::FileFormat::Header::ID666Tag tag)
{
  switch (tag)
  {
  case Ranty::SPC::FileFormat::Header::ID666Tag::Present:
    stream << "Present";
    break;
  case Ranty::SPC::FileFormat::Header::ID666Tag::NotPresent:
    stream << "Not Present";
    break;
  default:
    stream << "Invalid Value";
    break;
  }
  return stream;
}
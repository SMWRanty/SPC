#include "FileFormat.hpp"

namespace Ranty::SPC
{
  namespace
  {
    constexpr const char* magic = "SNES-SPC700 Sound File Data v0.30";
  }

  FileFormat::FileFormat()
  {
    memcpy(header.magic, magic, sizeof(header.magic));
  }
}
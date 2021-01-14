#pragma once

#include "spcCore.hpp"

namespace Ranty::SPC
{
  class FileFormatHeader
  { 
  public: 
    enum class ID666Tag: uint8_t
    {
      Present = 0x1A,
      NotPresent = 0x1B
    };
    char magic[35];
    ID666Tag id666;
    uint8_t versionMinor;
  };

  class FileFormat
  {
  public:
    FileFormat();

    using Header = FileFormatHeader;
    
    FileFormatHeader header;
  };
}

std::ostream& operator << (std::ostream& stream, Ranty::SPC::FileFormat::Header::ID666Tag tag);
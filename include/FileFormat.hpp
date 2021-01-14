#pragma once

#include "spcCore.hpp"

namespace Ranty::SPC
{
  #pragma pack(push, 1)

  class FileFormatHeader{ 
  public: 
    enum class ID666Tag: uint8_t
    {
      Present = 0x1A,
      NotPresent = 0x1B
    };
    using Magic = char[35];
    using VersionMinor = uint8_t;

    Magic magic;
    ID666Tag id666;
    VersionMinor versionMinor;
  };

  class FileFormatRegisters
  { 
  public: 
   using PC = uint16_t;
   using A = uint8_t;
   using X = uint8_t;
   using Y = uint8_t;
   using PSW = uint8_t;
   using SP = uint8_t;
   using Reserved = uint16_t;

   PC pc;
   A a;
   X x;
   Y y;
   PSW psw;
   SP sp;
   Reserved reserved;
  };

  class FileFormat
  {
  public:
    FileFormat();

    using Header = FileFormatHeader;
    using Registers = FileFormatRegisters;
    
    Header header;
    Registers registers;
  };

  #pragma pack(pop)
}

std::ostream& operator << (std::ostream& stream, Ranty::SPC::FileFormat::Header::ID666Tag tag);
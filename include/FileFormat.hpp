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

  class FileFormatID666
  {
  public:
    enum class DefaultChannel: uint8_t
    {
      Enabled = 1,
      Disabled = 0
    };

    enum class Emulator: uint8_t
    {
      Unknown = '0',
      ZSNES = '1',
      Snes9x = '2'
    };
    using SongTitle = char[32];
    using GameTitle = char[32];
    using Author = char[16];
    using Comments = char[32];
    using Date = char[11];
    using SongLength = char[3];
    using FadeLength = char[5];
    using Artist = char[32];

    SongTitle songTitle;
    GameTitle gameTitle;
    Author author;
    Comments comments;
    Date date;
    SongLength songLength;
    FadeLength fadeLength;
    Artist artist;
    DefaultChannel defaultChannel;
    Emulator emulator;
  };

  class FileFormat
  {
  public:
    FileFormat();

    using Header = FileFormatHeader;
    using Registers = FileFormatRegisters;
    using ID666 = FileFormatID666;
    
    Header header;
    Registers registers;
    ID666 id666;
  };

  #pragma pack(pop)
}

std::ostream& operator << (std::ostream& stream, Ranty::SPC::FileFormat::Header::ID666Tag tag);
std::ostream& operator << (std::ostream& stream, Ranty::SPC::FileFormat::ID666::DefaultChannel defaultChannel);
std::ostream& operator << (std::ostream& stream, Ranty::SPC::FileFormat::ID666::Emulator emulator);
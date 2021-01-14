#include "FileFormat.hpp"

namespace Ranty::SPC
{
  namespace
  {
    constexpr const char* magic = "SNES-SPC700 Sound File Data v0.30\x1A\x1A";
    constexpr FileFormat::Header::ID666Tag id666Present = FileFormat::Header::ID666Tag::Present;
    constexpr FileFormat::Header::VersionMinor versionMinor = 30;
    constexpr FileFormat::Registers::PC defaultPC = 0x0000;
    constexpr FileFormat::Registers::A defaultA = 0x00;
    constexpr FileFormat::Registers::X defaultX = 0x00;
    constexpr FileFormat::Registers::Y defaultY = 0x00;
    constexpr FileFormat::Registers::PSW defaultPSW = 0x00;
    constexpr FileFormat::Registers::SP defaultSP = 0x00;
    constexpr FileFormat::Registers::Reserved defaultReserved = 0x00;
    constexpr FileFormat::ID666::Date defaultDate = "01/01/1970";
    constexpr FileFormat::ID666::SongLength defaultSongLength = {'0','0','0'};
    constexpr FileFormat::ID666::FadeLength defaultFadeLength = {'0','0','0','0','0'};

  } 

  FileFormat::FileFormat()
  {
    memcpy(header.magic, magic, sizeof(header.magic));
    header.id666 = id666Present;
    header.versionMinor = versionMinor;

    registers.pc = defaultPC;
    registers.a = defaultA;
    registers.x = defaultX;
    registers.y = defaultY;
    registers.psw = defaultPSW;
    registers.sp = defaultSP;
    registers.reserved = defaultReserved;

    memset(id666.songTitle, 0, sizeof(id666.songTitle));
    memset(id666.gameTitle, 0, sizeof(id666.gameTitle));
    memcpy(id666.date, defaultDate, sizeof(id666.date));
    memcpy(id666.songLength, defaultSongLength, sizeof(id666.songLength));
    memcpy(id666.fadeLength, defaultFadeLength, sizeof(id666.fadeLength));
    memset(id666.artist, 0, sizeof(id666.artist));
    id666.defaultChannel = ID666::DefaultChannel::Enabled;
    id666.emulator = ID666::Emulator::Unknown;
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

std::ostream& operator << (std::ostream& stream, Ranty::SPC::FileFormat::ID666::DefaultChannel defaultChannel)
{
  switch (defaultChannel)
  {
  case Ranty::SPC::FileFormat::ID666::DefaultChannel::Enabled:
    stream << "Enabled";
    break;
  case Ranty::SPC::FileFormat::ID666::DefaultChannel::Disabled:
    stream << "Disabled";
    break;
  default:
    stream << "Invalid Value";
    break;
  }
  return stream;
}

std::ostream& operator << (std::ostream& stream, Ranty::SPC::FileFormat::ID666::Emulator emulator)
{
  switch (emulator)
  {
  case Ranty::SPC::FileFormat::ID666::Emulator::Unknown:
    stream << "Unknown";
    break;
  case Ranty::SPC::FileFormat::ID666::Emulator::ZSNES:
    stream << "ZSNES";
    break;
  case Ranty::SPC::FileFormat::ID666::Emulator::Snes9x:
    stream << "Snes9x";
    break;
  default:
    stream << "Invalid Value";
    break;
  }
  return stream;
}
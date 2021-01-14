#include "FileFormat.hpp"

namespace Ranty::SPC
{
  namespace
  {
    constexpr const char* magic = "SNES-SPC700 Sound File Data v0.30\x1A\x1A";
    constexpr FileFormat::Header::ID666Tag id666 = FileFormat::Header::ID666Tag::Present;
    constexpr FileFormat::Header::VersionMinor versionMinor = 30;
    constexpr FileFormat::Registers::PC defaultPC = 0x0000;
    constexpr FileFormat::Registers::A defaultA = 0x00;
    constexpr FileFormat::Registers::X defaultX = 0x00;
    constexpr FileFormat::Registers::Y defaultY = 0x00;
    constexpr FileFormat::Registers::PSW defaultPSW = 0x00;
    constexpr FileFormat::Registers::SP defaultSP = 0x00;
    constexpr FileFormat::Registers::Reserved defaultReserved = 0x00;

  } 

  FileFormat::FileFormat()
  {
    memcpy(header.magic, magic, sizeof(header.magic));
    header.id666 = id666;
    header.versionMinor = versionMinor;
    registers.pc = defaultPC;
    registers.a = defaultA;
    registers.x = defaultX;
    registers.y = defaultY;
    registers.psw = defaultPSW;
    registers.sp = defaultSP;
    registers.reserved = defaultReserved;
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
#include "FileFormat.hpp"

#include "test/test.hpp"

namespace Ranty::SPC
{
  describe("SPC File Format", []() {
    it("has the correct file header \"magic\" string", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.header.magic)).to.equal(35);
      expect(offsetof(FileFormat, header.magic)).to.equal(0x00);
      expect(std::string(spcFileFormat.header.magic, 35)).to.equal("SNES-SPC700 Sound File Data v0.30\x1A\x1A");
    });

    it("has the correct file header id666 value", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.header.id666)).to.equal(1);
      expect(offsetof(FileFormat, header.id666)).to.equal(0x23);
      expect(spcFileFormat.header.id666).to.equal(FileFormat::Header::ID666Tag::Present);
    });

    it("has the correct file header id666 enum values", []() {
      FileFormat spcFileFormat;
      expect(static_cast<uint8_t>(FileFormat::Header::ID666Tag::Present)).to.equal(0x1A);
      expect(static_cast<uint8_t>(FileFormat::Header::ID666Tag::NotPresent)).to.equal(0x1B);
    });

    it("has the correct file header version ", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.header.versionMinor)).to.equal(1);
      expect(offsetof(FileFormat, header.versionMinor)).to.equal(0x24);
      expect(spcFileFormat.header.versionMinor).to.equal(30);
    });

    it("has the correct file PC register (default value 0)", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.registers.pc)).to.equal(2);
      expect(offsetof(FileFormat, registers.pc)).to.equal(0x25);
      expect(spcFileFormat.registers.pc).to.equal(0x0000);
    });

    it("has the correct file A register (default value 0)", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.registers.a)).to.equal(1);
      expect(offsetof(FileFormat, registers.a)).to.equal(0x27);
      expect(spcFileFormat.registers.a).to.equal(0x00);
    });

    it("has the correct file X register (default value 0)", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.registers.x)).to.equal(1);
      expect(offsetof(FileFormat, registers.x)).to.equal(0x28);
      expect(spcFileFormat.registers.x).to.equal(0x00);
    });

    it("has the correct file Y register (default value 0)", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.registers.y)).to.equal(1);
      expect(offsetof(FileFormat, registers.y)).to.equal(0x29);
      expect(spcFileFormat.registers.y).to.equal(0x00);
    });

    it("has the correct file PSW register (default value 0)", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.registers.psw)).to.equal(1);
      expect(offsetof(FileFormat, registers.psw)).to.equal(0x2A);
      expect(spcFileFormat.registers.psw).to.equal(0x00);
    });

    it("has the correct file SP register (default value 0)", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.registers.sp)).to.equal(1);
      expect(offsetof(FileFormat, registers.sp)).to.equal(0x2B);
      expect(spcFileFormat.registers.sp).to.equal(0x00);
    });

    it("has the correct file ID666 Default song title", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.id666.songTitle)).to.equal(32);
      expect(offsetof(FileFormat, id666.songTitle)).to.equal(0x2E);
      expect(spcFileFormat.id666.songTitle[0]).to.equal('\0');
    });

    it("has the correct file ID666 Default game title", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.id666.gameTitle)).to.equal(32);
      expect(offsetof(FileFormat, id666.gameTitle)).to.equal(0x4E);
      expect(spcFileFormat.id666.gameTitle[0]).to.equal('\0');
    });

    it("has the correct file ID666 Default author", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.id666.author)).to.equal(16);
      expect(offsetof(FileFormat, id666.author)).to.equal(0x6E);
      expect(spcFileFormat.id666.author[0]).to.equal('\0');
    });

    it("has the correct file ID666 Default comments", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.id666.comments)).to.equal(32);
      expect(offsetof(FileFormat, id666.comments)).to.equal(0x7E);
      expect(spcFileFormat.id666.comments[0]).to.equal('\0');
    });

    it("has the correct file ID666 Default date as epoch", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.id666.date)).to.equal(11);
      expect(offsetof(FileFormat, id666.date)).to.equal(0x9E);
      expect(std::string(spcFileFormat.id666.date)).to.equal("01/01/1970");
    });

    it("has the correct file ID666 Default song length (0 seconds)", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.id666.songLength)).to.equal(3);
      expect(offsetof(FileFormat, id666.songLength)).to.equal(0xA9);
      expect(std::string(spcFileFormat.id666.songLength, sizeof(spcFileFormat.id666.songLength))).to.equal("000");
    });

    it("has the correct file ID666 Default fade length (0 milliseconds)", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.id666.fadeLength)).to.equal(5);
      expect(offsetof(FileFormat, id666.fadeLength)).to.equal(0xAC);
      expect(std::string(spcFileFormat.id666.fadeLength, sizeof(spcFileFormat.id666.fadeLength))).to.equal("00000");
    });

    it("has the correct file ID666 Default artist", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.id666.artist)).to.equal(32);
      expect(offsetof(FileFormat, id666.artist)).to.equal(0xB1);
      expect(spcFileFormat.id666.artist[0]).to.equal('\0');
    });

    it("has the correct file ID666 default channel enabled", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.id666.defaultChannel)).to.equal(1);
      expect(offsetof(FileFormat, id666.defaultChannel)).to.equal(0xD1);
      expect(spcFileFormat.id666.defaultChannel).to.equal(FileFormat::ID666::DefaultChannel::Enabled);
    });


    it("has the correct file default channel enum values", []() {
      FileFormat spcFileFormat;
      expect(static_cast<uint8_t>(FileFormat::ID666::DefaultChannel::Enabled)).to.equal(0x01);
      expect(static_cast<uint8_t>(FileFormat::ID666::DefaultChannel::Disabled)).to.equal(0x00);
    });

    it("has the correct file ID666 emulator", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.id666.emulator)).to.equal(1);
      expect(offsetof(FileFormat, id666.emulator)).to.equal(0xD2);
      expect(spcFileFormat.id666.emulator).to.equal(FileFormat::ID666::Emulator::Unknown);
    });


    it("has the correct file emulator enum values", []() {
      FileFormat spcFileFormat;
      expect(static_cast<uint8_t>(FileFormat::ID666::Emulator::Unknown)).to.equal('0');
      expect(static_cast<uint8_t>(FileFormat::ID666::Emulator::ZSNES)).to.equal('1');
      expect(static_cast<uint8_t>(FileFormat::ID666::Emulator::Snes9x)).to.equal('2');
    });
  });
}
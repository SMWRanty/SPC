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

    it("has the correct file PC register (default value 0) ", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.registers.pc)).to.equal(2);
      expect(offsetof(FileFormat, registers.pc)).to.equal(0x25);
      expect(spcFileFormat.registers.pc).to.equal(0x0000);
    });

    it("has the correct file A register (default value 0) ", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.registers.a)).to.equal(1);
      expect(offsetof(FileFormat, registers.a)).to.equal(0x27);
      expect(spcFileFormat.registers.a).to.equal(0x00);
    });

    it("has the correct file X register (default value 0) ", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.registers.x)).to.equal(1);
      expect(offsetof(FileFormat, registers.x)).to.equal(0x28);
      expect(spcFileFormat.registers.x).to.equal(0x00);
    });

    it("has the correct file Y register (default value 0) ", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.registers.y)).to.equal(1);
      expect(offsetof(FileFormat, registers.y)).to.equal(0x29);
      expect(spcFileFormat.registers.y).to.equal(0x00);
    });

    it("has the correct file PSW register (default value 0) ", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.registers.psw)).to.equal(1);
      expect(offsetof(FileFormat, registers.psw)).to.equal(0x2A);
      expect(spcFileFormat.registers.psw).to.equal(0x00);
    });

    it("has the correct file SP register (default value 0) ", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.registers.sp)).to.equal(1);
      expect(offsetof(FileFormat, registers.sp)).to.equal(0x2B);
      expect(spcFileFormat.registers.sp).to.equal(0x00);
    });
  });
}
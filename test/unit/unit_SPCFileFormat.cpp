#include "FileFormat.hpp"

#include "test/test.hpp"

namespace Ranty::SPC
{
  describe("SPC File Format", []() {
    it("has the correct file header \"magic\" string", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.header.magic)).to.equal(35);
      expect(offsetof(FileFormat, header.magic)).to.equal(0);
      expect(std::string(spcFileFormat.header.magic, 35)).to.equal("SNES-SPC700 Sound File Data v0.30\x1A\x1A");
    });

    it("has the correct file header id666 value", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.header.id666)).to.equal(1);
      expect(offsetof(FileFormat, header.id666)).to.equal(35);
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
      expect(offsetof(FileFormat, header.versionMinor)).to.equal(36);
      expect(spcFileFormat.header.versionMinor).to.equal(30);
    });
  });
}
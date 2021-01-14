#include "test/test.hpp"

#include "FileFormat.hpp"

namespace Ranty::SPC
{
  describe("SPC File Format", []() {
    it("has the correct file header \"magic\" string", []() {
      FileFormat spcFileFormat;
      expect(sizeof(spcFileFormat.header.magic)).to.equal(33);
      expect(std::string(spcFileFormat.header.magic, 33)).to.equal("SNES-SPC700 Sound File Data v0.30");
    });
  });
}
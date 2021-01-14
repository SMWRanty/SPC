#pragma once

#include "spcCore.hpp"

namespace Ranty::SPC
{
  class FileFormatHeader
  { 
  public: 
    char magic[33];
  };

  class FileFormat
  {
  public:
    FileFormat();
    
    using Header = FileFormatHeader;
    
    FileFormatHeader header;
  };
}
// This file is distributed under a BSD license. See LICENSE.txt for details.

#ifndef __PDBFILE_HPP_
#define __PDBFILE_HPP_

#include "debuginfo.hpp"

/****************************************************************************/

class IDiaSession;

class PDBFileReader : public DebugInfoReader
{
  struct SectionContrib;

  SectionContrib *Contribs;
  sInt nContribs;

  IDiaSession *Session;
  sU32 DanglingLengthStart;

  sU32 CompilandFromSectionOffset(sU32 section,sU32 offset,sBool &codeFlag);
  void ProcessSymbol(class IDiaSymbol *symbol,DebugInfo &to);
  void ReadEverything(DebugInfo &to);

public:
  sBool ReadDebugInfo(sChar *fileName,DebugInfo &to);
};

/****************************************************************************/

#endif

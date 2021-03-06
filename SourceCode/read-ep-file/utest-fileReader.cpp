//--- Unit test for fileReader.cpp.
//
/// \author David Lorenzetti,
///         Lawrence Berkeley National Laboratory,
///         dmlorenzetti@lbl.gov
/// \brief  Unit test for fileReader.cpp.


//--- Includes.
#include <assert.h>

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "fileReader.h"


//--- Main driver.
//
//   Read a file and echo it back out.
//
int main(int argc, const char* argv[]) {
  //
  int lineNo;
  string s;
  const string delimiters = ",;";
  const string commentChars = "!";
  const string illegalChars = "!";  // Note could treat comment char as legal delimiter, if willing to check on return from fr.getToken().
  //
  // Get input file.
  if( 2 != argc ){
    cout << "Error: missing filename\nUsage: " << argv[0] << "  <name of input file to parse>\n";
    return(1);
  }
  fileReader fr(argv[1]);
  //
  // Attach an external reporting function.
  //   Not done for this unit test.
  // fr.attachErrorFcn(reportInputError);
  //
  fr.open();
  //
  cout << "lineNo:token pairs in file " << argv[1] << ":" << endl;
  //
  while( 1 ){
    lineNo = 0;  // Demonstrate that {lineNo} is set by the \c fileReader.
    fr.skipComment(commentChars, lineNo);
    // Get a token-- defined as a string that ends with a delimiter, or with EOF.
    fr.getToken(delimiters, illegalChars, s);
    // Consume the delimiter that caused getToken() to return above.
    if( ! fr.moveForward(1) ){
      // Here, hit EOF.
      break;
    }
    assert( ! fr.isEOF() );
    cout << lineNo << ":" << s << endl;
  }
  //
  // Here, hit EOF.
  assert( fr.isEOF() );
  if( s.length() > 0 ){
    cout << lineNo << ":" << s << " (non-delimited string) ";
  }
  cout << "EOF" << endl;
  fr.close();
  //
  return(0);
}  // End fcn main().


/*
***********************************************************************************
Copyright Notice
----------------

Functional Mock-up Unit Export of EnergyPlus (C)2013, The Regents of
the University of California, through Lawrence Berkeley National
Laboratory (subject to receipt of any required approvals from
the U.S. Department of Energy). All rights reserved.

If you have questions about your rights to use or distribute this software,
please contact Berkeley Lab's Technology Transfer Department at
TTD@lbl.gov.referring to "Functional Mock-up Unit Export
of EnergyPlus (LBNL Ref 2013-088)".

NOTICE: This software was produced by The Regents of the
University of California under Contract No. DE-AC02-05CH11231
with the Department of Energy.
For 5 years from November 1, 2012, the Government is granted for itself
and others acting on its behalf a nonexclusive, paid-up, irrevocable
worldwide license in this data to reproduce, prepare derivative works,
and perform publicly and display publicly, by or on behalf of the Government.
There is provision for the possible extension of the term of this license.
Subsequent to that period or any extension granted, the Government is granted
for itself and others acting on its behalf a nonexclusive, paid-up, irrevocable
worldwide license in this data to reproduce, prepare derivative works,
distribute copies to the public, perform publicly and display publicly,
and to permit others to do so. The specific term of the license can be identified
by inquiry made to Lawrence Berkeley National Laboratory or DOE. Neither
the United States nor the United States Department of Energy, nor any of their employees,
makes any warranty, express or implied, or assumes any legal liability or responsibility
for the accuracy, completeness, or usefulness of any data, apparatus, product,
or process disclosed, or represents that its use would not infringe privately owned rights.


Copyright (c) 2013, The Regents of the University of California, Department
of Energy contract-operators of the Lawrence Berkeley National Laboratory.
All rights reserved.

1. Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

(1) Redistributions of source code must retain the copyright notice, this list
of conditions and the following disclaimer.

(2) Redistributions in binary form must reproduce the copyright notice, this list
of conditions and the following disclaimer in the documentation and/or other
materials provided with the distribution.

(3) Neither the name of the University of California, Lawrence Berkeley
National Laboratory, U.S. Dept. of Energy nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

2. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

3. You are under no obligation whatsoever to provide any bug fixes, patches,
or upgrades to the features, functionality or performance of the source code
("Enhancements") to anyone; however, if you choose to make your Enhancements
available either publicly, or directly to Lawrence Berkeley National Laboratory,
without imposing a separate written license agreement for such Enhancements,
then you hereby grant the following license: a non-exclusive, royalty-free
perpetual license to install, use, modify, prepare derivative works, incorporate
into other computer software, distribute, and sublicense such enhancements or
derivative works thereof, in binary and source code form.

NOTE: This license corresponds to the "revised BSD" or "3-clause BSD"
License and includes the following modification: Paragraph 3. has been added.


***********************************************************************************
*/

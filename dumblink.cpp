// Copyright (c) 2011 Johannes Huning
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

//#LFLAGS << -lboost_filesystem-gcc45-mt-1_47
//#LFLAGS << -lboost_system-gcc45-mt-1_47

#include <sstream>

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

using namespace boost::filesystem; // Sue me.

int main(int argc, char const *argv[])
{
  if (argc < 4) {
    std::cout << "Usage: " << argv[0] << " <source> " <<
      "<target_dir> <amount>" << std::endl;
    return 1;
  }

  path source = absolute(argv[1]);
  path target_dir = absolute(argv[2]);
  int amount = boost::lexical_cast<int>(argv[3]);

  std::cout << "Hardlinking " << amount << " times to '" <<
    source << "' in '" << target_dir << "'..." << std::endl;

  for (int i = 0; i < amount; ++i) {
    path target(target_dir /
      (std::string("link") + boost::lexical_cast<std::string>(i)));
    create_hard_link(source, target);
  }

  return 0;
}

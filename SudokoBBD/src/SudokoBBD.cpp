//============================================================================
// Name        : SudokoBBD.cpp
// Author      : Stefan Ekman
// Version     :
// Copyright   : Free to use, copy and abuse in any way you like
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <igloo/igloo_alt.h>

using namespace igloo;

int main() 
{
#ifdef WIN32
    VisualStudioResultsOutput VSOutput;
    TestRunner runner(VSOutput);
    return runner.Run();
#else
    return TestRunner::RunAllTests();
#endif
}

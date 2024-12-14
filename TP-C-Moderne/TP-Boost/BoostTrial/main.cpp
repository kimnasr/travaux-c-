//
//  main.cpp
//  BoostTrial
//
//  Created by nasr on 07/12/2024.
//

//to find issue with PATH:
// https://topic.alibabacloud.com/a/relative-path-and-absolute-path-settings-in-xcode-xcode-absolute-path_1_19_32517324.html
//http://thegreyblog.blogspot.com/2014/02/how-to-include-apple-frameworks-headers.html
//https://www.geeksforgeeks.org/how-to-fix-bits-std-cpp-h-file-not-found-in-macos/
/*
#include <iostream>
#include <algorithm>
#include <chrono>
#include <format>
#include <tuple>
#include "boost/convert.hpp"


int main(int argc, const char * argv[]) {
    // insert code here...Ò
    std::cout << "Hello, World!\n";
    return 0;
}
*/
// Projet BoostTrial
// se mettre dans repertoire BoostTrial et passer par terminal et ligne de commande compilateur clang++
// faut tout mettre dans meme repertoire, marche pas pour le moment sous xcode car mauvaise configuration du path
// clang++ -std=c++17 -I boost -L timer  main.cpp -o test -lboost_system -lboost_filesystem -lboost_timer

/*
#include "boost/timer/timer.hpp"
#include <iostream>
#include <cmath>
*/
 
#include "timer/progress.hpp"
#include <iostream>
#include <climits>




/*
int main() {
    boost::timer::auto_cpu_timer t;

      for (long i = 0; i < 100000000; ++i)
        std::sqrt(123.456L); // burn some time

      return 0;
    
}
*/

/*
int main()
{
  cpu_timer timer;

  for (int i = 0; i < 1000000; ++i)
    std::pow(1.234, i);
  std::cout << timer.format() << '\n';

  timer.stop();

  for (int i = 0; i < 1000000; ++i)
    std::pow(1.234, i);
  std::cout << timer.format() << '\n';

  timer.resume();

  for (int i = 0; i < 1000000; ++i)
    std::pow(1.234, i);
  std::cout << timer.format() << '\n';
}
*/

/*
int main( int argc, char * argv[] )
{
  if ( argc == 1 )
  {
    std::cout << "invoke: timex [-v] command [args...]\n"
      "  command will be executed and timings displayed\n"
      "  -v option causes command and args to be displayed\n";
    return 1;
  }

  std::string s;

  bool verbose = false;
  if ( argc > 1 && *argv[1] == '-' && *(argv[1]+1) == 'v' )
  {
    verbose = true;
    ++argv;
    --argc;
  }

  for ( int i = 1; i < argc; ++i )
  {
    if ( i > 1 ) s += ' ';
    s += argv[i];
  }

  if ( verbose )
    { std::cout << "command: \"" << s.c_str() << "\"\n"; }

  boost::timer::auto_cpu_timer t(" %ws elapsed wall-clock time\n");

  return std::system( s.c_str() );
}
*/


using boost::timer;
using boost::progress_timer;
using boost::progress_display;
using std::cout;
using std::endl;

int main() {

  timer t0;  // used only for elapsed_max() and elapsed_min()

  cout << "timer::elapased_min() reports " << t0.elapsed_min() << " seconds\n";
  cout << "timer::elapased_max() reports " << t0.elapsed_max()
       << " seconds, which is " << t0.elapsed_max()/3600.0 << " hours\n";

  cout << "\nverify progress_display(0) doesn't divide by zero" << endl;
  progress_display zero( 0 );  // verify 0 doesn't divide by zero
  ++zero;

    
  // pour faire une temporisation de 60sec fixée par time
    
  long loops;
  timer loop_timer;
  const double time = 60.0;

  cout << "\ndetermine " << time << " second iteration count" << endl;
  for ( loops = 0; loops < LONG_MAX
     && loop_timer.elapsed() < time; ++loops ) {}
  cout << loops << " iterations"<< endl;
    
  long i;
  bool time_waster; // defeat [some] optimizers by storing result here

  progress_timer pt;
  timer t1;
  timer t4;
  timer t5;

  cout << "\nburn about " << time << " seconds" << endl;
  
  // pour faire affichage de la même temporisation avec bargraph equivalent a time
  /*
    burn about 1 seconds

    0%   10   20   30   40   50   60   70   80   90   100%
    |----|----|----|----|----|----|----|----|----|----|
    ***************************************************
  */
    
  progress_display pd( loops );
  for ( i = loops; i--; )
    { time_waster = loop_timer.elapsed() < time; ++pd; }

  timer t2( t1 );
  timer t3;
  t4 = t3;
  t5.restart();

  cout << "\nburn about " << time << " seconds again" << endl;
  pd.restart( loops );
  for ( i = loops; i--; )
    { time_waster = loop_timer.elapsed() < time; ++pd; }

  if ( time_waster ) cout << ' ';  // using time_waster quiets compiler warnings
  progress_display pd2( 50, cout, "\nLead string 1 ", "Lead string 2 ", "Lead string 3 " );
  for ( ; pd2.count() < 50; ++pd2 ) {}

  cout << "\nt1 elapsed: " << t1.elapsed() << '\n';
  cout << "t2 elapsed: " << t2.elapsed() << '\n';
  cout << "t3 elapsed: " << t3.elapsed() << '\n';
  cout << "t4 elapsed: " << t4.elapsed() << '\n';
  cout << "t5 elapsed: " << t5.elapsed() << '\n';
  cout << "t1 and t2 should report the same times (very approximately "
       << 2*time << " seconds).\n";
  cout << "t3, t4 and t5 should report about the same times,\n";
  cout << "and these should be about half the t1 and t2 times.\n";
  cout << "The following elapsed time should be slightly greater than t1."
       << endl;
  return 0;
  } // main


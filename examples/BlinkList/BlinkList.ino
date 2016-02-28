//***********************************************************************************
// A version of the Blink demo, but with delays stored in two instances of etl::list
//***********************************************************************************

#undef min
#undef max

#include <etl_arduino.h> // Contains platform macros for Arduino.
#include <list.h>

void setup()
{
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

void loop()
{
  int delay_times1[] = { 900, 800, 700, 600, 500, 400, 300, 200, 100 };
  int delay_times2[] = { 400, 300, 200, 100 };

  // Fill the first delay list, then reverse it.
  etl::list<int, 10> delays1(etl::begin(delay_times1), etl::end(delay_times1));
  delays1.reverse();

  // Fill the second delay list,
  etl::list<int, 4> delays2(etl::begin(delay_times2), etl::end(delay_times2));

  while (true)
  {
    // Common iterator for both lists;
    etl::ilist<int>::const_iterator itr;

    // Iterate through the first list.
    itr = delays1.begin();

    while (itr != delays1.end())
    {
      digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);               // wait
      digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
      delay(*itr++);            // wait
    }

    // Iterate through the second list.
    itr = delays2.begin();

    while (itr != delays2.end())
    {
      digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);               // wait
      digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
      delay(*itr++);            // wait
    }
  }
}
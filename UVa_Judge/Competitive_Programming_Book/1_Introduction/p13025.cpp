#include <bits/stdc++.h>

using namespace std;

string getFormatedDate(int dd, int mm, int yyyy) {
  /* get current timeinfo and modify it to the entry day, month, year */
  time_t rawtime;
  struct tm * timeinfo;
  const char * weekday [] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
  };
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  timeinfo->tm_year = yyyy - 1900;
  timeinfo->tm_mon = mm - 1;
  timeinfo->tm_mday = dd;

  /* call mktime: timeinfo->tm_wday will be set */
  mktime(timeinfo);

  return weekday[timeinfo->tm_wday];
}

int main() {
  // 29/05/2013
  // October 30, 2015 Friday
  cout<<"May 29, 2013 "<<getFormatedDate(29, 5, 2013)<<"\n";
  return 0;
}
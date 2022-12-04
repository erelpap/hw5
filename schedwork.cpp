#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please
#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here
bool isValid(const AvailabilityMatrix& avail,
    const size_t maxShifts,
    const DailySchedule sched,
    unsigned int curr_shift,
    unsigned int curr_day);

bool schedHelper(const AvailabilityMatrix& avail,
    const size_t maxShifts,
    DailySchedule& sched,
    unsigned int curr_shift,
    unsigned int curr_day);




// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
  if(avail.size() == 0U){
      return false;
  }
  sched.clear();

  // Add your code below
  
  // calculating noOfDays
  unsigned int numberOfDays = 0;
  for(unsigned int i = 0; i < avail.size(); i++){
    numberOfDays = numberOfDays + 1;
  }

  // creating a sched with a right size with dummy no's in it
  Worker_T a = -1;
  for(unsigned int i = 0; i < numberOfDays; i++){
    vector<Worker_T> temp;
    for(unsigned int j = 0; j < dailyNeed; j++){
      temp.push_back(a);
    }
    sched.push_back(temp);
  }

  unsigned int curr_shift = 0;
  unsigned int curr_day = 0;

  return schedHelper(avail, maxShifts, sched, curr_shift, curr_day);
  
}

bool schedHelper(const AvailabilityMatrix& avail,
    const size_t maxShifts,
    DailySchedule& sched, 
    unsigned int curr_shift,
    unsigned int curr_day){

  if(curr_shift == sched[0].size()){
    curr_shift = 0;
    curr_day = curr_day + 1;
  }

  if(curr_day == sched.size()){
    return true;
  }
	
  for(Worker_T id = 0; id < avail[0].size(); id++){
    sched[curr_day][curr_shift] = id;
    if(isValid(avail, maxShifts, sched, curr_shift, curr_day)){
       return schedHelper(avail, maxShifts, sched, curr_shift + 1, curr_day);
    }
  }

  return false;
}

bool isValid(const AvailabilityMatrix& avail,
    const size_t maxShifts,
    const DailySchedule sched,
    unsigned int curr_shift,
    unsigned int curr_day){

  // Findig the current ID
  Worker_T id = sched[curr_day][curr_shift];
  bool doesNotExceedMaxShifts = true;
  bool availableOnThatDay = false;

  // check avail to see if that person is available on that day
  if(avail[curr_day][id] == 1){
    availableOnThatDay = true;
  }

  // iterate through sched count the number of shifts for an ID
  unsigned int noOfShifts = 0;

  for(unsigned int i = 0; i < sched.size(); i++){
    for(unsigned int j = 0; j < sched[0].size(); j++){
      if(sched[i][j] == id){
        noOfShifts = noOfShifts + 1;
      }
    }
  }

  if(noOfShifts > maxShifts){
    doesNotExceedMaxShifts = false;
  }

  // if both of these conditions are met, return true
  return availableOnThatDay && doesNotExceedMaxShifts;

}




/*
3 1000 2 3
200
0 2 2
300
27 3 0
5 2000 2 4
300
4 3 0 4
450
7 8 0 13

3 1000 2 3
200
0 2 2
300
27 3 20
5 2000 2 4
300
4 3 0 4
450
7 8 0 13
-1 -1 -1 -1
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int persons, budget, hotels, weeks,
    hotel_price_week_per_person,
    beds,
    hotel_cost,
    minimum_cost,

    idx;

  bool free_for_weeks;

  vector<int> beds_for_weeks;

  while (cin >> persons >> budget >> hotels >> weeks) {

    // if (persons == -1 && budget == -1 && hotels == -1 && weeks == -1) {
    //   break;
    // }

    minimum_cost = budget + 1; // The minimum cost is equals to the budget plus 1

    while (hotels--) {
      beds_for_weeks.clear();
      cin >> hotel_price_week_per_person;
      idx = 0;
      while (idx < weeks) {
        cin >> beds;
        beds_for_weeks.push_back(beds);
        idx++;
      }

      // free_for_weeks = true;
      for (auto week_beds: beds_for_weeks) {
        if (week_beds >= persons) {
          hotel_cost = persons*hotel_price_week_per_person;
          if ( hotel_cost <= budget && hotel_cost <= minimum_cost) {
            minimum_cost = hotel_cost;
          }
        }
        // else {
        //   free_for_weeks = false;
        //   break;
        // }
      }
    }

    if (minimum_cost == budget + 1) {
      cout<<"stay home\n";
    } else {
      cout<<minimum_cost<<"\n";
    }

    // break;
  }

  return 0;
}
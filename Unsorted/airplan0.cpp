#include <iostream>
using namespace std;
#include <deque>
#include <time.h>
#include <algorithm>
int chose_id[4];
pair<int, int> landing_num[6] = { {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
pair<int, int> takeoff_num[4] = { {0, 0}, {0, 1}, {0, 2}, {0, 3}};
void fly();
struct landing_plane {
    landing_plane(int a, int b) {
        id = a;
        fuel = b;
    }
  int id;
  int fuel;
  int waiting_time = 0;
};

struct takeoff_plane {
    takeoff_plane(int a) {
        id = a;
    }
  int id;
  int waiting_time = 0;
};

deque <landing_plane> LN[6]; //0 => runway2 first landing queue
deque <takeoff_plane> TA[4];

void print_info() {
  
  printf("Runway%d(%d)\n", 1, chose_id[0]);
  printf("L1:\n");
  printf("L2:\n");
  printf("T:");
  for (auto p : TA[0]) {
    printf("(%d), ", p.id);
  }
  printf("\n");
  for (int i = 1; i < 4; i++) {
    printf("Runway%d(%d)\n", i+1, chose_id[i]);
    printf("L1:");
    for (auto p : LN[i*2-2]) {
      printf("(%d, %d), ", p.id, p.fuel);
    }
    cout << endl;
    printf("L2:");
    for (auto p : LN[i*2-1]) {
      printf("(%d, %d), ", p.id, p.fuel);
    }

    // cout<<LN[i*2-1].size()<<'\n';
    // for (int j=0 ;j<LN[i*2-1].size() ; j++) {
    //   printf("(%d, %d), ", LN[i*2-1][j].id, LN[i*2-1][j].fuel);
    // }
    cout << endl;
    printf("T:");
    for (auto p : TA[i]) {
      printf("(%d), ", p.id);
    }
    printf("\n\n");
  }
}


int main() {
  int sim_time = 3;
  printf("How Many Time Unit You want to Simulate: ");
  // cin >> sim_time;
  srand( time(NULL) );
  int landing_no = 1;
  int takeoff_no = 2;
  float sum_landing_time = 0;
  float sum_takeoff_time = 0;
  int sum_landing_num = 1;
  int sum_takeoff_num = 1;
  int sum_fuel_save = 0;
  int total_plane_crash = 0;
  for (int i = 1; i <= sim_time; i++) {
    for (int j = 0; j < 4; j++) chose_id[j] = -1;
    printf("Simulation Time: %d\n\n", i);
    print_info();
    /**Step 1 new landing plane**/
    cout << "Step1:\n";
    cout << "landing plane:";    
    int landing_plane_num = rand()%5;
    for (int i = 0; i < landing_plane_num; i++) {
      landing_plane p(landing_no, rand()%10+1);
      printf("(%d, %d), ", p.id, p.fuel);
      landing_no += 2;
      sort(landing_num, landing_num+6);
      int mn_idx = landing_num[0].second;
      landing_num[0].first++;
      LN[mn_idx].push_back(p);
    }
    cout << endl;
    print_info();
    /**Step 2 new takof plane**/
    printf("Step 2:\n");
    cout << "takeof plane:";   
    int takeoff_plane_num = rand()%4;
    for (int i = 0; i < takeoff_plane_num; i++) {
      takeoff_plane p(takeoff_no);
      printf("(%d), ", p.id);
      takeoff_no += 2;
      sort(takeoff_num, takeoff_num+4);
      int mn_idx = takeoff_num[0].second;
      takeoff_num[0].first++;
      TA[mn_idx].push_back(p);
    }
    cout << endl;
    print_info();
    printf("Step 3\n");
    printf("emergency plane:\n");
    for (int i = 0; i < 6; i++) {
      for (auto p : LN[i]) {
        if (p.fuel == 0) {
          printf("id -- %d\n", p.id);
          for (int i = 0; i <4; i++) {
            if (chose_id[i] == -1) {
              chose_id[i] = p.id;
              sum_landing_time += p.waiting_time;
              sum_landing_num++;
              LN[i].pop_front();
              break;
            }
            if (i == 3) {
              cout << "Crash!! no runway" << endl;
              total_plane_crash++;
            }
          }
        }
      }
    }
    print_info();
    printf("Step 4\n");
    for (int i = 0; i < 4; i++) {
      if (chose_id[i] == -1) {
        if (TA[i].size() || LN[i].size()) continue;
        if (TA[i].size() > 2 || LN[i].size() == 0) {
          chose_id[i] = TA[i].front().id;
          sum_takeoff_time += TA[i].front().waiting_time;
          sum_takeoff_num++;
          TA[i].pop_front();
          continue;
        }
        chose_id[i] = LN[i].front().id;
        sum_landing_time += LN[i].front().waiting_time;
        sum_landing_num++;
        sum_fuel_save += LN[i].front().fuel;
        LN[i].pop_front();
      }
    }
    print_info();
    fly();
  }
  printf("land time %.1f takeoff time %.1f, fuel_save %d, crash %d\n",
    sum_landing_time/ sum_landing_num, sum_takeoff_time/ sum_takeoff_num,
    sum_fuel_save, total_plane_crash);
}


void fly() {
  for (int i = 0; i < 6; i++) {
    for (auto p : LN[i]) {
      p.fuel--;
      p.waiting_time++;
    }
  }
  for (int i = 0; i < 4; i++) {
    for (auto p : TA[i]) {
      p.waiting_time++;
    }
  }
    
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    bool boosted = false; 
    double last_dist = 0;
    double dist = 0;

    // game loop
    while (1) {
        int x;
        int y;
        int next_checkpoint_x; // x position of the next check point
        int next_checkpoint_y; // y position of the next check point
        int next_checkpoint_dist; // distance to the next checkpoint
        int next_checkpoint_angle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> next_checkpoint_x >> next_checkpoint_y >> next_checkpoint_dist >> next_checkpoint_angle; cin.ignore();
        int opponent_x;
        int opponent_y;
        int thrust;
        int x_distance = abs(next_checkpoint_x - x);
        cin >> opponent_x >> opponent_y; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // You have to output the target position
        // followed by the power (0 <= thrust <= 100) or "BOOST"
        // i.e.: "x y thrust"

        
        
        // boost
        if (next_checkpoint_dist > 6000 && !boosted && next_checkpoint_angle == 0) {
            boosted = true;
            cout << next_checkpoint_x << " " << next_checkpoint_y << " " << "BOOST" << endl;
        }

        
        
        cout << next_checkpoint_x << " " << next_checkpoint_y << " " << thrust << endl;
        cerr << "this is angle: " << next_checkpoint_angle << endl; // own interest to gather ideas


        
        if (next_checkpoint_dist > last_dist) {
            dist = next_checkpoint_dist;
            cerr << "this is distance: " << dist << endl;

        }
        last_dist = next_checkpoint_dist;

        double dist_traveled = 1 - (next_checkpoint_dist / dist);

        
        cerr << "new thrust: " << thrust << endl;
// when will pod decrease thrust and when not
        if (-20 < next_checkpoint_angle < 20) {
            if (next_checkpoint_dist < 5500) {
                thrust = ((pow(dist_traveled, 6) * -1) +1) *100;
        }
            else {
                thrust = 100;
        }

            if (thrust > 80) {
                thrust = 100;
        }

        }
        else {
            thrust = 5;
        }
// when checkpoints are extra close then thrust is 10
        if (next_checkpoint_dist < 500) {
            thrust = 10;
        }
// if next_checkpoint_dist is small then thrust is lower ---> change 1.5 try?!
        if (next_checkpoint_dist < 1500) {
            thrust = ((pow(dist_traveled, 1.5) * -1) +1) *100;
        }
        else {
            thrust = 100;

            }
        



// printed out to get ideas and to check
// can also be commented out
        cerr << "distance traveled:  " << dist_traveled << endl;
        cerr << "distance:   " << dist << endl;
        cerr << "next distance:   " << next_checkpoint_dist << endl;
   



        
    }
}

/* 853. Car Fleet
 * Link: https://leetcode.com/problems/car-fleet/description/
 */

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // we need to find the distances of cars by the time they reach the finish line
        // however, it might be easier to calculate the times it will take for each car to finish
        // a car at position i will finish at the same time as car at position in front (like i + 1), or will finish on its own

        // i feel like this might be cheating it

        vector<pair<int, int>> position_speed (position.size(), make_pair(0, 0));
        vector<float> time (position.size(), 0);
        int fleets = 1;

        for (int i = 0; i < position.size(); ++i)
        {
            position_speed[i] = make_pair(position[i], speed[i]);
        }

        // sort the position_speed vector
        sort(position_speed.begin(), position_speed.end());

        // make the time vector
        for (int i = position.size() -1; i >= 0; --i)
        {
            time[i] = ( (float)target - (float)position_speed[i].first ) / (float)position_speed[i].second;
        }

        // if a car has a greater time expected to get to the target, then they will be in a separate fleet
        float max_time = time[time.size() - 1];
        for (int i = time.size() - 1; i >= 0; --i)
        {
            if (time[i] > max_time)
            {
                ++fleets; max_time = time[i];
            }
        }

        return fleets;
    }
};

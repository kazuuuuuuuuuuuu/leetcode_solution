// custom comparison function
bool compare(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        // sort the meeting vector using the custom comparison function
        sort(meetings.begin(), meetings.end(), compare);

        // min_heap for engaged room
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> engaged_room;

        // min_heap for spare room
        priority_queue<int, vector<int>, greater<int>> unengaged_room;

        // count the number of meetings held in each room
        vector<int> freq(n, 0);

        // initialize the spare room set
        for(int i=0;i<n;i++)
            unengaged_room.push(i);

        // iterate each meeting
        for(auto x : meetings)
        {
            int s = x[0];
            int e = x[1];

            // handle engaged room
            while(engaged_room.size()>0&&engaged_room.top().first<=s)
            {
                int room = engaged_room.top().second;
                engaged_room.pop();
                unengaged_room.push(room);
            }

            // handle the case where there are rooms available
            if(unengaged_room.size()>0)
            {
                int room = unengaged_room.top();
                unengaged_room.pop();
                engaged_room.push(pair(e, room));
                freq[room] ++;
            }
            // handle the case where there are not rooms available
            else
            {
                pair<long long, int> topmost = engaged_room.top();
                engaged_room.pop();
                long long newEnd = topmost.first + e - s;
                engaged_room.push(pair(newEnd, topmost.second));
                freq[topmost.second] ++;

            }
        }

        int ans = 0;
        for(int i=1;i<n;i++)
        {
            if(freq[i]>freq[ans])
                ans = i;
        }

        return ans;
    }
};
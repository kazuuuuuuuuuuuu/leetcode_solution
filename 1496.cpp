class Solution {
public:
    bool isPathCrossing(string path) 
    {
        et<tuple<int, int> > position;
        tuple<int, int> point = make_tuple(0, 0);
        position.insert(point);
        //'N', 'S', 'E' or 'W'

        for(char a : path)
        {
            switch(a)
            {
            case 'N':
                {
                auto [x, y] = point;
                point = make_tuple(x, y+1);
                if(position.find(point)!=position.end())
                    return true;
                else
                    position.insert(point);
                break;                    
                }

            case 'S':
                {                
                auto [x, y] = point;
                point = make_tuple(x, y-1);
                if(position.find(point)!=position.end())
                    return true;
                else
                    position.insert(point);
                break;
                }
            case 'E':
{                auto [x, y] = point;
                point = make_tuple(x+1, y);
                if(position.find(point)!=position.end())
                    return true;
                else
                    position.insert(point);
                break;}
            case 'W':
{                auto [x, y] = point;
                point = make_tuple(x-1, y);
                if(position.find(point)!=position.end())
                    return true;
                else
                    position.insert(point);
                break;}
            }
        }
        return false;
    }
};
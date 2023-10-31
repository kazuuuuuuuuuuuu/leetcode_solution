// 算法是 如果尚未满足要求 从lowest order to highest order 进位
class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) 
    {
        long long digit = 10;
        long long result = 0;
        while(true)
        {
            if(finished(n, target))
                break;

            long long difference = digit - n % digit;
            result += difference;
            n += difference;
            digit *= 10;
        }

        return result;
    }

    bool finished(long long n, int target)
    {
        int sum = 0;
        while(n!=0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum<=target;
    }
};
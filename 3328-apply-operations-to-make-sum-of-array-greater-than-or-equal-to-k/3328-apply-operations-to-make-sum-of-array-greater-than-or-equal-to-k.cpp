class Solution {
public:
    int minOperations(int k) 
    {
           int su=1e9;
           int i=1;
           if(i==k)
           {
            return 0;
           }
           while(i<k)
           {
                int an=i-1;
                if(k%i==0)
                {
                    an=an+(k/i)-1;
                }
                else 
                {
                    an=an+(k/i);
                }
                if(su>an)
                {
                    su=an;
                }
                
                i++;
                
           } 
           return su;
    }
};
vector <int> BIT;
int N;

void init (vector<int>& nums) 
{
    BIT.clear();
    N = nums.size();
    BIT = vector <int> (N+1,0);
    for (int i = 0 ;i < nums.size(); i++) update (i+1,nums[i]);
}

void update(int x,int val) 
{ 
    while(x<=N)
    {  
        BIT[x]+=val;  x+=(x&-x);  
    }
}
    
int sumRange(int i, int j) 
{
    return query (j) - query (i-1);    
}

int query(int x) 
{  
    int res=0;  
    while(x>0)  
    {  
        res+=BIT[x];  x-=(x&-x);  
    } 
    return res; 
}

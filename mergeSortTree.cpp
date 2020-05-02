
struct SegmentTree
{
public:
	vl arr;
	vector<vl> segment;

	SegmentTree(ll n) : arr(n+1), segment(4*n) {}

	void combine(vl &c, vl &a, vl &b)
	{
		merge(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));
	}

	void build(ll v, ll start, ll end)
	{
		if (start == end)
		{
			segment[v].pb(arr[start]);return;
		}
		ll mid = (start + end) >> 1;
		build(2*v,start,mid); build(2*v+1,mid+1,end);
		combine(segment[v],segment[2*v],segment[2*v+1]);
	}

	ll query(ll v, ll start, ll end, ll rangeX, ll rangeY, ll k)
	{
		if (rangeX > end or rangeY < start)
		{
			return 0;
		}
		if (rangeX <= start and end <= rangeY)
		{
			ll count = (segment[v].end() - upper_bound(segment[v].begin(),segment[v].end(),k));
			return count;
		}
		ll mid = (start + end) >> 1;
		ll a = query(2*v,start, mid, rangeX, rangeY,k);
		ll b = query(2*v+1,mid+1, end, rangeX, rangeY,k);
		return (a+b);
	}
};

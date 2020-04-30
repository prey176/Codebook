
struct SegmentTree
{
public:
	vl arr;
	vl segment;

	SegmentTree(ll n) : arr(n+1), segment(4*n) {}

	ll combine(ll a, ll b)
	{
		return min(a,b);
	}

	void build(ll v, ll start, ll end)
	{
		if (start == end)
		{
			segment[v] = arr[start];return;
		}
		ll mid = (start + end) >> 1;
		build(2*v,start,mid); build(2*v+1,mid+1,end);
		segment[v] = combine(segment[2*v],segment[2*v+1]);
	}

	void update(ll v, ll start, ll end, ll index, ll val)
	{
		if (index > end or index < start)
		{
			return;
		}
		if (index <= start and end <= index)
		{
			segment[v] += val;
			arr[index] += val;
			return;
		}
		ll mid = (start + end) >> 1;
		update(2*v,start,mid,index,val);
		update(2*v+1,mid+1,end,index,val);
		segment[v] = combine(segment[2*v],segment[2*v+1]);
	}

	ll query(ll v, ll start, ll end, ll rangeX, ll rangeY)
	{
		if (rangeX > end or rangeY < start)
		{
			return (1e15);
		}
		if (rangeX <= start and end <= rangeY)
		{
			return segment[v];
		}
		ll mid = (start + end) >> 1;
		ll a = query(2*v,start, mid, rangeX, rangeY);
		ll b = query(2*v+1,mid+1, end, rangeX, rangeY);
		return combine(a,b);
	}
};

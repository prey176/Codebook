
struct Node
{
public:
	ll num;

	Node(ll a) : num(a) {}
	Node() : num(0) {}
	
	void add(ll val)
	{
		num += val;
	}
 
};
 
struct SegmentTree
{
public:
	vector<Node> segment;
	vl lazy;
 
	SegmentTree (ll n) : segment(4*n), lazy(4*n,0) {}
 
	Node combine (Node a, Node b)
	{
		return Node(a.num+b.num);
	}
 
	void propogate(ll v, ll start, ll end)
	{
		if (start != end)
		{
			lazy[2*v] += lazy[v];
			lazy[2*v+1] += lazy[v];
		}
		segment[v].add(lazy[v]*(end - start + 1));
		lazy[v] = 0;
	}
 
	void build(ll v, ll start , ll end)
	{
		if (start == end)
		{
			segment[v] = Node();
			return;
		}
		ll mid = (start + end) >> 1;
		build(2*v,start,mid);
		build(2*v+1,mid+1,end);
		segment[v] = combine(segment[2*v],segment[2*v+1]);
	}
 
	void update(ll v, ll start, ll end, ll rangeX, ll rangeY, ll val)
	{
		propogate(v,start,end);
		if (rangeX > end or rangeY < start)
		{
			return;
		}
		if (rangeX <= start and end <= rangeY)
		{
			lazy[v] += val;
			propogate(v,start,end);
			return;
		}
		ll mid = (start + end) >> 1;
		update(2*v,start,mid,rangeX,rangeY,val);
		update(2*v+1,mid+1,end,rangeX,rangeY,val);
		segment[v] = combine(segment[2*v],segment[2*v+1]);
	}
 
	Node query(ll v, ll start, ll end, ll rangeX, ll rangeY)
	{
		propogate(v,start,end);
		if (rangeY < start or end < rangeX)
		{
			return Node();
		}
		if (rangeX <= start and end <= rangeY)
		{
			return segment[v];
		}
		ll mid = (start + end) >> 1;
		Node a = query(2*v,start,mid,rangeX,rangeY);
		Node b = query(2*v+1,mid+1,end,rangeX,rangeY);
		return combine(a,b);
	}
 
};

class XorShift{
	unsigned int x,y,z,w;
public:
	XorShift():x(123456789),y(362436069),z(521288629),w(88675123){}
	unsigned int rand() {
		unsigned int t = (x ^ (x << 11)); x = y; y = z; z = w;
		return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
	}
};

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// #define DEBUG 1  //���Կ���
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
  char buf[MAXSIZE], *p1, *p2;
  char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
  IO() : p1(buf), p2(buf), pp(pbuf) {}
  ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
  inline char gc() {
#if DEBUG  //���ԣ�����ʾ�ַ�
    return getchar();
#endif
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
    return p1 == p2 ? ' ' : *p1++;
  }
  inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }
  template <class T>
  inline void read(T &x) {
    register double tmp = 1;
    register bool sign = 0;
    x = 0;
    register char ch = gc();
    for (; !isdigit(ch); ch = gc())
      if (ch == '-') sign = 1;
    for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
    if (ch == '.')
      for (ch = gc(); isdigit(ch); ch = gc())
        tmp /= 10.0, x += tmp * (ch - '0');
    if (sign) x = -x;
  }
  inline void read(char *s) {
    register char ch = gc();
    for (; blank(ch); ch = gc())
      ;
    for (; !blank(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }
  inline void read(char &c) {
    for (c = gc(); blank(c); c = gc())
      ;
  }
  inline void push(const char &c) {
#if DEBUG  //���ԣ�����ʾ�ַ�
    putchar(c);
#else
    if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
    *pp++ = c;
#endif
  }
  template <class T>
  inline void write(T x) {
    if (x < 0) x = -x, push('-');  // �������
    static T sta[35];
    T top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) push(sta[--top] + '0');
  }
  template <class T>
  inline void write(T x, char lastChar) {
    write(x), push(lastChar);
  }
} io;

typedef long long ll;

int n, m;
vector<vector<ll> > a, b;

int main()
{
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	
	io.read(n);
	io.read(m);
	
	a.resize(n + 1, vector<ll>(n + 1, 0));
	b.resize(n + 1, vector<ll>(n + 1, 0));
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			io.read(a[i][j]);
			a[i][j] += a[i - 1][j];
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			io.read(b[i][j]);
			b[i][j] += b[i][j - 1];
		}
	}
	
	while (m--)
	{
		int l, r, p, q;
		
		io.read(l);
		io.read(p);
		io.read(r);
		io.read(q);
		
		if (l > r) swap(l, r);
		if (p > q) swap(p, q);
		
		ll ans = 0;
		
		for (int i = 1; i <= n; ++i) ans += (a[r][i] - a[l - 1][i]) * (b[i][q] - b[i][p - 1]);
		
		io.write(ans, '\n');
	}
	
	return 0;
}

#include <iostream>
long long gcd(long long a, long long b) {
    if (b == 0) { return a; }
    else { a = (gcd(b, a % b)); }
    return a;
}

long long phi (long long n) {
	long long result = n;
	for (long long i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}
int main() {
  long long a, n;
  std::cin >> a >> n;
  if (gcd(a, n) != 1){
    std::cout << -1 << std::endl;
    return 0;
  }
  long long res = 1;
  long long k = phi(n) - 1;
  while (k > 0){
      if (k % 2 == 1){ 
         k = k - 1;
         res = ((res * a)) % n;
      }
      else {
         k = k / 2;
         a = (a * a) % n;
      }
  }
  if (res < 0){res=res + n*(res / n + 1);}
  std::cout << (res % n) << std::endl;
  return 0;
}
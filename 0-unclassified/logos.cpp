#include <bits/stdc++.h>

using namespace std;

pair<int, int> x[4];
char s[200][200];
int n;

int p, q, r;

bool can(int a, int b, int c, int d, int e, int f) {
  if(a + c == e && e == n && b == d && b + f == n) {
    goto nice;
  }
  if(a == c && a + e == n && b + d == n && f == n) {
    goto nice;
  }
  if(c == e && a + c == n && d + f == n && b == n) {
    goto nice;
  }
  if(c + e == n && a == n && d == f && b + d == n) {
    goto nice;
  }
  if(a == c && c == e && e == n && b + d + f == n) {
    goto nice;
  }
  if(b == d & d == f && f == n && a + c + e == n) {
    goto nice;
  }
  return 0;
  
  nice:;
  for(int i = 0; i < a; i++) {
    for(int j = 0; j < b; j++) {
      s[i][j] = p + 'A';
    }
  }
  for(int i = n - e; i < n; i++) {
    for(int j = n - f; j < n; j++) {
      s[i][j] = r + 'A';
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(!s[i][j]) s[i][j] = q + 'A';
    }
  }
  return 1;
}

int main() {
  int tot = 0;
  for(int i = 0; i < 3; i++) {
    scanf("%d %d", &x[i].first, &x[i].second);
    tot += x[i].first * x[i].second;
  }
  for(int i = 0; i < 10000; i++) {
    if(i * i == tot) {
      n = i;
      break;
    }
    if(i * i > tot) {
      puts("-1");
      return 0;
    }
  }
  
  int t[3];
  for(int i = 0; i < 3; i++) {
    t[i] = i;
  }
  do {
    p = t[0]; q = t[1]; r = t[2];
    
    for(int mask = 0; mask < (1 << 3); mask++) {
      for(int i = 0; i < 3; i++) {
        if(mask & (1 << i)) {
          swap(x[i].first, x[i].second);
        }
      }
      if(can(x[t[0]].first, x[t[0]].second, x[t[1]].first, x[t[1]].second, x[t[2]].first, x[t[2]].second)) {
        goto print;
      }
      for(int i = 0; i < 3; i++) {
        if(mask & (1 << i)) {
          swap(x[i].first, x[i].second);
        }
      }
    }
  } while(next_permutation(t, t + 3));
  
  puts("-1");
  return 0;

  print:;
  printf("%d\n", n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%c", s[i][j]);
    }
    printf("\n");
  }
  return 0;
}

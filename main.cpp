#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

static std::vector<size_t> prim_memo = { 2 };

static bool findFromMemo(size_t n) // not used, and not optimized
{
  bool result = false;
  for (size_t i = 0; i < prim_memo.size(); ++i) {
    result |= (prim_memo[i] == n);
  }
  return result;
}

static bool checkNewPrim(size_t n)
{
  bool result = true;
  for (size_t i = 0; i < prim_memo.size(); ++i)
    result &= (n % prim_memo[i] != 0);
  if (result) prim_memo.push_back(n);
  return result;
}

static bool isPrim(size_t n)
{
  if (n < 2) return false;
  if (n <= (prim_memo.back())) return findFromMemo(n);
  else return checkNewPrim(n);
}

int main()
{
  size_t finish;
  size_t section;
  cin >> finish >> section;

  for (size_t start = 1; start < finish; start += section) {
    size_t end = start + section;
    cout << setw(2) << setfill('0') << start << "-";
    cout << setw(2) << setfill('0') << end - 1 << ":";
    for (size_t i = start; i < end; ++i) {
      if (isPrim(i)) cout << "*";
    }
    cout << endl;
  }
}

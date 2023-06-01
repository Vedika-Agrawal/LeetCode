​
2. 1. travese the array
2.  check  for adj ele
3.  if they are diff  swap it with idx and then inc idx and i .
4.  if not then simply inc the value of i .
5.  reutn idx +1 (becz size return kr na hai or idx ki value0 sa start hai ).
===================================================
Easily solved using in buit function unique.
nums.erase(unique(nums.begin() ,nums.end()),nums.end() );
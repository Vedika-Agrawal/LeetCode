class Solution {
public:

int poorPigs(int buckets, int poisonTime, int totalTime) {
    return ceil(log2(buckets) / log2(totalTime / poisonTime + 1));
}
};
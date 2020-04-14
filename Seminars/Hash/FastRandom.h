class FastRandom {
private:
    unsigned long long rnd;
public:
    FastRandom() {
        rnd = 1;
    }
    void seed(unsigned long long seed) {
        rnd = seed;
    }
    unsigned long long rand() {
        rnd ^= rnd << 21;
        rnd ^= rnd >> 35;
        rnd ^= rnd << 4;
        return rnd;
    }
};
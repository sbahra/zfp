#define SEED 5

// https://nuclear.llnl.gov/CNP/rng/rngman/node4.html
#define MULTIPLIER 2862933555777941757
#define INCREMENT 3037000493

#define MAX_RAND_63 (0x7fffffffffffffffuLL)

static uint64 X;

static void
resetRandGen()
{
  X = SEED;
}

// returns integer [0, 2^63 - 1]
static uint64
nextUnsignedRand()
{
  // (mod 2^64)
  X = MULTIPLIER*X + INCREMENT;
  return (uint64)(X & MAX_RAND_63);
}

// returns integer [-(2^62), 2^62 - 1]
static int64
nextSignedRand()
{
  uint64 uDisplace = (uint64)1 << 62;
  return (int64)nextUnsignedRand() - (int64)uDisplace;
}

// domain [0, 1]
static double
nextRandDouble()
{
  return ((double)nextUnsignedRand()) / MAX_RAND_63;
}

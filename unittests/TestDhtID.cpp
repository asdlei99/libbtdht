#include "TestDHT.h"

class dht_id_test : public dht_test {
	protected:
		DhtID aDHT;
		DhtID bDHT;
};

TEST_F(dht_id_test, init) {
	uint Sum = 0;

	for(uint x=0; x<5; ++x) {
		Sum += aDHT.id[x];
	}
	EXPECT_EQ(0, Sum);
}

TEST_F(dht_id_test, equal) {
	aDHT.id[0] = bDHT.id[0] = 0x80000000;
	aDHT.id[1] = bDHT.id[1] = 0x0;
	aDHT.id[2] = bDHT.id[2] = 0x0;
	aDHT.id[3] = bDHT.id[3] = 0x0;
	aDHT.id[4] = bDHT.id[4] = 0x00000001;

	EXPECT_TRUE(aDHT == bDHT);
}

TEST_F(dht_id_test, unequal) {
	aDHT.id[0] = bDHT.id[0] = 0x80000000;
	aDHT.id[1] = bDHT.id[1] = 0x0;
	aDHT.id[2] = bDHT.id[2] = 0x0;
	aDHT.id[3] = bDHT.id[3] = 0x0;
	aDHT.id[4] = 0x0;
	bDHT.id[4] = 0x00000001;

	EXPECT_FALSE(aDHT == bDHT);
}

TEST_F(dht_id_test, lessthan_equal) {
	aDHT.id[0] = bDHT.id[0] = 0x800f0040;
	aDHT.id[1] = bDHT.id[1] = 0x80f00040;
	aDHT.id[2] = bDHT.id[2] = 0x030f005a;
	aDHT.id[3] = bDHT.id[3] = 0xe00f0040;
	aDHT.id[4] = bDHT.id[4] = 0x00c00001;
	EXPECT_FALSE(aDHT < bDHT);
}

TEST_F(dht_id_test, lessthan_less) {
	aDHT.id[0] = bDHT.id[0] = 0x80000000;
	aDHT.id[1] = bDHT.id[1] = 0x0;
	aDHT.id[2] = bDHT.id[2] = 0x0;
	aDHT.id[3] = bDHT.id[3] = 0x0;
	aDHT.id[4] = 0x0;
	bDHT.id[4] = 0x00000001;
	EXPECT_TRUE(aDHT < bDHT);
}

TEST_F(dht_id_test, lessthan_greater) {
	aDHT.id[0] = bDHT.id[0] = 0x80000000;
	aDHT.id[1] = bDHT.id[1] = 0x0;
	aDHT.id[2] = bDHT.id[2] = 0x0;
	aDHT.id[3] = bDHT.id[3] = 0x0;
	aDHT.id[4] = 0x00000001;
	bDHT.id[4] = 0x0;
	EXPECT_FALSE(aDHT < bDHT);
}

TEST_F(dht_id_test, notequal_high) {
	aDHT.id[0] = 0x80000000;
	bDHT.id[0] = 0x40000000;
	aDHT.id[1] = bDHT.id[1] = 0x0;
	aDHT.id[2] = bDHT.id[2] = 0x0;
	aDHT.id[3] = bDHT.id[3] = 0x0;
	aDHT.id[4] = bDHT.id[4] = 0x00000001;
	EXPECT_TRUE(aDHT != bDHT);
}

TEST_F(dht_id_test, notequal_low) {
	aDHT.id[0] = bDHT.id[0] = 0x80000000;
	aDHT.id[1] = bDHT.id[1] = 0x0;
	aDHT.id[2] = bDHT.id[2] = 0x0;
	aDHT.id[3] = bDHT.id[3] = 0x0;
	aDHT.id[4] = 0x0;
	bDHT.id[4] = 0x00000001;
	EXPECT_TRUE(aDHT != bDHT);
}

TEST_F(dht_id_test, notequal_false) {
	aDHT.id[0] = bDHT.id[0] = 0x80000000;
	aDHT.id[1] = bDHT.id[1] = 0x0;
	aDHT.id[2] = bDHT.id[2] = 0x0;
	aDHT.id[3] = bDHT.id[3] = 0x0;
	aDHT.id[4] = bDHT.id[4] = 0x00000001;
	EXPECT_FALSE(aDHT != bDHT);
}

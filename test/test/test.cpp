#include "pch.h"

//#include "../../arg/arg.h"
#include "arg.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}



TEST(CalculateArgInteger, SameQuadrantSum) {

	//testdata
	// pi/6
	double arg1 = M_PI / 6;
	// pi/12
	double arg2 = M_PI / 12;

	ArgInteger iarg1(arg1);
	ArgInteger iarg2(arg2);

	int sum = iarg1 + iarg2;
	
	//pi/4
	int ans = (ArgScale / 8.0) - 1;
	EXPECT_EQ(sum, ans);
}

TEST(CalculateArgInteger, SameQuadrantDiff) {

	//testdata
	// pi/6
	double arg1 = M_PI / 6;
	// pi/12
	double arg2 = M_PI / 12;

	ArgInteger iarg1(arg1);
	ArgInteger iarg2(arg2);

	int sum = iarg1 - iarg2;
	
	//pi/12
	ArgInteger ansint(M_PI / 12);
	int ans = ansint;
	EXPECT_EQ(sum, ans);
}

TEST(CalculateArgDouble, SameQuadrant) {



}
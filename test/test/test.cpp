#include "pch.h"

//#include "../../arg/arg.h"
#include "arg.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}



TEST(CalculateArgInteger, Sum) {

	//testdata
	// pi/6
	double arg1 = M_PI / 6;
	// pi/12
	double arg2 = M_PI / 12;

	ArgInteger iarg1(arg1);
	ArgInteger iarg2(arg2);

	ArgInteger sum = iarg1 + iarg2;
	
	//ミリradの精度で比較する。
	EXPECT_NEAR(sum.GetRadian(), (M_PI / 4), 1.0e-3);
}

TEST(CalculateArgInteger, Diff) {

	//testdata
	// pi/6
	double arg1 = M_PI / 6;
	// pi/12
	double arg2 = M_PI / 12;

	ArgInteger iarg1(arg1);
	ArgInteger iarg2(arg2);

	ArgInteger diff = iarg1 - iarg2;
	
	//ミリradの精度で比較する。
	EXPECT_NEAR(diff.GetRadian(), (M_PI / 12), 1.0e-3);
}

TEST(CalculateArg, TrigonometricCalc) {

	// pi/6
	double arg1 = M_PI / 6;
	// pi/12
	double arg2 = M_PI / 12;

	ArgFromTrigonometric<double> targ1(arg1);
	ArgFromTrigonometric<double> targ2(arg2);

	ArgFromTrigonometric<double> sum = targ1 + targ2;
	//ミリradの精度で比較する。
	EXPECT_NEAR(sum.GetRadian(), (M_PI / 4), 1.0e-3);

	ArgFromTrigonometric<double> diff = targ1 - targ2;
	//ミリradの精度で比較する。
	EXPECT_NEAR(diff.GetRadian(), (M_PI / 12), 1.0e-3);
}

TEST(CalculateArg, Calc) {

	// pi/6
	double arg1 = M_PI / 6;
	// pi/12
	double arg2 = M_PI / 12;

	Arg<double> carg1(arg1);
	Arg<double> carg2(arg2);

	Arg<double> sum = carg1 + carg2;
	//ミリradの精度で比較する。
	EXPECT_NEAR(sum.GetRadian(), (M_PI / 4), 1.0e-3);

	Arg<double> diff = carg1 - carg2;
	//ミリradの精度で比較する。
	EXPECT_NEAR(diff.GetRadian(), (M_PI / 12), 1.0e-3);
}

TEST(CalculateArg, Sum) {

	//冗長だが、[-4π,4π)x[-4π,4π)の領域を全検査する。
	double init1 = -4 * M_PI;
	double end1 = 4 * M_PI;
	double step1 = 0.01;

	double init2 = -4 * M_PI;
	double end2 = 4 * M_PI;
	double step2 = 0.01;

	for (double arg1 = init1; arg1 < end1; arg1 += step1) {
		for (double arg2 = init2; arg2 < end2; arg2 += step2) {
			Arg<double> carg1(arg1);
			Arg<double> carg2(arg2);
			Arg<double> csum = carg1 + carg2;

			ArgFromTrigonometric<double> targ1(arg1);
			ArgFromTrigonometric<double> targ2(arg2);
			ArgFromTrigonometric<double> tsum = targ1 + targ2;
			//ミリradの精度で比較する。
			EXPECT_NEAR(csum.GetRadian(), tsum.GetRadian(), 1.0e-3);

		}
	}
}

TEST(CalculateArg, Diff) {

	//冗長だが、[-4π,4π)x[-4π,4π)の領域を全検査する。
	double init1 = -4 * M_PI;
	double end1 = 4 * M_PI;
	double step1 = 0.01;

	double init2 = -4 * M_PI;
	double end2 = 4 * M_PI;
	double step2 = 0.01;

	for (double arg1 = init1; arg1 < end1; arg1 += step1) {
		for (double arg2 = init2; arg2 < end2; arg2 += step2) {
			Arg<double> carg1(arg1);
			Arg<double> carg2(arg2);
			Arg<double> cdiff = carg1 - carg2;

			ArgFromTrigonometric<double> targ1(arg1);
			ArgFromTrigonometric<double> targ2(arg2);
			ArgFromTrigonometric<double> tdiff = targ1 - targ2;
			//ミリradの精度で比較する。
			EXPECT_NEAR(cdiff.GetRadian(), tdiff.GetRadian(), 1.0e-3);

		}
	}

}

TEST(CalculateArg, Avg) {

	//冗長だが、[-4π,4π)x[-4π,4π)の領域を全検査する。
	double init1 = -4 * M_PI;
	double end1 = 4 * M_PI;
	double step1 = 0.01;

	double init2 = -4 * M_PI;
	double end2 = 4 * M_PI;
	double step2 = 0.01;

	for (double arg1 = init1; arg1 < end1; arg1 += step1) {
		for (double arg2 = init2; arg2 < end2; arg2 += step2) {
			Arg<double> carg1(arg1);
			Arg<double> carg2(arg2);
			Arg<double> cavg = Arg<double>::Average(carg1,carg2);

			ArgFromTrigonometric<double> targ1(arg1);
			ArgFromTrigonometric<double> targ2(arg2);
			ArgFromTrigonometric<double> tavg = ArgFromTrigonometric<double>::Average(targ1, targ2);
			//ミリradの精度で比較する。
			//EXPECT_NEAR(cavg.GetRadian(), tavg.GetRadian(), 1.0e-3);
			ASSERT_NEAR(cavg.GetRadian(), tavg.GetRadian(), 1.0e-3);
		}
	}

}



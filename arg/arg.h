

#ifndef CALCULATE_ARG
#define CALCULATE_ARG


#define M_PI       3.14159265358979323846   // pi

//浮動小数点演算で角度を計算するクラス
template<typename T>
class Arg {
private:
	T mArg;
public:

	Arg(const T &pArg): mArg(normalization(pArg)) {}

	float mod(const float &a, const float &b) {
		return a - std::floorf(a / b) * b;
	}
	double mod(const double &a, const double &b) {
		return a - std::floor(a / b) * b;
	}

	inline T normalization0to2pi(const T &pArg) {
		constexpr T pi2 = static_cast<T>(2) * static_cast<T>(M_PI);
		return mod(pArg, pi2);
	}
	inline T normalization(const T &pArg) {
		constexpr T pi = static_cast<T>(M_PI);
		return normalization0to2pi(pArg + pi) - pi;
	}

	Arg& operator = (Arg &pArg) {
		mArg = pArg.mArg;
	}

	Arg operator + (Arg &pArg) {
		return Arg(this->mArg + pArg.mArg);
	}

	Arg operator - (Arg pArg) {
		return Arg(this->mArg - pArg.mArg);
	}

	Arg operator / (T pNum) {
		return Arg(this->mArg / pNum);
	}

	T GetRadian() {
		return mArg;
	}

	static Arg Average(Arg &pArg1, Arg &pArg2) {
		Arg diff = pArg2 - pArg1;
		Arg avg = pArg1 + (diff/2);
		return avg;
	}

};


//整数演算で角度を計算するクラス
constexpr int ArgScale = 32768;
class ArgInteger {
private:
	int mArg;

	int Wrap(int pArg) {
		return (((pArg + 16384) & 0x7fff) - 16384);
	}

public:
	ArgInteger(double pRadian) {
		mArg = pRadian * ArgScale / (2 * M_PI);
	}

	ArgInteger(int pArg) : mArg(pArg) {}

	int operator + (ArgInteger pArgInt) {
		return Wrap(this->mArg + pArgInt.mArg);
	}
	int operator - (ArgInteger pArgInt) {
		return Wrap(this->mArg - pArgInt.mArg);
	}

	double GetRadian() {
		return mArg * ((2 * M_PI)/ArgScale);
	}

};

//答え合わせ用。回転座標変換で正解を求めるクラス
template<typename T>
class ArgFromTrigonometric {
private:
	T mX;
	T mY;
public:
	ArgFromTrigonometric(const T &pRadian)
		:mX(cos(pRadian)), mY(sin(pRadian)) 
	{}

	ArgFromTrigonometric(const T &pX, const T &pY)
		:mX(pX), mY(pY)
	{}

	ArgFromTrigonometric& operator = (const ArgFromTrigonometric &pArg) {
		mX = pArg.mX;
		mY = pArg.mY;
	}

	ArgFromTrigonometric operator + (const ArgFromTrigonometric &pArg) {
		T y = this->mY * pArg.mX + this->mX * pArg.mY;
		T x = this->mX * pArg.mX - this->mY * pArg.mY;
		return ArgFromTrigonometric(x, y);
	}

	ArgFromTrigonometric operator - (const ArgFromTrigonometric &pArg) {
		T y = this->mY * pArg.mX - this->mX * pArg.mY;
		T x = this->mX * pArg.mX + this->mY * pArg.mY;
		return ArgFromTrigonometric(x, y);
	}

	T GetRadian() {
		return atan2(mY, mX);
	}

	ArgFromTrigonometric static Average(const ArgFromTrigonometric &pArg1, const ArgFromTrigonometric &pArg2) {
		T sumX = (pArg1.mX + pArg2.mX) / 2;
		T sumY = (pArg1.mY + pArg2.mY) / 2;
		return ArgFromTrigonometric(sumX, sumY);
	}

};


#endif




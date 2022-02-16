

#ifndef CALCULATE_ARG
#define CALCULATE_ARG


#define M_PI       3.14159265358979323846   // pi

//���������_���Z�Ŋp�x���v�Z����N���X
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

	T GetRadian() {
		return mArg;
	}

};


//�������Z�Ŋp�x���v�Z����N���X
constexpr int ArgScale = 32768;
class ArgInteger {
private:
	int mArg;

	int ReWrap(int pArg) {
		return (((pArg + 16384) & 0x7fff) - 16384);
	}

public:
	ArgInteger(double pRadian) {
		mArg = pRadian * ArgScale / (2 * M_PI);
	}

	ArgInteger(int pArg) : mArg(pArg) {}

	int operator + (ArgInteger pArgInt) {
		return ReWrap(this->mArg + pArgInt.mArg);
	}
	int operator - (ArgInteger pArgInt) {
		return ReWrap(this->mArg - pArgInt.mArg);
	}

	double GetRadian() {
		return mArg * ((2 * M_PI)/ArgScale);
	}

};

//�������킹�p�B��]���W�ϊ��Ő��������߂�N���X
template<typename T>
class ArgForTrigonometric {
private:
	T mX;
	T mY;
public:
	ArgForTrigonometric(T pRadian) {
		mX = cos(pRadian);
		mY = sin(pRadian);
	}

	ArgForTrigonometric(T pX, T pY) {
		mX = pX;
		mY = pY;
	}

	ArgForTrigonometric& operator = (ArgForTrigonometric pArg) {
		mX = pArg.mX;
		mY = pArg.mY;
	}

	ArgForTrigonometric operator + (ArgForTrigonometric pArg) {
		T y = this->mY * pArg.mX + this->mX * pArg.mY;
		T x = this->mX * pArg.mX - this->mY * pArg.mY;
		return ArgForTrigonometric(x, y);
	}

	ArgForTrigonometric operator - (ArgForTrigonometric pArg) {
		T y = this->mY * pArg.mX - this->mX * pArg.mY;
		T x = this->mX * pArg.mX + this->mY * pArg.mY;
		return ArgForTrigonometric(x, y);
	}

	T GetRadian() {
		return atan2(mY, mX);
	}

};


#endif




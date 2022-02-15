

#ifndef CALCULATE_ARG
#define CALCULATE_ARG


#define M_PI       3.14159265358979323846   // pi

//���������_���Z�Ŋp�x���v�Z����N���X
class Arg {

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

	int operator = (ArgInteger pArgInt) {
		return pArgInt.mArg;
	}
	int operator + (ArgInteger pArgInt) {
		return ReWrap(this->mArg + pArgInt.mArg);
	}
	int operator - (ArgInteger pArgInt) {
		return ReWrap(this->mArg - pArgInt.mArg);
	}

};

//�������킹�p�B��]���W�ϊ��Ő��������߂�N���X
class ArgForTrigonometric {

};


#endif




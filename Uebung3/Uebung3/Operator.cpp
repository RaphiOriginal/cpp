

template<typename T> struct Plus {
	static T apply(T Left, T Right) {
		return Left + Right;
	}
};

template<typename T> struct Minus {
	static T apply(T Left, T Right) {
		return Left - Right;
	}
};
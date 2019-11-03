#ifndef MATRIX_DIMENSIONS
#define MATRIX_DIMENSIONS

struct MatrixDimensions {
	private:
		int height;
		int width;

	public:
		MatrixDimensions(int height, int width);
		int getHeight();
		int getWidth();
		static MatrixDimensions createFromUserInput();
};

#endif
using BYTE = unsigned char;
using COLORREF = unsigned int;

struct DebugImage {
	int nChannels;
	int width;
	int height;
	int pitch;
	BYTE* data;
};

int main() {
	const int size = 51;
	COLORREF array[size][size];
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			array[y][x] = *reinterpret_cast<int*>(0xffffff00);
		}
	}
	DebugImage debug = DebugImage();
	debug.nChannels = 4;
	debug.height = size;
	debug.width = size;
	debug.pitch = sizeof(array[0]);
	debug.data = reinterpret_cast<BYTE*>(&array[0][0]);
}


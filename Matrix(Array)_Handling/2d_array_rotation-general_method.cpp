// counter clockwise rotation of 3 by 3 array

void rotate(int arr[][3])
{
	int tmp[3][3] = { 0 };
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			tmp[2 - x][y] = arr[y][x];
		}
	}

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			arr[y][x] = tmp[y][x];
		}
	}
}
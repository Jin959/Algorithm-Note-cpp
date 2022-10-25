//  rotation of 3 by 3 array

void copy_result(int tmp[][3], int arr[][3])
{
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			arr[y][x] = tmp[y][x];
		}
	}
}

void rotate_left(int arr[][3])  //counter clockwise
{
	int tmp[3][3] = { 0 };
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			tmp[2 - x][y] = arr[y][x];
		}
	}

	copy_result(tmp, arr);
}

void rotate_right(int arr[][3]) // clockwise
{
	int tmp[3][3] = { 0 };
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			tmp[x][2 - y] = arr[y][x];
		}
	}

	copy_result(tmp, arr);
}
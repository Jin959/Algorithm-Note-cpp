// counter clockwise rotation of 3 by 3 array

/*
 배열과 실수 좌표는 y축 방향이 반대이기 때문에 +90이 아닌 -90회전이 된다.
 반시계 방향 1회 회전은 theta = -90에 대한 회전변환이다.


 회전 변환
 x_prime = x*cos(-90) - y*sin(-90)
 y_prime = x*sin(-90) + y*cos(-90)
 
 sin(-90) = -1, cos(-90) = 0
 <cmath>라이브러리의 삼각함수는 radian을 사용하기 때문에
 매크로 상수 PI = 3.141592를 사용하면 소수가 나온다.
 따라서 그냥 계산값을 사용하는 것이 더욱 정확한 답이 나온다.
*/

void rotate(int arr[][3])
{
	int tmp[3][3] = { 0 };
	
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			int xp = x * 0 - y * (-1);
			int yp = x * (-1) + y * 0;

			// 4 사분면에 존재하기 때문에 yp를 (col.size - 1 )만큼 끌어올려 배열에 맞춘다. 
			tmp[yp + 2][xp] = arr[y][x];
		}
	}


	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			arr[i][j] = tmp[i][j];

}
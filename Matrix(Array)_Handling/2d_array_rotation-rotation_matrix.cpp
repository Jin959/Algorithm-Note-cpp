// counter clockwise rotation of 3 by 3 array

/*
 �迭�� �Ǽ� ��ǥ�� y�� ������ �ݴ��̱� ������ +90�� �ƴ� -90ȸ���� �ȴ�.
 �ݽð� ���� 1ȸ ȸ���� theta = -90�� ���� ȸ����ȯ�̴�.


 ȸ�� ��ȯ
 x_prime = x*cos(-90) - y*sin(-90)
 y_prime = x*sin(-90) + y*cos(-90)
 
 sin(-90) = -1, cos(-90) = 0
 <cmath>���̺귯���� �ﰢ�Լ��� radian�� ����ϱ� ������
 ��ũ�� ��� PI = 3.141592�� ����ϸ� �Ҽ��� ���´�.
 ���� �׳� ��갪�� ����ϴ� ���� ���� ��Ȯ�� ���� ���´�.
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

			// 4 ��и鿡 �����ϱ� ������ yp�� (col.size - 1 )��ŭ ����÷� �迭�� �����. 
			tmp[yp + 2][xp] = arr[y][x];
		}
	}


	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			arr[i][j] = tmp[i][j];

}
#include<iostream>
using namespace std;
int **arr;
void fill(int start_y, int start_x, int hall_y, int hall_x,int size);

int main(){
	int size;
	cin >> size;
	arr = new int*[size];
	for (int i = 0; i < size; i++){
		arr[i] = new int[size];
	}
	int hall_x, hall_y;
	cin >> hall_y >> hall_x;
	arr[hall_y][hall_x] = 0;

	int temp=size;
	int count = 0;
	for (; temp != 1; temp=temp / 2){
		count++;
	}

	fill(0, 0, hall_y, hall_x,size);
	

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void fill(int start_y, int start_x, int hall_y, int hall_x,int size){
		if (hall_y<start_y+size/2&&hall_x<start_x+size/2){			//왼쪽상단
			arr[start_y + size / 2 - 1][start_x + size / 2] = 1;
			arr[start_y + size / 2][start_x + size / 2] = 1;
			arr[start_y + size / 2][start_x + size / 2 - 1] = 1;
			if (size != 2){
				fill(start_y, start_x, hall_y, hall_x, size / 2);
				fill(start_y, start_x + size / 2, start_y + size / 2 - 1, start_x + size / 2, size / 2);
				fill(start_y + size / 2, start_x + size / 2, start_y + size / 2, start_x + size / 2, size / 2);
				fill(start_y + size / 2, start_x, start_y + size / 2, start_x + size / 2 - 1, size / 2);
			}
		}
		else if (hall_y<start_y+size/2&&hall_x>=start_x+size/2){		//오른쪽상단
			arr[start_y + size / 2-1][start_x + size / 2-1] = 2;
			arr[start_y + size / 2][start_x + size / 2-1] = 2;
			arr[start_y + size / 2][start_x + size / 2] = 2;
			if (size != 2){
				fill(start_y, start_x+size/2, hall_y, hall_x, size / 2);
				fill(start_y, start_x, start_y + size / 2 - 1, start_x + size / 2 - 1, size / 2);
				fill(start_y + size / 2, start_x, start_y + size / 2, start_x + size / 2 - 1, size / 2);
				fill(start_y + size / 2, start_x + size / 2, start_y + size / 2, start_x + size / 2, size / 2);
			}
		}
		else if (hall_y>=start_y + size / 2 && hall_x < start_x + size / 2){		//왼쪽하단
			arr[start_y + size / 2-1][start_x + size / 2-1] = 3;
			arr[start_y + size / 2-1][start_x + size / 2] = 3;
			arr[start_y + size / 2][start_x + size / 2] = 3;
			if (size != 2){
				fill(start_y+size/2, start_x , hall_y, hall_x, size / 2);
				fill(start_y, start_x, start_y + size / 2 - 1, start_x + size / 2 - 1, size / 2);
				fill(start_y, start_x + size / 2, start_y + size / 2 - 1, start_x + size / 2, size / 2);
				fill(start_y + size / 2, start_x + size / 2, start_y + size / 2, start_x + size / 2, size / 2);
			}
		}
		else if (hall_y>=start_y + size / 2 && hall_x >= start_x + size / 2){					//오른쪽하단
			arr[start_y + size / 2][start_x + size / 2-1] = 4;
			arr[start_y + size / 2-1][start_x + size / 2-1] = 4;
			arr[start_y + size / 2-1][start_x + size / 2] = 4;
			if (size != 2){
				fill(start_y + size / 2, start_x+size/2, hall_y, hall_x, size / 2);
				fill(start_y + size / 2, start_x, start_y + size / 2, start_x + size / 2 - 1, size / 2);
				fill(start_y, start_x, start_y + size / 2 - 1, start_x + size / 2 - 1, size / 2);
				fill(start_y, start_x + size / 2, start_y + size / 2 - 1, start_x + size / 2, size / 2);
			}
		}
		else{}
	

	
}

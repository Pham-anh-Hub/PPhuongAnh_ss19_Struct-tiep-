#include<stdio.h>
#include<string.h>
struct SinhVien{
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void delItem(struct SinhVien sinhvien[100], int n);

int main(){
	int n = 5;
    struct SinhVien sinhvien[100] = {
        {1,"Linh", 18, "0987126443"},
        {2,"Trang", 19, "0982713422"},
        {3,"Dung", 18, "0923674532"},
        {4,"Mai", 19, "0982713422"},
        {5,"Bong", 18, "0923674532"}
    };
    sort(sinhvien, n);
	return 0;
}

void sort( struct SinhVien sinhvien[100], int n){
	struct SinhVien temp;
		for( int i = 0; i< n; i++){
			for ( int j = 0; j< n-1-i; j++){
				if ( strcmp(sinhvien[j].name, sinhvien[j+1].name) > 0 ){
					temp = sinhvien[j];
	                sinhvien[j] = sinhvien[j+1];
	                sinhvien[j+1] = temp;
				}
			}
		}
	printf("\nKet qua: \n");
	for ( int i = 0; i< n ; i++){
		printf("\nid: %d\n ten: %s tuoi: %d\n sdt: %s", sinhvien[i].id, sinhvien[i].name, sinhvien[i].age, sinhvien[i].phoneNumber);
	}
}


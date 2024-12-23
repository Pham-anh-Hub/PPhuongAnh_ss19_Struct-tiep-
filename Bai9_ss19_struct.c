#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct SinhVien{
	char id[20];
	char name[25];
	int age;
	char phoneNumber[20];
};

void show(struct SinhVien sv[50], int n);
void add(struct SinhVien sv[50], int *n);
void edit(struct SinhVien sv[50], int n);
void erase(struct SinhVien sv[50], int *n);
void find(struct SinhVien sv[50], int n);
void arrange(struct SinhVien sv[50], int n);



int main(){
	int choice, n=4;
	struct SinhVien sv[50] = {
		{"B24DTCN413", "Pham Phuong Anh", 18,"0912741432"},
		{"B24DTCN152", "Le Nhat Linh", 18, "092735463"},
		{"B24DTCN412", "Ha Minh Trang", 18, "081241453"},
		{"B24DTCN342", "Pham Minh Quan", 19, "082174732"}
	};
	do{
		printf("\n\t******MENU*******\n");
		printf("1. Hien thi danh sach sinh vien\n");
		printf("2. Them sinh vien\n");
		printf("3. Sua thong tin sinh vien\n");
		printf("4. Xoa sinh vien\n");
		printf("5. Tim kiem thong tin sinh vien\n");
		printf("6. Sap xep danh sach sinh vien\n");
		printf("7. Thoat\n");
		printf("\tLua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				show(sv, n);
				break;
			case 2:
				add(sv, &n);
				break;
			case 3:
				edit(sv, n);
				break;
			case 4:
				erase(sv, &n);
				break;
			case 5:
				find(sv, n);
				break;
			case 6:
				arrange(sv, n);
				break;
			case 7:
				printf("Thoat!!!");
				exit(0);
				break;
			default:
				printf("Moi chon 1 -> 6");
		}
	}while(1);

	return 0;
}

void show(struct SinhVien sv[], int n){
	printf("\n\tThong tin cac sinh vien: \n");
	for(int i=0; i<n; i++){
		printf("Ma sinh vien: %s", sv[i].id);
		printf("\nHo va ten: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSo dien thoai: %s",sv[i].phoneNumber);
		printf("\n");
	}
}

void add(struct SinhVien sv[], int *n){
	 
	printf("Moi nhap thong tin sv:");
	fflush(stdin); 
	printf("Moi nhap ma sv: ");
	fgets(sv[*n].id, 20, stdin); 
	printf("\nNhap ho va ten: ");
	fgets(sv[*n].name, 25, stdin);
	printf("Nhap tuoi: ");
	scanf("%d",&sv[*n].age);
	fflush(stdin); 
	printf("Nhap so dien thoai: ");
	fgets(sv[*n].phoneNumber, 20, stdin);
	(*n)++;
	
	printf("\n\tThong tin cac sinh vien: \n");
	for(int i=0; i<*n; i++){
		printf("\nMa sinh vien: %s", sv[i].id);
		printf("\nHo va ten: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSo dien thoai: %s",sv[i].phoneNumber);
		printf("\n");
	}
}
void  edit(struct SinhVien sv[], int n){
	char check[20];
	int temp=0, index; 
	for(int i=0; i<n; i++){
		printf("\nMa sinh vien: %s", sv[i].id);
		printf("\nHo va ten: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSo dien thoai: %s",sv[i].phoneNumber);
		printf("\n");
	}
	fflush(stdin); 
	printf("Moi nhap ma sinh vien muon xoa: ");
    fgets(check, 20, stdin);
    check[strcspn(check, "\n")] = 0;
	for (int i = 0; i < n; i++){
        if (strcmp(sv[i].id, check) == 0) {
            temp = 1;
            index = i; 
            break;
        }
    }
	if(temp == 1){
		fflush(stdin);
		printf("\nMoi nhap ten: ");
		fgets(sv[index].name, 25, stdin);
		sv[index].name[strlen(sv[index].name) -1] = '\0' ; 
		printf("Moi nhap tuoi: ");
		scanf("%d", &sv[index].age);
		fflush(stdin); 
		printf("Moi nhap so dien thoai: ");
		fgets(sv[index].phoneNumber, 20, stdin);
		sv[index].phoneNumber[strlen(sv[index].phoneNumber) -1] = '\0' ; 
	}
	for(int i=0; i<n; i++){
		printf("\nMa sinh vien: %s", sv[i].id);
		printf("\nHo va ten: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSo dien thoai: %s",sv[i].phoneNumber);
		printf("\n");
	}
}
void erase(struct SinhVien sv[], int *n){
	char check[20];
	int temp=0, index; 
	for(int i=0; i<*n; i++){
		printf("\nMa sinh vien: %s", sv[i].id);
		printf("\nHo va ten: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSo dien thoai: %s",sv[i].phoneNumber);
		printf("\n");
	}
	fflush(stdin); 
	printf("Moi nhap ma sinh vien muon sua: ");
    fgets(check, 20, stdin);
    check[strcspn(check, "\n")] = 0;
	for (int i = 0; i < *n; i++){
        if (strcmp(sv[i].id, check) == 0) {
            temp = 1;
            index = i; 
            break;
        }
    }
	if(temp == 1){
		for(int i=index; i<*n; i++){
			sv[i]=sv[i+1]; 
		} 
	}
	(*n)--;
	printf("\tThong tin sv sau xoa: \n"); 
	for(int i=0; i<*n; i++){
		printf("\nMa sinh vien: %s", sv[i].id);
		printf("\nHo va ten: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSo dien thoai: %s",sv[i].phoneNumber);
		printf("\n");
	}
}
void find(struct SinhVien sv[], int n){
	char check[20];
	int temp = 0, index;
	fflush(stdin);
	printf("Moi nhap ten sv muon tim: ");
	fgets(check, 20, stdin);
	check[strcspn(check, "\n")] = 0;
	for (int i = 0; i < n; i++){
        if (strstr(sv[i].name, check) == 0) {
            printf("\nMa sinh vien: %s", sv[i].id);
			printf("\nHo va ten: %s", sv[i].name);
			printf("\nTuoi: %d", sv[i].age);
			printf("\nSo dien thoai: %s",sv[i].phoneNumber);
			printf("\n");
        }else{
        	printf("Khong tim thay !!");
		} 
    }	
}

void arrange( struct SinhVien sv[], int n){
	
	for( int i = 0; i< n; i++){
		for ( int j = 0; j< n-1-i; j++){
			if ( strcmp(sv[j].id, sv[j+1].id ) > 0 ){
				struct SinhVien temp = sv[j];
                sv[j] = sv[j+1];
                sv[j+1] = temp;
			}
		}
	}
	printf("\nKet qua: \n");
	for ( int i = 0; i< n ; i++){
		printf("\n\nID: %s", sv[i].id);
		printf("\nTen: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSdt: %s ", sv[i].phoneNumber);
	}
}








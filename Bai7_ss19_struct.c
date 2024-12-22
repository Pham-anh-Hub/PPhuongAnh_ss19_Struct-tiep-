#include<stdio.h>
#include<string.h>

struct SinhVien{
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void delItem(struct SinhVien sinhvien[100], int *n);

int main() {
    int n = 5;
    struct SinhVien sinhvien[100] = {
        {1,"Anh", 18, "0987126443"},
        {2,"Bong", 19, "0982713422"},
        {3,"Chinh", 18, "0923674532"},
        {4,"Bi", 19, "0982713422"},
        {5,"Chip", 18, "0923674532"}
    };
    
    delItem(sinhvien, &n);  
    
    return 0;
}

void delItem(struct SinhVien sinhvien[100], int *n) {
    char found[20];
    int check = 0;  
    printf("Danh sach sinh vien:\n");
    
    // Display current student list
    for(int i = 0; i < *n; i++) {
        printf("\nSinh vien %d:\n", i+1);
        printf("id: %d\t ten: %s tuoi: %d\t sdt: %s", sinhvien[i].id, sinhvien[i].name, sinhvien[i].age, sinhvien[i].phoneNumber);
    }

    
    printf("\n\nMoi nhap ten sv muon xoa: ");
    fgets(found, 20, stdin);
    
    if (found[strlen(found) - 1] == '\n') {
        found[strlen(found) - 1] = '\0'; 
    } 

    
    for(int i = 0; i < *n; i++) {
        if(strcmp(sinhvien[i].name, found) == 0) {
            check = 1;
            for(int j = i; j < *n - 1; j++) {
                sinhvien[j] = sinhvien[j+1]; 
            }
            (*n)--;  
            break;
        }
    }
    
    if(check != 1) {
        printf("Khong tim thay sinh vien!!\n");
    } else {
        printf("\n\tThong tin cac sinh vien sau khi xoa:\n");
        for(int i = 0; i < *n; i++) {
            printf("\nSinh vien %d:\n", i+1);
            printf("id: %d\t ten: %s tuoi: %d\t sdt: %s", sinhvien[i].id, sinhvien[i].name, sinhvien[i].age, sinhvien[i].phoneNumber);
        }
    }
}


#include <stdio.h>
#include "contact.h"
#include "storage.h"
#include "ui.h"
#include "util.h"

#define DATA_FILE "contacts.txt"

int main(void) {
    Book book;
    book_init(&book);
    output();

    if (storage_load(&book, DATA_FILE) == 0) {
        printf("已载入 %d 条记录\n", book.count);
    } else {
        printf("没有数据文件，从空通讯录开始\n");
    }

    char choice[8];
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];

    while (1) {
        ui_menu();
        ui_read_line("", choice, sizeof(choice));

        if (choice[0] == '1') {
            ui_read_line("姓名: ", name, sizeof(name));
            ui_read_line("电话: ", phone, sizeof(phone));
            ui_read_line("邮箱: ", email, sizeof(email));
            int r = book_add(&book, name, phone, email);
            if (r == 0)       printf("已添加\n");
            else if (r == -1) printf("通讯录满了\n");
            else              printf("这个名字已经存在\n");

        } else if (choice[0] == '2') {
            ui_read_line("要删除的姓名: ", name, sizeof(name));
            if (book_remove(&book, name) == 0) printf("已删除\n");
            else                               printf("没找到这个人\n");

        } else if (choice[0] == '3') {
            ui_read_line("要查找的姓名: ", name, sizeof(name));
            int i = book_find(&book, name);
            if (i >= 0) printf("%s  %s  %s\n", book.items[i].name, book.items[i].phone,book.items[i].email);
            else        printf("没找到这个人\n");

        } else if (choice[0] == '4') {
            ui_show_all(&book);

        } else if (choice[0] == '5'){
            ui_read_line("要修改的联系人：",name,sizeof(name));
            ui_read_line("姓名: ", name, sizeof(name));
            ui_read_line("电话: ", phone, sizeof(phone));
            ui_read_line("邮箱: ", email, sizeof(email));

            int r = book_fix(&book,name,phone,email);
            if (r == 0) printf ("已成功修改！");
            else printf("修改失败，请重试");

        }else if (choice[0] == '0') {
            if (storage_save(&book, DATA_FILE) == 0) printf("已保存，再见\n");
            else                                     printf("保存失败\n");
            break;

        } else {
            printf("无效选择\n");
        }
    }
    return 0;
}
